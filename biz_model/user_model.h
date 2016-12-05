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

#ifndef BIZ_MODEL_USER_MODEL_H_
#define BIZ_MODEL_USER_MODEL_H_

#include "nebula/storage/storage_util.h"
#include "biz_model/base_biz_model_data.h"

// SELECT app_id, user_id FROM users WHERE app_id IN
//    (SELECT app_id FROM app_keys WHERE app_key='nebula-im(zhazha)') AND
//    user_token='benqi@zhazha.nebula.im'

//////////////////////////////////////////////////////////////////////////////////////////
struct GetUserInfoByToken  : public QueryWithResult {
  GetUserInfoByToken(const std::string& _app_key,
                      const std::string& _user_token,
                      UserEntity& _user)
    : app_key(_app_key),
      user_token(_user_token),
      user(_user) {}
  
  bool SerializeToQuery(std::string& query_string) const override;
  int ParseFrom(db::QueryAnswer& answ) override;
  
  const std::string& app_key;
  const std::string& user_token;
  UserEntity& user;
};

struct GetUserInfoByUserNamePasswd  : public QueryWithResult {
  GetUserInfoByUserNamePasswd(uint32_t _app_id,
                              const std::string& _user_id,
                              const std::string& _passwd,
                              UserEntity& _user)
  : app_id(_app_id),
    user_id(_user_id),
    passwd(_passwd),
    user(_user) {}
  
  bool SerializeToQuery(std::string& query_string) const override;
  int ParseFrom(db::QueryAnswer& answ) override;
  
  uint32_t app_id;
  const std::string& user_id;
  const std::string& passwd;
  
  UserEntity& user;
};

#endif
