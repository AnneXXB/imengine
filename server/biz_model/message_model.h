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

#ifndef BIZ_MODEL_MESSAGE_MODEL_H_
#define BIZ_MODEL_MESSAGE_MODEL_H_


#include <string>
#include <list>

class MessageModel {
public:
  ~MessageModel() = default;
  
  static MessageModel& GetInstance();
  
  int CreateIfNotExists(const std::string& sender_user_id,
                        uint32_t peer_type,
                        const std::string& peer_id,
                        uint64_t message_peer_seq,
                        uint64_t rid,
                        int message_content_type,
                        const std::string& message_content_data,
                        const std::string& passthrough_data);
  
  // 发送服务端消息
  int SendServerMessage(const std::string& from_id,
                        const std::string& to_id,
                        uint64_t message_peer_seq,
                        int message_content_type,
                        const std::string& message_content_data,
                        const std::string& passthrough_data);

  int SendServerGroupMessage(const std::string& from_id,
                             const std::string& group_id,
                             const std::list<std::string>& group_user_id_list,
                             uint64_t message_peer_seq,
                             int message_content_type,
                             const std::string& message_content_data,
                             const std::string& passthrough_data);

};


#endif
