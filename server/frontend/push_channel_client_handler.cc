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

#include "gate/push_channel_client_handler.h"

#include "proto/api/cc/auth.pb.h"
#include "proto/s2s/cc/presences.pb.h"
#include "proto/s2s/cc/servers.pb.h"
#include "nebula/net/zproto/api_message_box.h"
#include "nebula/base/id_util.h"

#include "base/message_handler_util.h"
#include "gate/gate_server_util.h"

int PushChannelClientHandler::OnNewConnection() {
  state_ = State::CONNECTED;
  server_auth_message_id_ = GetNextIDBySnowflake();

  auto server_auth_req = std::make_shared<ApiRpcRequest<zproto::ServerAuthReq>>();
  (*server_auth_req)->set_server_id(GetServerID());
  (*server_auth_req)->set_server_name("gate_server");

  // TODO(@benqi): 设置S2SMessageData数据
  server_auth_req->set_message_id(server_auth_message_id_);

  std::unique_ptr<folly::IOBuf> data;
  server_auth_req->SerializeToIOBuf(data);
  pipeline_->write(std::move(data));


  // TODO(@benqi):
  // 如果一段时间内未收到ServerAuthRsp，则断开重连
  return 0;
}

int PushChannelClientHandler::OnDataReceived(std::shared_ptr<PackageMessage> message_data) {
  if (state_ == State::WORKING) {
    // 转发客户端
    WritePackage(message_data->birth_conn_id(), message_data);
  } else if (state_ == State::CONNECTED) {
    // 能且只能收到ServerAuthRsp

    auto encoded = std::static_pointer_cast<ProtoRpcResponse>(message_data);

    // 检查message_id
    if (encoded->req_message_id != server_auth_message_id_) {
      LOG(ERROR) << "OnDataReceived - recv invalid packaet, server_auth_message_id_: " << server_auth_message_id_
                  << ", message_data: " << message_data->ToString();

      // TODO(@benqi): 主动关闭，还是在下个循环里关闭？
      pipeline_->close();
      return -1;
    }
    state_ = State::WORKING;
    server_auth_message_id_ = 0;
  } else {
    LOG(ERROR) << "OnDataReceived - Invalid state: " << static_cast<int>(state_)
                << ", message_data: " << message_data->ToString();

    // TODO(@benqi): 主动关闭，还是在下个循环里关闭？
    pipeline_->close();
    return -1;
  }
  return 0;
}

int PushChannelClientHandler::OnConnectionClosed() {
  return 0;
}
