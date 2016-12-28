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

#ifndef	GATE_GATE_SERVER_HANDLER_H_
#define	GATE_GATE_SERVER_HANDLER_H_

#include <folly/io/async/EventBase.h>
#include "nebula/net/handler/nebula_base_handler.h"
#include "nebula/net/handler/zproto/zproto_handler.h"

#include "gate/gate_base_handler.h"

// 客户端连接成功后
// 1. 10秒内没收到数据包则断开
// 2. 收到的第一个包必须是用户认证包
// 3. 认证包转发给auth服务器处理
// 4. 认证必须在15秒内返回
// 5. 认证成功后通知状态服务器客户端上线
// 6. 通知成功后返回后认证成功
// 7. 可以接收客户端消息
// 8. 收到消息后转发给router
class GateServerHandler : public GateBaseHandler {
public:
  GateServerHandler() = default;
  virtual ~GateServerHandler() = default;

  enum class State : int
  {
    NONE = 0,
    CONNECTED = 1,
    HANDSHAKE = 2,
    AUTH = 3,
    FORWARD_TO_STATUS = 4,
    WORKING = 5,
    CLOSING = 6,
    ERROR = 7
  };

  ///////////////////////////////////////////////////////////////////////////////////////
  int OnNewConnection() override;
  int OnDataReceived(std::shared_ptr<PackageMessage> message_data) override;
  int OnConnectionClosed() override;

  // TODO(@benqi): 支持异步关闭
  void Close(int resaon);

  void NotifyClientOnline();
  void NotifyClientOffline();
  
  int OnGateClientAuthReq(std::shared_ptr<PackageMessage> message_data);
  int OnAuthServerAuthRsp(ProtoRpcResponsePtr response);

protected:
  State state_ {State::NONE};

  // 用户基本信息
  // TODO(@benqi): 缓存更多的用户数据
  uint32_t app_id_ {1};
  std::string user_id_;
  std::string nick_;
  std::string avatar_;
};

#endif // GATE_GATE_SERVER_HANDLER_H_

