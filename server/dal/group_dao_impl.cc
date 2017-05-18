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

#include "dal/group_dao_impl.h"

GroupDAO& GroupDAO::GetInstance() {
  static GroupDAOImpl impl;
  return impl;
}

int GroupDAOImpl::CheckExists(const std::string& creator_user_id, uint64_t client_group_id) {
  return DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          folly::format(&query_string, "SELECT id FROM groups WHERE creator_user_id='{}' AND client_group_id={} LIMIT 1",
                                        creator_user_id,
                                        client_group_id);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          return BREAK;
                        });
}

int64_t GroupDAOImpl::Create(GroupDO& group) {
  return DoStorageInsertID("nebula_engine",
                           [&](std::string& query_string) {
                             QueryParam p;
                             p.AddParam(group.group_id.c_str());
                             p.AddParam(group.creator_user_id.c_str());
                             p.AddParam(&group.client_group_id);
                             p.AddParamEsc(group.title.c_str());
                             p.AddParamEsc(group.avatar.c_str());
                             p.AddParamEsc(group.topic.c_str());
                             p.AddParamEsc(group.about.c_str());
                             p.AddParam(&group.created_at);
                             p.AddParam(&group.updated_at);
                             
                             MakeQueryString("INSERT INTO groups "
                                                 "(group_id,creator_user_id,client_group_id,title,avatar,topic,about,status,created_at,updated_at) "
                                                 "VALUES "
                                                 "(:1,:2,:3,:4,:5,:6,:7,1,:8,:9)",
                                                 &p,
                                                 &query_string);
                           });
}

int GroupDAOImpl::GetGroup(const std::string& group_id, GroupDO& group) {
  return DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          folly::format(&query_string, "SELECT id FROM groups WHERE group_id='{}' LIMIT 1",
                                        group_id);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          group.app_id = 1;
                          // ...
                          return BREAK;
                        });
}
