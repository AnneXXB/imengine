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

#include "client/client.h"

#include <iostream>

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/net/net_engine_manager.h"
#include "nebula/base/readline_gets.h"

#include "client/client_command_handler.h"
#include "client/client_handler.h"

bool Client::Initialize() {
  // 初始化处理器
//  ZProtoEventCallback::Initializer(client_handler::OnNewConnection,
//                                   client_handler::OnDataReceived,
//                                   client_handler::OnConnectionClosed);

  // 注册服务
  RegisterService("gate_client", "rpc_client", "zrpc");
  
  return BaseServer::Initialize();
}

bool Client::Run() {
  // auto net_engine_manager = nebula::NetEngineManager::GetInstance();
  // 启动成功
  try {
    nebula::NetEngineManager::GetInstance()->Start();
  } catch (std::exception& e) {
    LOG(ERROR) << "Run - catch exception: " << e.what();
    return false;
  } catch (...) {
    LOG(ERROR) << "Run - catch  a invalid exception";
    return false;
  }
  
  // GPerftoolsProfiler profiler;
  // profiler.ProfilerStart();
  
  //BaseDaemon::Run();
  DoCommandLineLoop();
  
  // profiler.ProfilerStop();
  
  nebula::NetEngineManager::GetInstance()->Stop();

  return true;
  // return BaseServer::Run();
}

void Client::DoCommandLineLoop() {
  
  try {
    while (true) {
      auto line = ReadlineGets("nebula-im> ");
      if (line.empty()) {
        continue;
      }
      
      std::vector<folly::StringPiece> cmds;
      folly::split(" ", line, cmds);
      
      if (-2 == DoClientCommand(cmds)) {
        break;
      }
      
      // Execute(v);
/*
      std::cout << "Input string and int" << std::endl;
      std::string in;
      std::cin >> in;
      if (in == "quit") break;
      
      // SELECT app_id,user_id,open_id,nick,avatar FROM users WHERE app_id=1 AND open_id='benqi@zhazha' AND user_token='benqi@zhazha.nebula.im'
      auto req = std::make_shared<ApiRpcRequest<zproto::UserTokenAuthReq>>();
      (*req)->set_app_key("nebula-im(zhazha)");
      (*req)->set_user_id("benqi@zhazha");
      (*req)->set_user_token("benqi@zhazha.nebula.im");
      //(*req)->set_online_status(teamtalk::USER_STATUS_ONLINE);
      //(*req)->set_client_type(teamtalk::CLIENT_TYPE_MAC);
      
      ZRpcUtil::DoClientCall("frontend_client", req).then([](ProtoRpcResponsePtr rsp) {
        if (rsp) {
          auto login_rsp = ToApiRpcOk<zproto::UserTokenAuthRsp>(rsp);
          LOG(INFO) << (*login_rsp)->Utf8DebugString();
        }
      });
 */
    }
  } catch (const std::exception& e) {
    std::cout << "DoCommandLineLoop - " << folly::exceptionStr(e) << std::endl;
  }
}


int main(int argc, char* argv[]) {
  return nebula::DoMain<Client>(argc, argv);
}
