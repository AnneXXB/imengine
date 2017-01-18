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

#ifndef DAL_ONLINE_STATUS_DO_H_
#define DAL_ONLINE_STATUS_DO_H_

#include "dal/base_dal.h"

struct OnlineStatusDO {
  OnlineStatusDO() = default;
  OnlineStatusDO(uint32_t sid, uint64_t cid, int s)
    : server_id(sid),
      conn_id(cid),
      state(s) {}
  
  // uint32_t app_id;
  // std::string user_id;
  uint32_t server_id;
  uint64_t conn_id;
  int state;
};

using OnlineStatusDOList = std::list<OnlineStatusDO>;

#endif
