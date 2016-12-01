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

#include "proto/api_message_box.h"
// #include "nebula/base/timer_manager.h"
#include "push/zrpc_push_service.h"


bool PushServer::Initialize() {
  // 初始化处理器
  RegisterService("push_server", "zrpc_server", "zrpc");
  
  // register rpc call
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

bool PushServer::Run() {
  return BaseServer::Run();
}

int main(int argc, char* argv[]) {
  return nebula::DoMain<PushServer>(argc, argv);
}
