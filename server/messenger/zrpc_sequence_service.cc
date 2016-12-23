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

// TODO(@benqi): 使用zrpc-code-gen代码生成工具自动生成

#include "messenger/zrpc_sequence_service.h"

#include "nebula/base/logger/glog_util.h"

int ZRpcSequenceService::GetState(const zproto::GetStateReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcSequenceService - GetState unimplemented";
  return -1;
}

int ZRpcSequenceService::GetDifference(const zproto::GetDifferenceReq& request, zproto::GetDifferenceRsp* response) {
  LOG(ERROR) << "ZRpcSequenceService - GetDifference unimplemented";
  return -1;
}

int ZRpcSequenceService::SubscribeToOnline(const zproto::SubscribeToOnlineReq& request, zproto::VoidRsp* response) {
  LOG(ERROR) << "ZRpcSequenceService - SubscribeToOnline unimplemented";
  return -1;
}

int ZRpcSequenceService::SubscribeFromOnline(const zproto::SubscribeFromOnlineReq& request, zproto::VoidRsp* response) {
  LOG(ERROR) << "ZRpcSequenceService - SubscribeFromOnline unimplemented";
  return -1;
}

int ZRpcSequenceService::SubscribeToGroupOnline(const zproto::SubscribeToGroupOnlineReq& request, zproto::VoidRsp* response) {
  LOG(ERROR) << "ZRpcSequenceService - SubscribeToGroupOnline unimplemented";
  return -1;
}

int ZRpcSequenceService::SubscribeFromGroupOnline(const zproto::SubscribeFromGroupOnlineReq& request, zproto::VoidRsp* response) {
  LOG(ERROR) << "ZRpcSequenceService - SubscribeFromGroupOnline unimplemented";
  return -1;
}
