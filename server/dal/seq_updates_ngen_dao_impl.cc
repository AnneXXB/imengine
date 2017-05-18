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

#include "dal/seq_updates_ngen_dao_impl.h"

SeqUpdatesNgenDAO& SeqUpdatesNgenDAO::GetInstance() {
  static SeqUpdatesNgenDAOImpl impl;
  return impl;
}

int64_t SeqUpdatesNgenDAOImpl::GetSequence(const std::string& user_id) {
  int64_t seq = 0;
  DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          folly::format(&query_string,
                                        "SELECT seq FROM seq_updates_ngen WHERE user_id='{}'",
                                        user_id);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          answ.GetColumn(0, &seq);
                          return BREAK;
                        });
  return seq;
}

int SeqUpdatesNgenDAOImpl::Upsert(SeqUpdatesNgenDO& seq_updates_ngen_do) {
  return DoStorageExecute("nebula_engine",
                           [&](std::string& query_string) {
                             if (seq_updates_ngen_do.seq == 1) {
                               folly::format(&query_string,
                                             "REPLACE INTO seq_updates_ngen "
                                             "(user_id,seq,timestamp) "
                                             "VALUES "
                                             "('{}',{},{})",
                                             seq_updates_ngen_do.user_id,
                                             seq_updates_ngen_do.seq,
                                             seq_updates_ngen_do.timestamp);
                             } else {
                               folly::format(&query_string,
                                             "UPDATE seq_updates_ngen SET seq='{}',timestamp={} WHERE user_id='{}'",
                                             seq_updates_ngen_do.seq,
                                             seq_updates_ngen_do.timestamp,
                                             seq_updates_ngen_do.user_id);
                             }
                           });
}
