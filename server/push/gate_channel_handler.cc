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

#include "push/gate_channel_handler.h"

#include <folly/Conv.h>

// #include "nebula/net/net_engine_manager.h"
#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/net/handler/nebula_handler_util.h"

#include "proto/s2s/cc/servers.pb.h"
#include "nebula/net/zproto/api_message_box.h"
// #include "proto/zproto/zproto_api_message_types.h"
#include "push/gate_channel_manager.h"

// folly::future

int push::OnNewConnection(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline) {
  LOG(INFO) << "OnNewConnection - conn new";
  
  // gate_channel_server
  
  return 0;
}

int push::OnDataReceived(nebula::ZProtoPipeline* pipeline, std::shared_ptr<PackageMessage> message_data) {
  LOG(INFO) << "OnDataReceived - recv data: " << message_data->ToString();
  
  // gate_channel_server

  auto encoded = std::static_pointer_cast<EncodedRpcRequest>(message_data);
  if (encoded->GetMethodID() != CRC32("zproto.ServerAuthReq")) {
    // TODO(@benqi): LOG(ERROR) << "";
    
    return 0;
  }

  auto server_auth_req = ToApiRpcRequest<zproto::ServerAuthReq>(encoded);
  DCHECK(server_auth_req);
  auto h = pipeline->getHandler<ZProtoHandler>();
  LOG(INFO) << "OnDataReceived - recv data: " << server_auth_req->ToString() << ", conn_id: " << h->GetConnID();

  GateChannelManager::GetInstance()->OnNewGateChannel((*server_auth_req)->server_id(),
                                                      h->GetConnID());

  zproto::ServerAuthRsp server_auth_rsp;
  auto rpc_ok = MakeRpcOK(server_auth_rsp);
  rpc_ok->set_req_message_id(server_auth_req->message_id());
  
  std::unique_ptr<folly::IOBuf> data;
  rpc_ok->SerializeToIOBuf(data);
  pipeline->write(std::move(data));

  return 0;
}

int push::OnConnectionClosed(nebula::TcpServiceBase* service, nebula::ZProtoPipeline* pipeline) {
  LOG(INFO) << "OnConnectionClosed - conn closed";
  
  // gate_channel_server

  auto h = pipeline->getHandler<ZProtoHandler>();
  GateChannelManager::GetInstance()->OnGateChannelClosed(h->GetConnID());
  return 0;
}
