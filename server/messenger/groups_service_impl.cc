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
#include "proto/api/cc/messaging.pb.h"
#include "dal/sequence_dao.h"

#include "biz_model/group_model.h"
#include "biz_model/dialog_model.h"
#include "biz_model/message_model.h"

int GroupsServiceImpl::LoadFullGroups(const zproto::LoadFullGroupsReq& request, zproto::LoadFullGroupsRsp* response) {
  for (int i=0; i<request.groups_size(); ++i) {
  }
  
  // repeated GroupOutPeer groups = 1; // Groups to load
  // virtual int LoadHistoryMessageList(std::list<uint64_t>& message_id_list,
  //                                    HistoryMessageDOList& message_list) = 0;

  return -1;
}

int GroupsServiceImpl::LoadMembers(const zproto::LoadMembersReq& request, zproto::LoadMembersRsp* response) {
  return -1;
}

int GroupsServiceImpl::CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response) {
  //  创建一个群最少要有3个人
  //  1(创建者) + request.users_size(>2)
  if (request.users_size() < 2) {
    LOG(ERROR) << "CreateGroup - member's size < 3!!!";
    return -1;
  }
  
  std::list<std::string> member_list;
  for (int i=0; i<request.users_size(); ++i) {
    const auto& user = request.users(i);
    member_list.push_back(user.uid());
  }

  // 创建群ID
  std::string group_id;
  
  auto seq = SequenceDAO::GetInstance().GetNextID(uid());
  auto now = NowInMsecTime();
  
  int rv = GroupModel::GetInstance().CreateIfNotExists(uid(),
                                                       request.rid(),
                                                       request.title(),
                                                       member_list,
                                                       &group_id);
  if (rv == kErrDBDup) {
    LOG(ERROR) << "CreateGroup - CreateIfNotExists error";
    
    // 幂等操作，如果Group存在，则认为已经走完流程了。
    // 已经存在，直接返回
    LOG(WARNING) << "CreateGroup - isexists by uid: " << uid() << ", rid: " << request.rid();
    
    // 直接生成一个SEQ返回，
    response->set_seq(seq);
    response->set_date(now);
    
    return kErrOK;
  } else if (rv != kErrOK) {
    LOG(ERROR) << "CreateGroup - ";
    return rv;
  }
  
  member_list.push_front(uid());
  // TODO(@benqi): 创建会话(user_dialog)
  rv = DialogModel::GetInstance().CreateIfNotExists(member_list, zproto::PEER_TYPE_GROUP, group_id);
  

  // TODO(@benqi): 发一群创建消息
  MessageModel::GetInstance().SendServerGroupMessage(uid(),
                                                     group_id,
                                                     member_list,
                                                     seq,
                                                     zproto::TEXT,
                                                     "uid",
                                                     "");
  // 返回
  response->set_seq(GetNextIDBySnowflake());
  response->set_date(NowInMsecTime());
  auto group = response->mutable_group();
  group->set_id(group_id);
  group->set_title(request.title());

  return kErrOK;
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
