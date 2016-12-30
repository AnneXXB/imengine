/*
 *  Copyright (c) 2016, https://github.com/nebula-im
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

#include "messenger/messaging_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"
//
//#include "proto/s2s/cc/servers.pb.h"
//
//#include "dal/user_dao.h"
//#include "dal/history_message_dao.h"
//#include "dal/user_message_dao.h"
//#include "dal/user_dialog_dao.h"
#include "dal/sequence_dao.h"

//#include "dal/group_dao.h"
#include "dal/group_user_dao.h"
//#include "dal/user_sequence_dao.h"
#include "biz_model/message_model.h"
#include "biz_model/dialog_model.h"
#include "biz_model/sequence_model.h"

int MessagingServiceImpl::SendMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response) {
  // auto& history_message_dao = HistoryMessageDAO::GetInstance();

  auto message_peer_seq = SequenceDAO::GetInstance().GetNextID(uid());

  int rv = MessageModel::GetInstance().CreateIfNotExists(uid(),
                                                         request.peer().type(),
                                                         request.peer().id(),
                                                         message_peer_seq,
                                                         request.rid(),
                                                         request.message().message_type(),
                                                         request.message().message_data(),
                                                         request.passthrough_data());
  
  if (rv==kErrDBError) {
    // TODO(@benqi): 区分数据库异常和重复问题
    LOG(ERROR) << "CreateIfNotExists - CheckExists DBError by uid: " << uid() << ", rid: " << request.rid();
    return kErrDBError;
  } else if (rv==kErrDBDup) {
    // 直接生成一个SEQ返回，
    // 幂等操作，如果History存在，则认为已经走完流程了。
    // 已经存在，直接返回
    LOG(WARNING) << "CreateIfNotExists - isexists by uid: " << uid() << ", rid: " << request.rid();
    response->set_seq(message_peer_seq);
    response->set_date(NowInMsecTime());
    return kErrOK;
  }
  
  std::list<std::string> uid_list;

  if (request.peer().type() == zproto::PEER_TYPE_PRIVATE) {
    // 创建会话
    rv = DialogModel::GetInstance().CreateIfNotExists(uid(), request.peer().type(), request.peer().id());
    // TODO(@benqi): 检查rv
    
    uid_list.push_back(uid());
    uid_list.push_back(request.peer().id());
  } else {
    // 会话已创建，在建群时会预先创建一会话
    GroupUserDAO::GetInstance().GetGroupUserIDList(request.peer().id(), uid_list);
  }

  zproto::MessageNotify message_notify;
  message_notify.mutable_peer()->set_id(request.peer().id());
  message_notify.mutable_peer()->set_type(request.peer().type());
  message_notify.set_sender_uid(uid());
  message_notify.set_rid(request.rid());
  message_notify.set_date(NowInMsecTime());
  message_notify.mutable_message ()->CopyFrom(request.message());

  SequenceModel::GetInstance().DeliveryUpdateDataNotMe(conn_id(), uid_list, message_notify);

  // ACK
  response->set_seq(message_peer_seq);
  response->set_date(NowInMsecTime());

  return kErrOK;
}

int MessagingServiceImpl::MessageReceived(const zproto::MessageReceivedReq& request, zproto::VoidRsp* response) {
  return -1;
}

int MessagingServiceImpl::MessageRead(const zproto::MessageReadReq& request, zproto::VoidRsp* response) {
  return -1;
}

int MessagingServiceImpl::DeleteMessage(const zproto::DeleteMessageReq& request, zproto::SeqRsp* response) {
  return -1;
}

int MessagingServiceImpl::ClearChat(const zproto::ClearChatReq& request, zproto::SeqRsp* response) {
  return -1;
}

int MessagingServiceImpl::DeleteChat(const zproto::DeleteChatReq& request, zproto::SeqRsp* response) {
  return -1;
}

int MessagingServiceImpl::LoadHistory(const zproto::LoadHistoryReq& request, zproto::LoadHistoryRsp* response) {
 /*
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
*/
  return -1;
}

int MessagingServiceImpl::LoadDialogs(const zproto::LoadDialogsReq& request, zproto::LoadDialogsRsp* response) {
 /*
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
*/
  return -1;
}

int MessagingServiceImpl::LoadGroupedDialogs(const zproto::LoadGroupedDialogsReq& request, zproto::LoadGroupedDialogsRsp* response) {
  return -1;
}

#if 0
// 发送私聊
int MessagingServiceImpl::SendPrivateMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response) {
  auto& history_message_dao = HistoryMessageDAO::GetInstance();

  auto message_peer_seq = SequenceDAO::GetInstance().GetNextID(uid());
  auto now = NowInMsecTime();

  HistoryMessageDO message_do;

  CreateIfNotExists(const std::string& sender_user_id,
                    int peer_type,
                    const std::string& peer_id,
                    uint64_t message_peer_seq,
                    uint64_t rid,
                    int message_content_type,
                    const std::string& message_content_data,
                    const std::string& passthrough_data);
  // 入库
  message_do.sender_user_id = uid();
  message_do.peer_id = request.peer().id();
  message_do.peer_type = request.peer().type();
  message_do.message_peer_seq = message_peer_seq;
  message_do.client_message_id = request.rid();
  message_do.message_content_type = request.message().message_type();
  // 这个地方比较重
  message_do.message_content_data = request.message().message_data();
  message_do.passthrough_data = request.passthrough_data();
  message_do.status = 1;
  message_do.created_at = now;
  message_do.updated_at = now;

  auto message_id = history_message_dao.Create(message_do);
  if (message_id<0) {
    // TODO(@benqi): 数据库异常，让客户端重试吧
    LOG(ERROR) << "SendMessage - Create error!!";
    return kErrorNo_DBError;
  }

  // TODO(@benqi): 最好能有个地方能保证保证会话已经存在
  // 会话处理
  // 正向
  // 检查会话是否存在
  int r = UserDialogDAO::GetInstance().CheckExists(uid(),
                                                   request.peer().id(),
                                                   request.peer().type());
  // TODO(@benqi): 出错
  if (r == 0) {
    UserDialogDO user_dialog;
    user_dialog.user_id = uid();
    user_dialog.peer_id = request.peer().id();
    user_dialog.peer_type = request.peer().type();
    user_dialog.created_at = now;
    user_dialog.updated_at = now;

    r = UserDialogDAO::GetInstance().Create(user_dialog);
    if (r<0) {
      LOG(ERROR) << "SendMessage - Create error!!";
      // TODO(@benqi): 是否回滚？
      r = kErrorNo_DBError;
    }
  } else {
    // ERROR
  }

  // 反向
  // 检查会话是否存在
  r = UserDialogDAO::GetInstance().CheckExists(request.peer().id(),
                                               uid(),
                                               request.peer().type());
  if (r == 0) {
    UserDialogDO user_dialog;
    user_dialog.user_id = request.peer().id();
    user_dialog.peer_id = uid();
    user_dialog.peer_type = request.peer().type();
    user_dialog.created_at = now;
    user_dialog.updated_at = now;

    r = UserDialogDAO::GetInstance().Create(user_dialog);
    if (r<0) {
      LOG(ERROR) << "SendMessage - Create error!!";
      // TODO(@benqi): 是否回滚？
      r = kErrorNo_DBError;
      // break;
    }
  }
  
  // 可以异步处理
  // TODO(@benqi): 未读计数
  // TODO(@benqi): 缓存最后一条消息

  // 同步队列
  UserSequenceDO user_sequence_do;
  auto seq = SequenceDAO::GetInstance().GetNextID(uid());

  user_sequence_do.seq = seq;
  user_sequence_do.user_id = uid();
  user_sequence_do.header = CRC32(request.GetTypeName());
  request.SerializeToString(&user_sequence_do.data);
  user_sequence_do.created_at = now;
  UserSequenceDAO::GetInstance().Create(user_sequence_do);

  user_sequence_do.user_id = request.peer().id();
  seq = SequenceDAO::GetInstance().GetNextID(request.peer().id());
  UserSequenceDAO::GetInstance().Create(user_sequence_do);

  // 转发消息
  zproto::DeliveryDataToUsersReq delivery;
  delivery.set_my_conn_id(session_id());
  delivery.add_uid_list(uid());
  delivery.add_uid_list(request.peer().id());
  delivery.set_raw_data_header(user_sequence_do.header);
  delivery.set_raw_data(user_sequence_do.data);

  // TODO(@benqi): 还是用协程简单
  // 转发给push_server成功后才能返回
  // 如果push_server有问题，则可能会导致丢消息，解决:
  // 1. 告诉客户端发送消息失败，让客户端重试
  // 2. 服务端重试
  ZRpcUtil::DoClientCall("push_client", MakeRpcRequest(delivery))
    .within(std::chrono::milliseconds(5000))
    .then([](ProtoRpcResponsePtr rsp2) {
      CHECK(rsp2);
      LOG(INFO) << "push_client rsp: " << rsp2->ToString();
      // auto online_rep = ToApiRpcOk<zproto::ClientOnlineRsp>(rsp2);
      // LOG(INFO) << (*online_rep)->Utf8DebugString();
      //
    });

  // ACK
  response->set_seq(message_peer_seq);
  response->set_date(now);

  return 0;
}

int MessagingServiceImpl::SendGroupMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response) {
  auto& history_message_dao = HistoryMessageDAO::GetInstance();
  
  auto message_peer_seq = SequenceDAO::GetInstance().GetNextID(uid());
  auto now = NowInMsecTime();
  
  HistoryMessageDO message_do;
  
  // 入库
  message_do.sender_user_id = uid();
  message_do.peer_id = request.peer().id();
  message_do.peer_type = request.peer().type();
  message_do.message_peer_seq = message_peer_seq;
  message_do.client_message_id = request.rid();
  message_do.message_content_type = request.message().message_type();
  // 这个地方比较重
  message_do.message_content_data = request.message().message_data();
  message_do.passthrough_data = request.passthrough_data();
  message_do.status = 1;
  message_do.created_at = now;
  message_do.updated_at = now;
  
  auto message_id = history_message_dao.Create(message_do);
  if (message_id<0) {
    // TODO(@benqi): 数据库异常，让客户端重试吧
    LOG(ERROR) << "SendMessage - Create error!!";
    return kErrorNo_DBError;
  }
  
  // 可以异步处理
  // TODO(@benqi): 未读计数
  // TODO(@benqi): 缓存最后一条消息

  // 同步队列
  UserSequenceDO user_sequence_do;
  user_sequence_do.header = CRC32(request.GetTypeName());
  request.SerializeToString(&user_sequence_do.data);
  user_sequence_do.created_at = now;

  // 转发消息
  zproto::DeliveryDataToUsersReq delivery;

  // 创建群聊
  std::list<std::string> group_user_ids;
  GroupUserDAO::GetInstance().GetGroupUserIDList(request.peer().id(), group_user_ids);
  for (auto& v : group_user_ids) {
    int64_t seq = 0;
    if (v == uid()) {
      seq = message_peer_seq;
    } else {
      seq = SequenceDAO::GetInstance().GetNextID(v);
    }
    
    user_sequence_do.seq = seq;
    user_sequence_do.user_id = v;
    
    UserSequenceDAO::GetInstance().Create(user_sequence_do);
    delivery.add_uid_list(v);
  }
  
  delivery.set_my_conn_id(session_id());
  delivery.add_uid_list(request.peer().id());
  delivery.set_raw_data_header(user_sequence_do.header);
  delivery.set_raw_data(user_sequence_do.data);
  
  // TODO(@benqi): 还是用协程简单
  // 转发给push_server成功后才能返回
  // 如果push_server有问题，则可能会导致丢消息，解决:
  // 1. 告诉客户端发送消息失败，让客户端重试
  // 2. 服务端重试
  ZRpcUtil::DoClientCall("push_client", MakeRpcRequest(delivery))
  .within(std::chrono::milliseconds(5000))
  .then([](ProtoRpcResponsePtr rsp2) {
    CHECK(rsp2);
    LOG(INFO) << "push_client rsp: " << rsp2->ToString();
    // auto online_rep = ToApiRpcOk<zproto::ClientOnlineRsp>(rsp2);
    // LOG(INFO) << (*online_rep)->Utf8DebugString();
    //
  });
  
  // ACK
  response->set_seq(message_peer_seq);
  response->set_date(now);
  
  return 0;
}
#endif

