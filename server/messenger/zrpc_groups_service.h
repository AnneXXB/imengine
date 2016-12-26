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

#ifndef	MESSENGER_ZRPC_GROUPS_SERVICE_H_
#define	MESSENGER_ZRPC_GROUPS_SERVICE_H_

#include "proto/api/cc/groups.pb.h"
#include "base/base_zrpc_service.h"

class ZRpcGroupsService : public BaseZRpcService {
public:
  virtual ~ZRpcGroupsService() = default;
  
  ////////////////////////////////////////////////////////////////////////////////////////////////
  virtual int LoadFullGroups(const zproto::LoadFullGroupsReq& request, zproto::LoadFullGroupsRsp* response);
  virtual int LoadMembers(const zproto::LoadMembersReq& request, zproto::LoadMembersRsp* response);

  virtual int CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response);

  virtual int EditGroupTitle(const zproto::EditGroupTitleReq& request, zproto::SeqDateRsp* response);
  virtual int EditGroupAvatar(const zproto::EditGroupAvatarReq& request, zproto::EditGroupAvatarRsp* response);
  virtual int RemoveGroupAvatar(const zproto::RemoveGroupAvatarReq& request, zproto::SeqDateRsp* response);
  virtual int EditGroupShortName(const zproto::EditGroupShortNameReq& request, zproto::SeqRsp* response);
  virtual int EditGroupTopic(const zproto::EditGroupTopicReq& request, zproto::SeqDateRsp* response);
  virtual int EditGroupAbout(const zproto::EditGroupAboutReq& request, zproto::SeqDateRsp* response);
  virtual int InviteUser(const zproto::InviteUserReq& request, zproto::SeqDateRsp* response);
  virtual int LeaveGroup(const zproto::LeaveGroupReq& request, zproto::SeqDateRsp* response);
  virtual int LeaveAndDelete(const zproto::LeaveAndDeleteReq& request, zproto::SeqDateRsp* response);
  virtual int KickUser(const zproto::KickUserReq& request, zproto::SeqDateRsp* response);
  virtual int JoinGroupByPeer(const zproto::JoinGroupByPeerReq& request, zproto::SeqRsp* response);
  virtual int MakeUserAdmin(const zproto::MakeUserAdminReq& request, zproto::SeqDateRsp* response);
  virtual int DismissUserAdmin(const zproto::DismissUserAdminReq& request, zproto::SeqDateRsp* response);
  virtual int TransferOwnership(const zproto::TransferOwnershipReq& request, zproto::SeqDateRsp* response);
  virtual int LoadAdminSettings(const zproto::LoadAdminSettingsReq& request, zproto::SeqDateRsp* response);
  virtual int SaveAdminSettings(const zproto::SaveAdminSettingsReq& request, zproto::SeqDateRsp* response);
  virtual int DeleteGroup(const zproto::DeleteGroupReq& request, zproto::SeqDateRsp* response);
  virtual int JoinGroup(const zproto::JoinGroupReq& request, zproto::JoinGroupRsp* response);

};

#endif

