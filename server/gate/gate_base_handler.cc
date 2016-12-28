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

#include "gate/gate_base_handler.h"

#include "gate/auth_client_handler.h"
#include "gate/gate_server_handler.h"
#include "gate/messenger_client_handler.h"
#include "gate/online_status_client_handler.h"
#include "gate/push_channel_client_handler.h"

#include "nebula/net/handler/zproto/zproto_handler.h"

std::shared_ptr<GateBaseHandler> GateBaseHandler::MakeHandler(const std::string& service_name) {
  std::shared_ptr<GateBaseHandler> handler;

  if (service_name == "gate_server") {
    handler = std::make_shared<GateServerHandler>();
  } else if (service_name == "push_channel_client") {
    handler = std::make_shared<PushChannelClientHandler>();
  } else if (service_name == "messenger_client") {
    handler = std::make_shared<MessengerClientHandler>();
  } else if (service_name == "auth_client") {
    handler = std::make_shared<AuthClientHandler>();
  } else if (service_name == "online_statsus_client") {
    handler = std::make_shared<OnlineStatusClientHandler>();
  } else {
    LOG(ERROR) << "MakeHandler - Invalid service_name: " << service_name;
    return handler;
  }

  return handler;
}

