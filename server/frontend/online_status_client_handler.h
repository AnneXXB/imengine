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

#ifndef	GATE_ONLINE_STATUS_CLIENT_HANDLER_H_
#define	GATE_ONLINE_STATUS_CLIENT_HANDLER_H_

#include <folly/io/async/EventBase.h>
#include "nebula/net/handler/nebula_base_handler.h"
#include "nebula/net/handler/zproto/zproto_handler.h"

#include "gate/gate_base_handler.h"

// gate->messenger是无状态的，转发数据即可
class OnlineStatusClientHandler : public GateBaseHandler {
public:

  OnlineStatusClientHandler() = default;
  ~OnlineStatusClientHandler() = default;
  
  ///////////////////////////////////////////////////////////////////////////////////////
  int OnNewConnection() override;
  int OnDataReceived(std::shared_ptr<PackageMessage> message_data) override;
  int OnConnectionClosed() override;
};

#endif // GATE_ONLINE_STATUS_CLIENT_HANDLER_H_

