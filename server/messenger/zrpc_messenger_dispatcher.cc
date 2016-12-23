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

#include "messenger/zrpc_messenger_dispatcher.h"

#include "nebula/net/rpc/zrpc_service_util.h"

#include "messenger/messaging_service_impl.h"
#include "messenger/groups_service_impl.h"
#include "messenger/privacy_service_impl.h"
#include "messenger/sequence_service_impl.h"
#include "messenger/weak_service_impl.h"

static ZRpcMessengerDispatcher g_messenger_push_dispatcher;

ZRpcMessengerDispatcher::ZRpcMessengerDispatcher() {
  ZRpcUtil::Register("zproto.SendMessageReq", SendMessage);
  /*
  ZRpcUtil::Register("zproto.MessageSyncReq", MessageSync);
  ZRpcUtil::Register("zproto.LoadHistoryMessageReq", LoadHistoryMessage);
  ZRpcUtil::Register("zproto.LoadDialogsReq", LoadDialogs);
  ZRpcUtil::Register("zproto.CreateGroupReq", CreateGroup);
   */
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::SendMessage(RpcRequestPtr request) {
  CAST_RPC_REQUEST(SendMessageReq, send_message_req);
  LOG(INFO) << send_message_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  MessagingServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.SendMessage(send_message_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

/*
ProtoRpcResponsePtr ZRpcMessengerDispatcher::MessageSync(RpcRequestPtr request) {
  CAST_RPC_REQUEST(MessageSyncReq, message_sync_req);
  LOG(INFO) << "DoMessageSync - message_sync_req: " << message_sync_req.Utf8DebugString();
  
  zproto::MessageSyncRsp message_sync_rsp;
  
  MessengerServiceImpl service_impl;
  service_impl.MessageSync(message_sync_req, &message_sync_rsp);
  
  return MakeRpcOK(message_sync_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::LoadHistoryMessage(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LoadHistoryMessageReq, load_history_message_req);
  LOG(INFO) << "DoLoadHistoryMessage - load_history_message_req: " << load_history_message_req.Utf8DebugString();
  
  zproto::LoadHistoryMessageRsp load_history_message_rsp;
  
  MessengerServiceImpl service_impl;
  service_impl.LoadHistoryMessage(load_history_message_req, &load_history_message_rsp);
  
  return MakeRpcOK(load_history_message_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::LoadDialogs(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LoadDialogsReq, load_dialogs_req);
  LOG(INFO) << "DoLoadDialogs - load_dialogs_req: " << load_dialogs_req.Utf8DebugString();
  
  zproto::LoadDialogsRsp load_dialogs_rsp;

  MessengerServiceImpl service_impl;
  service_impl.LoadDialogs(load_dialogs_req, &load_dialogs_rsp);
  
  return MakeRpcOK(load_dialogs_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::CreateGroup(RpcRequestPtr request) {
  CAST_RPC_REQUEST(CreateGroupReq, create_group_req);
  LOG(INFO) << "DoCreateGroup - create_group_req: " << create_group_req.Utf8DebugString();

  zproto::CreateGroupRsp create_group_rsp;
  
  MessengerServiceImpl service_impl;
  service_impl.CreateGroup(create_group_req, &create_group_rsp);
  
  return MakeRpcOK(create_group_rsp);
}
*/
