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

#include "auth/auth_server.h"

// #include "nebula/base/timer_manager.h"
#include "auth/rpc_auth_service.h"

bool AuthServer::Initialize() {
  // 初始化处理器
  // ZProtoEventCallback::Initializer(auth_handler::OnNewConnection,
  //                                 auth_handler::OnDataReceived,
  //                                 auth_handler::OnConnectionClosed);

  RegisterService("auth_server", "rpc_server", "zrpc");
 
  ZRpcUtil::Register("zproto.UserTokenAuthReq", DoUserTokenAuthReq);

  // RegisterService("biz_server", "rpc_server", "zrpc");

  BaseServer::Initialize();
  
  /*
    // one
    timer_manager_->ScheduleOneShotTimeout([]() {
      LOG(INFO) << "ScheduleOneShotTimeout!!!!";
    }, 1000);
    
    // once
    timer_manager_->ScheduleRepeatingTimeout([]() {
      static int i = 0;
      LOG(INFO) << "ScheduleRepeatingTimeout - " << i++;
    }, 1000);
   */
  
  return true;
}

bool AuthServer::Run() {
  return BaseServer::Run();
}

int main(int argc, char* argv[]) {
    return nebula::DoMain<AuthServer>(argc, argv);
}
