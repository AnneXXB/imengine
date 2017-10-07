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

#include "dal/history_message_dao_impl.h"

HistoryMessageDAO& HistoryMessageDAO::GetInstance() {
  static HistoryMessageDAOImpl impl;
  return impl;
}

int HistoryMessageDAOImpl::CheckExists(const std::string& user_id,
                                      const std::string& peer_id,
                                      uint32_t peer_type,
                                      uint64_t message_client_id) {
  return DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          folly::format(&query_string,
                                        "SELECT id FROM messages WHERE sender_user_id='{}' AND client_message_id={} LIMIT 1",
                                        user_id,
                                        message_client_id);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          return BREAK;
                        });
}


int64_t HistoryMessageDAOImpl::Create(HistoryMessageDO& message) {
  return DoStorageInsertID("nebula_engine",
                           [&](std::string& query_string) {
                             QueryParam p;
                             p.AddParam(message.sender_user_id.c_str());
                             p.AddParam(message.peer_id.c_str());
                             p.AddParam(&message.peer_type);
                             p.AddParam(&message.client_message_id);
                             p.AddParam(&message.message_peer_seq);
                             p.AddParam(&message.message_content_type);
                             p.AddParamEsc(message.message_content_data.c_str(),
                                           static_cast<int>(message.message_content_data.length()));
                             p.AddParamEsc(message.passthrough_data.c_str(),
                                           static_cast<int>(message.passthrough_data.length()));
                             p.AddParam(&message.created_at);
                             p.AddParam(&message.updated_at);
                             
                             MakeQueryString("INSERT INTO messages"
                                                 "(sender_user_id,peer_id,peer_type,client_message_id,message_peer_seq,message_content_type,"
                                                 "message_content_data,passthrough_data,status,created_at,updated_at)"
                                                 " VALUES "
                                                 "(:1,:2,:3,:4,:5,:6,:7,:8,1,:9,:10)",
                                                 &p,
                                                 &query_string);
                           });
}

int HistoryMessageDAOImpl::LoadHistoryMessageList(std::list<uint64_t>& message_id_list,
                                                  HistoryMessageDOList& message_list) {
  return DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          std::string message_ids;
                          folly::join("','", message_id_list, message_ids);
                          query_string = folly::sformat("SELECT id,sender_user_id,peer_id,peer_type,client_message_id,message_peer_seq,"
                                                        "message_content_type,message_content_data,passthrough_data,status,created_at,updated_at "
                                                        "FROM messages WHERE id in('{}')",
                                                        message_ids);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          auto message = std::make_shared<HistoryMessageDO>();
                          int result = CONTINUE;
                          do {
                            DB_GET_RETURN_COLUMN(0, message->id);
                            DB_GET_RETURN_COLUMN(1, message->sender_user_id);
                            DB_GET_RETURN_COLUMN(2, message->peer_id);
                            DB_GET_RETURN_COLUMN(3, message->peer_type);
                            DB_GET_RETURN_COLUMN(4, message->client_message_id);
                            DB_GET_RETURN_COLUMN(5, message->message_peer_seq);
                            DB_GET_RETURN_COLUMN(6, message->message_content_type);
                            DB_GET_COLUMN(7, message->message_content_data);
                            DB_GET_COLUMN(8, message->passthrough_data);
                            DB_GET_RETURN_COLUMN(9, message->status);
                            DB_GET_RETURN_COLUMN(10, message->created_at);
                            DB_GET_RETURN_COLUMN(11, message->updated_at);
                            
                            message_list.push_back(message);
                          } while (0);
                          
                          LOG(INFO) << "LoadHistoryMessageList - ParseFrom: " << message->id;
                          
                          return result;
                        });
}

