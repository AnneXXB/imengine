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

#include "messenger/zrpc_messenger_service.h"

#include "nebula/base/logger/glog_util.h"

int ZRpcMessengerService::SendMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcMessengerService - SendMessage unimplemented";
  return -1;
}

/*
int ZRpcMessengerService::MessageSync(const zproto::MessageSyncReq& request, zproto::MessageSyncRsp* response) {
  LOG(ERROR) << "ZRpcMessengerService - MessageSync unimplemented";
  return -1;
}

int ZRpcMessengerService::LoadHistoryMessage(const zproto::LoadHistoryMessageReq& request, zproto::LoadHistoryMessageRsp* response) {
  LOG(ERROR) << "ZRpcMessengerService - LoadHistoryMessage unimplemented";
  return -1;
}

int ZRpcMessengerService::LoadDialogs(const zproto::LoadDialogsReq& request, zproto::LoadDialogsRsp* response) {
  LOG(ERROR) << "ZRpcMessengerService - LoadDialogs unimplemented";
  return -1;
}

int ZRpcMessengerService::CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response) {
  LOG(ERROR) << "ZRpcMessengerService - CreateGroup unimplemented";
  return -1;
}
 */
