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

#include "proto/api/cc/messaging.pb.h"
#include "dal/online_status_dao.h"
#include "push/gate_channel_manager.h"

// 转发
inline folly::Future<folly::Unit> WritePackage(uint64_t conn_id, std::shared_ptr<PackageMessage> message_data) {
  std::unique_ptr<folly::IOBuf> data;
  message_data->SerializeToIOBuf(data);
  return WriterUtil::Write(conn_id, std::move(data));
}

int PushServiceImpl::DeliveryDataToUsers(const zproto::DeliveryDataToUsersReq& request, zproto::VoidRsp* response) {
  // const auto& message_data = request.message_data();
  std::list<std::string> user_id_list;
  
  for (int i=0; i<request.uid_list_size(); ++i) {
    user_id_list.push_back(request.uid_list(i));
  }
  
  OnlineStatusDOList onlines;
  zproto::MessageNotify message_notify;
  message_notify.ParseFromString(request.raw_data());
  OnlineStatusDAO::GetInstance().GetUsersOnlineStatus(1, user_id_list, onlines, request.my_conn_id());
  for (const auto& v : onlines) {
    auto gate_conn_id = GateChannelManager::GetInstance()->LookupConnID(v.server_id);
    if (gate_conn_id == 0 || request.my_conn_id() == v.conn_id) {
      continue;
    }
    
    auto push = MakePush(message_notify);
    // std::make_shared<ApiPush<zproto::MessageNotify>>();
    push->set_session_id(v.conn_id);
    push->set_birth_conn_id(v.conn_id);
    WritePackage(gate_conn_id, push);
  }

  return 0;
}
