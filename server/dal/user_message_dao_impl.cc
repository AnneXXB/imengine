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

#include "dal/user_message_dao_impl.h"

UserMessageDAO& UserMessageDAO::GetInstance() {
  static UserMessageDAOImpl impl;
  return impl;
}

int64_t UserMessageDAOImpl::Create(UserMessageDO& user_message) {
  return DoStorageInsertID("nebula_engine",
                           [&](std::string& query_string) {
                             QueryParam p;
                             p.AddParam(user_message.user_id.c_str());
                             p.AddParam(&user_message.message_seq);
                             p.AddParam(&user_message.message_id);
                             p.AddParam(user_message.sender_user_id.c_str());
                             p.AddParam(user_message.peer_id.c_str());
                             p.AddParam(&user_message.peer_type);
                             p.AddParam(&user_message.message_peer_seq);
                             p.AddParam(&user_message.created_at);
                             p.AddParam(&user_message.updated_at);
                             
                             MakeQueryString("INSERT INTO user_messages"
                                                 "(user_id,message_seq,message_id,sender_user_id,peer_id,peer_type,message_peer_seq,status,created_at,updated_at)"
                                                 " VALUES "
                                                 "(:1,:2,:3,:4,:5,:6,:7,1,:8,:9)",
                                                 &p,
                                                 &query_string);
                           });
}

int UserMessageDAOImpl::LoadUserMessageList(const std::string& user_id,
                                            uint64_t received_max_message_seq,
                                            UserMessageDOList& user_message_list) {
  return DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          query_string = folly::sformat("SELECT message_id,message_seq FROM user_messages WHERE user_id='{}' AND message_seq>{} LIMIT 200",
                                                        user_id,
                                                        received_max_message_seq);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          auto message = std::make_shared<UserMessageDO>();
                          message->user_id = user_id;
                          answ.GetColumn(0, &message->message_id);
                          answ.GetColumn(1, &message->message_seq);
                          user_message_list.push_back(message);
                          return CONTINUE;
                        });

}

int UserMessageDAOImpl::LoadUserDialogMessageList(const std::string& user_id,
                                                  const std::string& peer_id,
                                                  uint32_t peer_type,
                                                  UserMessageDOList& message_list) {
  return DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          query_string = folly::sformat("SELECT message_id,message_seq FROM user_messages WHERE user_id='{}' AND peer_id='{}' AND peer_type={} LIMIT 200",
                                                        user_id,
                                                        peer_id,
                                                        peer_type);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          auto message = std::make_shared<UserMessageDO>();
                          message->user_id = user_id;
                          answ.GetColumn(0, &message->message_id);
                          answ.GetColumn(1, &message->message_seq);
                          message_list.push_back(message);
                          return CONTINUE;
                        });

}
