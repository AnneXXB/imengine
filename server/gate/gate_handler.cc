/*
 *  Copyright (c) 2016, https://github.com/zhatalk
 *  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "gate/gate_handler.h"

#include <folly/Conv.h>

// #include "nebula/net/handler/zproto/zproto_handler.h"
#include "nebula/net/net_engine_manager.h"
#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/net/handler/nebula_handler_util.h"
#include "nebula/base/id_util.h"
#include "nebula/base/time_util.h"

#include "proto/api/cc/auth.pb.h"
#include "proto/s2s/cc/presences.pb.h"
#include "proto/s2s/cc/servers.pb.h"
#include "nebula/net/zproto/api_message_box.h"

#include "gate/gate_server_util.h"
// folly::future

int gate::OnNewConnection(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline) {
  LOG(INFO) << "OnNewConnection - conn new";
  
  // DCHECK(service->GetServiceName() == "frontend");
  if (service->GetServiceName() == "gate_server") {
    // 1. 设置客户端连接数据
    auto h = pipeline->getHandler<ZProtoHandler>();
    DCHECK(h);
    
    auto conn_data = std::make_shared<ClientConnContext>();
    conn_data->state = ClientConnContext::State::CONNECTED;
    h->SetAttachData(conn_data);
    
    // TODO(@benqi):
    // 启动定时器等15秒
  } else if (service->GetServiceName() == "push_channel_client") {
    // 注册到push_server
    auto server_auth_req = std::make_shared<ApiRpcRequest<zproto::ServerAuthReq>>();
    (*server_auth_req)->set_server_id(1);
    (*server_auth_req)->set_server_name("gate_server");
    
    std::unique_ptr<folly::IOBuf> data;
    server_auth_req->SerializeToIOBuf(data);
    pipeline->write(std::move(data));
  }
  return 0;
}

int gate::OnDataReceived(nebula::ZProtoPipeline* pipeline, std::shared_ptr<PackageMessage> message_data) {
  LOG(INFO) << "OnDataReceived - recv data" << message_data->ToString();
  // 拦截zproto::LoginOkPush
  //
  
  auto h = pipeline->getHandler<ZProtoHandler>();
  DCHECK(h);
  const std::string& service_name = h->GetServiceBase()->GetServiceName();
  
  if (service_name == "gate_server") {
    
    ClientConnContext* conn_data = h->CastByGetAttachData<ClientConnContext>();
    DCHECK(conn_data);
    
    if (!conn_data) {
      // TODO(@benqi): LOG(ERROR) << "";
      // 断开连接
      return 0;
    }
    
    // 第一个包必须是zproto::UserTokenAuthReq
    if (conn_data->state == ClientConnContext::State::CONNECTED) {
      if (message_data->GetPackageType() != Package::RPC_REQUEST) {
        // TODO(@benqi): LOG(ERROR) << "";
        // 断开连接
        
        return 0;
      } else {
        // TODO(@benqi):
        // 启动定时器20秒等authd返回
        conn_data->state = ClientConnContext::State::AUTH;
        conn_data->state = ClientConnContext::State::WORKING;
        
        auto encoded = std::static_pointer_cast<EncodedRpcRequest>(message_data);
        LOG(ERROR) << "zproto.StartTestingAuthReq => " << CRC32("zproto.StartTestingAuthReq");
        if (encoded->GetMethodID() != CRC32("zproto.StartTestingAuthReq")) {
          LOG(ERROR) << "recv a invalid method_id: " << encoded->GetMethodID();
          return 0;
        }
        
        uint64_t conn_id = h->GetConnID();
        // uint32_t user_id;
        
        LOG(INFO) << "encoded: " << encoded->ToString();
        LOG(INFO) << "encoded's message_id: " << encoded->message_id();

        ZRpcUtil::DoClientCall("auth_client", encoded)
        .within(std::chrono::milliseconds(5000))
        // TODO(@benqi): conn_data可能会失效
        .then([conn_data, conn_id](ProtoRpcResponsePtr rsp) {
          CHECK(rsp);
          LOG(INFO) << "auth_client rsp: " << rsp->ToString();
          // (*login_rsp)->Utf8DebugString();
          WritePackage(conn_id, rsp);
          
          if (rsp->GetPackageType() == Package::RPC_OK) {
            auto login_rsp = ToApiRpcOk<zproto::AuthRsp>(rsp);
            LOG(INFO) << "auth_client login_rsp: " << (*login_rsp)->Utf8DebugString();

            // TODO(@benqi): 移到用户认证成功后通知
            // 3. 上线通知在线状态服务器
            auto req = std::make_shared<ApiRpcRequest<zproto::ClientOnlineReq>>();
            (*req)->set_server_id(1);
            (*req)->set_conn_id(conn_id);
            (*req)->set_app_id(1);
            // (*req)->set_user_id(folly::to<uint32_t>((*login_rsp)->user_id()));
            (*req)->set_user_id((*login_rsp)->user().uid());
            //folly::to<uint32_t>((*login_rsp)->user_id()));
            (*req)->set_state(1);

            conn_data->app_id = 1;
            conn_data->user_id = (*login_rsp)->user().uid();
            
            ZRpcUtil::DoClientCall("online_status_client", req)
            .within(std::chrono::milliseconds(5000))
            .then([](ProtoRpcResponsePtr rsp2) {
              CHECK(rsp2);
              LOG(INFO) << "online_status_client rsp: " << rsp2->ToString();
              // auto online_rep = ToApiRpcOk<zproto::ClientOnlineRsp>(rsp2);
              // LOG(INFO) << (*online_rep)->Utf8DebugString();
            });
          }
        });
      }
    } else if (conn_data->state == ClientConnContext::State::AUTH) {
      // TODO(@benqi): 还在验证，收到的数据包都为非法包，直接断开
      conn_data->state = ClientConnContext::State::ERROR;
    } else if (conn_data->state == ClientConnContext::State::WORKING) {
      
      // 转发到router_server
      message_data->set_session_id(h->GetConnID());
      message_data->set_birth_conn_id(h->GetConnID());
      message_data->set_birth_server_id(1);
      message_data->set_birth_track_uuid(GetNextIDBySnowflake());
      message_data->set_birth_timetick(NowInMsecTime());
      message_data->set_birth_remote_ip(h->GetRemoteAddress());
      message_data->set_birth_from("gate_server");
      message_data->push_back_option(1);
      message_data->push_back_option(conn_data->user_id);
      
      WritePackage("messenger_client", message_data);
      
      //    auto encoded = std::static_pointer_cast<teamtalk::EncodedMessage>(message_data);
      //    DCHECK(encoded);
      //
      //    auto rpc = std::make_shared<EncodedRpcRequest>();
      //
      //    // 构建Rpc包，设置method_id
      //    // 填充AttachData
      //    // 然后转发给router_client
      //    rpc->method_id = encoded->GetMessageType();
      //    rpc->message.SwapPayload(encoded->payload());
    }
  } else {
    // 转发客户端
    uint64_t conn_id = message_data->session_id();
    WritePackage(conn_id, message_data);
    // WriterUtil::Write(conn_id, message_data);
  }
  
  // auto service = h->GetServiceBase();
  return 0;
}

int gate::OnConnectionClosed(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline) {
  LOG(INFO) << "OnConnectionClosed - conn closed";
  // DCHECK(service->GetServiceName() == "frontend");
  
  // TODO(@benqi):
  auto h = pipeline->getHandler<ZProtoHandler>();
  DCHECK(h);
  
  return 0;
}
