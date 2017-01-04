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

#include "messenger/dialog_service_impl.h"

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
#include "dal/user_dialog_dao.h"
#include "dal/sequence_dao.h"

//#include "dal/group_dao.h"
//#include "dal/group_user_dao.h"
//#include "dal/user_sequence_dao.h"
//#include "biz_model/message_model.h"
#include "biz_model/dialog_model.h"
#include "biz_model/sequence_model.h"

int DialogServiceImpl::CreateChatDialog(const zproto::CreateChatDialogReq& request, zproto::CreateChatDialogRsp* response) {
  LOG(INFO) << "CreateChatDialog - request: " << request.Utf8DebugString();
  DialogModel::GetInstance().CreateIfNotExists(uid(), zproto::PEER_TYPE_PRIVATE, request.peer_id());
  response->mutable_peer()->set_type(zproto::PEER_TYPE_PRIVATE);
  response->mutable_peer()->set_id(request.peer_id());
  response->mutable_peer()->set_access_hash(1);
  return 0;
}

int DialogServiceImpl::LoadDialogs(const zproto::LoadDialogsReq& request, zproto::LoadDialogsRsp* response) {
  UserDialogDOList dialog_list;
  UserDialogDAO::GetInstance().LoadUserDialogList(uid(),
                                                  request.min_date(),
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

int DialogServiceImpl::BlockPeer(const zproto::BlockPeerReq& request, zproto::SeqRsp* response) {
  UserDialogDAO::GetInstance().UpdateBlock(uid(),
                                           request.peer().id(),
                                           request.peer().type(),
                                           true);

  zproto::PeerBlockedNotify notify;
  notify.mutable_peer()->set_id(request.peer().id());
  notify.mutable_peer()->set_type(request.peer().type());
  auto seq = SequenceModel::GetInstance().DeliveryUpdateDataNotMe(conn_id(), uid(), notify);
  
  // 返回
  response->set_seq(seq);
  
  return 0;
}

int DialogServiceImpl::UnblockPeer(const zproto::UnblockPeerReq& request, zproto::SeqRsp* response) {
  UserDialogDAO::GetInstance().UpdateBlock(uid(),
                                           request.peer().id(),
                                           request.peer().type(),
                                           false);
  
  zproto::PeerUnblockedNotify notify;
  notify.mutable_peer()->set_id(request.peer().id());
  notify.mutable_peer()->set_type(request.peer().type());
  auto seq = SequenceModel::GetInstance().DeliveryUpdateDataNotMe(conn_id(), uid(), notify);
  
  // 返回
  response->set_seq(seq);
  
  return 0;
}

int DialogServiceImpl::TopPeer(const zproto::TopPeerReq& request, zproto::SeqRsp* response) {
  UserDialogDAO::GetInstance().UpdateTop(uid(),
                                           request.peer().id(),
                                           request.peer().type(),
                                           true);
  
  zproto::PeerTopedNotify notify;
  notify.mutable_peer()->set_id(request.peer().id());
  notify.mutable_peer()->set_type(request.peer().type());
  auto seq = SequenceModel::GetInstance().DeliveryUpdateDataNotMe(conn_id(), uid(), notify);
  
  // 返回
  response->set_seq(seq);
  
  return 0;
}

int DialogServiceImpl::UntopPeer(const zproto::UntopPeerReq& request, zproto::SeqRsp* response) {
  UserDialogDAO::GetInstance().UpdateTop(uid(),
                                           request.peer().id(),
                                           request.peer().type(),
                                           false);
  
  zproto::PeerUntopedNotify notify;
  notify.mutable_peer()->set_id(request.peer().id());
  notify.mutable_peer()->set_type(request.peer().type());
  auto seq = SequenceModel::GetInstance().DeliveryUpdateDataNotMe(conn_id(), uid(), notify);
  
  // 返回
  response->set_seq(seq);
  
  return 0;
}

int DialogServiceImpl::DndPeer(const zproto::DndPeerReq& request, zproto::SeqRsp* response) {
  UserDialogDAO::GetInstance().UpdateDnd(uid(),
                                           request.peer().id(),
                                           request.peer().type(),
                                           true);
  
  zproto::PeerDndedNotify notify;
  notify.mutable_peer()->set_id(request.peer().id());
  notify.mutable_peer()->set_type(request.peer().type());
  auto seq = SequenceModel::GetInstance().DeliveryUpdateDataNotMe(conn_id(), uid(), notify);
  
  // 返回
  response->set_seq(seq);
  
  return 0;
}

int DialogServiceImpl::UndndPeer(const zproto::UndndPeerReq& request, zproto::SeqRsp* response) {
  UserDialogDAO::GetInstance().UpdateDnd(uid(),
                                           request.peer().id(),
                                           request.peer().type(),
                                           false);
  
  zproto::PeerUndndedNotify notify;
  notify.mutable_peer()->set_id(request.peer().id());
  notify.mutable_peer()->set_type(request.peer().type());
  auto seq = SequenceModel::GetInstance().DeliveryUpdateDataNotMe(conn_id(), uid(), notify);
  
  // 返回
  response->set_seq(seq);
  
  return 0;
}
