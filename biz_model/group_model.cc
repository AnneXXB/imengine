/*
 *  Copyright (c) 2016, https://github.com/nebula-im/imengine
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

#include "biz_model/group_model.h"

#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

#include "dal/group_dao.h"
#include "dal/group_user_dao.h"

GroupModel& GroupModel::GetInstance() {
  static GroupModel instance;
  return instance;
}

int GroupModel::CreateIfNotExists(const std::string& creator_user_id,
                                  uint64_t rid,
                                  const std::string& title,
                                  const std::list<std::string>& member_list,
                                  std::string* group_id) {
  auto& group_dao = GroupDAO::GetInstance();
  auto r = group_dao.CheckExists(creator_user_id, rid);
  if (r<0) {
    // TODO(@benqi): 区分数据库异常和重复问题
    // LOG(ERROR) << "CreateGroup - CheckExists DBError";
    return kErrDBError;
  } else if (r > 0) {
    // 幂等操作，如果Group存在，则认为已经走完流程了。
    // 已经存在，直接返回
    // LOG(WARNING) << "CreateGroup - isexists by uid: " << uid() << ", rid: " << request.rid();
    
    // auto seq = SequenceDAO::GetInstance().GetNextID(uid());
    // auto now = NowInMsecTime();
    
    // // 直接生成一个SEQ返回，
    // response->set_seq(seq);
    // response->set_date(now);
    return kErrDBDup;
    // return 0;
  }
  
  GroupDO group_do;
  GroupUserDOList group_user_do_list;
  auto now = NowInMsecTime();
  
  group_do.group_id = folly::to<std::string>(GetNextIDBySnowflake());
  group_do.app_id = 1;
  group_do.creator_user_id = creator_user_id;
  group_do.client_group_id = rid;
  group_do.title = title;
  group_do.status = 1;
  group_do.created_at = now;
  group_do.updated_at = now;
  
  auto group_user_do = std::make_shared<GroupUserDO>();
  group_user_do->group_id = group_do.group_id;
  group_user_do->user_id = creator_user_id;
  group_user_do->inviter_user_id = creator_user_id;
  group_user_do->is_admin = 1;
  group_user_do->status = 1;
  group_user_do->joined_at = now;
  group_user_do->created_at = now;
  group_user_do->updated_at = now;
  group_user_do_list.push_back(group_user_do);
  
  for (auto& member_id : member_list) {
    group_user_do = std::make_shared<GroupUserDO>();
    // const auto& user = request.users(i);
    group_user_do->group_id = group_do.group_id;
    group_user_do->user_id = member_id;
    group_user_do->inviter_user_id = creator_user_id;
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
    return kErrDBError;
  }
  
  r = GroupUserDAO::GetInstance().Create(group_user_do_list);
  if (r<0) {
    LOG(ERROR) << "CreateGroup - Create error!!";
    // TODO(@benqi): 是否回滚？
    return kErrDBError;
  }
  
  *group_id = group_do.group_id;
  return kErrOK;
}

