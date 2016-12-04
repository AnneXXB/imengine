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

#ifndef BIZ_MODEL_ONLINE_STATUS_HELPER_H_
#define BIZ_MODEL_ONLINE_STATUS_HELPER_H_

#include <string>
#include <list>

struct OnlineUserInfo {
  OnlineUserInfo() = default;
  OnlineUserInfo(uint32_t sid, uint64_t cid, int s)
  : server_id(sid),
    conn_id(cid),
    state(s) {}
  
  // uint32_t app_id;
  // std::string user_id;
  uint32_t server_id;
  uint64_t conn_id;
  int state;
};

bool GetUsersOnlineStatus(uint32_t app_id,
                          const std::list<std::string>& user_id_list,
                          std::list<OnlineUserInfo>& onlines,
                          uint64_t my_conn_id = 0);

#endif
