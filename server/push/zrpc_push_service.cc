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

#include "push/zrpc_push_service.h"

#include "nebula/net/handler/nebula_handler_util.h"

#include "proto/api_message_box.h"
#include "biz_model/online_status_model.h"
#include "push/gate_channel_manager.h"

// 转发
inline folly::Future<folly::Unit> WritePackage(uint64_t conn_id, std::shared_ptr<PackageMessage> message_data) {
  std::unique_ptr<folly::IOBuf> data;
  message_data->SerializeToIOBuf(data);
  return WriterUtil::Write(conn_id, std::move(data));
}

ProtoRpcResponsePtr DoForwardMessage(RpcRequestPtr request) {
  // 1.
  auto forward_message_req = ToApiRpcRequest<zproto::ForwardMessageReq>(request);
  const auto& message_data = (*forward_message_req)->message_data();
  // const auto& not_send_conn_ids = (*forward_message_req)->not_send_conn_ids();
  
  std::list<std::string> user_id_list;
  user_id_list.push_back(message_data.sender_user_id());
  user_id_list.push_back(message_data.peer().id());
  
  std::list<OnlineUserInfo> onlines;
  GetUsersOnlineStatus(1, user_id_list, onlines, request->session_id());
  for (const auto& v : onlines) {
    auto gate_conn_id = GateChannelManager::GetInstance()->LookupConnID(v.server_id);
    if (gate_conn_id == 0) {
      continue;
    }
    bool not_send = false;
    for (int i=0; i<(*forward_message_req)->not_send_conn_ids_size(); ++i) {
      if ((*forward_message_req)->not_send_conn_ids(i) == gate_conn_id) {
        not_send = true;
        break;
      }
    }
    if (not_send ) {
      continue;
    }
    
    auto push = std::make_shared<ApiPush<zproto::MessageNotify>>();
    push->set_session_id(v.conn_id);
    WritePackage(gate_conn_id, push);
  }

  auto response = std::make_shared<ApiRpcOk<zproto::VoidRsp>>();
  response->set_session_id(request->session_id());
  response->set_req_message_id(request->message_id());
  return response;
}
