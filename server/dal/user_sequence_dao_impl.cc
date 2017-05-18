/*
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

#include "dal/user_sequence_dao_impl.h"

UserSequenceDAO& UserSequenceDAO::GetInstance() {
  static UserSequenceDAOImpl impl;
  return impl;
}

int64_t UserSequenceDAOImpl::Create(UserSequenceDO& user_sequence) {
  return DoStorageInsertID("nebula_engine",
                           [&](std::string& query_string) {
                             QueryParam p;
                             p.AddParam(user_sequence.user_id.c_str());
                             p.AddParam(&user_sequence.seq);
                             p.AddParam(&user_sequence.header);
                             p.AddParamEsc(user_sequence.data.c_str());
                             p.AddParam(&user_sequence.created_at);
                             
                             MakeQueryString("INSERT INTO user_sequence"
                                                 "(user_id,seq,header,data,created_at)"
                                                 " VALUES "
                                                 "(:1,:2,:3,:4,:5)",
                                                 &p,
                                                 &query_string);
                           });
}

int64_t UserSequenceDAOImpl::GetCurrentSequence(const std::string& user_id) {
  int64_t sequence = 0;
  DoStorageQuery("nebula_engine",
                 [&](std::string& query_string) {
                   query_string = folly::sformat("SELECT seq FROM user_sequence WHERE user_id='{}' order by seq desc limit 1",
                                                 user_id);
                 },
                 [&](MysqlResultSet& answ) -> int {
                   answ.GetColumn(0, &sequence);
                   return BREAK;
                 });
  return sequence;
}

uint64_t id;
std::string user_id;
uint64_t seq;
uint64_t header;
std::string data; // 发送方
uint64_t created_at;

int UserSequenceDAOImpl::LoadSequenceData(const std::string& user_id, int64_t min_seq, UserSequenceDOList& user_sequence_list) {
  return DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          query_string = folly::sformat("SELECT seq,header,data,created_at "
                                                        "FROM user_sequence WHERE user_id='{}' AND seq>{} "
                                                        "order by seq desc limit 100",
                                                        user_id,
                                                        min_seq);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          auto user_sequence = std::make_shared<UserSequenceDO>();
                          
                          int result = CONTINUE;
                          do {
                            DB_GET_RETURN_COLUMN(0, user_sequence->seq);
                            DB_GET_RETURN_COLUMN(1, user_sequence->header);
                            DB_GET_RETURN_COLUMN(2, user_sequence->data);
                            DB_GET_RETURN_COLUMN(3, user_sequence->created_at);
                            
                            user_sequence->user_id = user_id;
                            user_sequence_list.push_back(user_sequence);
                          } while (0);
                          
                          LOG(INFO) << "LoadSequenceData - ParseFrom: " << user_sequence->seq;
                          
                          return result;
                        });
}

