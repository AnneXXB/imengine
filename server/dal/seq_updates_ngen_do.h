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

#ifndef DAL_SEQ_UPDATE_NGEN_DO_H_
#define DAL_SEQ_UPDATE_NGEN_DO_H_

#include "dal/base_dal.h"

struct SeqUpdatesNgenDO {
  SeqUpdatesNgenDO() = default;
  SeqUpdatesNgenDO(const std::string& uid, int64_t s, int64_t t)
    : user_id(uid),
      seq(s),
      timestamp(t) {}
  
  std::string user_id;
  int64_t seq;
  int64_t timestamp;
};

#endif
