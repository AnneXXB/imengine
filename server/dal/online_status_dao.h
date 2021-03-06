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

#ifndef DAL_ONLINE_STATUS_DAO_H_
#define DAL_ONLINE_STATUS_DAO_H_

#include "dal/online_status_do.h"

struct OnlineStatusDAO : public BaseDAO {
  virtual ~OnlineStatusDAO() = default;
  
  static OnlineStatusDAO& GetInstance();

  virtual bool GetUsersOnlineStatus(uint32_t app_id,
                                    const std::list<std::string>& user_id_list,
                                    OnlineStatusDOList& onlines,
                                    uint64_t my_conn_id = 0) = 0;
};

#endif
