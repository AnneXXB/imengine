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

#include "messenger/auth_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int AuthServiceImpl::auth_bindTempAuthKey(const mtproto::TL_auth_bindTempAuthKey& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "auth_bindTempAuthKey - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_cancelCode(const mtproto::TL_auth_cancelCode& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "auth_cancelCode - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_checkPassword(const mtproto::TL_auth_checkPassword& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(INFO) << "auth_checkPassword - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_checkPhone(const mtproto::TL_auth_checkPhone& request, std::shared_ptr<mtproto::auth_CheckedPhone>& response) {
  LOG(INFO) << "auth_checkPhone - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_dropTempAuthKeys(const mtproto::TL_auth_dropTempAuthKeys& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "auth_dropTempAuthKeys - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_exportAuthorization(const mtproto::TL_auth_exportAuthorization& request, std::shared_ptr<mtproto::auth_ExportedAuthorization>& response) {
  LOG(INFO) << "auth_exportAuthorization - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_importAuthorization(const mtproto::TL_auth_importAuthorization& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(INFO) << "auth_importAuthorization - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_importBotAuthorization(const mtproto::TL_auth_importBotAuthorization& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(INFO) << "auth_importBotAuthorization - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_logOut(const mtproto::TL_auth_logOut& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "auth_logOut - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_recoverPassword(const mtproto::TL_auth_recoverPassword& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(INFO) << "auth_recoverPassword - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_requestPasswordRecovery(const mtproto::TL_auth_requestPasswordRecovery& request, std::shared_ptr<mtproto::auth_PasswordRecovery>& response) {
  LOG(INFO) << "auth_requestPasswordRecovery - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_resendCode(const mtproto::TL_auth_resendCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) {
  LOG(INFO) << "auth_resendCode - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_resetAuthorizations(const mtproto::TL_auth_resetAuthorizations& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "auth_resetAuthorizations - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_sendCode(const mtproto::TL_auth_sendCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) {
  LOG(INFO) << "auth_sendCode - " << request.ToString();
  
  auto auth_sentCode = std::make_shared<mtproto::TL_auth_sentCode>();
  auto sent_code_type = auth_sentCode->mutable_type<mtproto::TL_auth_sentCodeTypeApp>();
  sent_code_type->set_length(6);
  auth_sentCode->set_phone_code_hash("123456");
  
  response = auth_sentCode;
  return kErrOK;
}

int AuthServiceImpl::auth_sendInvites(const mtproto::TL_auth_sendInvites& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "auth_sendInvites - " << request.ToString();
  
  return kErrNotImpl;
}

int AuthServiceImpl::auth_signIn(const mtproto::TL_auth_signIn& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(INFO) << "auth_signIn - " << request.ToString();
  
  auto auth_authorization = std::make_shared<mtproto::TL_auth_authorization>();
  auto user = auth_authorization->mutable_user<mtproto::TL_user>();
  user->set_id(1);
  user->set_access_hash(1);
  user->set_first_name("wu");
  user->set_first_name("benqi");
  user->set_username("benqi");
  user->set_phone("8613606512716");
  
  response = auth_authorization;
  return kErrOK;
}

int AuthServiceImpl::auth_signUp(const mtproto::TL_auth_signUp& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(INFO) << "auth_signUp - " << request.ToString();
  
  return kErrNotImpl;
}

