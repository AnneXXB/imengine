/*
 *  Copyright (c) 2016, https://github.com/nebula-im/imengine
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

#include "gate/gate_server_handler.h"

#include "nebula/base/id_util.h"
#include "nebula/base/time_util.h"
#include "nebula/net/rpc/zrpc_service_util.h"

#include "base/message_handler_util.h"
#include "gate/gate_server_util.h"

int GateServerHandler::OnNewConnection() {
  state_ = State::CONNECTED;
  // TODO(@benqi):
  // 启动定时器，一段时间内如果没有收到任何消息，
  // 则认为可能是攻击数据包，关闭连接并记录审计日志IP
  return 0;
}

int GateServerHandler::OnDataReceived(std::shared_ptr<PackageMessage> message_data) {
  // TODO(@benqi): 后续处理如果比较复杂，可以使用状态机模式

  LOG(INFO) << "OnDataReceived - recv message_data: " << message_data->ToString();
  
  if (message_data->GetPackageType() != Package::RPC_REQUEST) {
    // 收到的数据包必须是RPC_REQUEST
    LOG(ERROR) << "OnDataReceived - recv invalid message_data: " << message_data->ToString();
    // TODO(@benqi): 断开连接
    // 一般是攻击包或客户端bug，直接关闭连接并记录审计日志IP
    Close(0);
    return -1;
  }

  if (state_ == State::CONNECTED) {
    OnGateClientAuthReq(message_data);
  } else if (state_ == State::AUTH) {
    // TODO(@benqi): 还在验证，收到的数据包都为非法包，直接断开
    // conn_data->state = ClientConnContext::State::ERROR;
  } else if (state_ == State::WORKING) {
    auto encoded = std::static_pointer_cast<EncodedRpcRequest>(message_data);
    if (encoded->GetMethodID() == CRC32("zproto.StartTestingAuthReq")) {
      LOG(ERROR) << "OnDataReceived － StartTestingAuthReq recved: " << encoded->ToString();
      Close(0);
      return 0;
    }

    // 转发到message_server
    message_data->set_session_id(conn_id_);
    message_data->set_birth_conn_id(conn_id_);
    message_data->set_birth_server_id(GetServerID());
    message_data->set_birth_track_uuid(GetNextIDBySnowflake());
    message_data->set_birth_timetick(NowInMsecTime());
    message_data->set_birth_remote_ip("127.0.0.1");
    message_data->set_birth_from("gate_server");
    message_data->push_back_option(app_id_);
    message_data->push_back_option(user_id_);

    WritePackage("messenger_client", message_data);
  }
  return 0;
}

int GateServerHandler::OnConnectionClosed() {
  if (state_ >= State::AUTH) {
    NotifyClientOffline();
  }
  
  state_ = State::CLOSING;
  return 0;
}

void GateServerHandler::Close(int reason) {
  pipeline_->close();
}

void GateServerHandler::NotifyClientOnline() {
  auto client_online_req = std::make_shared<ApiRpcRequest<zproto::ClientOnlineReq>>();
  
  (*client_online_req)->set_server_id(GetServerID());
  (*client_online_req)->set_conn_id(conn_id_);
  (*client_online_req)->set_app_id(app_id_);
  // (*req)->set_user_id(folly::to<uint32_t>((*login_rsp)->user_id()));
  (*client_online_req)->set_user_id(user_id_);
  //folly::to<uint32_t>((*login_rsp)->user_id()));
  (*client_online_req)->set_state(1);

  auto uuid = GetNextIDBySnowflake();
  client_online_req->set_session_id(conn_id_);
  client_online_req->set_birth_conn_id(conn_id_);
  client_online_req->set_birth_server_id(GetServerID());
  client_online_req->set_birth_track_uuid(uuid);
  client_online_req->set_birth_timetick(NowInMsecTime());
  client_online_req->set_birth_remote_ip(pipeline_->getHandler<ZProtoHandler>()->GetRemoteAddress());
  client_online_req->set_birth_from("gate_server");

  client_online_req->set_message_id(uuid);
  
  WritePackage("online_status_client", client_online_req);
}

void GateServerHandler::NotifyClientOffline() {
  auto client_offline_req = std::make_shared<ApiRpcRequest<zproto::ClientOfflineReq>>();
  
  (*client_offline_req)->set_server_id(GetServerID());
  (*client_offline_req)->set_conn_id(conn_id_);
  
  auto uuid = GetNextIDBySnowflake();
  client_offline_req->set_session_id(conn_id_);
  client_offline_req->set_birth_conn_id(conn_id_);
  client_offline_req->set_birth_server_id(GetServerID());
  client_offline_req->set_birth_track_uuid(GetNextIDBySnowflake());
  client_offline_req->set_birth_timetick(NowInMsecTime());
  client_offline_req->set_birth_remote_ip(pipeline_->getHandler<ZProtoHandler>()->GetRemoteAddress());
  client_offline_req->set_birth_from("gate_server");

  client_offline_req->set_message_id(uuid);

  WritePackage("online_status_client", client_offline_req);
}

int GateServerHandler::OnGateClientAuthReq(std::shared_ptr<PackageMessage> message_data) {
  // 第一个包必须是zproto::UserTokenAuthReq
  // TODO(@benqi): 这里先使用测试验证包：StartTestingAuthReq
  auto encoded = std::static_pointer_cast<EncodedRpcRequest>(message_data);
  if (encoded->GetMethodID() != CRC32("zproto.StartTestingAuthReq")) {
    LOG(ERROR) << "OnDataReceived － Will recv StartTestingAuthReq, method_id: " << CRC32("zproto.StartTestingAuthReq")
                << ", but recv a invalid method_id: " << encoded->ToString();
    Close(0);
    return 0;
  }
  
  // TODO(@benqi): S2SAttachData其它数据设置
  encoded->set_session_id(conn_id_);
  encoded->set_birth_conn_id(conn_id_);
  encoded->set_birth_server_id(GetServerID());
  encoded->set_birth_track_uuid(GetNextIDBySnowflake());
  encoded->set_birth_timetick(NowInMsecTime());
  encoded->set_birth_remote_ip(pipeline_->getHandler<ZProtoHandler>()->GetRemoteAddress());
  encoded->set_birth_from("gate_server");
  
  // TODO(@benqi): 借鉴RPC
  WritePackage("auth_client", encoded);
  
  // TODO(@benqi): 准备验证
  state_ = State::AUTH;
  
  return 0;
}

int GateServerHandler::OnAuthServerAuthRsp(ProtoRpcResponsePtr response) {
  if (state_ != State::AUTH) {
    LOG(ERROR) << "OnAuthServerAuthRsp - Invalid state: " << static_cast<int>(state_)
                  << ", message_data: " << response->ToString();
    
    return -1;
  }
  
  // 转发给客户端
  WriteToClientPackage(pipeline_, response);

  if (response->GetPackageType() == Package::RPC_OK) {
    auto auth_rsp = ToApiRpcOk<zproto::AuthRsp>(response);
    DCHECK(auth_rsp);
    state_ = State::WORKING;
    
    app_id_ = 1;
    user_id_ = (*auth_rsp)->user().uid();
    // nick_ = (*auth_rsp)->user().nick();

    NotifyClientOnline();
  } else {
    // WritePackage(pipeline_, response);
  }
  return 0;
}
