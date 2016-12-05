/**
 *  Copyright (c) 2016, https://github.com/zhatalk
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

#ifndef BIZ_MODEL_GROUP_MODEL_H_
#define BIZ_MODEL_GROUP_MODEL_H_

#include "nebula/storage/storage_util.h"
#include "biz_model/base_biz_model_data.h"

//////////////////////////////////////////////////////////////////////////////////////////
// 去重

bool CheckGroupDuplication(const std::string& creator_uid, uint64_t rid);

struct CreateGroup : public BaseSqlQuery {
  explicit CreateGroup(GroupEntity& _group)
    : group(_group) {}
  
  bool SerializeToQuery(std::string& query_string) const override;
  
  GroupEntity& group;
};

struct CreateGroupUsers : public BaseSqlQuery {
  explicit CreateGroupUsers(GroupMemberEntityList& _group_members)
    : group_members(_group_members) {}
  
  bool SerializeToQuery(std::string& query_string) const override;
  
  GroupMemberEntityList& group_members;
};

#endif
