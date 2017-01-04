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

#include "messenger/zrpc_dialog_service.h"

#include "nebula/base/logger/glog_util.h"

int ZRpcDialogService::CreateChatDialog(const zproto::CreateChatDialogReq& request, zproto::CreateChatDialogRsp* response) {
  LOG(ERROR) << "ZRpcDialogService - CreateChatDialog unimplemented";
  return -1;
}

int ZRpcDialogService::LoadDialogs(const zproto::LoadDialogsReq& request, zproto::LoadDialogsRsp* response) {
  LOG(ERROR) << "ZRpcDialogService - LoadDialogs unimplemented";
  return -1;
}

int ZRpcDialogService::BlockPeer(const zproto::BlockPeerReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcDialogService - BlockPeer unimplemented";
  return -1;
}

int ZRpcDialogService::UnblockPeer(const zproto::UnblockPeerReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcDialogService - UnBlockPeer unimplemented";
  return -1;
}

int ZRpcDialogService::TopPeer(const zproto::TopPeerReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcDialogService - TopPeer unimplemented";
  return -1;
}

int ZRpcDialogService::UntopPeer(const zproto::UntopPeerReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcDialogService - UnTopPeer unimplemented";
  return -1;
}

int ZRpcDialogService::DndPeer(const zproto::DndPeerReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcDialogService - DndPeer unimplemented";
  return -1;
}

int ZRpcDialogService::UndndPeer(const zproto::UndndPeerReq& request, zproto::SeqRsp* response) {
  LOG(ERROR) << "ZRpcDialogService - UnDndPeer unimplemented";
  return -1;
}

