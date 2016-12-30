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

#include "push/push_server.h"

// #include "proto/zproto/zproto_api_message_types.h"
//include "proto/zproto/cc/method_types.pb.h"

#include "push/zrpc_push_service.h"
#include "push/gate_channel_handler.h"


bool PushServer::Initialize() {
  // 内部推送路由通道
  RegisterService("push_server", "rpc_server", "zrpc");
  // 接入网关通道
  RegisterService("push_channel_server", "tcp_server", "zproto");
  // 在线服务
  RegisterService("status_rpc_client", "rpc_client", "zrpc");
  
  // 连接router，使用zproto协议
  ZProtoEventCallback::Initializer(push::OnNewConnection,
                                   push::OnDataReceived,
                                   push::OnConnectionClosed);

  // register rpc call
  BaseServer::Initialize();
  
  return true;
}

bool PushServer::Run() {
  BaseServer::Run();
  ZProtoEventCallback::Destroy();
  return true;
}

int main(int argc, char* argv[]) {
  return nebula::DoMain<PushServer>(argc, argv);
}
