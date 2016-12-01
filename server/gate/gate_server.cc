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

#include "gate/gate_server.h"
#include "gate/gate_handler.h"

bool GateServer::Initialize() {
  // 初始化处理器

//  // 连接router，使用zproto协议
//  TeamtalkEventCallback::Initializer(FrontendHandler::OnNewConnection,
//                                     FrontendHandler::OnDataReceived,
//                                     FrontendHandler::OnConnectionClosed);

  // 连接router，使用zproto协议
  ZProtoEventCallback::Initializer(gate::OnNewConnection,
                                   gate::OnDataReceived,
                                   gate::OnConnectionClosed);

  // 注册服务
  RegisterService("gate_server", "tcp_server", "zproto");
  
  // 推消息等
  RegisterService("push_client", "tcp_client", "zproto");
  // 在线状态
  RegisterService("online_status_client", "rpc_client", "zrpc");
  // 登录认证
  RegisterService("auth_client", "rpc_client", "zrpc");

  // IM核心服务
  RegisterService("messenger_client", "tcp_client", "zproto");
  // 非IM核心业务
  // RegisterService("app_client", "tcp_client", "zproto");

  return BaseServer::Initialize();
}

bool GateServer::Run() {
  return BaseServer::Run();
}


int main(int argc, char* argv[]) {
  return nebula::DoMain<GateServer>(argc, argv);
}
