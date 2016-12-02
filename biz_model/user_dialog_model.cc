/**
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

#include "biz_model/user_dialog_model.h"

#include <folly/Format.h>

#include "nebula/storage/conn_pool_manager.h"

#include "proto/zproto/cc/bases.pb.h"

//////////////////////////////////////////////////////////////////////////////////////////
int CheckUserDialogDuplication::ParseFrom(db::QueryAnswer& answ) {
  is_duplication = 1;
  return BREAK;
}

bool CheckUserDialogDuplication::SerializeToQuery(std::string& query_string) const {
  query_string = folly::sformat("SELECT id FROM user_dialogs WHERE user_id='{}' AND peer_id='{}' AND peer_type={}",
                                conversation_id.sender_user_id,
                                conversation_id.peer_id,
                                conversation_id.peer_type);
  return true;
}

//////////////////////////////////////////////////////////////////////////////////////////
bool CreateUserDialog::SerializeToQuery(std::string& query_string) const {
  folly::format(&query_string, "INSERT INTO user_dialogs(user_id,peer_id,peer_type,status,created_at,updated_at) "
                "VALUES('{}','{}',{},1,{},{})",
                dialog.user_id,
                dialog.peer_id,
                dialog.peer_type,
                dialog.created_at,
                dialog.updated_at);
  
  return !query_string.empty();
}

//////////////////////////////////////////////////////////////////////////////////////////
bool LoadUserDialogList::SerializeToQuery(std::string& query_string) const {
  if (load_mode == zproto::EnumHelper::FOWRARD) {
    query_string = folly::sformat("SELECT id,peer_id,peer_type,updated_at FROM user_dialogs WHERE user_id='{}' AND updated_at<{} order by updated_at desc LIMIT {}",
                                  user_id,
                                  loaded_time,
                                  load_limit);
  } else {
    query_string = folly::sformat("SELECT id,peer_id,peer_type,updated_at FROM user_dialogs WHERE user_id='{}' AND updated_at>{} order by updated_at asc LIMIT {}",
                                  user_id,
                                  loaded_time,
                                  load_limit);
  }
  
  
  LOG(INFO) << "LoadUserMessageList - query_string: " << query_string;
  return !query_string.empty();
}

int LoadUserDialogList::ParseFrom(db::QueryAnswer& answ) {
  auto dialog = std::make_shared<UserDialogEntity>();

  int result = CONTINUE;
  do {
    DB_GET_RETURN_COLUMN(0, dialog->id);
    DB_GET_COLUMN(1, dialog->peer_id);
    DB_GET_RETURN_COLUMN(2, dialog->peer_type);
    DB_GET_RETURN_COLUMN(3, dialog->updated_at);
    
    dialog->user_id = user_id;
    dialog_list.push_back(dialog);
  } while (0);
  
  LOG(INFO) << "LoadUserDialogs - ParseFrom: " << dialog->id;
  
  return result;
}

