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

#include "biz_model/group_model.h"

#include <folly/Format.h>

#include "nebula/base/string_builder.h"
#include "nebula/storage/conn_pool_manager.h"

struct GroupExist : public QueryWithResult {
  GroupExist(const std::string& uid, uint64_t rid)
    : creator_user_id(uid), client_group_id(rid) {}
  
  int ParseFrom(db::QueryAnswer& answ) override {
    is_duplication = 1;
    return BREAK;
  }
  
  bool SerializeToQuery(std::string& query_string) const override {
    query_string = folly::sformat("SELECT id FROM groups WHERE creator_user_id='{}' AND client_group_id={} LIMIT 1",
                                  creator_user_id,
                                  client_group_id);
    return true;
  }
  
  std::string creator_user_id;
  uint64_t client_group_id;
  int is_duplication {-1};
};

bool CheckGroupDuplication(const std::string& creator_uid, uint64_t rid) {
  GroupExist group_exist(creator_uid, rid);
  SqlQuery("nebula_engine", group_exist);
  
  return group_exist.is_duplication == 1;
}

bool CreateGroup::SerializeToQuery(std::string& query_string) const {
  //std::string sql;
  db::QueryParam p;
  p.AddParam(group.group_id.c_str());
  p.AddParam(group.creator_user_id.c_str());
  p.AddParam(&group.client_group_id);
  p.AddParamEsc(group.title.c_str());
  p.AddParamEsc(group.avatar.c_str());
  p.AddParamEsc(group.topic.c_str());
  p.AddParamEsc(group.about.c_str());
  p.AddParam(&group.created_at);
  p.AddParam(&group.updated_at);
  
  db::MakeQueryString("INSERT INTO groups "
                      "(group_id,creator_user_id,client_group_id,title,avatar,topic,about,status,created_at,updated_at) "
                      "VALUES "
                      "(:1,:2,:3,:4,:5,:6,:7,1,:8,:9)",
                      &p,
                      &query_string);
  return true;
}

bool CreateGroupUsers::SerializeToQuery(std::string& query_string) const {
  StringBuilder sb("INSERT INTO group_users "
                         "(group_id,user_id,is_admin,status,invited_at,inviter_user_id,joined_at,created_at,updated_at) "
                         " VALUES ");
  bool first = true;
  for (auto v : group_members) {
    if (first) {
      first = false;
    } else {
      sb.Append(",");
    }
    
    sb.Append(folly::sformat("('{}','{}',{},1,{},'{}',{},{},{})",
                             v->group_id,
                             v->user_id,
                             v->is_admin,
                             v->invited_at,
                             v->inviter_user_id,
                             v->joined_at,
                             v->created_at,
                             v->updated_at));
  }
  
  query_string = sb.ToString();
  return true;
}

