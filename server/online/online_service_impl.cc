/*
 *  Copyright (c) 2016, https://github.com/nebula-im
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

#include "online/online_service_impl.h"

#include "online/online_session_manager.h"
//#include "proto/zproto/zproto_api_message_types.h"

int OnlineServiceImpl::ClientOnline(const zproto::ClientOnlineReq& request, zproto::ClientOnlineRsp* response) {
  auto online_manager = OnlineSessionManager::GetInstance();
  online_manager->AddEntry(static_cast<uint16_t>(request.server_id()),
                           request.conn_id(),
                           request.app_id(),
                           request.user_id(),
                           static_cast<uint16_t>(request.state()));
  response->set_index_id(1234);
  
  return 0;
}

int OnlineServiceImpl::ClientOffline(const zproto::ClientOfflineReq& request, zproto::ClientOfflineRsp* response) {
  auto online_manager = OnlineSessionManager::GetInstance();
  online_manager->RemoveEntryBySessionID(static_cast<uint16_t>(request.server_id()),
                                         request.conn_id());
  
  response->set_index_id(1234);
  
  return 0;
}

int OnlineServiceImpl::QueryOnlineUser(const zproto::QueryOnlineUserReq& request, zproto::QueryOnlineUserRsp* response) {
  auto online_manager = OnlineSessionManager::GetInstance();
  
  std::list<std::string> app_user_id_list;
  SessionEntryList sessions;
  
  for (int i=0; i<request.user_id_list_size(); ++i) {
    std::string app_user_id = request.user_id_list(i).user_id() + "@" + folly::to<std::string>(request.user_id_list(i).app_id());
    app_user_id_list.push_back(app_user_id);
  }
  
  online_manager->LookupEntrysByUserIDList(app_user_id_list, &sessions);
  
  for (auto& v : sessions) {
    auto online_user = response->add_online_users();
    online_user->set_app_id(v.app_id);
    online_user->set_user_id(v.user_id);
    online_user->set_server_id(v.server_id);
    online_user->set_conn_id(v.session_id);
  }
  
  return 0;
}
