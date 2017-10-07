/*
 *  Copyright (c) 2016, https://github.com/nebula-im
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

// TODO(@benqi): 使用zrpc-code-gen代码生成工具自动生成

#include "messenger/messenger_server.h"

#include "nebula/mysql_client/mysql_client_util.h"

// #include "nebula/base/timer_manager.h"

void Initialize_Database() {
  // SelfRegisterFactoryManagerTest();
  DBAddrInfo db_addr;
  db_addr.host = "localhost";
  db_addr.port = 3307;
  db_addr.user = "root";
  db_addr.passwd = "";
  db_addr.db_name = "nebula_platform";
  db_addr.db_type = "mysql";
  
  DBAddrInfo db_addr2;
  db_addr2.host = "localhost";
  db_addr2.port = 3307;
  db_addr2.user = "root";
  db_addr2.passwd = "";
  db_addr2.db_name = "nebula_engine";
  db_addr2.db_type = "mysql";
  
  std::vector<DBAddrInfo> db_addrs = {db_addr, db_addr2};
  InitializeMysqlClient(db_addrs, 2);
}

bool MessengerServer::Initialize() {
  // RegisterService("tcpd", "tcp_server");
  RegisterService("messenger_server", "rpc_server", "zrpc");
  // RegisterService("push_client", "rpc_client", "zrpc");

  Initialize_Database();
  
  BaseServer::Initialize();
  
  return true;
}


int main(int argc, char* argv[]) {
    return nebula::DoMain<MessengerServer>(argc, argv);
}
