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

#ifndef	MESSENGER_DIALOG_SERVICE_IMPL_H_
#define	MESSENGER_DIALOG_SERVICE_IMPL_H_

#include "messenger/zrpc_dialog_service.h"

class DialogServiceImpl : public ZRpcDialogService {
public:
  DialogServiceImpl() = default;
  ~DialogServiceImpl() = default;
  
  int CreateChatDialog(const zproto::CreateChatDialogReq& request, zproto::CreateChatDialogRsp* response) override;
  int LoadDialogs(const zproto::LoadDialogsReq& request, zproto::LoadDialogsRsp* response) override;
  
  int BlockPeer(const zproto::BlockPeerReq& request, zproto::SeqRsp* response) override;
  int UnblockPeer(const zproto::UnblockPeerReq& request, zproto::SeqRsp* response) override;
  int TopPeer(const zproto::TopPeerReq& request, zproto::SeqRsp* response) override;
  int UntopPeer(const zproto::UntopPeerReq& request, zproto::SeqRsp* response) override;
  int DndPeer(const zproto::DndPeerReq& request, zproto::SeqRsp* response) override;
  int UndndPeer(const zproto::UndndPeerReq& request, zproto::SeqRsp* response) override;

private:
  // 发送消息
  // int SendPrivateMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response);
  // int SendGroupMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response);

};

#endif
