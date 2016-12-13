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
#include "nebula/base/id_util.h"

#include "proto/zproto/zproto_api_message_types.h"

#include "dal/user_dao.h"
#include "dal/history_message_dao.h"
#include "dal/user_message_dao.h"
#include "dal/user_dialog_dao.h"
#include "dal/sequence_dao.h"
#include "dal/group_dao.h"
#include "dal/group_user_dao.h"

//#include "biz_model/user_model.h"
//#include "biz_model/history_message_model.h"
//#include "biz_model/user_message_model.h"
//#include "biz_model/sequence_model.h"
//#include "biz_model/user_dialog_model.h"
//#include "biz_model/group_model.h"

// #include "biz_model/model_main_manager.h"

// #include "biz_model/login_manager.h"

void MessengerRpcRegister() {
  ZRpcUtil::Register("zproto.SendMessageReq", DoSendMessage);
  ZRpcUtil::Register("zproto.MessageSyncReq", DoMessageSync);
  ZRpcUtil::Register("zproto.LoadHistoryMessageReq", DoLoadHistoryMessage);
  ZRpcUtil::Register("zproto.LoadDialogsReq", DoLoadDialogs);
  ZRpcUtil::Register("zproto.CreateGroupReq", DoCreateGroup);
}

//////////////////////////////////////////////////////////////////////////////////////////////
int DoSendMessageInternal(uint64_t conn_id, const zproto::SendMessageReq& send_message_req, zproto::SeqDateRsp* seq_date_rsp) {
  // 检查send_message_req
  // TODO(@benqi): 回滚
  const auto& message_data = send_message_req.message_data();
  int r = HistoryMessageDAO::GetInstance().CheckExists(send_message_req.message_data().sender_user_id(),
                                               send_message_req.message_data().peer().id(),
                                               send_message_req.message_data().peer().type(),
                                               send_message_req.message_data().client_message_id());
  
  // SequenceModel sequence;
  auto message_peer_seq = SequenceDAO::GetInstance().GetNextID(message_data.sender_user_id());

  HistoryMessageDO message_entity;
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

  auto message_id = HistoryMessageDAO::GetInstance().Create(message_entity);
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
    sender_message_seq = SequenceDAO::GetInstance().GetNextID(message_entity.sender_user_id);
    message_entity.message_seq = sender_message_seq;
    message_entity.user_id = message_entity.sender_user_id;
    
    UserMessageDO user_message;

    user_message.message_seq = sender_message_seq;
    user_message.user_id = message_entity.sender_user_id;
    user_message.message_id = message_entity.message_id;
    user_message.sender_user_id = message_entity.sender_user_id;
    user_message.peer_id = message_entity.peer_id;
    user_message.peer_type = message_entity.peer_type;
    user_message.message_peer_seq = message_entity.message_peer_seq;
    user_message.created_at = created_at;
    user_message.updated_at = created_at;
    
    auto iid = UserMessageDAO::GetInstance().Create(user_message);
    if (iid<0) {
      // TODO(@benqi):
    }
    
    // 接收者
    sender_message_seq = SequenceDAO::GetInstance().GetNextID(message_entity.peer_id);
    user_message.message_seq = sender_message_seq;
    user_message.user_id = message_entity.peer_id;
    iid = UserMessageDAO::GetInstance().Create(user_message);
    if (iid<0) {
      // TODO(@benqi):
    }
    
    // 创建会话
    
    // 正向
    // 检查会话是否存在
    r = UserDialogDAO::GetInstance().CheckExists(message_data.sender_user_id(),
                                                 message_data.peer().id(),
                                                 message_data.peer().type());
    // TODO(@benqi): 出错
    if (r == 0) {
      UserDialogDO user_dialog;
      user_dialog.user_id = message_data.sender_user_id();
      user_dialog.peer_id = message_data.peer().id();
      user_dialog.peer_type = message_data.peer().type();
      user_dialog.created_at = created_at;
      user_dialog.updated_at = created_at;
      
      iid = UserDialogDAO::GetInstance().Create(user_dialog);
      if (iid<0) {
        // TODO(@benqi):
      }
    }
    
    // 反向
    // 检查会话是否存在
    r = UserDialogDAO::GetInstance().CheckExists(message_data.peer().id(),
                                                 message_data.sender_user_id(),
                                                 message_data.peer().type());
    if (r == 0) {
      UserDialogDO user_dialog;
      user_dialog.user_id = message_data.peer().id();
      user_dialog.peer_id = message_data.sender_user_id();
      user_dialog.peer_type = message_data.peer().type();
      user_dialog.created_at = created_at;
      user_dialog.updated_at = created_at;

      iid = UserDialogDAO::GetInstance().Create(user_dialog);
      if (iid<0) {
        // TODO(@benqi):
      }
    }
    
    // TODO(@benqi): 未读计数
    
    // 转发消息
    zproto::ForwardMessageReq forward;
    forward.mutable_message_data()->CopyFrom(message_data);
    forward.add_not_send_conn_ids(conn_id); //request->session_id());
    
    ZRpcUtil::DoClientCall("push_client", MakeRpcRequest(forward))
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
  
  // zproto::SeqDateRsp seq_date_rsp;
  
  // ACK
  seq_date_rsp->set_seq(sender_message_seq);
  seq_date_rsp->set_created(created_at);

  return 0;
}

ProtoRpcResponsePtr DoSendMessage(RpcRequestPtr request) {
  CAST_RPC_REQUEST(SendMessageReq, send_message_req);
  zproto::SeqDateRsp seq_date_rsp;
  
  DoSendMessageInternal(request->session_id(), send_message_req, &seq_date_rsp);
  
  return MakeRpcOK(seq_date_rsp);
}

//////////////////////////////////////////////////////////////////////////////////////////////
ProtoRpcResponsePtr DoMessageSync(RpcRequestPtr request) {
  CAST_RPC_REQUEST(MessageSyncReq, message_sync_req);
  LOG(INFO) << "DoMessageSync - message_sync_req: " << message_sync_req.Utf8DebugString();
  
  std::string user_id = "benqi@zhazha";
  uint64_t received_max_seq = message_sync_req.received_max_seq();
  
  UserMessageDOList user_message_list;
  UserMessageDAO::GetInstance().LoadUserMessageList(user_id, received_max_seq, user_message_list);
  // TODO(@benqi): 出错

  std::list<uint64_t> message_ids;
  for (auto& v : user_message_list) {
    message_ids.push_back(v->message_id);
  }
  
  HistoryMessageDOList history_message_list;
  HistoryMessageDAO::GetInstance().LoadHistoryMessageList(message_ids, history_message_list);
  // TODO(@benqi): 出错
  
  zproto::MessageSyncRsp message_sync_rsp;
  // auto response = std::make_shared<ApiRpcOk<zproto::MessageSyncRsp>>();
  // response->set_session_id(request->session_id());
  // response->set_req_message_id(request->message_id());
  
  for (auto& v : history_message_list) {
    auto message_data = message_sync_rsp.add_message_data();
    message_data->set_message_id(v->id);
    message_data->set_sender_user_id(v->sender_user_id);
    message_data->mutable_peer()->set_id(v->peer_id);
    message_data->mutable_peer()->set_type(v->peer_type);
    message_data->set_client_message_id(v->client_message_id);
  }
  
  LOG(INFO) << "DoMessageSync - rsp: " << message_sync_rsp.Utf8DebugString();
  return MakeRpcOK(message_sync_rsp);
}

ProtoRpcResponsePtr DoLoadHistoryMessage(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LoadHistoryMessageReq, load_history_message_req);
  LOG(INFO) << "DoLoadHistoryMessage - load_history_message_req: " << load_history_message_req.Utf8DebugString();
  
  std::string user_id = "benqi@zhazha";
  // uint64_t received_max_seq = (*message_sync_req)->received_max_seq();
  
  UserMessageDOList user_message_list;
  UserMessageDAO::GetInstance().LoadUserDialogMessageList(user_id,
                                                          load_history_message_req.peer().id(),
                                                          load_history_message_req.peer().type(),
                                                          user_message_list);
  // TODO(@benqi): 出错
  
  std::list<uint64_t> message_ids;
  for (auto& v : user_message_list) {
    message_ids.push_back(v->message_id);
  }
  
  HistoryMessageDOList history_message_list;
  HistoryMessageDAO::GetInstance().LoadHistoryMessageList(message_ids, history_message_list);
  // TODO(@benqi): 出错
  
  zproto::LoadHistoryMessageRsp load_history_message_rsp;
  
  for (auto& v : history_message_list) {
    auto message_data = load_history_message_rsp.add_history();
    message_data->set_message_id(v->id);
    message_data->set_sender_user_id(v->sender_user_id);
    message_data->mutable_peer()->set_id(v->peer_id);
    message_data->mutable_peer()->set_type(v->peer_type);
    message_data->set_client_message_id(v->client_message_id);
  }
  
  LOG(INFO) << "DoLoadHistoryMessage - rsp: " << load_history_message_rsp.Utf8DebugString();
  return MakeRpcOK(load_history_message_rsp);
}

ProtoRpcResponsePtr DoLoadDialogs(RpcRequestPtr request) {
  CAST_RPC_REQUEST(LoadDialogsReq, load_dialogs_req);
  LOG(INFO) << "DoLoadDialogs - load_dialogs_req: " << load_dialogs_req.Utf8DebugString();

  std::string user_id = "benqi@zhazha";

  UserDialogDOList dialog_list;
  UserDialogDAO::GetInstance().LoadUserDialogList(user_id,
                                                  load_dialogs_req.date(),
                                                  load_dialogs_req.load_mode(),
                                                  load_dialogs_req.limit(),
                                                  dialog_list);
  // TODO(@benqi): 出错

  zproto::LoadDialogsRsp load_dialogs_rsp;

  for (auto & d : dialog_list) {
    auto peer = load_dialogs_rsp.add_dialogs()->mutable_peer();
    peer->set_id(d->peer_id);
    peer->set_type(d->peer_type);
  }
  return MakeRpcOK(load_dialogs_rsp);
}

ProtoRpcResponsePtr DoCreateGroup(RpcRequestPtr request) {
  CAST_RPC_REQUEST(CreateGroupReq, create_group_req);
  LOG(INFO) << "DoCreateGroup - create_group_req: " << create_group_req.Utf8DebugString();
  
  auto r = GroupDAO::GetInstance().CheckExists(create_group_req.creator_user_id(),
                                               create_group_req.client_group_id());
  // TODO(@benqi):
  
  GroupDO group_entity;
  GroupUserDOList group_member_list;
  auto now = NowInMsecTime();
  
  group_entity.group_id = folly::to<std::string>(GetNextIDBySnowflake());
  group_entity.app_id = 1;
  group_entity.creator_user_id = create_group_req.creator_user_id();
  group_entity.client_group_id = create_group_req.client_group_id();
  group_entity.title = create_group_req.title();
  group_entity.status = 1;
  group_entity.created_at = now;
  group_entity.updated_at = now;

  for (int i=0; i<create_group_req.user_ids_size(); ++i) {
    auto group_memeber = std::make_shared<GroupUserDO>();
    group_memeber->group_id = group_entity.group_id;
    group_memeber->user_id = create_group_req.user_ids(i);
    group_memeber->inviter_user_id = group_entity.creator_user_id;
    if (group_memeber->user_id == group_memeber->inviter_user_id) {
      group_memeber->is_admin = 1;
    } else {
      group_memeber->is_admin = 0;
    }
    group_memeber->status = 1;

    group_memeber->joined_at = now;
    group_memeber->created_at = now;
    group_memeber->updated_at = now;
    
    group_member_list.push_back(group_memeber);
  }
  
  auto iid = GroupDAO::GetInstance().Create(group_entity);
  if (iid<0) {
    // TODO(@benqi):
  }
  
  iid = GroupUserDAO::GetInstance().Create(group_member_list);
  if (iid<0) {
    // TODO(@benqi):
  }
  
  zproto::CreateGroupRsp create_group_rsp;

  create_group_rsp.set_seq(GetNextIDBySnowflake());
  create_group_rsp.set_created(now);
  auto group = create_group_rsp.mutable_group();
  group->set_group_id(group_entity.group_id);
  group->set_title(group_entity.title);
  for (auto m : group_member_list) {
    auto member = group->add_members();
    member->set_user_id(m->user_id);
    member->set_inviter_uid(m->inviter_user_id);
    member->set_date(m->created_at);
    member->set_is_admin(m->is_admin == 1);
  }
  
  create_group_rsp.mutable_user_ids()->CopyFrom(create_group_req.user_ids());
  return MakeRpcOK(create_group_rsp);
}
