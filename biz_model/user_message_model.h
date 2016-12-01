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

#ifndef BIZ_MODEL_USER_MESSAGE_MODEL_H_
#define BIZ_MODEL_USER_MESSAGE_MODEL_H_

#include "nebula/storage/storage_util.h"
#include "biz_model/base_biz_model_data.h"

//////////////////////////////////////////////////////////////////////////////////////////
struct StoreUserShortMessage : public BaseSqlQuery {
  StoreUserShortMessage(MessageEntity& message)
    : user_message(message) {}
  
  bool SerializeToQuery(std::string& query_string) const override;

  MessageEntity& user_message;
};

//class StoreStoreUserShortMessageOp : public DBBaseObject {
//public:
//  StoreStoreUserShortMessageOp() = default;
//  
//  // DBBaseObject
//  bool AddNew(DBResource& data) override;
//};

//////////////////////////////////////////////////////////////////////////////////////////
struct LoadUserMessageList  : public QueryWithResult {
  LoadUserMessageList(std::string _user_id,
                      uint64_t _received_max_message_seq,
                      MessageEntityList& _message_list)
    : user_id(_user_id),
      received_max_message_seq(_received_max_message_seq),
      message_list(_message_list) {}
  
  bool SerializeToQuery(std::string& query_string) const override;
  int ParseFrom(db::QueryAnswer& answ) override;
  
  std::string user_id;
  uint64_t received_max_message_seq;
  MessageEntityList& message_list;
};

//class LoadUserMessagesOp : public DBBaseObject {
//public:
//  LoadUserMessagesOp() = default;
//  
//  // DBBaseObject
//  bool Load(DBResource& data) override;
//};

//////////////////////////////////////////////////////////////////////////////////////////
struct LoadUserDialogMessageList  : public QueryWithResult {
  LoadUserDialogMessageList(std::string _user_id,
                            std::string _peer_id,
                            uint32_t _peer_type,
                            MessageEntityList& _message_list)
  : message_list(_message_list) {
    cid.sender_user_id = _user_id;
    cid.peer_id = _peer_id;
    cid.peer_type = _peer_type;
  }
  
  bool SerializeToQuery(std::string& query_string) const override;
  int ParseFrom(db::QueryAnswer& answ) override;
  
  ConversationID cid;
  MessageEntityList& message_list;
};

#endif
