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

#include "biz_model/user_model.h"

#include <folly/Format.h>

#include "nebula/storage/conn_pool_manager.h"

bool GetUserInfoByToken::SerializeToQuery(std::string& query_string) const {
  folly::format(&query_string, "SELECT app_id,user_id,nick,avatar FROM users WHERE app_id IN "
                                "(SELECT app_id FROM app_keys WHERE app_key='{}') AND "
                                "user_token='{}'",
                app_key,
                user_token);
  return !query_string.empty();
}

int GetUserInfoByToken::ParseFrom(db::QueryAnswer& answ) {
  int result = CONTINUE;
  
  do {
    // DB_GET_RETURN_COLUMN(idx, message->id);
    DB_GET_RETURN_COLUMN(0, user.app_id);
    DB_GET_COLUMN(2, user.user_id);
    DB_GET_COLUMN(3, user.nick);
    DB_GET_COLUMN(4, user.avatar);
  } while (0);
  
  return BREAK;
}

bool GetUserInfoByUserNamePasswd::SerializeToQuery(std::string& query_string) const {
  folly::format(&query_string, "SELECT app_id,user_id,nick,avatar FROM users WHERE "
                "app_id={} AND user_id='{}' AND user_token='{}'",
                app_id,
                user_id,
                passwd);
  LOG(INFO) << query_string;
  
  return !query_string.empty();
}

int GetUserInfoByUserNamePasswd::ParseFrom(db::QueryAnswer& answ) {
  int result = CONTINUE;
  
  do {
    // DB_GET_RETURN_COLUMN(idx, message->id);
    DB_GET_RETURN_COLUMN(0, user.app_id);
    DB_GET_COLUMN(1, user.user_id);
    DB_GET_COLUMN(2, user.nick);
    DB_GET_COLUMN(3, user.avatar);
  } while (0);
  
  return BREAK;
}
