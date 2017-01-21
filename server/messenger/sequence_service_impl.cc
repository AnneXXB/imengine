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

#include "messenger/sequence_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "dal/user_sequence_dao.h"

int SequenceServiceImpl::GetState(const zproto::GetStateReq& request, zproto::SeqRsp* response) {
  auto& user_sequence_dao = UserSequenceDAO::GetInstance();
  response->set_seq(user_sequence_dao.GetCurrentSequence(uid()));
  return 0;
}

int SequenceServiceImpl::GetDifference(const zproto::GetDifferenceReq& request, zproto::GetDifferenceRsp* response) {
  auto& user_sequence_dao = UserSequenceDAO::GetInstance();
  UserSequenceDOList user_sequence_list;
  user_sequence_dao.LoadSequenceData(uid(), request.seq(), user_sequence_list);
  for (auto user_sequence : user_sequence_list) {
    auto update = response->add_updates();
    update->set_update_header(user_sequence->header);
    update->set_update(user_sequence->data);
  }
  if (!user_sequence_list.empty()) {
    response->set_seq((*user_sequence_list.rbegin())->seq);
  }
  return 0;
}

int SequenceServiceImpl::SubscribeToOnline(const zproto::SubscribeToOnlineReq& request, zproto::VoidRsp* response) {
  return -1;
}

int SequenceServiceImpl::SubscribeFromOnline(const zproto::SubscribeFromOnlineReq& request, zproto::VoidRsp* response) {
  return -1;
}

int SequenceServiceImpl::SubscribeToGroupOnline(const zproto::SubscribeToGroupOnlineReq& request, zproto::VoidRsp* response) {
  return -1;
}

int SequenceServiceImpl::SubscribeFromGroupOnline(const zproto::SubscribeFromGroupOnlineReq& request, zproto::VoidRsp* response) {
  return -1;
}
