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

#ifndef	MESSENGER_ZRPC_DIALOG_SERVICE_H_
#define	MESSENGER_ZRPC_DIALOG_SERVICE_H_

#include "proto/api/cc/misc.pb.h"
#include "proto/api/cc/dialogs.pb.h"

#include "base/base_zrpc_service.h"

class ZRpcDialogService : public BaseZRpcService {
public:
  virtual ~ZRpcDialogService() = default;

  ////////////////////////////////////////////////////////////////////////////////////////////////
  virtual int CreateChatDialog(const zproto::CreateChatDialogReq& request, zproto::CreateChatDialogRsp* response);
  virtual int LoadDialogs(const zproto::LoadDialogsReq& request, zproto::LoadDialogsRsp* response);

  virtual int BlockPeer(const zproto::BlockPeerReq& request, zproto::SeqRsp* response);
  virtual int UnblockPeer(const zproto::UnblockPeerReq& request, zproto::SeqRsp* response);
  virtual int TopPeer(const zproto::TopPeerReq& request, zproto::SeqRsp* response);
  virtual int UntopPeer(const zproto::UntopPeerReq& request, zproto::SeqRsp* response);
  virtual int DndPeer(const zproto::DndPeerReq& request, zproto::SeqRsp* response);
  virtual int UndndPeer(const zproto::UndndPeerReq& request, zproto::SeqRsp* response);
};

#endif

