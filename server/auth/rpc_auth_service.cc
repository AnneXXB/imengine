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
#include "biz_model/user_model.h"
#include "proto/api_message_box.h"


ProtoRpcResponsePtr DoUserTokenAuthReq(RpcRequestPtr request) {
  auto user_token_auth_req = ToApiRpcRequest<zproto::UserTokenAuthReq>(request);
  LOG(INFO) << "DoUserTokenAuthReq - user_token_auth_req ==> " << user_token_auth_req->ToString();
  LOG(INFO) << (*user_token_auth_req)->Utf8DebugString();
  
  UserEntity user_entity;
  GetUserInfoByUserNamePasswd get_user_info_by_user_name_passwd(
                                                                1,
                                                                (*user_token_auth_req)->user_id(),
                                                                (*user_token_auth_req)->user_token(),
                                                                user_entity);
  
  auto rv = SqlQuery("nebula_platform", get_user_info_by_user_name_passwd);
  
  auto user_token_auth_rsp = std::make_shared<ApiRpcOk<zproto::UserTokenAuthRsp>>();
  user_token_auth_rsp->set_req_message_id(request->message_id());
  (*user_token_auth_rsp)->set_app_id(1);
  (*user_token_auth_rsp)->set_user_id(user_entity.user_id);
  (*user_token_auth_rsp)->set_nick(user_entity.nick);
  (*user_token_auth_rsp)->set_avatar(user_entity.avatar);
  
//  (*login_rsp)->set_server_time(Now());
//  (*login_rsp)->set_result_code(teamtalk::REFUSE_REASON_NONE);
//  (*login_rsp)->set_online_status(teamtalk::USER_STATUS_ONLINE);
//  
//  auto user_info = (*login_rsp)->mutable_user_info();
//  user_info->set_id(user_entity.id);
//  user_info->set_user_gender(1);
//  user_info->set_user_nick_name(user_entity.nick);
//  user_info->set_avatar_url(user_entity.avatar);
//  user_info->set_department_id(1);
//  user_info->set_email("wubenqi@gmail.com");
//  user_info->set_user_real_name("wubenqi");
//  user_info->set_user_tel("10086");
//  user_info->set_user_domain("wubenqi");
//  user_info->set_status(0);
//  
//  LOG(INFO) << (*login_rsp)->Utf8DebugString();
  
  LOG(INFO) << "DoUserTokenAuthReq - user_token_auth_rsp ==> " << user_token_auth_rsp->ToString();

  return user_token_auth_rsp;
}
