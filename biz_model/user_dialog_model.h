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

#ifndef BIZ_MODEL_USER_DIALOG_MODEL_H_
#define BIZ_MODEL_USER_DIALOG_MODEL_H_

#include "nebula/storage/storage_util.h"
#include "biz_model/base_biz_model_data.h"

//////////////////////////////////////////////////////////////////////////////////////////
struct CheckUserDialogDuplication : public QueryWithResult {
  CheckUserDialogDuplication(ConversationID& cid)
    : conversation_id(cid){}
  
  CheckUserDialogDuplication(std::string _user_id,
                             std::string _peer_id,
                             uint32_t _peer_type) {
    
    conversation_id.sender_user_id = _user_id;
    conversation_id.peer_id = _peer_id;
    conversation_id.peer_type = _peer_type;
  }
  
  int ParseFrom(db::QueryAnswer& answ) override;
  bool SerializeToQuery(std::string& query_string) const override;
  
  ConversationID conversation_id;
  int is_duplication {-1};
};

//////////////////////////////////////////////////////////////////////////////////////////
struct CreateUserDialog : public BaseSqlQuery {
  CreateUserDialog(UserDialogEntity& _dialog)
    : dialog(_dialog) {}
  
  bool SerializeToQuery(std::string& query_string) const override;
  
  UserDialogEntity& dialog;
};

//////////////////////////////////////////////////////////////////////////////////////////
struct LoadUserDialogList : public QueryWithResult {
  LoadUserDialogList(std::string _user_id,
                  uint64_t _loaded_time,
                  int _load_mode,
                  uint32_t _load_limit,
                  UserDialogEntityList& _dialogs)
    : user_id(_user_id),
      loaded_time(_loaded_time),
      load_mode(_load_mode),
      load_limit(_load_limit),
      dialog_list(_dialogs) {}
  
  bool SerializeToQuery(std::string& query_string) const override;
  int ParseFrom(db::QueryAnswer& answ) override;

  std::string user_id; // 用户ID
  uint64_t loaded_time;
  int load_mode;
  uint32_t load_limit;

  UserDialogEntityList& dialog_list;
};

#endif // BIZ_MODEL_USER_DIALOG_MODEL_H_
