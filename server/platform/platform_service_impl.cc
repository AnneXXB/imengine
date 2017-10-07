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

// TODO(@benqi): 使用zrpc-code-gen代码生成工具自动生成服务框架代码

#include "auth/auth_service_impl.h"

#include "nebula/base/time_util.h"
#include "dal/user_dao_impl.h"
//#include "biz_model/user_model.h"
// #include "proto/zproto/zproto_api_message_types.h"

int AuthServiceImpl::StartTestingAuth(const zproto::StartTestingAuthReq& request, zproto::AuthRsp* response) {
  LOG(INFO) << "StartTestingAuth - " << request.Utf8DebugString();
  UserDO user_do;
  UserDAO::GetInstance().GetUserByUserID(1,
                                         request.user_id(),
                                         user_do);
  
  auto user = response->mutable_user();
  user->set_uid(user_do.user_id);
  // user->set_nick(user_do.nick);
  // user->set_name(user_do.nick);
  // user->mutable_avatar()->set set_avatar(user_do.avatar);
  
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
int AuthServiceImpl::StartTokenAuth(const zproto::StartTokenAuthReq& request, zproto::AuthRsp* response) {
  LOG(INFO) << "StartTokenAuth - " << request.Utf8DebugString();

  UserDO user_do;
  UserDAO::GetInstance().GetUserByNamePasswd(1,
                                             request.api_key(),
                                             request.token(),
                                             user_do);
  
  auto user = response->mutable_user();
  user->set_uid(user_do.user_id);
  // user->set_nick(user_do.nick);
  // user->set_name(user_do.nick);
  // user->mutable_avatar()->set set_avatar(user_do.avatar);

  return 0;
}
