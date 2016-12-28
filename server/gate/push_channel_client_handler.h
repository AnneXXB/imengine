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

#ifndef	GATE_PUSH_CHANNEL_CLIENT_HANDLER_H_
#define	GATE_PUSH_CHANNEL_CLIENT_HANDLER_H_

#include <folly/io/async/EventBase.h>
#include "nebula/net/handler/nebula_base_handler.h"
#include "nebula/net/handler/zproto/zproto_handler.h"

#include "gate/gate_base_handler.h"

// 消息发送流程: gate->messenger->push_server->gate
// 可能有多个gate连接到push_server，
// 连接成功后要将gate的唯一ID注册到push_server上
class PushChannelClientHandler : public GateBaseHandler {
public:
  enum class State : int
  {
    NONE = 0,
    CONNECTED = 1,
    HANDSHAKE = 2,
    AUTH = 3,
    FORWARD_TO_STATUS = 4,
    WORKING = 5,
    ERROR = 6
    };

  PushChannelClientHandler() = default;
  virtual ~PushChannelClientHandler() = default;
  
  ///////////////////////////////////////////////////////////////////////////////////////
  int OnNewConnection() override;
  int OnDataReceived(std::shared_ptr<PackageMessage> message_data) override;
  int OnConnectionClosed() override;
  
protected:
  State state_ {State::NONE};

  // 缓存ServerAuthReq的message_id
  uint64_t server_auth_message_id_ {0};

};

#endif // GATE_PUSH_CHANNEL_CLIENT_HANDLER_H_

