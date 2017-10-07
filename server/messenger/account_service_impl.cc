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

#include "messenger/account_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int AccountServiceImpl::account_changePhone(const mtproto::TL_account_changePhone& request, std::shared_ptr<mtproto::User>& response) {
  LOG(INFO) << "account_changePhone - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_checkUsername(const mtproto::TL_account_checkUsername& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_checkUsername - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_confirmPhone(const mtproto::TL_account_confirmPhone& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_confirmPhone - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_deleteAccount(const mtproto::TL_account_deleteAccount& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_deleteAccount - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_getAccountTTL(const mtproto::TL_account_getAccountTTL& request, std::shared_ptr<mtproto::AccountDaysTTL>& response) {
  LOG(INFO) << "account_getAccountTTL - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_getAuthorizations(const mtproto::TL_account_getAuthorizations& request, std::shared_ptr<mtproto::account_Authorizations>& response) {
  LOG(INFO) << "account_getAuthorizations - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_getNotifySettings(const mtproto::TL_account_getNotifySettings& request, std::shared_ptr<mtproto::PeerNotifySettings>& response) {
  LOG(INFO) << "account_getNotifySettings - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_getPassword(const mtproto::TL_account_getPassword& request, std::shared_ptr<mtproto::account_Password>& response) {
  LOG(INFO) << "account_getPassword - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_getPasswordSettings(const mtproto::TL_account_getPasswordSettings& request, std::shared_ptr<mtproto::account_PasswordSettings>& response) {
  LOG(INFO) << "account_getPasswordSettings - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_getPrivacy(const mtproto::TL_account_getPrivacy& request, std::shared_ptr<mtproto::account_PrivacyRules>& response) {
  LOG(INFO) << "account_getPrivacy - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_getTmpPassword(const mtproto::TL_account_getTmpPassword& request, std::shared_ptr<mtproto::account_TmpPassword>& response) {
  LOG(INFO) << "account_getTmpPassword - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_getWallPapers(const mtproto::TL_account_getWallPapers& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::WallPaper>>& response) {
  LOG(INFO) << "account_getWallPapers - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_registerDevice(const mtproto::TL_account_registerDevice& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_registerDevice - " << request.ToString();

  auto token_type = request.token_type();
  auto token = request.token();
  LOG(INFO) << "token_type = " << token_type << ", token = " << token;
  response = std::make_shared<mtproto::TL_boolTrue>();

  return kErrOK;
}

int AccountServiceImpl::account_reportPeer(const mtproto::TL_account_reportPeer& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_reportPeer - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_resetAuthorization(const mtproto::TL_account_resetAuthorization& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_resetAuthorization - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_resetNotifySettings(const mtproto::TL_account_resetNotifySettings& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_resetNotifySettings - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_sendChangePhoneCode(const mtproto::TL_account_sendChangePhoneCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) {
  LOG(INFO) << "account_sendChangePhoneCode - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_sendConfirmPhoneCode(const mtproto::TL_account_sendConfirmPhoneCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) {
  LOG(INFO) << "account_sendConfirmPhoneCode - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_setAccountTTL(const mtproto::TL_account_setAccountTTL& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_setAccountTTL - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_setPrivacy(const mtproto::TL_account_setPrivacy& request, std::shared_ptr<mtproto::account_PrivacyRules>& response) {
  LOG(INFO) << "account_setPrivacy - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_unregisterDevice(const mtproto::TL_account_unregisterDevice& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_unregisterDevice - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_updateDeviceLocked(const mtproto::TL_account_updateDeviceLocked& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_updateDeviceLocked - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_updateNotifySettings(const mtproto::TL_account_updateNotifySettings& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_updateNotifySettings - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_updatePasswordSettings(const mtproto::TL_account_updatePasswordSettings& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_updatePasswordSettings - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_updateProfile(const mtproto::TL_account_updateProfile& request, std::shared_ptr<mtproto::User>& response) {
  LOG(INFO) << "account_updateProfile - " << request.ToString();
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_updateStatus(const mtproto::TL_account_updateStatus& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "account_updateStatus - " << request.ToString();
  
  auto r = std::make_shared<mtproto::TL_boolTrue>();
  response = r;
  
  return kErrNotImpl;
}

int AccountServiceImpl::account_updateUsername(const mtproto::TL_account_updateUsername& request, std::shared_ptr<mtproto::User>& response) {
  LOG(INFO) << "account_updateUsername - " << request.ToString();
  
  return kErrNotImpl;
}
