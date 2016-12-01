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

#include "online/online_status_server.h"

// #include "nebula/base/timer_manager.h"

#include "proto/api_message_box.h"
#include "online/rpc_online_service.h"

bool OnlineStatusServer::Initialize() {
  RegisterService("online_status_server", "rpc_server", "zrpc");

  ZRpcUtil::Register(zproto::CLIENT_ONLINE_REQ, DoClientOnline);
  ZRpcUtil::Register(zproto::CLIENT_ONLINE_RSP, DoClientOffline);
  
  BaseServer::Initialize();
  
#if 0
  // one
  timer_manager_->ScheduleOneShotTimeout([]() {
    LOG(INFO) << "ScheduleOneShotTimeout!!!!";
  }, 1000);
  
  // once
  timer_manager_->ScheduleRepeatingTimeout([]() {
    static int i = 0;
    LOG(INFO) << "ScheduleRepeatingTimeout - " << i++;
  }, 1000);
#endif
  
  return true;
}

int main(int argc, char* argv[]) {
  return nebula::DoMain<OnlineStatusServer>(argc, argv);
}
