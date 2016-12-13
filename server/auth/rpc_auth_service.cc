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

#include "auth/rpc_auth_service.h"

#include "nebula/base/time_util.h"
#include "dal/user_dao_impl.h"
//#include "biz_model/user_model.h"
#include "proto/zproto/zproto_api_message_types.h"

void AuthRpcRegister() {
  ZRpcUtil::Register("zproto.UserTokenAuthReq", DoUserTokenAuthReq);
}

///////////////////////////////////////////////////////////////////////////////
int DoUserTokenAuthReqInternal(uint64_t conn_id,
                               const zproto::UserTokenAuthReq& user_token_auth_req,
                               zproto::UserTokenAuthRsp* user_token_auth_rsp) {

  UserDO user;

  UserDAO::GetInstance().GetUserByNamePasswd(1,
                          user_token_auth_req.user_id(),
                          user_token_auth_req.user_token(),
                          user);

  user_token_auth_rsp->set_app_id(1);
  user_token_auth_rsp->set_user_id(user.user_id);
  user_token_auth_rsp->set_nick(user.nick);
  user_token_auth_rsp->set_avatar(user.avatar);
  
  return 0;
}

ProtoRpcResponsePtr DoUserTokenAuthReq(RpcRequestPtr request) {
  CAST_RPC_REQUEST(UserTokenAuthReq, user_token_auth_req);
  zproto::UserTokenAuthRsp user_token_auth_rsp;
  
  DoUserTokenAuthReqInternal(request->session_id(), user_token_auth_req, &user_token_auth_rsp);
  
  return MakeRpcOK(user_token_auth_rsp);
}
