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

#include "messenger/rpc_messenger_service.h"

#include "nebula/base/time_util.h"
#include "proto/api_message_box.h"

#include "biz_model/user_model.h"
#include "biz_model/history_message_model.h"
#include "biz_model/user_message_model.h"
#include "biz_model/sequence_model.h"
#include "biz_model/user_dialog_model.h"


// #include "biz_model/model_main_manager.h"

// #include "biz_model/login_manager.h"

ProtoRpcResponsePtr DoSendMessage(RpcRequestPtr request) {
  auto send_message_req = ToApiRpcRequest<zproto::SendMessageReq>(request);
  // 检查send_message_req
  // TODO(@benqi): 回滚
  const auto& message_data = (*send_message_req)->message_data();
  CheckMessageDuplication check_duplication((*send_message_req)->message_data().sender_user_id(),
         (*send_message_req)->message_data().peer().id(),
         (*send_message_req)->message_data().peer().type(),
         (*send_message_req)->message_data().client_message_id());
  
  if (0 != SqlQuery("nebula_engine", check_duplication)) {
    // TODO(@benqi): 出错
  }
  
  SequenceModel sequence;
  auto message_peer_seq = sequence.GetNextID(message_data.sender_user_id());

  MessageEntity message_entity;
  message_entity.sender_user_id = message_data.sender_user_id();
  message_entity.peer_id = message_data.peer().id();
  message_entity.peer_type = message_data.peer().type();
  message_entity.message_peer_seq = message_peer_seq;
  message_entity.client_message_id = message_data.client_message_id();
  message_entity.message_content_type = message_data.message_type();
  // 这个地方比较重
  message_entity.message_content_data = message_data.message_content();
  message_entity.passthrough_data = message_data.passthrough_data();
  message_entity.status = 1;
  auto created_at = NowInMsecTime();
  message_entity.created_at = created_at;
  message_entity.updated_at = created_at;

  StoreHistoryMessage storage_history_message(message_entity);
  auto message_id = SqlExecuteInsertID("nebula_engine", storage_history_message);
  if (message_id<0) {
    // TODO(@benqi):
  }
  
  uint64_t sender_message_seq = 0;
  
  message_entity.message_id = message_id;
  // 创建用户消息
  if (message_entity.peer_type == zproto::EnumHelper::PRIVATE) {
    // 单聊
    // 创建者
    // biz_model::UserMessageEntity user_message_entity;
    // 发送者
    sender_message_seq = sequence.GetNextID(message_entity.sender_user_id);
    message_entity.message_seq = sender_message_seq;
    message_entity.user_id = message_entity.sender_user_id;
    StoreUserShortMessage store_user_short_message(message_entity);
    auto iid = SqlExecuteInsertID("nebula_engine", store_user_short_message);
    if (iid<0) {
      // TODO(@benqi):
    }
    
    // 接收者
    sender_message_seq = sequence.GetNextID(message_entity.peer_id);
    message_entity.message_seq = sender_message_seq;
    message_entity.user_id = message_entity.peer_id;
    iid = SqlExecuteInsertID("nebula_engine", store_user_short_message);
    if (iid<0) {
      // TODO(@benqi):
    }
    
    // 创建会话
    
    // 正向
    // 检查会话是否存在
    CheckUserDialogDuplication check_dialog_duplication(message_data.sender_user_id(),
                                                        message_data.peer().id(),
                                                        message_data.peer().type());

    if (0 != SqlQuery("nebula_engine", check_dialog_duplication)) {
      // TODO(@benqi): 出错
    }

    if (check_dialog_duplication.is_duplication != 1) {
      UserDialogEntity user_dialog;
      user_dialog.user_id = message_data.sender_user_id();
      user_dialog.peer_id = message_data.peer().id();
      user_dialog.peer_type = message_data.peer().type();
      user_dialog.created_at = created_at;
      user_dialog.updated_at = created_at;
      
      CreateUserDialog create_user_dialog(user_dialog);
      iid = SqlExecuteInsertID("nebula_engine", create_user_dialog);
      if (iid<0) {
        // TODO(@benqi):
      }
    }
    
    // 反向
    // 检查会话是否存在
    check_dialog_duplication.is_duplication = -1;
    check_dialog_duplication.conversation_id.peer_id = message_data.sender_user_id();
    check_dialog_duplication.conversation_id.sender_user_id = message_data.peer().id();
    
    if (0 != SqlQuery("nebula_engine", check_dialog_duplication)) {
      // TODO(@benqi): 出错
    }

    if (check_dialog_duplication.is_duplication != 1) {
      UserDialogEntity user_dialog;
      user_dialog.user_id = message_data.peer().id();
      user_dialog.peer_id = message_data.sender_user_id();
      user_dialog.peer_type = message_data.peer().type();
      user_dialog.created_at = created_at;
      user_dialog.updated_at = created_at;

      CreateUserDialog create_user_dialog(user_dialog);
      iid = SqlExecuteInsertID("nebula_engine", create_user_dialog);
      if (iid<0) {
        // TODO(@benqi):
      }
    }
    
    // TODO(@benqi): 未读计数
    
    // 转发消息
    auto forward = std::make_shared<ApiRpcRequest<zproto::ForwardMessageReq>>();
    (*forward)->mutable_message_data()->CopyFrom(message_data);
    (*forward)->add_not_send_conn_ids(request->session_id());
    
    ZRpcUtil::DoClientCall("push_client", forward)
    .within(std::chrono::milliseconds(5000))
    .then([](ProtoRpcResponsePtr rsp2) {
      CHECK(rsp2);
      LOG(INFO) << "push_client rsp: " << rsp2->ToString();
      // auto online_rep = ToApiRpcOk<zproto::ClientOnlineRsp>(rsp2);
      // LOG(INFO) << (*online_rep)->Utf8DebugString();
    });
  } else {
    // 群聊
    // TODO(@benqi): 麻烦
  }
  
  auto response = std::make_shared<ApiRpcOk<zproto::SeqDateRsp>>();
  response->set_session_id(request->session_id());
  response->set_req_message_id(request->message_id());

  (*response)->set_seq(sender_message_seq);
  (*response)->set_created(created_at);
  return response;
}

ProtoRpcResponsePtr DoMessageSync(RpcRequestPtr request) {
  auto message_sync_req = ToApiRpcRequest<zproto::MessageSyncReq>(request);
  LOG(INFO) << "DoMessageSync - message_sync_req: " << message_sync_req->ToString();
  
  std::string user_id = "benqi@zhazha";
  uint64_t received_max_seq = (*message_sync_req)->received_max_seq();
  
  MessageEntityList message_list;
  LoadUserMessageList load_message_list(user_id, received_max_seq, message_list);
  if (0 != SqlQuery("nebula_engine", load_message_list)) {
    // LOG(ERROR) << "";
    // TODO(@benqi): 出错
  }

  std::list<uint64_t> message_ids;
  for (auto& v : message_list) {
    message_ids.push_back(v->message_id);
  }
  
  message_list.clear();
  
  LoadHistoryMessageList load_history_message_list(message_ids, message_list);
  if (0 != SqlQuery("nebula_engine", load_history_message_list)) {
    // TODO(@benqi): 出错
  }
  
  auto response = std::make_shared<ApiRpcOk<zproto::MessageSyncRsp>>();
  response->set_session_id(request->session_id());
  response->set_req_message_id(request->message_id());
  
  for (auto& v : message_list) {
    auto message_data = (*response)->add_message_data();
    message_data->set_message_id(v->id);
    message_data->set_sender_user_id(v->sender_user_id);
    message_data->mutable_peer()->set_id(v->peer_id);
    message_data->mutable_peer()->set_type(v->peer_type);
    message_data->set_client_message_id(v->client_message_id);
  }
  
  LOG(INFO) << "DoMessageSync - rsp: " << (*response)->Utf8DebugString();
  return response;
}

ProtoRpcResponsePtr DoLoadHistoryMessage(RpcRequestPtr request) {
  auto load_history_message_req = ToApiRpcRequest<zproto::LoadHistoryMessageReq>(request);
  LOG(INFO) << "DoLoadHistoryMessage - load_history_message_req: " << load_history_message_req->ToString();
  
  std::string user_id = "benqi@zhazha";
  // uint64_t received_max_seq = (*message_sync_req)->received_max_seq();
  
  MessageEntityList message_list;
  LoadUserDialogMessageList load_message_list(user_id,
                                              (*load_history_message_req)->peer().id(),
                                              (*load_history_message_req)->peer().type(),
                                              message_list);
  if (0 != SqlQuery("nebula_engine", load_message_list)) {
    // LOG(ERROR) << "";
    // TODO(@benqi): 出错
  }
  
  std::list<uint64_t> message_ids;
  for (auto& v : message_list) {
    message_ids.push_back(v->message_id);
  }
  
  message_list.clear();
  
  LoadHistoryMessageList load_history_message_list(message_ids, message_list);
  if (0 != SqlQuery("nebula_engine", load_history_message_list)) {
    // TODO(@benqi): 出错
  }
  
  auto response = std::make_shared<ApiRpcOk<zproto::LoadHistoryMessageRsp>>();
  response->set_session_id(request->session_id());
  response->set_req_message_id(request->message_id());
  
  for (auto& v : message_list) {
    auto message_data = (*response)->add_history();
    message_data->set_message_id(v->id);
    message_data->set_sender_user_id(v->sender_user_id);
    message_data->mutable_peer()->set_id(v->peer_id);
    message_data->mutable_peer()->set_type(v->peer_type);
    message_data->set_client_message_id(v->client_message_id);
  }
  
  LOG(INFO) << "DoLoadHistoryMessage - rsp: " << (*response)->Utf8DebugString();
  return response;
}

ProtoRpcResponsePtr DoLoadDialogs(RpcRequestPtr request) {
  auto load_dialogs_req = ToApiRpcRequest<zproto::LoadDialogsReq>(request);
  LOG(INFO) << "DoLoadDialogs - load_dialogs_req: " << load_dialogs_req->ToString();

  std::string user_id = "benqi@zhazha";

  UserDialogEntityList dialog_list;
  LoadUserDialogList load_dialog_list(user_id,
                                      (*load_dialogs_req)->date(),
                                      (*load_dialogs_req)->load_mode(),
                                      (*load_dialogs_req)->limit(),
                                      dialog_list);
  
  if (0 != SqlQuery("nebula_engine", load_dialog_list)) {
    // LOG(ERROR) << "";
    // TODO(@benqi): 出错
  }

  auto response = std::make_shared<ApiRpcOk<zproto::LoadDialogsRsp>>();

  for (auto & d : dialog_list) {
    auto peer = (*response)->add_dialogs()->mutable_peer();
    peer->set_id(d->peer_id);
    peer->set_type(d->peer_type);
  }
  return response;
}
