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

#include "dal/user_dao_impl.h"

UserDAO& UserDAO::GetInstance() {
  static UserDAOImpl impl;
  return impl;
}

int UserDAOImpl::GetUserByUserID(uint32_t app_id,
                                 const std::string& user_id,
                                 UserDO& user_do) {
  return DoStorageQuery("nebula_platform",
                        [&](std::string& query_string) {
                          folly::format(&query_string,
                                        "SELECT app_id,user_id,nick,avatar FROM users WHERE "
                                        "app_id={} AND user_id='{}'",
                                        app_id,
                                        user_id);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          int result = CONTINUE;
                          
                          do {
                            // DB_GET_RETURN_COLUMN(idx, message->id);
                            DB_GET_RETURN_COLUMN(0, user_do.app_id);
                            DB_GET_COLUMN(1, user_do.user_id);
                            DB_GET_COLUMN(2, user_do.nick);
                            DB_GET_COLUMN(3, user_do.avatar);
                          } while (0);
                          
                          return BREAK;
                        });
}

int UserDAOImpl::GetUserByToken(const std::string& app_key,
                               const std::string& user_token,
                               UserDO& user_do) {
  return DoStorageQuery("nebula_platform",
                        [&](std::string& query_string) {
                          folly::format(&query_string,
                                        "SELECT app_id,user_id,nick,avatar FROM users WHERE app_id IN "
                                        "(SELECT app_id FROM app_keys WHERE app_key='{}') AND "
                                        "user_token='{}'",
                                        app_key,
                                        user_token);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          int result = CONTINUE;
                          
                          do {
                            // DB_GET_RETURN_COLUMN(idx, message->id);
                            DB_GET_RETURN_COLUMN(0, user_do.app_id);
                            DB_GET_COLUMN(1, user_do.user_id);
                            DB_GET_COLUMN(2, user_do.nick);
                            DB_GET_COLUMN(3, user_do.avatar);
                          } while (0);
                          
                          return BREAK;
                        });
}

int UserDAOImpl::GetUserByNamePasswd(uint32_t app_id,
                                    const std::string& user_id,
                                    const std::string& passwd,
                                    UserDO& user_do) {
  return DoStorageQuery("nebula_platform",
                        [&](std::string& query_string) {
                          folly::format(&query_string,
                                        "SELECT app_id,user_id,nick,avatar FROM users WHERE "
                                        "app_id=1 AND user_id='{}'",
                                        // app_id,
                                        user_id);
                                        // passwd);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          int result = CONTINUE;
                          
                          do {
                            // DB_GET_RETURN_COLUMN(idx, message->id);
                            DB_GET_RETURN_COLUMN(0, user_do.app_id);
                            DB_GET_COLUMN(1, user_do.user_id);
                            DB_GET_COLUMN(2, user_do.nick);
                            DB_GET_COLUMN(3, user_do.avatar);
                          } while (0);
                          
                          return BREAK;
                        });
}
