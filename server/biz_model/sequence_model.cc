/*
 *  Copyright (c) 2016, https://github.com/nebula-im/imengine
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

#include "biz_model/sequence_model.h"

#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"
#include "nebula/net/rpc/zrpc_service_util.h"

#include "proto/api/error_codes.h"
#include "proto/s2s/cc/servers.pb.h"
#include "nebula/net/zproto/zproto_api_message_box.h"

#include "dal/sequence_dao.h"
#include "dal/user_sequence_dao.h"

SequenceModel& SequenceModel::GetInstance() {
  static SequenceModel instance;
  return instance;
}

int SequenceModel::DeliveryUpdateDataNotMe(uint64_t my_conn_id, const std::list<std::string>& uid_list, uint32_t update_header, const std::string& update_data) {
  // 同步队列
  auto& sequence_dao = SequenceDAO::GetInstance();
  auto& user_sequence_dao = UserSequenceDAO::GetInstance();
  auto now = NowInMsecTime();

  // UserSequenceDO
  UserSequenceDO user_sequence_do;
  user_sequence_do.header = update_header;
  user_sequence_do.data = update_data;
  user_sequence_do.created_at = now;

  // 转发消息
  zproto::DeliveryDataToUsersReq delivery;
  delivery.set_my_conn_id(my_conn_id);
  delivery.set_raw_data_header(update_header);
  delivery.set_raw_data(update_data);

  // auto seq =
  for (auto & uid : uid_list) {
    // user_sequence_do
    user_sequence_do.seq = sequence_dao.GetNextID2(uid);
    user_sequence_do.user_id = uid;
    
    int r = user_sequence_dao.Create(user_sequence_do);
    if (r<0) {
      // TODO(@beneqi)
      return kErrDBError;
    }
    
    // delivery
    delivery.add_uid_list(uid);
  }
  
  // TODO(@benqi): 还是用协程简单
  // 转发给push_server成功后才能返回
  // 如果push_server有问题，则可能会导致丢消息，解决:
  // 1. 告诉客户端发送消息失败，让客户端重试
  // 2. 服务端重试
  ZRpcUtil::DoClientCall("push_client", MakeRpcRequest(delivery))
  .within(std::chrono::milliseconds(5000))
  .then([](zproto::ProtoRpcResponsePtr rsp2) {
    CHECK(rsp2);
    LOG(INFO) << "push_client rsp: " << rsp2->ToString();
    // auto online_rep = ToApiRpcOk<zproto::ClientOnlineRsp>(rsp2);
    // LOG(INFO) << (*online_rep)->Utf8DebugString();
    //
  });

  return kErrOK;
}

int SequenceModel::DeliveryUpdateDataNotMe(uint64_t my_conn_id, const std::list<std::string>& uid_list, const google::protobuf::Message& message) {
  auto update_header = zproto::CRC32(message.GetTypeName());
  std::string update_data;
  message.SerializeToString(&update_data);
  return DeliveryUpdateDataNotMe(my_conn_id, uid_list, update_header, update_data);
}

uint64_t SequenceModel::DeliveryUpdateDataNotMe(uint64_t my_conn_id, const std::string& uid, const google::protobuf::Message& message) {
  auto update_header = zproto::CRC32(message.GetTypeName());
  std::string update_data;
  message.SerializeToString(&update_data);

  // 同步队列
  auto& sequence_dao = SequenceDAO::GetInstance();
  auto& user_sequence_dao = UserSequenceDAO::GetInstance();
  auto now = NowInMsecTime();
  
  // UserSequenceDO
  UserSequenceDO user_sequence_do;
  user_sequence_do.header = update_header;
  user_sequence_do.data = update_data;
  user_sequence_do.created_at = now;
  
  // 转发消息
  zproto::DeliveryDataToUsersReq delivery;
  delivery.set_my_conn_id(my_conn_id);
  delivery.set_raw_data_header(update_header);
  delivery.set_raw_data(update_data);
  
  // user_sequence_do
  user_sequence_do.seq = sequence_dao.GetNextID2(uid);
  user_sequence_do.user_id = uid;
  
  int r = user_sequence_dao.Create(user_sequence_do);
  if (r<0) {
    // TODO(@beneqi)
    return 0;
  }
  
  // delivery
  delivery.add_uid_list(uid);
  
  // TODO(@benqi): 还是用协程简单
  // 转发给push_server成功后才能返回
  // 如果push_server有问题，则可能会导致丢消息，解决:
  // 1. 告诉客户端发送消息失败，让客户端重试
  // 2. 服务端重试
  ZRpcUtil::DoClientCall("push_client", MakeRpcRequest(delivery))
  .within(std::chrono::milliseconds(5000))
  .then([](zproto::ProtoRpcResponsePtr rsp2) {
    CHECK(rsp2);
    LOG(INFO) << "push_client rsp: " << rsp2->ToString();
    // auto online_rep = ToApiRpcOk<zproto::ClientOnlineRsp>(rsp2);
    // LOG(INFO) << (*online_rep)->Utf8DebugString();
    //
  });
  
  return user_sequence_do.seq;
}
