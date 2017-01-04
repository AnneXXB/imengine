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

#include "messenger/dialog_service_impl.h"
#include "messenger/messaging_service_impl.h"
#include "messenger/groups_service_impl.h"
#include "messenger/privacy_service_impl.h"
#include "messenger/sequence_service_impl.h"
#include "messenger/weak_service_impl.h"

static ZRpcMessengerDispatcher g_messenger_push_dispatcher;

ZRpcMessengerDispatcher::ZRpcMessengerDispatcher() {
  // dialog
  ZRpcUtil::Register("zproto.CreateChatDialogReq", CreateChatDialog);
  ZRpcUtil::Register("zproto.LoadDialogsReq", LoadDialogs);
  ZRpcUtil::Register("zproto.BlockPeerReq", BlockPeer);
  ZRpcUtil::Register("zproto.UnblockPeerReq", UnblockPeer);
  ZRpcUtil::Register("zproto.TopPeerReq", TopPeer);
  ZRpcUtil::Register("zproto.UntopPeerReq", UntopPeer);
  ZRpcUtil::Register("zproto.DndPeerReq", DndPeer);
  ZRpcUtil::Register("zproto.UndndPeerReq", UndndPeer);
  
  // message
  ZRpcUtil::Register("zproto.SendMessageReq", SendMessage);
  ZRpcUtil::Register("zproto.MessageReceivedReq", MessageReceived);
  ZRpcUtil::Register("zproto.MessageReadReq", MessageRead);
  ZRpcUtil::Register("zproto.DeleteMessageReq", DeleteMessage);
  ZRpcUtil::Register("zproto.ClearChatReq", ClearChat);
  ZRpcUtil::Register("zproto.DeleteChatReq", DeleteChat);

  ZRpcUtil::Register("zproto.LoadHistoryReq", LoadHistory);

  // group
  ZRpcUtil::Register("zproto.LoadFullGroupsReq", LoadFullGroups);
  ZRpcUtil::Register("zproto.LoadMembersReq", LoadMembers);
  ZRpcUtil::Register("zproto.CreateGroupReq", CreateGroup);
  ZRpcUtil::Register("zproto.EditGroupTitleReq", EditGroupTitle);
  ZRpcUtil::Register("zproto.EditGroupAvatarReq", EditGroupAvatar);
  ZRpcUtil::Register("zproto.RemoveGroupAvatarReq", RemoveGroupAvatar);
  ZRpcUtil::Register("zproto.EditGroupShortNameReq", EditGroupShortName);
  ZRpcUtil::Register("zproto.EditGroupTopicReq", EditGroupTopic);
  ZRpcUtil::Register("zproto.EditGroupAboutReq", EditGroupAbout);
  ZRpcUtil::Register("zproto.InviteUserReq", InviteUser);
  ZRpcUtil::Register("zproto.LeaveGroupReq", LeaveGroup);
  ZRpcUtil::Register("zproto.LeaveAndDeleteReq", LeaveAndDelete);
  ZRpcUtil::Register("zproto.KickUserReq", KickUser);
  ZRpcUtil::Register("zproto.JoinGroupByPeerReq", JoinGroupByPeer);
  ZRpcUtil::Register("zproto.MakeUserAdminReq", MakeUserAdmin);
  ZRpcUtil::Register("zproto.DismissUserAdminReq", DismissUserAdmin);
  ZRpcUtil::Register("zproto.TransferOwnershipReq", TransferOwnership);
  ZRpcUtil::Register("zproto.LoadAdminSettingsReq", LoadAdminSettings);
  ZRpcUtil::Register("zproto.SaveAdminSettingsReq", SaveAdminSettings);
  ZRpcUtil::Register("zproto.DeleteGroupReq", DeleteGroup);
  ZRpcUtil::Register("zproto.JoinGroupReq", JoinGroup);
}

/////////////////////////////////////////////////////////////////////////////////
// dialog
ProtoRpcResponsePtr ZRpcMessengerDispatcher::CreateChatDialog(RpcRequestPtr request) {
  CAST_RPC_REQUEST(CreateChatDialogReq, create_chat_dialog_req);
  LOG(INFO) << "CreateChatDialog - create_chat_dialog_req: " << create_chat_dialog_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::CreateChatDialogRsp create_chat_dialog_rsp;
  
  DialogServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.CreateChatDialog(create_chat_dialog_req, &create_chat_dialog_rsp);
  
  return MakeRpcOK(create_chat_dialog_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::LoadDialogs(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LoadDialogsReq, load_dialogs_req);
  LOG(INFO) << "LoadDialogs - load_dialogs_req: " << load_dialogs_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::LoadDialogsRsp load_dialogs_rsp;
  
  DialogServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.LoadDialogs(load_dialogs_req, &load_dialogs_rsp);
  
  return MakeRpcOK(load_dialogs_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::BlockPeer(RpcRequestPtr request) {
  CAST_RPC_REQUEST(BlockPeerReq, block_peer_req);
  LOG(INFO) << "BlockPeerReq - block_peer_req: " << block_peer_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  DialogServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.BlockPeer(block_peer_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::UnblockPeer(RpcRequestPtr request) {
  CAST_RPC_REQUEST(UnblockPeerReq, unblock_peer_req);
  LOG(INFO) << "UnBlockPeer - unblock_peer_req: " << unblock_peer_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  DialogServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.UnblockPeer(unblock_peer_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::TopPeer(RpcRequestPtr request) {
  CAST_RPC_REQUEST(TopPeerReq, top_peer_req);
  LOG(INFO) << "UnTopPeer - top_peer_req: " << top_peer_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  DialogServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.TopPeer(top_peer_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::UntopPeer(RpcRequestPtr request) {
  CAST_RPC_REQUEST(UntopPeerReq, untop_peer_req);
  LOG(INFO) << "UnTopPeer - untop_peer_req: " << untop_peer_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  DialogServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.UntopPeer(untop_peer_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::DndPeer(RpcRequestPtr request) {
  CAST_RPC_REQUEST(DndPeerReq, dnd_peer_req);
  LOG(INFO) << "DndPeer - dnd_peer_req: " << dnd_peer_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  DialogServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.DndPeer(dnd_peer_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::UndndPeer(RpcRequestPtr request) {
  CAST_RPC_REQUEST(UndndPeerReq, undnd_peer_req);
  LOG(INFO) << "UnDndPeer - load_dialogs_req: " << undnd_peer_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  DialogServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.UndndPeer(undnd_peer_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

/////////////////////////////////////////////////////////////////////////////////
// message
ProtoRpcResponsePtr ZRpcMessengerDispatcher::SendMessage(RpcRequestPtr request) {
  CAST_RPC_REQUEST(SendMessageReq, send_message_req);
  LOG(INFO) << "SendMessage - send_message_req: " << send_message_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  MessagingServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.SendMessage(send_message_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::MessageReceived(RpcRequestPtr request) {
  CAST_RPC_REQUEST(MessageReceivedReq, message_received_req);
  LOG(INFO) << "MessageReceivedReq - message_received_req: " << message_received_req.Utf8DebugString();;
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::VoidRsp void_rsp;
  
  MessagingServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.MessageReceived(message_received_req, &void_rsp);
  
  return MakeRpcOK(void_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::MessageRead(RpcRequestPtr request) {
  CAST_RPC_REQUEST(MessageReadReq, message_read_req);
  LOG(INFO) << "MessageReadReq - message_read_req: " << message_read_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::VoidRsp void_rsp;
  
  MessagingServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.MessageRead(message_read_req, &void_rsp);
  
  return MakeRpcOK(void_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::DeleteMessage(RpcRequestPtr request) {
  CAST_RPC_REQUEST(DeleteMessageReq, delete_message_req);
  LOG(INFO) << "DeleteMessage - delete_message_req: " << delete_message_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  MessagingServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.DeleteMessage(delete_message_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::ClearChat(RpcRequestPtr request) {
  CAST_RPC_REQUEST(ClearChatReq, clear_chat_req);
  LOG(INFO) << "ClearChat - clear_chat_req: " << clear_chat_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  MessagingServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.ClearChat(clear_chat_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::DeleteChat(RpcRequestPtr request) {
  CAST_RPC_REQUEST(DeleteChatReq, delete_chat_req);
  LOG(INFO) << "DeleteChat - delete_chat_req: " << delete_chat_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  MessagingServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.DeleteChat(delete_chat_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

/////////////////////////////////////////////////////////////////////////////////
// dialog
ProtoRpcResponsePtr ZRpcMessengerDispatcher::LoadHistory(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LoadHistoryReq, load_history_req);
  LOG(INFO) << "LoadHistory - load_history_req: " << load_history_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::LoadHistoryRsp load_history_rsp;
  
  MessagingServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.LoadHistory(load_history_req, &load_history_rsp);
  
  return MakeRpcOK(load_history_rsp);
}


/////////////////////////////////////////////////////////////////////////////////
// group
ProtoRpcResponsePtr ZRpcMessengerDispatcher::LoadFullGroups(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LoadFullGroupsReq, load_full_group_req);
  LOG(INFO) << "LoadFullGroups - load_full_group_req: " << load_full_group_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::LoadFullGroupsRsp load_full_group_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.LoadFullGroups(load_full_group_req, &load_full_group_rsp);
  
  return MakeRpcOK(load_full_group_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::LoadMembers(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LoadMembersReq, load_members_req);
  LOG(INFO) << "LoadFullGroups - LoadMembersReq: " << load_members_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::LoadMembersRsp load_members_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.LoadMembers(load_members_req, &load_members_rsp);
  
  return MakeRpcOK(load_members_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::CreateGroup(RpcRequestPtr request) {
  CAST_RPC_REQUEST(CreateGroupReq, create_group_req);
  LOG(INFO) << "CreateGroup - create_group_req: " << create_group_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::CreateGroupRsp create_group_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.CreateGroup(create_group_req, &create_group_rsp);
  
  return MakeRpcOK(create_group_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::EditGroupTitle(RpcRequestPtr request) {
  CAST_RPC_REQUEST(EditGroupTitleReq, edit_group_title_req);
  LOG(INFO) << edit_group_title_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.EditGroupTitle(edit_group_title_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::EditGroupAvatar(RpcRequestPtr request) {
  CAST_RPC_REQUEST(EditGroupAvatarReq, edit_group_avatar_req);
  LOG(INFO) << edit_group_avatar_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::EditGroupAvatarRsp edit_group_avatar_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.EditGroupAvatar(edit_group_avatar_req, &edit_group_avatar_rsp);
  
  return MakeRpcOK(edit_group_avatar_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::RemoveGroupAvatar(RpcRequestPtr request) {
  CAST_RPC_REQUEST(RemoveGroupAvatarReq, remove_group_avatar_req);
  LOG(INFO) << remove_group_avatar_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.RemoveGroupAvatar(remove_group_avatar_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::EditGroupShortName(RpcRequestPtr request) {
  CAST_RPC_REQUEST(EditGroupShortNameReq, edit_group_short_name_req);
  LOG(INFO) << edit_group_short_name_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.EditGroupShortName(edit_group_short_name_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::EditGroupTopic(RpcRequestPtr request) {
  CAST_RPC_REQUEST(EditGroupTopicReq, edit_group_topic_req);
  LOG(INFO) << edit_group_topic_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.EditGroupTopic(edit_group_topic_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::EditGroupAbout(RpcRequestPtr request) {
  CAST_RPC_REQUEST(EditGroupAboutReq, edit_group_about_req);
  LOG(INFO) << edit_group_about_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.EditGroupAbout(edit_group_about_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::InviteUser(RpcRequestPtr request) {
  CAST_RPC_REQUEST(InviteUserReq, invite_user_req);
  LOG(INFO) << invite_user_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.InviteUser(invite_user_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::LeaveGroup(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LeaveGroupReq, leave_group_req);
  LOG(INFO) << leave_group_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.LeaveGroup(leave_group_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::LeaveAndDelete(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LeaveAndDeleteReq, leave_and_delete_req);
  LOG(INFO) << leave_and_delete_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.LeaveAndDelete(leave_and_delete_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::KickUser(RpcRequestPtr request) {
  CAST_RPC_REQUEST(KickUserReq, kick_user_req);
  LOG(INFO) << kick_user_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.KickUser(kick_user_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::JoinGroupByPeer(RpcRequestPtr request) {
  CAST_RPC_REQUEST(JoinGroupByPeerReq, join_group_by_peer_req);
  LOG(INFO) << join_group_by_peer_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqRsp seq_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.JoinGroupByPeer(join_group_by_peer_req, &seq_rsp);
  
  return MakeRpcOK(seq_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::MakeUserAdmin(RpcRequestPtr request) {
  CAST_RPC_REQUEST(MakeUserAdminReq, make_user_admin_req);
  LOG(INFO) << make_user_admin_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.MakeUserAdmin(make_user_admin_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::DismissUserAdmin(RpcRequestPtr request) {
  CAST_RPC_REQUEST(DismissUserAdminReq, dismiss_user_admin_req);
  LOG(INFO) << dismiss_user_admin_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.DismissUserAdmin(dismiss_user_admin_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::TransferOwnership(RpcRequestPtr request) {
  CAST_RPC_REQUEST(TransferOwnershipReq, transfer_owner_ship_req);
  LOG(INFO) << transfer_owner_ship_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.TransferOwnership(transfer_owner_ship_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::LoadAdminSettings(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LoadAdminSettingsReq, load_admin_settings_req);
  LOG(INFO) << load_admin_settings_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.LoadAdminSettings(load_admin_settings_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::SaveAdminSettings(RpcRequestPtr request) {
  CAST_RPC_REQUEST(SaveAdminSettingsReq, save_admin_setting_req);
  LOG(INFO) << save_admin_setting_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.SaveAdminSettings(save_admin_setting_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::DeleteGroup(RpcRequestPtr request) {
  CAST_RPC_REQUEST(DeleteGroupReq, delete_group_req);
  LOG(INFO) << delete_group_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::SeqDateRsp seq_date_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.DeleteGroup(delete_group_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

ProtoRpcResponsePtr ZRpcMessengerDispatcher::JoinGroup(RpcRequestPtr request) {
  CAST_RPC_REQUEST(JoinGroupReq, join_group_req);
  LOG(INFO) << join_group_req.Utf8DebugString();
  
  // TODO(@benqi): 检查是否存在S2SAttachData，保证service能获取attach_data
  zproto::JoinGroupRsp join_group_rsp;
  
  GroupsServiceImpl service_impl;
  service_impl.Initialize(request);
  service_impl.JoinGroup(join_group_req, &join_group_rsp);
  
  return MakeRpcOK(join_group_rsp);
}

