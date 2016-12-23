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

#ifndef DAL_USER_SEQUENCE_DO_H_
#define DAL_USER_SEQUENCE_DO_H_

#include <list>
#include <string>

#include "dal/base_dal.h"

// user_messages表
struct UserSequenceDO {
  // DO成员
  uint64_t id;
  std::string user_id;
  uint64_t seq;
  uint64_t header;
  std::string data; // 发送方
  uint64_t created_at;
  //反射
  // META(id, user_id, seq, header, data, created_at);
};

using UserSequenceDOPtr = std::shared_ptr<UserSequenceDO>;
using UserSequenceDOList = std::list<UserSequenceDOPtr>;

#endif
