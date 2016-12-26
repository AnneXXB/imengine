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

#ifndef	MESSENGER_GROUPS_SERVICE_IMPL_H_
#define	MESSENGER_GROUPS_SERVICE_IMPL_H_

#include "messenger/zrpc_groups_service.h"

class GroupsServiceImpl : public ZRpcGroupsService {
public:
  GroupsServiceImpl() = default;
  ~GroupsServiceImpl() = default;
  
  int LoadFullGroups(const zproto::LoadFullGroupsReq& request, zproto::LoadFullGroupsRsp* response) override;
  int LoadMembers(const zproto::LoadMembersReq& request, zproto::LoadMembersRsp* response) override;
  
  int CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response) override;
  
  int EditGroupTitle(const zproto::EditGroupTitleReq& request, zproto::SeqDateRsp* response) override;
  int EditGroupAvatar(const zproto::EditGroupAvatarReq& request, zproto::EditGroupAvatarRsp* response) override;
  int RemoveGroupAvatar(const zproto::RemoveGroupAvatarReq& request, zproto::SeqDateRsp* response) override;
  int EditGroupShortName(const zproto::EditGroupShortNameReq& request, zproto::SeqRsp* response) override;
  int EditGroupTopic(const zproto::EditGroupTopicReq& request, zproto::SeqDateRsp* response) override;
  int EditGroupAbout(const zproto::EditGroupAboutReq& request, zproto::SeqDateRsp* response) override;
  int InviteUser(const zproto::InviteUserReq& request, zproto::SeqDateRsp* response) override;
  int LeaveGroup(const zproto::LeaveGroupReq& request, zproto::SeqDateRsp* response) override;
  int LeaveAndDelete(const zproto::LeaveAndDeleteReq& request, zproto::SeqDateRsp* response) override;
  int KickUser(const zproto::KickUserReq& request, zproto::SeqDateRsp* response) override;
  int JoinGroupByPeer(const zproto::JoinGroupByPeerReq& request, zproto::SeqRsp* response) override;
  int MakeUserAdmin(const zproto::MakeUserAdminReq& request, zproto::SeqDateRsp* response) override;
  int DismissUserAdmin(const zproto::DismissUserAdminReq& request, zproto::SeqDateRsp* response) override;
  int TransferOwnership(const zproto::TransferOwnershipReq& request, zproto::SeqDateRsp* response) override;
  int LoadAdminSettings(const zproto::LoadAdminSettingsReq& request, zproto::SeqDateRsp* response) override;
  int SaveAdminSettings(const zproto::SaveAdminSettingsReq& request, zproto::SeqDateRsp* response) override;
  int DeleteGroup(const zproto::DeleteGroupReq& request, zproto::SeqDateRsp* response) override;
  int JoinGroup(const zproto::JoinGroupReq& request, zproto::JoinGroupRsp* response) override;
};

#endif
