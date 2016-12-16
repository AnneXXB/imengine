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

// TODO(@benqi): 使用zrpc-code-gen代码生成工具自动生成服务框架代码

#include "messenger/messenger_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

// #include "proto/zproto/zproto_api_message_types.h"

#include "dal/user_dao.h"
#include "dal/history_message_dao.h"
#include "dal/user_message_dao.h"
#include "dal/user_dialog_dao.h"
#include "dal/sequence_dao.h"
#include "dal/group_dao.h"
#include "dal/group_user_dao.h"

/*

int MessengerServiceImpl::SendMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response) {
  // 检查request
  // TODO(@benqi): 回滚
  const auto& message_data = request.message_data();
  int r = HistoryMessageDAO::GetInstance().CheckExists(request.message_data().sender_user_id(),
                                                       request.message_data().peer().id(),
                                                       request.message_data().peer().type(),
                                                       request.message_data().client_message_id());
  
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
  if (message_entity.peer_type == zproto::PRIVATE) {
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
    forward.add_not_send_conn_ids(session_id()); //request->session_id());
    
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
  response->set_seq(sender_message_seq);
  response->set_created(created_at);
  
  return 0;
}

int MessengerServiceImpl::MessageSync(const zproto::MessageSyncReq& request, zproto::MessageSyncRsp* response) {
  std::string user_id = "benqi@zhazha";
  uint64_t received_max_seq = request.received_max_seq();
  
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
  
  for (auto& v : history_message_list) {
    auto message_data = response->add_message_data();
    message_data->set_message_id(v->id);
    message_data->set_sender_user_id(v->sender_user_id);
    message_data->mutable_peer()->set_id(v->peer_id);
    message_data->mutable_peer()->set_type((zproto::PeerType)v->peer_type);
    message_data->set_client_message_id(v->client_message_id);
  }

  return 0;
}

int MessengerServiceImpl::LoadHistoryMessage(const zproto::LoadHistoryMessageReq& request, zproto::LoadHistoryMessageRsp* response) {
  std::string user_id = "benqi@zhazha";
  // uint64_t received_max_seq = (*message_sync_req)->received_max_seq();
  
  UserMessageDOList user_message_list;
  UserMessageDAO::GetInstance().LoadUserDialogMessageList(user_id,
                                                          request.peer().id(),
                                                          request.peer().type(),
                                                          user_message_list);
  // TODO(@benqi): 出错
  
  std::list<uint64_t> message_ids;
  for (auto& v : user_message_list) {
    message_ids.push_back(v->message_id);
  }
  
  HistoryMessageDOList history_message_list;
  HistoryMessageDAO::GetInstance().LoadHistoryMessageList(message_ids, history_message_list);
  // TODO(@benqi): 出错
  
  for (auto& v : history_message_list) {
    auto message_data = response->add_history();
    message_data->set_message_id(v->id);
    message_data->set_sender_user_id(v->sender_user_id);
    message_data->mutable_peer()->set_id(v->peer_id);
    message_data->mutable_peer()->set_type((zproto::PeerType)v->peer_type);
    message_data->set_client_message_id(v->client_message_id);
  }
  
  return 0;
}

int MessengerServiceImpl::LoadDialogs(const zproto::LoadDialogsReq& request, zproto::LoadDialogsRsp* response) {
  std::string user_id = "benqi@zhazha";
  
  UserDialogDOList dialog_list;
  UserDialogDAO::GetInstance().LoadUserDialogList(user_id,
                                                  request.date(),
                                                  request.load_mode(),
                                                  request.limit(),
                                                  dialog_list);
  // TODO(@benqi): 出错
  
  for (auto & d : dialog_list) {
    auto peer = response->add_dialogs()->mutable_peer();
    peer->set_id(d->peer_id);
    peer->set_type((zproto::PeerType)d->peer_type);
  }
  
  return 0;
}

int MessengerServiceImpl::CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response) {
  auto r = GroupDAO::GetInstance().CheckExists(request.creator_user_id(),
                                               request.client_group_id());
  // TODO(@benqi):
  
  GroupDO group_entity;
  GroupUserDOList group_member_list;
  auto now = NowInMsecTime();
  
  group_entity.group_id = folly::to<std::string>(GetNextIDBySnowflake());
  group_entity.app_id = 1;
  group_entity.creator_user_id = request.creator_user_id();
  group_entity.client_group_id = request.client_group_id();
  group_entity.title = request.title();
  group_entity.status = 1;
  group_entity.created_at = now;
  group_entity.updated_at = now;
  
  for (int i=0; i<request.user_ids_size(); ++i) {
    auto group_memeber = std::make_shared<GroupUserDO>();
    group_memeber->group_id = group_entity.group_id;
    group_memeber->user_id = request.user_ids(i);
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
  
  response->set_seq(GetNextIDBySnowflake());
  response->set_created(now);
  auto group = response->mutable_group();
  group->set_group_id(group_entity.group_id);
  group->set_title(group_entity.title);
  for (auto m : group_member_list) {
    auto member = group->add_members();
    member->set_user_id(m->user_id);
    member->set_inviter_uid(m->inviter_user_id);
    member->set_date(m->created_at);
    member->set_is_admin(m->is_admin == 1);
  }
  response->mutable_user_ids()->CopyFrom(request.user_ids());
  
  return 0;
}
*/

