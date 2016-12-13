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

#ifndef IMENGINGE_DAL_HISTORY_MESSAGE_DAO_IMPL_H_
#define IMENGINGE_DAL_HISTORY_MESSAGE_DAO_IMPL_H_

#include "dal/history_message_dao.h"

struct HistoryMessageDAOImpl : public HistoryMessageDAO {
  virtual ~HistoryMessageDAOImpl() = default;
  
  int CheckExists(const std::string& user_id,
                  const std::string& peer_id,
                  uint32_t peer_type,
                  uint64_t message_client_id) override;
  
  int64_t Create(HistoryMessageDO& message) override;
  
  int LoadHistoryMessageList(std::list<uint64_t>& message_id_list,
                             HistoryMessageDOList& message_list) override;
};

#endif
