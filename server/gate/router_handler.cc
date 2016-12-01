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

#include "frontend/router_handler.h"

#include "nebula/net/handler/zproto/zproto_handler.h"

// WriterUtil::Write("net_engine_client_test", std::move(o));

#include "nebula/net/zproto/api/api_message_box.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/net/handler/nebula_handler_util.h"

// folly::future

//folly::Future<folly::Unit> WritePackage(const std::string& service_name, std::shared_ptr<PackageMessage> message_data) {
//  std::unique_ptr<folly::IOBuf> data;
//  message_data->SerializeToIOBuf(data);
//  return WriterUtil::Write(service_name, std::move(data));
//}

#if 0
///////////////////////////////////////////////////////////////////////////////////////
int RouterHandler::OnNewConnection(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline) {
  LOG(INFO) << "OnNewConnection - conn new";
  DCHECK(service->GetServiceName() == "router_handler");
  
//  if (service->GetServiceName() == "frontend") {
//    // 设置客户端连接数据
//    auto h = pipeline->getHandler<ZProtoHandler>();
//    auto conn_data = std::make_shared<FrontendContext>();
//    conn_data->state = FrontendContext::State::CONNECTED;
//    h->SetAttachData(std::make_shared<FrontendContext>());
//    
//    // 通知在线状态服务器
//    auto req = std::make_shared<ApiRpcRequest<zproto::ClientOnlineReq>>();
//    (*req)->set_server_id(1);
//    (*req)->set_conn_id(h->GetConnID());
//    (*req)->set_app_id(1);
//    (*req)->set_user_id(1);
//    (*req)->set_state(1);
//    req->method_id = 1;
//    
//    ZRpcUtil::DoClientCall("online_client", req).then([](ProtoRpcResponsePtr rsp) {
//      if (rsp) {
//        LOG(INFO) << rsp->ToString();
//      }
//    });
//  }
  return 0;
}

int RouterHandler::OnDataReceived(nebula::ZProtoPipeline* pipeline, std::shared_ptr<PackageMessage> message_data) {
  LOG(INFO) << "OnDataReceived - recv data";

  // TODO(@benqi):
  auto h = pipeline->getHandler<ZProtoHandler>();
  DCHECK(h);

  // 1. 客户端RpcRequest
  // 2. 服务端来的RpcOk/RpcError/RpcFloodWait/RpcInternalError
  // 3. Push
  ////////////////////////////////////////////////////////////////////////////////////////////////
  // 1. 拦截IMLoginRes
  switch (message_data->GetPackageType()) {
    case Package::RPC_OK:
    // case Package::RPC_ERROR:
    // case Package::RPC_FLOOD_WAIT:
    // case Package::RPC_INTERNAL_ERROR:
    // case Package::PUSH:
      {
        auto response = std::static_pointer_cast<EncodedRpcOk>(message_data);
        if (response->GetMethodResponseID() == zproto::USER_NAME_PASSWORD_AUTH_RSP) {
          auto rpc_ok = ToApiRpcOk<zproto::UserNamePasswordAuthRsp>(response);
          
          // TODO(@benqi): 移到用户认证成功后通知
          // 3. 上线通知在线状态服务器
          auto req = std::make_shared<ApiRpcRequest<zproto::ClientOnlineReq>>();
          (*req)->set_server_id(1);
          (*req)->set_conn_id(h->GetConnID());
          (*req)->set_app_id((*rpc_ok)->app_id());
          (*req)->set_user_id((*rpc_ok)->user_id());
          (*req)->set_state(1);
          ZRpcUtil::DoClientCall("online_client", req).then([](ProtoRpcResponsePtr rsp) {
            if (rsp) {
              LOG(INFO) << rsp->ToString();
            }
          });
          
          // 发布状态
          // 订阅状态
          // ......
        }
      }
      break;
    case Package::MESSAGE_ACK:
      break;
      
    default:
      LOG(ERROR) << "";
      break;
  }

  // 2. 返回给客户端

  //  if (message_data->GetPackageType() == Package::RPC_REQUEST) {
  //
  //  } else {
  //
  //  }
  
  // 2
  return 0;
}

int RouterHandler::OnConnectionClosed(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline) {
  LOG(INFO) << "OnDataReceived - conn closed";
  
  return 0;
}
#endif
