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

#include "messenger/zrpc_groups_service.h"

#include "nebula/base/logger/glog_util.h"

int ZRpcGroupsService::LoadFullGroups(const zproto::LoadFullGroupsReq& request, zproto::LoadFullGroupsRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - LoadFullGroups unimplemented";
  return -1;
}

int ZRpcGroupsService::LoadMembers(const zproto::LoadMembersReq& request, zproto::LoadMembersRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - LoadMembers unimplemented";
  return -1;
}

int ZRpcGroupsService::CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - CreateGroup unimplemented";
  return -1;
}

int ZRpcGroupsService::EditGroupTitle(const zproto::EditGroupTitleReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - EditGroupTitle unimplemented";
  return -1;
}

int ZRpcGroupsService::EditGroupAvatar(const zproto::EditGroupAvatarReq& request, zproto::EditGroupAvatarRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - EditGroupAvatar unimplemented";
  return -1;
}

int ZRpcGroupsService::RemoveGroupAvatar(const zproto::RemoveGroupAvatarReq& request, zproto::SeqDateRsp* response)  {
  LOG(ERROR) << "ZRpcGroupsService - RemoveGroupAvatar unimplemented";
  return -1;
}

int ZRpcGroupsService::EditGroupShortName(const zproto::EditGroupShortNameReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - EditGroupShortName unimplemented";
  return -1;
}

int ZRpcGroupsService::EditGroupTopic(const zproto::EditGroupTopicReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - EditGroupTopic unimplemented";
  return -1;
}

int ZRpcGroupsService::EditGroupAbout(const zproto::EditGroupAboutReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - EditGroupAbout unimplemented";
  return -1;
}

int ZRpcGroupsService::InviteUser(const zproto::InviteUserReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - InviteUser unimplemented";
  return -1;
}

int ZRpcGroupsService::LeaveGroup(const zproto::LeaveGroupReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - LeaveGroup unimplemented";
  return -1;
}

int ZRpcGroupsService::LeaveAndDelete(const zproto::LeaveAndDeleteReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - LeaveAndDelete unimplemented";
  return -1;
}

int ZRpcGroupsService::KickUser(const zproto::KickUserReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - KickUser unimplemented";
  return -1;
}

int ZRpcGroupsService::JoinGroupByPeer(const zproto::JoinGroupByPeerReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - JoinGroupByPeer unimplemented";
  return -1;
}

int ZRpcGroupsService::MakeUserAdmin(const zproto::MakeUserAdminReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - MakeUserAdmin unimplemented";
  return -1;
}

int ZRpcGroupsService::DismissUserAdmin(const zproto::DismissUserAdminReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - DismissUserAdmin unimplemented";
  return -1;
}

int ZRpcGroupsService::TransferOwnership(const zproto::TransferOwnershipReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - TransferOwnership unimplemented";
  return -1;
}

int ZRpcGroupsService::LoadAdminSettings(const zproto::LoadAdminSettingsReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - LoadAdminSettings unimplemented";
  return -1;
}

int ZRpcGroupsService::SaveAdminSettings(const zproto::SaveAdminSettingsReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - SaveAdminSettings unimplemented";
  return -1;
}

int ZRpcGroupsService::DeleteGroup(const zproto::DeleteGroupReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - DeleteGroup unimplemented";
  return -1;
}

int ZRpcGroupsService::JoinGroup(const zproto::JoinGroupReq& request, zproto::JoinGroupRsp* response) {
  LOG(ERROR) << "ZRpcGroupsService - JoinGroup unimplemented";
  return -1;
}

