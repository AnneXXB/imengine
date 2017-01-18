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

#ifndef IMENGINGE_DAL_GROUP_DO_H_
#define IMENGINGE_DAL_GROUP_DO_H_

#include <list>
#include <string>

#include "dal/base_dal.h"

// users表
struct GroupDO {
  // DO成员
  uint64_t id;
  uint32_t app_id{1};
  std::string group_id;
  std::string creator_user_id;
  uint64_t client_group_id;
  std::string title;
  std::string avatar;
  std::string topic;
  std::string about;
  int status{0};
  uint64_t created_at;
  uint64_t updated_at;
  std::string title_changer_user_id;
  uint64_t title_changer_at{0};
  std::string avatar_changer_user_id;
  uint64_t avatar_changer_at{0};
 
  //反射
  // META(id, app_id, user_id, avatar, nick, status, created_at, updated_at);
};

using GroupDOPtr = std::shared_ptr<GroupDO>;
using GroupDOList = std::list<GroupDOPtr>;

#endif
