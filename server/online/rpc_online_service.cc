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

#include "proto/api_message_box.h"

#include "online/online_session_manager.h"

ProtoRpcResponsePtr DoClientOnline(RpcRequestPtr request) {
  auto req = ToApiRpcRequest<zproto::ClientOnlineReq>(request);
  LOG(INFO) << (*req)->Utf8DebugString();

  auto online_manager = OnlineSessionManager::GetInstance();
  online_manager->AddEntry(static_cast<uint16_t>((*req)->server_id()),
                           (*req)->conn_id(),
                           (*req)->app_id(),
                           (*req)->user_id(),
                           static_cast<uint16_t>((*req)->state()));
  
  auto rsp = std::make_shared<ApiRpcOk<zproto::ClientOnlineRsp>>();
  rsp->set_req_message_id(request->message_id());
  (*rsp)->set_index_id(1234);
  
  return rsp;
}

ProtoRpcResponsePtr DoClientOffline(RpcRequestPtr request) {
  auto req = ToApiRpcRequest<zproto::ClientOfflineReq>(request);
  LOG(INFO) << (*req)->Utf8DebugString();
 
  auto online_manager = OnlineSessionManager::GetInstance();
  online_manager->RemoveEntryBySessionID(static_cast<uint16_t>((*req)->server_id()),
                                         (*req)->conn_id());
  
  auto rsp = std::make_shared<ApiRpcOk<zproto::ClientOfflineRsp>>();
  rsp->set_req_message_id(request->message_id());
  (*rsp)->set_index_id(1234);

  return rsp;
}

