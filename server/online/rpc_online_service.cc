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

#include "online/rpc_online_service.h"

#include "proto/zproto/zproto_api_message_types.h"

#include "online/online_session_manager.h"

ProtoRpcResponsePtr DoClientOnlineReq(RpcRequestPtr request) {
  CAST_RPC_REQUEST(ClientOnlineReq, client_online_req);
  LOG(INFO) << client_online_req.Utf8DebugString();

  auto online_manager = OnlineSessionManager::GetInstance();
  online_manager->AddEntry(static_cast<uint16_t>(client_online_req.server_id()),
                           client_online_req.conn_id(),
                           client_online_req.app_id(),
                           client_online_req.user_id(),
                           static_cast<uint16_t>(client_online_req.state()));
  
  zproto::ClientOnlineRsp client_online_rsp;
  client_online_rsp.set_index_id(1234);
  
  return MakeRpcOK(client_online_rsp);
}

ProtoRpcResponsePtr DoClientOfflineReq(RpcRequestPtr request) {
  CAST_RPC_REQUEST(ClientOfflineReq, client_offline_req);
  LOG(INFO) << client_offline_req.Utf8DebugString();
 
  auto online_manager = OnlineSessionManager::GetInstance();
  online_manager->RemoveEntryBySessionID(static_cast<uint16_t>(client_offline_req.server_id()),
                                         client_offline_req.conn_id());
  
  zproto::ClientOfflineRsp client_offline_rsp;
  client_offline_rsp.set_index_id(1234);

  return MakeRpcOK(client_offline_rsp);
}

ProtoRpcResponsePtr DoQueryOnlineUserReq(RpcRequestPtr request) {
  CAST_RPC_REQUEST(QueryOnlineUserReq, query_online_user_req);
  LOG(INFO) << query_online_user_req.Utf8DebugString();

  auto online_manager = OnlineSessionManager::GetInstance();
  
  std::list<std::string> app_user_id_list;
  SessionEntryList sessions;
  
  for (int i=0; i<query_online_user_req.user_id_list_size(); ++i) {
    std::string app_user_id = query_online_user_req.user_id_list(i).user_id() + "@" + folly::to<std::string>(query_online_user_req.user_id_list(i).app_id());
    app_user_id_list.push_back(app_user_id);
  }
  
  online_manager->LookupEntrysByUserIDList(app_user_id_list, &sessions);
  
  zproto::QueryOnlineUserRsp query_online_user_rsp;
  for (auto& v : sessions) {
    auto online_user = query_online_user_rsp.add_online_users();
    online_user->set_app_id(v.app_id);
    online_user->set_user_id(v.user_id);
    online_user->set_server_id(v.server_id);
    online_user->set_conn_id(v.session_id);
  }
  
  return MakeRpcOK(query_online_user_rsp);
}


