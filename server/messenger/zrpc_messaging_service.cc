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

#include "messenger/zrpc_messaging_service.h"

#include "nebula/base/logger/glog_util.h"

int ZRpcMessagingService::SendMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - SendMessage unimplemented";
  return -1;
}

/*
int ZRpcMessagingService::MessageSync(const zproto::MessageSyncReq& request, zproto::MessageSyncRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - MessageSync unimplemented";
  return -1;
}

int ZRpcMessagingService::LoadHistoryMessage(const zproto::LoadHistoryMessageReq& request, zproto::LoadHistoryMessageRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - LoadHistoryMessage unimplemented";
  return -1;
}

int ZRpcMessagingService::LoadDialogs(const zproto::LoadDialogsReq& request, zproto::LoadDialogsRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - LoadDialogs unimplemented";
  return -1;
}

int ZRpcMessagingService::CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - CreateGroup unimplemented";
  return -1;
}
 */

int ZRpcMessagingService::MessageReceived(const zproto::MessageReceivedReq& request, zproto::VoidRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - MessageReceived unimplemented";
  return -1;
}

int ZRpcMessagingService::MessageRead(const zproto::MessageReadReq& request, zproto::VoidRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - CreateGroup unimplemented";
  return -1;
}

int ZRpcMessagingService::DeleteMessage(const zproto::DeleteMessageReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - DeleteMessage unimplemented";
  return -1;
}

int ZRpcMessagingService::ClearChat(const zproto::ClearChatReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - ClearChat unimplemented";
  return -1;
}

int ZRpcMessagingService::DeleteChat(const zproto::DeleteChatReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - DeleteChat unimplemented";
  return -1;
}

int ZRpcMessagingService::LoadHistory(const zproto::LoadHistoryReq& request, zproto::LoadHistoryRsp* response) {
  LOG(ERROR) << "ZRpcMessagingService - LoadHistory unimplemented";
  return -1;
}
