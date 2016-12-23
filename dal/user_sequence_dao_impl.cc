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
                             db::QueryParam p;
                             p.AddParam(user_sequence.user_id.c_str());
                             p.AddParam(&user_sequence.seq);
                             p.AddParam(&user_sequence.header);
                             p.AddParam(user_sequence.data.c_str());
                             p.AddParam(&user_sequence.created_at);
                             
                             db::MakeQueryString("INSERT INTO user_sequence"
                                                 "(user_id,seq,header,data,created_at)"
                                                 " VALUES "
                                                 "(:1,:2,:3,:4,:5)",
                                                 &p,
                                                 &query_string);
                           });
}
