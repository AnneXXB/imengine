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

#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "nebula/net/rpc/zrpc_service_util.h"

#include "proto/api/error_codes.h"

#include "dal/group_dao.h"
#include "dal/group_user_dao.h"
#include "dal/sequence_dao.h"

int GroupsServiceImpl::LoadFullGroups(const zproto::LoadFullGroupsReq& request, zproto::LoadFullGroupsRsp* response) {
  return -1;
}

int GroupsServiceImpl::LoadMembers(const zproto::LoadMembersReq& request, zproto::LoadMembersRsp* response) {
  return -1;
}

int GroupsServiceImpl::CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response) {
  auto& group_dao = GroupDAO::GetInstance();
  
  auto r = group_dao.CheckExists(uid(),
                                 request.rid());
  
  if (r<0) {
    // TODO(@benqi): 区分数据库异常和重复问题
    LOG(ERROR) << "CreateGroup - CheckExists DBError";
    return kErrorNo_DBError;
  } else if (r > 0) {
    // 幂等操作，如果Group存在，则认为已经走完流程了。
    // 已经存在，直接返回
    LOG(WARNING) << "CreateGroup - isexists by uid: " << uid() << ", rid: " << request.rid();
    
    auto seq = SequenceDAO::GetInstance().GetNextID(uid());
    auto now = NowInMsecTime();
    
    // 直接生成一个SEQ返回，
    response->set_seq(seq);
    response->set_date(now);
    
    return 0;
  }

  // TODO(@benqi):
  //  创建一个群最少要有3个人
  //  1(创建者) + request.users_size(>2)
  
  GroupDO group_do;
  GroupUserDOList group_user_do_list;
  auto now = NowInMsecTime();
  
  group_do.group_id = folly::to<std::string>(GetNextIDBySnowflake());
  group_do.app_id = 1;
  group_do.creator_user_id = uid();
  group_do.client_group_id = request.rid();
  group_do.title = request.title();
  group_do.status = 1;
  group_do.created_at = now;
  group_do.updated_at = now;

  auto group_user_do = std::make_shared<GroupUserDO>();
  group_user_do->group_id = group_do.group_id;
  group_user_do->user_id = uid();
  group_user_do->inviter_user_id = uid();
  group_user_do->is_admin = 1;
  group_user_do->status = 1;
  group_user_do->joined_at = now;
  group_user_do->created_at = now;
  group_user_do->updated_at = now;
  group_user_do_list.push_back(group_user_do);
  
  for (int i=0; i<request.users_size(); ++i) {
    group_user_do = std::make_shared<GroupUserDO>();
    const auto& user = request.users(i);
    group_user_do->group_id = group_do.group_id;
    group_user_do->user_id = user.uid();
    group_user_do->inviter_user_id = uid();
    if (group_user_do->user_id == group_user_do->inviter_user_id) {
      group_user_do->is_admin = 1;
    } else {
      group_user_do->is_admin = 0;
    }
    group_user_do->status = 1;
    
    group_user_do->joined_at = now;
    group_user_do->created_at = now;
    group_user_do->updated_at = now;
    
    group_user_do_list.push_back(group_user_do);
  }
  
  r = group_dao.Create(group_do);
  if (r<0) {
    LOG(ERROR) << "CreateGroup - Create error!!";
    // TODO(@benqi): 是否回滚？
    return kErrorNo_DBError;
  }
  
  r = GroupUserDAO::GetInstance().Create(group_user_do_list);
  if (r<0) {
    LOG(ERROR) << "CreateGroup - Create error!!";
    // TODO(@benqi): 是否回滚？
    return kErrorNo_DBError;
  }
  
  // TODO(@benqi): 创建会话(user_dialog)
  
  // TODO(@benqi): 发一群创建消息
  
  // 返回
  response->set_seq(GetNextIDBySnowflake());
  response->set_date(now);
  auto group = response->mutable_group();
  group->set_id(group_do.group_id);
  group->set_title(group_do.title);

  return 0;
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

int GroupsServiceImpl::EditGroupTopic(const zproto::EditGroupTopicReq& request, zproto::SeqDateRsp* response) {
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
