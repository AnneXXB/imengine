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

#include "biz_model/message_model.h"

#include "nebula/base/time_util.h"
#include "proto/api/error_codes.h"
#include "dal/history_message_dao.h"

MessageModel& MessageModel::GetInstance() {
  static MessageModel instance;
  return instance;
}

int MessageModel::CreateIfNotExists(const std::string& sender_user_id,
                                    uint32_t peer_type,
                                    const std::string& peer_id,
                                    uint64_t message_peer_seq,
                                    uint64_t rid,
                                    int message_content_type,
                                    const std::string& message_content_data,
                                    const std::string& passthrough_data) {

  auto& history_message_dao = HistoryMessageDAO::GetInstance();
  
  // 去重
  int r = history_message_dao.CheckExists(sender_user_id,
                                          peer_id,
                                          peer_type,
                                          rid);
  
  if (r<0) {
    return kErrDBError;
  } else if (r > 0) {
    return kErrDBDup;
  }

  
  auto now = NowInMsecTime();
  HistoryMessageDO message_do;
  
  // 入库
  message_do.sender_user_id = sender_user_id;
  message_do.peer_id = peer_id;
  message_do.peer_type = peer_type;
  message_do.message_peer_seq = message_peer_seq;
  message_do.client_message_id = rid;
  message_do.message_content_type = message_content_type;
  // 这个地方比较重
  message_do.message_content_data = message_content_data;
  message_do.passthrough_data = passthrough_data;
  message_do.status = 1;
  message_do.created_at = now;
  message_do.updated_at = now;
  
  auto message_id = history_message_dao.Create(message_do);
  if (message_id<0) {
    // TODO(@benqi): 数据库异常，让客户端重试吧
    LOG(ERROR) << "CreateIfNotExists - Create error!!";
    return kErrDBError;
  }
  
  return kErrOK;
}
