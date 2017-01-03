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

#ifndef	MESSENGER_MESSAGING_SERVICE_IMPL_H_
#define	MESSENGER_MESSAGING_SERVICE_IMPL_H_

#include "messenger/zrpc_messaging_service.h"

class MessagingServiceImpl : public ZRpcMessagingService {
public:
  MessagingServiceImpl() = default;
  ~MessagingServiceImpl() = default;
  
  int SendMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response) override;
  int MessageReceived(const zproto::MessageReceivedReq& request, zproto::VoidRsp* response) override;
  int MessageRead(const zproto::MessageReadReq& request, zproto::VoidRsp* response) override;
  int DeleteMessage(const zproto::DeleteMessageReq& request, zproto::SeqRsp* response) override;
  int ClearChat(const zproto::ClearChatReq& request, zproto::SeqRsp* response) override;
  int DeleteChat(const zproto::DeleteChatReq& request, zproto::SeqRsp* response) override;
  
  int LoadHistory(const zproto::LoadHistoryReq& request, zproto::LoadHistoryRsp* response) override;

/*
  int MessageSync(const zproto::MessageSyncReq& request, zproto::MessageSyncRsp* response) override;
  int LoadHistoryMessage(const zproto::LoadHistoryMessageReq& request, zproto::LoadHistoryMessageRsp* response) override;
  int LoadDialogs(const zproto::LoadDialogsReq& request, zproto::LoadDialogsRsp* response) override;
  int CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response) override;
 */

private:
  // 发送消息
  // int SendPrivateMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response);
  // int SendGroupMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response);

};

#endif
