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

#ifndef IMENGINGE_DAL_USER_DO_H_
#define IMENGINGE_DAL_USER_DO_H_

#include <list>
#include <string>

#include "dal/base_dal.h"

// 表名: users
struct UserDO {
  // `id` bigint(20) NOT NULL,
  uint64_t id{0};
  // `app_id` int(11) NOT NULL DEFAULT '1',
  uint32_t app_id{1};
  // `user_id` varchar(256) NOT NULL,
  std::string user_token;
  // `user_token` varchar(256) NOT NULL,
  std::string user_id;
  // `avatar` varchar(256) NOT NULL DEFAULT '',
  std::string avatar;
  // `nick` varchar(256) NOT NULL DEFAULT '',
  std::string nick;
  // `is_active` tinyint(4) NOT NULL DEFAULT '0',
  int is_active;
  // `status` tinyint(4) NOT NULL DEFAULT '0',
  int status{1};
  //   `created_at` bigint(20) NOT NULL DEFAULT '0',
  uint32_t created_at{0};
  // `updated_at` bigint(20) NOT NULL DEFAULT '0'
  uint32_t updated_at{0};
 
  //反射
  META(id, app_id, user_id, avatar, nick, status, created_at, updated_at);
};

using UserDOPtr = std::shared_ptr<UserDO>;
using UserDOList = std::list<UserDOPtr>;

#endif
