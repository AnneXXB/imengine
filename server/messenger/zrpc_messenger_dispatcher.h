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

#ifndef	MESSENGER_ZRPC_MESSENGER_DISPATCHER_H_
#define	MESSENGER_ZRPC_MESSENGER_DISPATCHER_H_

#include "nebula/net/zproto/zproto_package_data.h"

class ZRpcMessengerDispatcher {
public:
  ZRpcMessengerDispatcher();
  ~ZRpcMessengerDispatcher() = default;

  ////////////////////////////////////////////////////////////////////////////////////////////////
  // dialog
  static ProtoRpcResponsePtr CreateChatDialog(RpcRequestPtr request);
  static ProtoRpcResponsePtr LoadDialogs(RpcRequestPtr request);
  static ProtoRpcResponsePtr BlockPeer(RpcRequestPtr request);
  static ProtoRpcResponsePtr UnBlockPeer(RpcRequestPtr request);
  static ProtoRpcResponsePtr TopPeer(RpcRequestPtr request);
  static ProtoRpcResponsePtr UnTopPeer(RpcRequestPtr request);
  static ProtoRpcResponsePtr DndPeer(RpcRequestPtr request);
  static ProtoRpcResponsePtr UnDndPeer(RpcRequestPtr request);
  
  // message
  static ProtoRpcResponsePtr SendMessage(RpcRequestPtr request);
  static ProtoRpcResponsePtr MessageReceived(RpcRequestPtr request);
  static ProtoRpcResponsePtr MessageRead(RpcRequestPtr request);
  static ProtoRpcResponsePtr DeleteMessage(RpcRequestPtr request);
  static ProtoRpcResponsePtr ClearChat(RpcRequestPtr request);
  static ProtoRpcResponsePtr DeleteChat(RpcRequestPtr request);
  static ProtoRpcResponsePtr LoadHistory(RpcRequestPtr request);

  // group
  static ProtoRpcResponsePtr LoadFullGroups(RpcRequestPtr request);
  static ProtoRpcResponsePtr LoadMembers(RpcRequestPtr request);
  static ProtoRpcResponsePtr CreateGroup(RpcRequestPtr request);
  static ProtoRpcResponsePtr EditGroupTitle(RpcRequestPtr request);
  static ProtoRpcResponsePtr EditGroupAvatar(RpcRequestPtr request);
  static ProtoRpcResponsePtr RemoveGroupAvatar(RpcRequestPtr request);
  static ProtoRpcResponsePtr EditGroupShortName(RpcRequestPtr request);
  static ProtoRpcResponsePtr EditGroupTopic(RpcRequestPtr request);
  static ProtoRpcResponsePtr EditGroupAbout(RpcRequestPtr request);
  static ProtoRpcResponsePtr InviteUser(RpcRequestPtr request);
  static ProtoRpcResponsePtr LeaveGroup(RpcRequestPtr request);
  static ProtoRpcResponsePtr LeaveAndDelete(RpcRequestPtr request);
  static ProtoRpcResponsePtr KickUser(RpcRequestPtr request);
  static ProtoRpcResponsePtr JoinGroupByPeer(RpcRequestPtr request);
  static ProtoRpcResponsePtr MakeUserAdmin(RpcRequestPtr request);
  static ProtoRpcResponsePtr DismissUserAdmin(RpcRequestPtr request);
  static ProtoRpcResponsePtr TransferOwnership(RpcRequestPtr request);
  static ProtoRpcResponsePtr LoadAdminSettings(RpcRequestPtr request);
  static ProtoRpcResponsePtr SaveAdminSettings(RpcRequestPtr request);
  static ProtoRpcResponsePtr DeleteGroup(RpcRequestPtr request);
  static ProtoRpcResponsePtr JoinGroup(RpcRequestPtr request);
  
};

#endif // MESSENGER_ZRPC_MESSENGER_DISPATCHER_H_
