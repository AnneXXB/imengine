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

// TODO(@benqi): 使用zrpc-code-gen代码生成工具自动生成服务框架代码

#include "push/push_service_impl.h"

#include "nebula/net/handler/nebula_handler_util.h"

// #include "proto/zproto/zproto_api_message_types.h"
#include "dal/online_status_dao.h"
#include "push/gate_channel_manager.h"

/*
// 转发
inline folly::Future<folly::Unit> WritePackage(uint64_t conn_id, std::shared_ptr<PackageMessage> message_data) {
  std::unique_ptr<folly::IOBuf> data;
  message_data->SerializeToIOBuf(data);
  return WriterUtil::Write(conn_id, std::move(data));
}

int PushServiceImpl::ForwardMessage(const zproto::ForwardMessageReq& request, zproto::VoidRsp* response) {
  const auto& message_data = request.message_data();
  // const auto& not_send_conn_ids = (*forward_message_req)->not_send_conn_ids();
  
  std::list<std::string> user_id_list;
  user_id_list.push_back(message_data.sender_user_id());
  user_id_list.push_back(message_data.peer().id());
  
  OnlineStatusDOList onlines;
  zproto::MessageNotify message_notify;
  OnlineStatusDAO::GetInstance().GetUsersOnlineStatus(1, user_id_list, onlines, request.my_conn_id());
  for (const auto& v : onlines) {
    auto gate_conn_id = GateChannelManager::GetInstance()->LookupConnID(v.server_id);
    if (gate_conn_id == 0) {
      continue;
    }
    bool not_send = false;
    for (int i=0; i<request.not_send_conn_ids_size(); ++i) {
      if (request.not_send_conn_ids(i) == gate_conn_id) {
        not_send = true;
        break;
      }
    }
    if (not_send ) {
      continue;
    }
    
    auto push = MakePush(message_notify);
    // std::make_shared<ApiPush<zproto::MessageNotify>>();
    push->set_session_id(v.conn_id);
    WritePackage(gate_conn_id, push);
  }

  return 0;
}
*/
