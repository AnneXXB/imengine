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

#ifndef	GATE_GATE_BASE_HANDLER_H_
#define	GATE_GATE_BASE_HANDLER_H_

#include <folly/io/async/EventBase.h>
#include "nebula/net/handler/nebula_base_handler.h"
#include "nebula/net/handler/zproto/zproto_handler.h"

// gate->messenger是无状态的，转发数据即可
class GateBaseHandler : public nebula::ConnAttachData {
public:
  GateBaseHandler() = default;
  virtual ~GateBaseHandler() = default;
  
  static std::shared_ptr<GateBaseHandler> MakeHandler(const std::string& service_name);
  
  void Initialize(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline, uint64_t conn_id) {
    service_ = service;
    pipeline_ = pipeline;
    conn_id_ = conn_id;
  }
  
  ///////////////////////////////////////////////////////////////////////////////////////
  virtual int OnNewConnection() {
    return 0;
  }
  
  virtual int OnDataReceived(std::shared_ptr<PackageMessage> message_data) {
    return 0;
  }
  
  virtual int OnConnectionClosed() {
    return 0;
  }
  
protected:
  nebula::TcpServiceBase* service_ {nullptr};
  nebula::ZProtoPipeline* pipeline_ {nullptr};
  uint64_t conn_id_ {0};
};

#endif // GATE_AUTH_CLIENT_HANDLER_H_

