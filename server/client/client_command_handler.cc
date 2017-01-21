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
#include "proto/api/cc/dialogs.pb.h"
#include "proto/api/cc/misc.pb.h"
#include "proto/api/cc/messaging.pb.h"
#include "proto/api/cc/groups.pb.h"
#include "proto/api/cc/sequence.pb.h"

#include "nebula/net/zproto/api_message_box.h"
#include "nebula/net/rpc/zrpc_service_util.h"

#include "base/message_handler_util.h"

typedef int (*ClientCommandHandlerFunc)(const std::vector<folly::StringPiece>&);

//
struct CmdEntry {
  const char* cmd;                    // 命令名
  const char* cmd_help;               // 命令帮助信息
  uint32_t cmd_num_min;               // 最少参数
  uint32_t cmd_num_max;               // 最大参数，如果值为0，则无参数限制
  ClientCommandHandlerFunc handler;   // 命令处理函数
};

static std::string g_my_uid;

int DoConnect(const std::vector<folly::StringPiece>& command_lines) {
  zproto::StartTestingAuthReq start_testing_auth_req;
  start_testing_auth_req.set_app_id(1);
  g_my_uid = command_lines[3].toString();
  start_testing_auth_req.set_user_id(command_lines[3].toString());
  
  ZRpcClientCall<zproto::AuthRsp>("gate_client",
                                  MakeRpcRequest(start_testing_auth_req),
                                  [] (std::shared_ptr<ApiRpcOk<zproto::AuthRsp>> auth_rsp,
                                      ProtoRpcResponsePtr rpc_error) -> int {
                                    if (rpc_error) {
                                      LOG(ERROR) << "DoConnect - rpc_error: " << rpc_error->ToString();
                                    } else {
                                      LOG(INFO) << "DoConnect - auth_rsp: " << auth_rsp->ToString();
                                    }
                                    return 0;
                                  });

/*
  auto req = std::make_shared<ApiRpcRequest<zproto::StartTestingAuthReq>>();
  
  (*req)->set_app_id(1);
  g_my_uid = command_lines[3].toString();
  (*req)->set_user_id(command_lines[3].toString());
  
  // (*req)->set_token("benqi@zhazha.nebula.im");
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
 */
  return 0;
}

int DoGetState(const std::vector<folly::StringPiece>& command_lines) {
  zproto::GetStateReq get_state_req;
  get_state_req.add_optimizations(zproto::NONE);
  ZRpcClientCall<zproto::SeqRsp>("gate_client",
                                              MakeRpcRequest(get_state_req),
                                              [] (std::shared_ptr<ApiRpcOk<zproto::SeqRsp>> seq_rsp,
                                                  ProtoRpcResponsePtr rpc_error) -> int {
                                                if (rpc_error) {
                                                  LOG(ERROR) << "DoGetState - rpc_error: " << rpc_error->ToString();
                                                } else {
                                                  LOG(INFO) << "DoGetState - seq_rsp: " << seq_rsp->ToString();
                                                }
                                                return 0;
                                              });

  return 0;
}

int DoGetDifference(const std::vector<folly::StringPiece>& command_lines) {
  zproto::GetDifferenceReq get_difference_req;
  get_difference_req.set_seq(folly::to<int64_t>(command_lines[1]));

  ZRpcClientCall<zproto::GetDifferenceRsp>("gate_client",
                                      MakeRpcRequest(get_difference_req),
                                      [] (std::shared_ptr<ApiRpcOk<zproto::GetDifferenceRsp>> get_difference_rsp,
                                          ProtoRpcResponsePtr rpc_error) -> int {
                                        if (rpc_error) {
                                          LOG(ERROR) << "DoGetState - rpc_error: " << rpc_error->ToString();
                                        } else {
                                          LOG(INFO) << "DoGetState - seq_rsp: " << get_difference_rsp->ToString();
                                        }
                                        return 0;
                                      });

  return 0;
}

int DoCreateChatDialog(const std::vector<folly::StringPiece>& command_lines) {
  zproto::CreateChatDialogReq create_chat_dialog_req;
  create_chat_dialog_req.set_peer_id(folly::to<std::string>(command_lines[1]));
  
  ZRpcClientCall<zproto::CreateChatDialogRsp>("gate_client",
                                 MakeRpcRequest(create_chat_dialog_req),
                                 [] (std::shared_ptr<ApiRpcOk<zproto::CreateChatDialogRsp>> create_chat_dialog_rsp,
                                     ProtoRpcResponsePtr rpc_error) -> int {
                                   if (rpc_error) {
                                     LOG(ERROR) << "DoCreateChatDialog - rpc_error: " << rpc_error->ToString();
                                   } else {
                                     LOG(INFO) << "DoCreateChatDialog - seq_rsp: " << create_chat_dialog_rsp->ToString();
                                   }
                                   return 0;
                                 });
  return 0;
}

int DoLoadDialogs(const std::vector<folly::StringPiece>& command_lines) {
  zproto::LoadDialogsReq load_dialogs_req;
  load_dialogs_req.set_min_date(0);
  load_dialogs_req.set_limit(100);
  load_dialogs_req.set_load_mode(zproto::FORWARD);
  ZRpcClientCall<zproto::LoadDialogsRsp>("gate_client",
                                         MakeRpcRequest(load_dialogs_req),
                                         [] (std::shared_ptr<ApiRpcOk<zproto::LoadDialogsRsp>> load_dialogs_rsp,
                                             ProtoRpcResponsePtr rpc_error) -> int {
                                           if (rpc_error) {
                                             LOG(ERROR) << "DoLoadDialogs - rpc_error: " << rpc_error->ToString();
                                           } else {
                                             LOG(INFO) << "DoLoadDialogs - load_dialogs_rsp: " << load_dialogs_rsp->ToString();
                                           }
                                           return 0;
                                         });
  return 0;
}

int DoBlockPeer(const std::vector<folly::StringPiece>& command_lines) {
  zproto::BlockPeerReq block_peer_req;
  block_peer_req.mutable_peer()->set_id(folly::to<std::string>(command_lines[1]));
  block_peer_req.mutable_peer()->set_type(folly::to<zproto::PeerType>(command_lines[2]));
  
  ZRpcClientCall<zproto::SeqRsp>("gate_client",
                                 MakeRpcRequest(block_peer_req),
                                 [] (std::shared_ptr<ApiRpcOk<zproto::SeqRsp>> seq_rsp,
                                     ProtoRpcResponsePtr rpc_error) -> int {
                                   if (rpc_error) {
                                     LOG(ERROR) << "DoBlockPeer - rpc_error: " << rpc_error->ToString();
                                   } else {
                                     LOG(INFO) << "DoBlockPeer - seq_rsp: " << seq_rsp->ToString();
                                   }
                                   return 0;
                                 });
  return 0;
}

int DoUnblockPeer(const std::vector<folly::StringPiece>& command_lines) {
  zproto::UnblockPeerReq unblock_peer_req;
  unblock_peer_req.mutable_peer()->set_id(folly::to<std::string>(command_lines[1]));
  unblock_peer_req.mutable_peer()->set_type(folly::to<zproto::PeerType>(command_lines[2]));
  
  ZRpcClientCall<zproto::SeqRsp>("gate_client",
                                 MakeRpcRequest(unblock_peer_req),
                                 [] (std::shared_ptr<ApiRpcOk<zproto::SeqRsp>> seq_rsp,
                                     ProtoRpcResponsePtr rpc_error) -> int {
                                   if (rpc_error) {
                                     LOG(ERROR) << "DoUnBlockPeer - rpc_error: " << rpc_error->ToString();
                                   } else {
                                     LOG(INFO) << "DoUnBlockPeer - seq_rsp: " << seq_rsp->ToString();
                                   }
                                   return 0;
                                 });
  return 0;
}

int DoTopPeer(const std::vector<folly::StringPiece>& command_lines) {
  zproto::TopPeerReq top_peer_req;
  top_peer_req.mutable_peer()->set_id(folly::to<std::string>(command_lines[1]));
  top_peer_req.mutable_peer()->set_type(folly::to<zproto::PeerType>(command_lines[2]));
  
  ZRpcClientCall<zproto::SeqRsp>("gate_client",
                                 MakeRpcRequest(top_peer_req),
                                 [] (std::shared_ptr<ApiRpcOk<zproto::SeqRsp>> seq_rsp,
                                     ProtoRpcResponsePtr rpc_error) -> int {
                                   if (rpc_error) {
                                     LOG(ERROR) << "DoTopPeer - rpc_error: " << rpc_error->ToString();
                                   } else {
                                     LOG(INFO) << "DoTopPeer - seq_rsp: " << seq_rsp->ToString();
                                   }
                                   return 0;
                                 });
  return 0;
}

int DoUntopPeer(const std::vector<folly::StringPiece>& command_lines) {
  zproto::UntopPeerReq untop_peer_req;
  untop_peer_req.mutable_peer()->set_id(folly::to<std::string>(command_lines[1]));
  untop_peer_req.mutable_peer()->set_type(folly::to<zproto::PeerType>(command_lines[2]));
  
  ZRpcClientCall<zproto::SeqRsp>("gate_client",
                                 MakeRpcRequest(untop_peer_req),
                                 [] (std::shared_ptr<ApiRpcOk<zproto::SeqRsp>> seq_rsp,
                                     ProtoRpcResponsePtr rpc_error) -> int {
                                   if (rpc_error) {
                                     LOG(ERROR) << "DoUnTopPeer - rpc_error: " << rpc_error->ToString();
                                   } else {
                                     LOG(INFO) << "DoUnTopPeer - seq_rsp: " << seq_rsp->ToString();
                                   }
                                   return 0;
                                 });
  return 0;
}

int DoDndPeer(const std::vector<folly::StringPiece>& command_lines) {
  zproto::DndPeerReq dnd_peer_req;
  dnd_peer_req.mutable_peer()->set_id(folly::to<std::string>(command_lines[1]));
  dnd_peer_req.mutable_peer()->set_type(folly::to<zproto::PeerType>(command_lines[2]));
  
  ZRpcClientCall<zproto::SeqRsp>("gate_client",
                                 MakeRpcRequest(dnd_peer_req),
                                 [] (std::shared_ptr<ApiRpcOk<zproto::SeqRsp>> seq_rsp,
                                     ProtoRpcResponsePtr rpc_error) -> int {
                                   if (rpc_error) {
                                     LOG(ERROR) << "DoDndPeer - rpc_error: " << rpc_error->ToString();
                                   } else {
                                     LOG(INFO) << "DoDndPeer - seq_rsp: " << seq_rsp->ToString();
                                   }
                                   return 0;
                                 });
  return 0;
}

int DoUndndPeer(const std::vector<folly::StringPiece>& command_lines) {
  zproto::UndndPeerReq undnd_peer_req;
  undnd_peer_req.mutable_peer()->set_id(folly::to<std::string>(command_lines[1]));
  undnd_peer_req.mutable_peer()->set_type(folly::to<zproto::PeerType>(command_lines[2]));
  
  ZRpcClientCall<zproto::SeqRsp>("gate_client",
                                 MakeRpcRequest(undnd_peer_req),
                                 [] (std::shared_ptr<ApiRpcOk<zproto::SeqRsp>> seq_rsp,
                                     ProtoRpcResponsePtr rpc_error) -> int {
                                   if (rpc_error) {
                                     LOG(ERROR) << "DoUnDndPeer - rpc_error: " << rpc_error->ToString();
                                   } else {
                                     LOG(INFO) << "DoUnDndPeer - seq_rsp: " << seq_rsp->ToString();
                                   }
                                   return 0;
                                 });
  return 0;
}


int DoSendMessage(const std::vector<folly::StringPiece>& command_lines) {
  auto req = std::make_shared<ApiRpcRequest<zproto::SendMessageReq>>();
  auto peer = (*req)->mutable_peer();
  peer->set_id(command_lines[1].toString());
  peer->set_type(zproto::PEER_TYPE_PRIVATE);
  peer->set_access_hash(1);
  auto message = (*req)->mutable_message();
  message->set_message_type(zproto::TEXT);
  message->set_message_data(command_lines[2].toString());
  (*req)->set_rid(GetNextIDBySnowflake());
  
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
  return 0;
}

int DoSendGroupMessage(const std::vector<folly::StringPiece>& command_lines) {
  auto req = std::make_shared<ApiRpcRequest<zproto::SendMessageReq>>();
  auto peer = (*req)->mutable_peer();
  peer->set_id(command_lines[1].toString());
  peer->set_type(zproto::PEER_TYPE_GROUP);
  peer->set_access_hash(1);
  auto message = (*req)->mutable_message();
  message->set_message_type(zproto::TEXT);
  message->set_message_data(command_lines[2].toString());
  (*req)->set_rid(GetNextIDBySnowflake());
  
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
  return 0;
}

/*
int DoMessageSync(const std::vector<folly::StringPiece>& command_lines) {
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
  return 0;
}
 */

// Creating group chat
// CreateGroupReq --> CreateGroupRsp
int DoCreateGroup(const std::vector<folly::StringPiece>& command_lines) {
  zproto::CreateGroupReq create_group_req;
  create_group_req.set_rid(GetNextIDBySnowflake());
  create_group_req.set_title(command_lines[1].toString());
  
  for (size_t i=2; i<command_lines.size(); ++i) {
    auto user = create_group_req.add_users();
    user->set_access_hash(i);
    user->set_uid(command_lines[i].toString());
  }

  LOG(INFO) << "DoCreateGroup - req: " << create_group_req.Utf8DebugString();
  
  ZRpcUtil::DoClientCall("gate_client", MakeRpcRequest(create_group_req))
  .within(std::chrono::milliseconds(5000))
  .then([](ProtoRpcResponsePtr rsp) {
    LOG(INFO) << "DoCreateGroup - rsp";
    LOG(INFO) << rsp->ToString();
  });
  return 0;
}


int DoClose(const std::vector<folly::StringPiece>& command_lines) {
  // exit(0);
  return -2;
}

int DoQuit(const std::vector<folly::StringPiece>& command_lines) {
  // exit(0);
  return -2;
}

CmdEntry g_cmds[] = {
  // login/logout
  {"connect", "connect serv_ip serv_port user_id", 4, 4, DoConnect},
  {"get_state", "get_state", 1, 1, DoGetState},
  {"get_difference", "get_difference", 2, 2, DoGetDifference},
  {"create_chat_dialog", "create_chat_dialog user_id", 2, 2, DoCreateChatDialog},
  {"load_dialogs", "load_dialogs", 1, 1, DoLoadDialogs},
  {"block_peer", "block_peer peer_id peer_type", 3, 3, DoBlockPeer},
  {"unblock_peer", "unblock_peer peer_id peer_type", 3, 3, DoUnblockPeer},
  {"top_peer", "top_peer peer_id peer_type", 3, 3, DoTopPeer},
  {"untop_peer", "unblock_peer peer_id peer_type", 3, 3, DoUntopPeer},
  {"dnd_peer", "dnd_peer peer_id peer_type", 3, 3, DoDndPeer},
  {"undnd_peer", "undnd_peer peer_id peer_type", 3, 3, DoUndndPeer},
  {"send_message", "send_message user_id content", 3, 3, DoSendMessage},
  {"send_group_message", "send_group_message group_id content", 3, 3, DoSendGroupMessage},
  {"create_group", "create_group group_title uid1...", 3, 0, DoCreateGroup},
  {"close", "close", 1, 1, DoClose},
  // quit
  {"quit", "quit", 1, 1, DoQuit}
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
