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

#include "client/client_command_handler.h"

#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/cc/auth.pb.h"
#include "proto/api/cc/misc.pb.h"
#include "proto/api/cc/messaging.pb.h"

#include "nebula/net/zproto/api_message_box.h"

#include "nebula/net/rpc/zrpc_service_util.h"

typedef int (*ClientCommandHandlerFunc)(const std::vector<folly::StringPiece>&);

//
struct CmdEntry {
  const char* cmd;                    // 命令名
  const char* cmd_help;               // 命令帮助信息
  uint32_t cmd_num_min;               // 最少参数
  uint32_t cmd_num_max;               // 最大参数，如果值为0，则无参数限制
  ClientCommandHandlerFunc handler;   // 命令处理函数
};

int DoConnect(const std::vector<folly::StringPiece>& command_lines) {
  auto req = std::make_shared<ApiRpcRequest<zproto::StartTokenAuthReq>>();
  
  (*req)->set_api_key("nebula-im(zhazha)");
  // (*req)->set_user_id("benqi@zhazha");
  (*req)->set_token("benqi@zhazha.nebula.im");
  //(*req)->set_online_status(teamtalk::USER_STATUS_ONLINE);
  //(*req)->set_client_type(teamtalk::CLIENT_TYPE_MAC);

  LOG(INFO) << "DoConnect : " << req->ToString();

  ZRpcUtil::DoClientCall("gate_client", req)
  .within(std::chrono::milliseconds(5000))
//  .onTimeout(std::chrono::milliseconds(5000), []() {
//    LOG(INFO) << "DoConnect - time_out!!";
//    ProtoRpcResponsePtr rsp;
//    return folly::makeFuture(rsp);
//  })
  .then([](ProtoRpcResponsePtr rsp) {
    LOG(INFO) << "DoConnect - rsp";
    if (rsp) {
      LOG(INFO) << rsp->ToString();
//      if (rsp->GetPackageType() == Package::RPC_OK) {
//        auto login_rsp = ToApiRpcOk<zproto::UserTokenAuthRsp>(rsp);
//        LOG(INFO) << (*login_rsp)->Utf8DebugString();
//      }
    } else {
      LOG(INFO) << "DoSendMessage - rsp is none!";
    }
  });
  return 0;
}

int DoSendMessage(const std::vector<folly::StringPiece>& command_lines) {
/*
  auto req = std::make_shared<ApiRpcRequest<zproto::SendMessageReq>>();
  auto message_data = (*req)->mutable_message_data();
  message_data->set_sender_user_id("benqi@zhazha");
  auto peer = message_data->mutable_peer();
  peer->set_id(command_lines[1].toString());
  peer->set_type(zproto::EnumHelper::PRIVATE);
  message_data->set_client_message_id(GetNextIDBySnowflake());
  message_data->set_message_type(zproto::EnumHelper::TEXT);
  message_data->set_message_content(command_lines[2].toString());
  
  ZRpcUtil::DoClientCall("gate_client", req)
  .within(std::chrono::milliseconds(5000))
  .then([](ProtoRpcResponsePtr rsp) {
    LOG(INFO) << "DoSendMessage - rsp";
    if (rsp) {
      LOG(INFO) << rsp->ToString();
      // auto login_rsp = ToApiRpcOk<zproto::SeqDateRsp>(rsp);
      // LOG(INFO) << (*login_rsp)->Utf8DebugString();
    }
  });
 */
  return 0;
}

int DoMessageSync(const std::vector<folly::StringPiece>& command_lines) {
/*
  auto req = std::make_shared<ApiRpcRequest<zproto::MessageSyncReq>>();
  (*req)->set_received_max_seq(0);
  
  LOG(INFO) << "DoMessageSync - req: " << req->ToString();
  
  ZRpcUtil::DoClientCall("gate_client", req)
  .within(std::chrono::milliseconds(5000))
  .then([](ProtoRpcResponsePtr rsp) {
    LOG(INFO) << "DoMessageSync - rsp";
    LOG(INFO) << rsp->ToString();
    // if (rsp) {
    //  auto login_rsp = ToApiRpcOk<zproto::SeqDateRsp>(rsp);
    //  LOG(INFO) << (*login_rsp)->Utf8DebugString();
    //}
  });
 */
  return 0;
}

int DoCreateGroup(const std::vector<folly::StringPiece>& command_lines) {
/*
  auto req = std::make_shared<ApiRpcRequest<zproto::CreateGroupReq>>();
  
  (*req)->set_creator_user_id("benqi@zhazha");
  (*req)->set_client_group_id(GetNextIDBySnowflake());
  (*req)->set_title(command_lines[1].toString());
  (*req)->add_user_ids("benqi@zhazha");
  for (int i=2; i<command_lines.size(); ++i) {
    (*req)->add_user_ids(command_lines[i].toString());
  }

  LOG(INFO) << "DoCreateGroup - req: " << req->ToString();
  
  ZRpcUtil::DoClientCall("gate_client", req)
  .within(std::chrono::milliseconds(5000))
  .then([](ProtoRpcResponsePtr rsp) {
    LOG(INFO) << "DoMessageSync - rsp";
    LOG(INFO) << rsp->ToString();
    // if (rsp) {
    //  auto login_rsp = ToApiRpcOk<zproto::SeqDateRsp>(rsp);
    //  LOG(INFO) << (*login_rsp)->Utf8DebugString();
    //}
  });
 */
  
  return 0;
}


int DoQuit(const std::vector<folly::StringPiece>& command_lines) {
  // exit(0);
  return -2;
}

CmdEntry g_cmds[] = {
  // login/logout
  {"connect", "connect serv_ip serv_port user_id", 4, 0, DoConnect},
  {"sendmessage", "sendmessage user_id content", 3, 0, DoSendMessage},
  {"messagesync", "messagesync", 1, 0, DoMessageSync},
  {"create_group", "create_group group_title uid1...", 3, 10, DoCreateGroup},
  // quit
  {"quit", "quit", 1, 0, DoQuit}
};

void PrintHelp() {
  printf("Usage(***all user_id/group_id/shop_id are string format***):\n");
  
  for (uint32_t i=0; i<sizeof(g_cmds)/sizeof(CmdEntry); ++i) {
    printf("\t %s\n", g_cmds[i].cmd_help);
  }
}


int DoClientCommand(const std::vector<folly::StringPiece>& command_lines) {
  if (command_lines.empty()) {
    return 0;
  }
  
  // init_log();
  
  CmdEntry* cmd = NULL;
  
  for (uint32_t i=0; i<sizeof(g_cmds)/sizeof(CmdEntry); ++i) {
    if (command_lines[0] == g_cmds[i].cmd) {
      cmd = &g_cmds[i];
      break;
    }
  }
  
  if (cmd == NULL) {
    PrintHelp();
    return 0;
  }
  
  uint32_t cmmand_param_num = (uint32_t)command_lines.size();
  
  // 检测输入参数
  if (cmd->cmd_num_max != 0) {
    if (cmmand_param_num < cmd->cmd_num_min || cmmand_param_num > cmd->cmd_num_max) {
      PrintHelp();
      return 0;
    }
  } else {
    if (cmmand_param_num != cmd->cmd_num_min) {
      PrintHelp();
      return 0;
    }
  }
  
  return cmd->handler(command_lines);
}



