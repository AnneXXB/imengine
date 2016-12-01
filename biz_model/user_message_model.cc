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

#include "biz_model/user_message_model.h"

#include <folly/Format.h>

#include "nebula/storage/conn_pool_manager.h"

//////////////////////////////////////////////////////////////////////////////////////////
bool StoreUserShortMessage::SerializeToQuery(std::string& query_string) const {
  db::QueryParam p;
  p.AddParam(user_message.user_id.c_str());
  p.AddParam(&user_message.message_seq);
  p.AddParam(&user_message.message_id);
  p.AddParam(user_message.sender_user_id.c_str());
  p.AddParam(user_message.peer_id.c_str());
  p.AddParam(&user_message.peer_type);
  p.AddParam(&user_message.message_peer_seq);
  p.AddParam(&user_message.created_at);
  p.AddParam(&user_message.updated_at);
  
  db::MakeQueryString("INSERT INTO user_messages"
                      "(user_id,message_seq,message_id,sender_user_id,peer_id,peer_type,message_peer_seq,status,created_at,updated_at)"
                      " VALUES "
                      "(:1,:2,:3,:4,:5,:6,:7,1,:8,:9)",
                      &p,
                      &query_string);

  return !query_string.empty();
}

//bool StoreUserShortMessageResource::SerializeToDatabase(db::QueryParam& param) const {
//  
//  return true;
//}
//
//bool StoreStoreUserShortMessageOp::AddNew(DBResource& data) {
//  auto entity = dynamic_cast<StoreUserShortMessageResource*>(&data);
//  CHECK(entity);
//  
//  db::QueryParam p;
//  entity->SerializeToDatabase(p);
//  
//  std::string sql;
//  db::MakeQueryString("INSERT INTO user_messages"
//                      "(user_id,message_seq,message_id,sender_user_id,peer_id,peer_type,message_peer_seq,status,created_at,updated_at)"
//                      " VALUES "
//                      "(:1,:2,:3,:4,:5,:6,:7,1,:8,:9)",
//                      &p,
//                      &sql);
//  
//  db::ScopedPtr_DatabaseConnection db_conn(db_conn_pool_);
//  entity->user_message.id = db_conn->ExecuteInsertID(sql);
//  return entity->user_message.id;
//}

//////////////////////////////////////////////////////////////////////////////////////////
bool LoadUserMessageList::SerializeToQuery(std::string& query_string) const {
  query_string = folly::sformat("SELECT message_id,message_seq FROM user_messages WHERE user_id='{}' AND message_seq>{} LIMIT 200",
                                user_id,
                                received_max_message_seq);
  
  LOG(INFO) << "LoadUserMessageList - query_string: " << query_string;

  return !query_string.empty();
}

int LoadUserMessageList::ParseFrom(db::QueryAnswer& answ) {
  auto message = std::make_shared<MessageEntity>();
  message->user_id = user_id;
  answ.GetColumn(0, &message->message_id);
  answ.GetColumn(1, &message->message_seq);
  message_list.push_back(message);
  
  return CONTINUE;
}

//bool UserMessageListResource::ParseFromDatabase(db::QueryAnswer& answ) {
//  auto message = std::make_shared<UserMessageEntity>();
//  message->user_id = user_id;
//  answ.GetColumn(0, &message->message_id);
//  answ.GetColumn(1, &message->message_seq);
//  message_list.push_back(message);
//  return true;
//}
//
//bool UserMessageListResource::SerializeToDatabase(db::QueryParam& param) const {
//  param.AddParam(&user_id);
//  param.AddParam(&received_max_message_seq);
//  return true;
//}
//
//bool LoadUserMessagesOp::Load(DBResource& data) {
//  auto entity = dynamic_cast<UserMessageListResource*>(&data);
//  CHECK(entity);
//  
//  std::string sql = folly::sformat("SELECT message_id,message_seq FROM user_messages WHERE user_id={} AND message_seq>{} LIMIT 200",
//                                   entity->user_id,
//                                   entity->received_max_message_seq);
//  
//  bool rv = true;
//  db::ScopedPtr_DatabaseConnection db_conn(db_conn_pool_);
//  std::unique_ptr<db::QueryAnswer> answ(db_conn->Query(sql));
//  // bool is_authed = true;
//  if (answ.get() != NULL) {
//    while (!answ->FetchRow()) {
//      entity->ParseFromDatabase(*answ);
//    }
//  } else {
//    rv = false;
//  }
//  
//  return rv;
//  return true;
//}

bool LoadUserDialogMessageList::SerializeToQuery(std::string& query_string) const {
  query_string = folly::sformat("SELECT message_id,message_seq FROM user_messages WHERE user_id='{}' AND peer_id='{}' AND peer_type={} LIMIT 200",
                                cid.sender_user_id,
                                cid.peer_id,
                                cid.peer_type);
  LOG(INFO) << "LoadUserDialogMessageList - query_string: " << query_string;
  
  return !query_string.empty();
}

int LoadUserDialogMessageList::ParseFrom(db::QueryAnswer& answ) {
  auto message = std::make_shared<MessageEntity>();
  message->user_id = cid.sender_user_id;
  answ.GetColumn(0, &message->message_id);
  answ.GetColumn(1, &message->message_seq);
  message_list.push_back(message);
  
  return CONTINUE;
}

