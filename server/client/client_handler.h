/*
 *  Copyright (c) 2016, https://github.com/zhatalk
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

#ifndef	CLIENT_CLIENT_HANDLER_H_
#define	CLIENT_CLIENT_HANDLER_H_

#include <folly/io/async/EventBase.h>

#include "nebula/net/base/nebula_pipeline.h"
#include "nebula/net/engine/tcp_service_base.h"
#include "nebula/net/zproto/zproto_package_data.h"

namespace client_handler {
  
///////////////////////////////////////////////////////////////////////////////////////
int OnNewConnection(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline);
int OnDataReceived(nebula::ZProtoPipeline* pipeline, std::shared_ptr<PackageMessage> message_data);
int OnConnectionClosed(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline);
  
}

#endif // FRONTEND_FRONTEND_HANDLER_H_

