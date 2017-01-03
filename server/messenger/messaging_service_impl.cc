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

