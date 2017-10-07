/**
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

#include "dal/online_status_dao_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"

#include "proto/s2s/cc/presences.pb.h"
#include "nebula/net/zproto/zproto_api_message_box.h"

OnlineStatusDAO& OnlineStatusDAO::GetInstance() {
  static OnlineStatusDAOImpl impl;
  return impl;
}

bool OnlineStatusDAOImpl::GetUsersOnlineStatus(uint32_t app_id,
                                               const std::list<std::string>& user_id_list,
                                               OnlineStatusDOList& onlines,
                                               uint64_t my_conn_id)  {
  // auto req = std::make_shared<zproto::ApiRpcRequest<zproto::QueryOnlineUserReq>>();
  zproto::QueryOnlineUserReq req;
  for (const auto& v : user_id_list) {
    auto user_id = req.add_user_id_list();
    user_id->set_app_id(app_id);
    user_id->set_user_id(v);
  }
  
  // TODO(@benqi): 还是用协程简单
  
  bool rv = false;
  auto rsp = ZRpcUtil::DoClientCall("status_rpc_client", zproto::MakeRpcRequest(req))
  .within(std::chrono::milliseconds(5000))
  .then([&](zproto::ProtoRpcResponsePtr rsp) {
    CHECK(rsp);
    LOG(INFO) << "online_client rsp: " << rsp->ToString();
    
    if (rsp->GetPackageType() == zproto::Package::RPC_OK) {
      rv = true;
//      auto online_users = zproto::ToApiRpcOk<zproto::QueryOnlineUserRsp>(rsp);
//      for (int i=0; i<(*online_users)->online_users_size(); ++i) {
//        auto online_user = (*online_users)->online_users(i);
//        onlines.emplace_back(online_user.server_id(), online_user.conn_id(), 1);
//      }
    }
  });
  
  rsp.get();

  return rv;
}
