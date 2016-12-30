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

// TODO(@benqi): 使用zrpc-code-gen代码生成工具自动生成

#include "online/zrpc_online_dispatcher.h"

#include "nebula/net/rpc/zrpc_service_util.h"

#include "online/online_service_impl.h"

static ZRpcOnlineDispatcher g_rpc_online_dispatcher;

ZRpcOnlineDispatcher::ZRpcOnlineDispatcher() {
  ZRpcUtil::Register("zproto.ClientOnlineReq", ZRpcOnlineDispatcher::ClientOnline);
  ZRpcUtil::Register("zproto.ClientOfflineReq", ZRpcOnlineDispatcher::ClientOffline);
  ZRpcUtil::Register("zproto.QueryOnlineUserReq", ZRpcOnlineDispatcher::QueryOnlineUser);
}

ProtoRpcResponsePtr ZRpcOnlineDispatcher::ClientOnline(RpcRequestPtr request) {
  CAST_RPC_REQUEST(ClientOnlineReq, client_online_req);
  LOG(INFO) << client_online_req.Utf8DebugString();
  
  zproto::ClientOnlineRsp client_online_rsp;

  OnlineServiceImpl service_impl;
  service_impl.ClientOnline(client_online_req, &client_online_rsp);

  return MakeRpcOK(client_online_rsp);
}

ProtoRpcResponsePtr ZRpcOnlineDispatcher::ClientOffline(RpcRequestPtr request) {
  CAST_RPC_REQUEST(ClientOfflineReq, client_offline_req);
  LOG(INFO) << client_offline_req.Utf8DebugString();
  
  zproto::ClientOfflineRsp client_offline_rsp;

  OnlineServiceImpl service_impl;
  service_impl.ClientOffline(client_offline_req, &client_offline_rsp);

  return MakeRpcOK(client_offline_rsp);
}

ProtoRpcResponsePtr ZRpcOnlineDispatcher::QueryOnlineUser(RpcRequestPtr request) {
  CAST_RPC_REQUEST(QueryOnlineUserReq, query_online_user_req);
  LOG(INFO) << query_online_user_req.Utf8DebugString();
  
  zproto::QueryOnlineUserRsp query_online_user_rsp;

  OnlineServiceImpl service_impl;
  service_impl.QueryOnlineUser(query_online_user_req, &query_online_user_rsp);

  return MakeRpcOK(query_online_user_rsp);
}

