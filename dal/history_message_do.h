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

#ifndef IMENGINGE_DAL_HISTORY_MESSAGE_DO_H_
#define IMENGINGE_DAL_HISTORY_MESSAGE_DO_H_

#include <list>
#include <string>

#include "dal/base_dal.h"

// history_messages表
struct HistoryMessageDO {
  // DO成员
  uint64_t id;
  std::string user_id;
  uint64_t message_seq;
  uint64_t message_id;
  std::string sender_user_id; // 发送方
  std::string peer_id;
  uint32_t peer_type;
  
  uint64_t client_message_id;
  uint64_t message_peer_seq;
  uint32_t message_content_type;
  std::string message_content_data;
  std::string passthrough_data;
  
  uint32_t status;
  uint64_t created_at;
  uint64_t updated_at;
 
  // 反射
  // META(id, app_id, user_id, avatar, nick, status, created_at, updated_at);
};

using HistoryMessageDOPtr = std::shared_ptr<HistoryMessageDO>;
using HistoryMessageDOList = std::list<HistoryMessageDOPtr>;

#endif
