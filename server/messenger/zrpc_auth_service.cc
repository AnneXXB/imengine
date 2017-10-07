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

#include "messenger/zrpc_auth_service.h"

#include "nebula/base/logger/glog_util.h"
#include "proto/api/error_codes.h"

int ZRpcAuthService::auth_bindTempAuthKey(const mtproto::TL_auth_bindTempAuthKey& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "auth_bindTempAuthKey not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_cancelCode(const mtproto::TL_auth_cancelCode& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "auth_cancelCode not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_checkPassword(const mtproto::TL_auth_checkPassword& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(ERROR) << "auth_checkPassword not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_checkPhone(const mtproto::TL_auth_checkPhone& request, std::shared_ptr<mtproto::auth_CheckedPhone>& response) {
  LOG(ERROR) << "auth_checkPhone not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_dropTempAuthKeys(const mtproto::TL_auth_dropTempAuthKeys& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "auth_dropTempAuthKeys not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_exportAuthorization(const mtproto::TL_auth_exportAuthorization& request, std::shared_ptr<mtproto::auth_ExportedAuthorization>& response) {
  LOG(ERROR) << "auth_exportAuthorization not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_importAuthorization(const mtproto::TL_auth_importAuthorization& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(ERROR) << "auth_importAuthorization not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_importBotAuthorization(const mtproto::TL_auth_importBotAuthorization& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(ERROR) << "auth_importBotAuthorization not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_logOut(const mtproto::TL_auth_logOut& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "auth_logOut not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_recoverPassword(const mtproto::TL_auth_recoverPassword& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(ERROR) << "auth_recoverPassword not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_requestPasswordRecovery(const mtproto::TL_auth_requestPasswordRecovery& request, std::shared_ptr<mtproto::auth_PasswordRecovery>& response) {
  LOG(ERROR) << "auth_requestPasswordRecovery not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_resendCode(const mtproto::TL_auth_resendCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) {
  LOG(ERROR) << "auth_resendCode not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_resetAuthorizations(const mtproto::TL_auth_resetAuthorizations& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "auth_resetAuthorizations not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_sendCode(const mtproto::TL_auth_sendCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) {
  LOG(ERROR) << "auth_sendCode not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_sendInvites(const mtproto::TL_auth_sendInvites& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "auth_sendInvites not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_signIn(const mtproto::TL_auth_signIn& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(ERROR) << "auth_signIn not impl";
  return kErrNotImpl;
}

int ZRpcAuthService::auth_signUp(const mtproto::TL_auth_signUp& request, std::shared_ptr<mtproto::auth_Authorization>& response) {
  LOG(ERROR) << "auth_signUp not impl";
  return kErrNotImpl;
}

