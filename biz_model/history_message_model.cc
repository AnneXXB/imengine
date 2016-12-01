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

#include "biz_model/history_message_model.h"

#include <folly/Format.h>
#include <folly/String.h>

#include "nebula/storage/conn_pool_manager.h"

//////////////////////////////////////////////////////////////////////////////////////////
int CheckMessageDuplication::ParseFrom(db::QueryAnswer& answ) {
  is_duplication = 1;
  return BREAK;
}

bool CheckMessageDuplication::SerializeToQuery(std::string& query_string) const {
  query_string = folly::sformat("SELECT id FROM history_messages WHERE sender_user_id='{}' AND client_message_id={} LIMIT 1",
                                conversation_id.sender_user_id,
                                client_message_id);
  return true;
}

//bool CheckMessageDuplicationResource::ParseFromDatabase(const db::QueryAnswer& answ) {
//  is_duplication = true;
//  return true;
//}

//bool CheckMessageDuplicationOp::Load(DBResource& data) {
//  auto entity = dynamic_cast<CheckMessageDuplicationResource*>(&data);
//  CHECK(entity);
//  
//  db::QueryParam p;
//  entity->SerializeToDatabase(p);
//
//  std::string sql = folly::sformat("SELECT id FROM history_messages WHERE sender_user_id={} AND client_message_id={} LIMIT 1",
//                                   entity->conversation_id.sender_user_id,
//                                   entity->client_message_id);
//  
//  db::ScopedPtr_DatabaseConnection db_conn(db_conn_pool_);
//  std::unique_ptr<db::QueryAnswer> answ(db_conn->Query(sql));
//  // bool is_authed = true;
//  if (answ.get() != NULL) {
//    if (answ->FetchRow()) {
//      // 没查到
//      entity->is_duplication = true;
//    } else {
//      entity->is_duplication = false;
//    }
//  } else {
//    return false;
//  }
//  
//  return true;
//}

//////////////////////////////////////////////////////////////////////////////////////////
bool StoreHistoryMessage::SerializeToQuery(std::string& query_string) const {
  //std::string sql;
  db::QueryParam p;
  p.AddParam(history_message.sender_user_id.c_str());
  p.AddParam(history_message.peer_id.c_str());
  p.AddParam(&history_message.peer_type);
  p.AddParam(&history_message.client_message_id);
  p.AddParam(&history_message.message_peer_seq);
  p.AddParam(&history_message.message_content_type);
  p.AddParamEsc(history_message.message_content_data.c_str(),
                static_cast<int>(history_message.message_content_data.length()));
  p.AddParamEsc(history_message.passthrough_data.c_str(),
                static_cast<int>(history_message.passthrough_data.length()));
  p.AddParam(&history_message.created_at);
  p.AddParam(&history_message.updated_at);

  db::MakeQueryString("INSERT INTO history_messages"
                      "(sender_user_id,peer_id,peer_type,client_message_id,message_peer_seq,message_content_type,"
                      "message_content_data,passthrough_data,status,created_at,updated_at)"
                      " VALUES "
                      "(:1,:2,:3,:4,:5,:6,:7,:8,1,:9,:10)",
                      &p,
                      &query_string);
  return true;
}

//bool StoreHistoryMessage::SerializeToDatabase(db::QueryParam& param) const {
//  param.AddParam(&history_message.sender_user_id);
//  param.AddParam(&history_message.peer_id);
//  param.AddParam(&history_message.peer_type);
//  param.AddParam(&history_message.client_message_id);
//  param.AddParamEsc(history_message.message_content_data.c_str(),
//                     static_cast<int>(history_message.message_content_data.length()));
//  param.AddParamEsc(history_message.passthrough_data.c_str(),
//                     static_cast<int>(history_message.passthrough_data.length()));
//  param.AddParam(&history_message.created_at);
//  param.AddParam(&history_message.updated_at);
//  
//  return true;
//}

//bool StoreHistoryMessageOp::AddNew(DBResource& data) {
//  auto entity = dynamic_cast<StoreHistoryMessageResource*>(&data);
//  CHECK(entity);
//
//  db::QueryParam p;
//  entity->SerializeToDatabase(p);
//  
//  std::string sql;
//  db::MakeQueryString("INSERT INTO history_messages"
//                      "(sender_user_id,peer_id,peer_type,client_message_id,message_peer_seq,message_content_type,"
//                      "message_content_data,passthrough_data,status,created_at,updated_at)"
//                      " VALUES "
//                      "(:1,:2,:3,:4,:5,:6,:7,:8,1,:9,:10)",
//                      &p,
//                      &sql);
//  
//  db::ScopedPtr_DatabaseConnection db_conn(db_conn_pool_);
//  entity->history_message.id = db_conn->ExecuteInsertID(sql);
//  return entity->history_message.id;
//}

//////////////////////////////////////////////////////////////////////////////////////////
bool LoadHistoryMessageList::SerializeToQuery(std::string& query_string) const {
  std::string message_ids;
  folly::join("','", message_id_list, message_ids);
  query_string = folly::sformat("SELECT id,sender_user_id,peer_id,peer_type,client_message_id,message_peer_seq,"
                                "message_content_type,message_content_data,passthrough_data,status,created_at,updated_at "
                                "FROM history_messages WHERE id in('{}')",
                                message_ids);
  
  LOG(INFO) << "LoadHistoryMessageList - query_string: " << query_string;
  return true;
}

int LoadHistoryMessageList::ParseFrom(db::QueryAnswer& answ) {
  auto message = std::make_shared<MessageEntity>();
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
}

//bool LoadMessageListOp::Load(DBResource& data) {
//  auto entity = dynamic_cast<LoadMessageListResource*>(&data);
//  CHECK(entity);
//
//  std::string message_ids;
//  folly::join(',', entity->message_ids, message_ids);
//  std::string sql = folly::sformat("SELECT id,sender_user_id,peer_id,peer_type,client_message_id,message_peer_seq,"
//                                   "message_content_type,message_content_data,passthrough_data,status,created_at,updated_at "
//                                   "FROM id in({})",
//                                   message_ids);
//  
//  db::ScopedPtr_DatabaseConnection db_conn(db_conn_pool_);
//  std::unique_ptr<db::QueryAnswer> answ(db_conn->Query(sql));
//  // bool is_authed = true;
//  if (answ.get() != NULL) {
//    while (answ->FetchRow()) {
//      entity->ParseFromDatabase(*answ);
//    }
//  } else {
//    return false;
//  }
//  
//  return true;
//}

