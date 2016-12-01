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

#ifndef BIZ_MODEL_HISTORY_MESSAGE_MODEL_H_
#define BIZ_MODEL_HISTORY_MESSAGE_MODEL_H_

#include "nebula/storage/storage_util.h"
#include "biz_model/base_biz_model_data.h"

//////////////////////////////////////////////////////////////////////////////////////////
// 去重
struct CheckMessageDuplication : public QueryWithResult {
  CheckMessageDuplication(ConversationID& cid, uint64_t rid)
    : conversation_id(cid), client_message_id(rid) {}
  
  CheckMessageDuplication(std::string _user_id,
                          std::string _peer_id,
                          uint32_t _peer_type,
                          uint64_t rid)
    : client_message_id(rid) {
      
    conversation_id.sender_user_id = _user_id;
    conversation_id.peer_id = _peer_id;
    conversation_id.peer_type = _peer_type;
  }
  
  int ParseFrom(db::QueryAnswer& answ) override;
  bool SerializeToQuery(std::string& query_string) const override;

  ConversationID conversation_id;
  uint64_t client_message_id;
  int is_duplication {-1};
};

//class CheckMessageDuplicationOp : public DBBaseObject {
//public:
//  CheckMessageDuplicationOp() = default;
//  
//  // DBBaseObject
//  bool Load(DBResource& data) override;
//};

// bool CheckMessageDuplication(const ConversationID& cid, uint64_t client_message_id) override;

//////////////////////////////////////////////////////////////////////////////////////////
struct StoreHistoryMessage : public BaseSqlQuery {
  StoreHistoryMessage(MessageEntity& message)
    : history_message(message) {}
  
  bool SerializeToQuery(std::string& query_string) const override;

  MessageEntity& history_message;
};

//class StoreHistoryMessageOp : public DBBaseObject {
//public:
//  StoreHistoryMessageOp() = default;
//  
//  // DBBaseObject
//  bool AddNew(DBResource& data) override;
//};

//////////////////////////////////////////////////////////////////////////////////////////
struct LoadHistoryMessageList : public QueryWithResult {
  LoadHistoryMessageList(std::list<uint64_t>& _message_id_list, MessageEntityList& _message_list)
    : message_id_list(_message_id_list), message_list(_message_list) {}
  
  int ParseFrom(db::QueryAnswer& answ) override;
  bool SerializeToQuery(std::string& query_string) const override;
  
  std::list<uint64_t>& message_id_list;
  MessageEntityList& message_list;
};

//class LoadMessageListOp : public DBBaseObject {
//public:
//  LoadMessageListOp() = default;
//  
//  // DBBaseObject
//  bool Load(DBResource& data) override;
//};

#endif
