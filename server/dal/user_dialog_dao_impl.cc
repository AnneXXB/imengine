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

#include "dal/user_dialog_dao_impl.h"

#include "nebula/base/time_util.h"
#include "proto/api/cc/messaging_base.pb.h"

UserDialogDAO& UserDialogDAO::GetInstance() {
  static UserDialogDAOImpl impl;
  return impl;
}

int UserDialogDAOImpl::CheckExists(const std::string& user_id,
                                   const std::string& peer_id,
                                   uint32_t peer_type) {
  return DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          folly::format(&query_string, "SELECT id FROM user_dialogs WHERE user_id='{}' AND peer_id='{}' AND peer_type={}",
                                                        user_id,
                                                        peer_id,
                                                        peer_type);
                        },
                        [&](MysqlResultSet& answ) -> int {
                          return BREAK;
                        });
}


int64_t UserDialogDAOImpl::Create(UserDialogDO& user_dialog) {
  return DoStorageInsertID("nebula_engine",
                           [&](std::string& query_string) {
                             folly::format(&query_string, "INSERT INTO user_dialogs(user_id,peer_id,peer_type,status,created_at,updated_at) "
                                           "VALUES('{}','{}',{},1,{},{})",
                                           user_dialog.user_id,
                                           user_dialog.peer_id,
                                           user_dialog.peer_type,
                                           user_dialog.created_at,
                                           user_dialog.updated_at);
                           });
}


int UserDialogDAOImpl::LoadUserDialogList(const std::string& user_id,
                                          uint64_t loaded_time,
                                          int load_mode,
                                          uint32_t load_limit,
                                          UserDialogDOList& user_dialogs) {
  return DoStorageQuery("nebula_engine",
                        [&](std::string& query_string) {
                          if (load_mode == zproto::FORWARD) {
                            folly::format(&query_string, "SELECT id,peer_id,peer_type,updated_at FROM user_dialogs WHERE user_id='{}' AND updated_at<={} order by updated_at desc LIMIT {}",
                                          user_id,
                                          loaded_time==0 ? std::numeric_limits<uint64_t>::max() : loaded_time,
                                          load_limit);
                          } else {
                            folly::format(&query_string, "SELECT id,peer_id,peer_type,updated_at FROM user_dialogs WHERE user_id='{}' AND updated_at>={} order by updated_at asc LIMIT {}",
                                          user_id,
                                          loaded_time==0 ? std::numeric_limits<uint64_t>::max() : loaded_time,
                                          load_limit);
                          }
                        },
                        [&](MysqlResultSet& answ) -> int {
                          auto dialog = std::make_shared<UserDialogDO>();
                          
                          int result = CONTINUE;
                          do {
                            DB_GET_RETURN_COLUMN(0, dialog->id);
                            DB_GET_COLUMN(1, dialog->peer_id);
                            DB_GET_RETURN_COLUMN(2, dialog->peer_type);
                            DB_GET_RETURN_COLUMN(3, dialog->updated_at);
                            
                            dialog->user_id = user_id;
                            user_dialogs.push_back(dialog);
                          } while (0);
                          
                          LOG(INFO) << "LoadUserDialogs - ParseFrom: " << dialog->id;
                          
                          return result;
                        });
}

// 阻止和取消
int UserDialogDAOImpl::UpdateBlock(const std::string& user_id,
                const std::string& peer_id,
                uint32_t peer_type,
                bool is_block) {
  return DoStorageExecute("nebula_engine",
                          [&](std::string& query_string) {
                            folly::format(&query_string,
                                          "UPDATE user_dialogs SET is_block={},updated_at={} WHERE user_id={} AND peer_id={} AND peer_type={};",
                                          is_block ? 1 : 0,
                                          NowInMsecTime(),
                                          user_id,
                                          peer_id,
                                          peer_type);
                          });
}

// 置顶和取消
int UserDialogDAOImpl::UpdateTop(const std::string& user_id,
              const std::string& peer_id,
              uint32_t peer_type,
              bool is_top) {
  return DoStorageExecute("nebula_engine",
                          [&](std::string& query_string) {
                            folly::format(&query_string,
                                          "UPDATE user_dialogs SET is_top={},updated_at={} WHERE user_id={} AND peer_id={} AND peer_type={};",
                                          is_top ? 1 : 0,
                                          NowInMsecTime(),
                                          user_id,
                                          peer_id,
                                          peer_type);
                          });
}

// 屏蔽和取消
int UserDialogDAOImpl::UpdateDnd(const std::string& user_id,
              const std::string& peer_id,
              uint32_t peer_type,
              bool is_dnd) {
  return DoStorageExecute("nebula_engine",
                          [&](std::string& query_string) {
                            folly::format(&query_string,
                                          "UPDATE user_dialogs SET is_dnd={},updated_at={} WHERE user_id={} AND peer_id={} AND peer_type={};",
                                          is_dnd ? 1 : 0,
                                          NowInMsecTime(),
                                          user_id,
                                          peer_id,
                                          peer_type);
                          });
}
