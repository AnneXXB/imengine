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

#include "dal/group_user_dao_impl.h"

#include "nebula/base/string_builder.h"

GroupUserDAO& GroupUserDAO::GetInstance() {
  static GroupUserDAOImpl impl;
  return impl;
}

int64_t GroupUserDAOImpl::Create(GroupUserDOList& group_users) {
  return DoStorageInsertID("nebula_engine",
                           [&](std::string& query_string) {
                             CStringBuilder sb("INSERT INTO group_users "
                                              "(group_id,user_id,is_admin,status,invited_at,inviter_user_id,joined_at,created_at,updated_at) "
                                              " VALUES ");
                             bool first = true;
                             for (auto& v : group_users) {
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
                             LOG(INFO) << query_string;

                           });
}

int GroupUserDAOImpl::GetGroupUserIDList(const std::string& group_id, std::list<std::string>& group_user_ids) {
  return DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          query_string = folly::sformat("SELECT user_id FROM group_users WHERE group_id='{}'",
                                                        group_id);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          std::string id;
                          if (answ.GetColumn(0, &id) && !id.empty()) {
                            group_user_ids.push_back(id);
                          }
                          return CONTINUE;
                        });
}
