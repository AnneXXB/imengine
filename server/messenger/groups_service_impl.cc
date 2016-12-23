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

#include "messenger/groups_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"

int GroupsServiceImpl::LoadFullGroups(const zproto::LoadFullGroupsReq& request, zproto::LoadFullGroupsRsp* response) {
  return -1;
}

int GroupsServiceImpl::LoadMembers(const zproto::LoadMembersReq& request, zproto::LoadMembersRsp* response) {
  return -1;
}

int GroupsServiceImpl::CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response) {
/*
  auto r = GroupDAO::GetInstance().CheckExists(request.creator_user_id(),
                                               request.client_group_id());
  // TODO(@benqi):
  
  GroupDO group_entity;
  GroupUserDOList group_member_list;
  auto now = NowInMsecTime();
  
  group_entity.group_id = folly::to<std::string>(GetNextIDBySnowflake());
  group_entity.app_id = 1;
  group_entity.creator_user_id = request.creator_user_id();
  group_entity.client_group_id = request.client_group_id();
  group_entity.title = request.title();
  group_entity.status = 1;
  group_entity.created_at = now;
  group_entity.updated_at = now;
  
  for (int i=0; i<request.user_ids_size(); ++i) {
    auto group_memeber = std::make_shared<GroupUserDO>();
    group_memeber->group_id = group_entity.group_id;
    group_memeber->user_id = request.user_ids(i);
    group_memeber->inviter_user_id = group_entity.creator_user_id;
    if (group_memeber->user_id == group_memeber->inviter_user_id) {
      group_memeber->is_admin = 1;
    } else {
      group_memeber->is_admin = 0;
    }
    group_memeber->status = 1;
    
    group_memeber->joined_at = now;
    group_memeber->created_at = now;
    group_memeber->updated_at = now;
    
    group_member_list.push_back(group_memeber);
  }
  
  auto iid = GroupDAO::GetInstance().Create(group_entity);
  if (iid<0) {
    // TODO(@benqi):
  }
  
  iid = GroupUserDAO::GetInstance().Create(group_member_list);
  if (iid<0) {
    // TODO(@benqi):
  }
  
  response->set_seq(GetNextIDBySnowflake());
  response->set_created(now);
  auto group = response->mutable_group();
  group->set_group_id(group_entity.group_id);
  group->set_title(group_entity.title);
  for (auto m : group_member_list) {
    auto member = group->add_members();
    member->set_user_id(m->user_id);
    member->set_inviter_uid(m->inviter_user_id);
    member->set_date(m->created_at);
    member->set_is_admin(m->is_admin == 1);
  }
  response->mutable_user_ids()->CopyFrom(request.user_ids());
  
  return 0;
*/
  return -1;
}

int GroupsServiceImpl::EditGroupTitle(const zproto::EditGroupTitleReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::EditGroupAvatar(const zproto::EditGroupAvatarReq& request, zproto::EditGroupAvatarRsp* response) {
  return -1;
}

int GroupsServiceImpl::RemoveGroupAvatar(const zproto::RemoveGroupAvatarReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::EditGroupShortName(const zproto::EditGroupShortNameReq& request, zproto::SeqRsp* response) {
  return -1;
}

int GroupsServiceImpl::EditGroupTopic(const zproto::EditGroupShortNameReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::EditGroupAbout(const zproto::EditGroupAboutReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::InviteUser(const zproto::InviteUserReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::LeaveGroup(const zproto::LeaveGroupReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::LeaveAndDelete(const zproto::LeaveAndDeleteReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::KickUser(const zproto::KickUserReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::JoinGroupByPeer(const zproto::JoinGroupByPeerReq& request, zproto::SeqRsp* response) {
  return -1;
}

int GroupsServiceImpl::MakeUserAdmin(const zproto::MakeUserAdminReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::DismissUserAdmin(const zproto::DismissUserAdminReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::TransferOwnership(const zproto::TransferOwnershipReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::LoadAdminSettings(const zproto::LoadAdminSettingsReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::SaveAdminSettings(const zproto::SaveAdminSettingsReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::DeleteGroup(const zproto::DeleteGroupReq& request, zproto::SeqDateRsp* response) {
  return -1;
}

int GroupsServiceImpl::JoinGroup(const zproto::JoinGroupReq& request, zproto::JoinGroupRsp* response) {
  return -1;
}
