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

#ifndef	MESSENGER_ZRPC_MESSENGER_RPC_SERVICE_H_
#define	MESSENGER_ZRPC_MESSENGER_RPC_SERVICE_H_

#include "proto/api/cc/misc.pb.h"
#include "proto/api/cc/messaging.pb.h"
#include "nebula/net/zproto/api_message_box.h"

class ZRpcMessengerService {
public:
  virtual ~ZRpcMessengerService() = default;

  void set_rpc_request(RpcRequestPtr v) { rpc_request_ = v; }
  uint64_t session_id() const {
    rpc_request_ ? rpc_request_->session_id() : 0;
  }
  virtual int SendMessage(const zproto::SendMessageReq& request, zproto::SeqDateRsp* response);
  
/*
  virtual int MessageSync(const zproto::MessageSyncReq& request, zproto::MessageSyncRsp* response);
  virtual int LoadHistoryMessage(const zproto::LoadHistoryMessageReq& request, zproto::LoadHistoryMessageRsp* response);
  virtual int LoadDialogs(const zproto::LoadDialogsReq& request, zproto::LoadDialogsRsp* response);
  virtual int CreateGroup(const zproto::CreateGroupReq& request, zproto::CreateGroupRsp* response);
 */
  
protected:
  RpcRequestPtr rpc_request_;
};

#endif

