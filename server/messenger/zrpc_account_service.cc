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

#include "messenger/zrpc_account_service.h"

#include "nebula/base/logger/glog_util.h"
#include "proto/api/error_codes.h"

int ZRpcAccountService::account_changePhone(const mtproto::TL_account_changePhone& request, std::shared_ptr<mtproto::User>& response) {
  LOG(ERROR) << "account_changePhone not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_checkUsername(const mtproto::TL_account_checkUsername& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_checkUsername not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_confirmPhone(const mtproto::TL_account_confirmPhone& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_confirmPhone not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_deleteAccount(const mtproto::TL_account_deleteAccount& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_deleteAccount not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_getAccountTTL(const mtproto::TL_account_getAccountTTL& request, std::shared_ptr<mtproto::AccountDaysTTL>& response) {
  LOG(ERROR) << "account_getAccountTTL not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_getAuthorizations(const mtproto::TL_account_getAuthorizations& request, std::shared_ptr<mtproto::account_Authorizations>& response) {
  LOG(ERROR) << "account_getAuthorizations not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_getNotifySettings(const mtproto::TL_account_getNotifySettings& request, std::shared_ptr<mtproto::PeerNotifySettings>& response) {
  LOG(ERROR) << "account_getNotifySettings not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_getPassword(const mtproto::TL_account_getPassword& request, std::shared_ptr<mtproto::account_Password>& response) {
  LOG(ERROR) << "account_getPassword not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_getPasswordSettings(const mtproto::TL_account_getPasswordSettings& request, std::shared_ptr<mtproto::account_PasswordSettings>& response) {
  LOG(ERROR) << "account_getPasswordSettings not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_getPrivacy(const mtproto::TL_account_getPrivacy& request, std::shared_ptr<mtproto::account_PrivacyRules>& response) {
  LOG(ERROR) << "account_getPrivacy not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_getTmpPassword(const mtproto::TL_account_getTmpPassword& request, std::shared_ptr<mtproto::account_TmpPassword>& response) {
  LOG(ERROR) << "account_getTmpPassword not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_getWallPapers(const mtproto::TL_account_getWallPapers& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::WallPaper>>& response) {
  LOG(ERROR) << "account_getWallPapers not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_registerDevice(const mtproto::TL_account_registerDevice& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_registerDevice not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_reportPeer(const mtproto::TL_account_reportPeer& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_reportPeer not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_resetAuthorization(const mtproto::TL_account_resetAuthorization& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_resetAuthorization not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_resetNotifySettings(const mtproto::TL_account_resetNotifySettings& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_resetNotifySettings not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_sendChangePhoneCode(const mtproto::TL_account_sendChangePhoneCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) {
  LOG(ERROR) << "account_sendChangePhoneCode not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_sendConfirmPhoneCode(const mtproto::TL_account_sendConfirmPhoneCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) {
  LOG(ERROR) << "account_sendConfirmPhoneCode not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_setAccountTTL(const mtproto::TL_account_setAccountTTL& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_setAccountTTL not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_setPrivacy(const mtproto::TL_account_setPrivacy& request, std::shared_ptr<mtproto::account_PrivacyRules>& response) {
  LOG(ERROR) << "account_setPrivacy not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_unregisterDevice(const mtproto::TL_account_unregisterDevice& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_unregisterDevice not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_updateDeviceLocked(const mtproto::TL_account_updateDeviceLocked& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_updateDeviceLocked not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_updateNotifySettings(const mtproto::TL_account_updateNotifySettings& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_updateNotifySettings not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_updatePasswordSettings(const mtproto::TL_account_updatePasswordSettings& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_updatePasswordSettings not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_updateProfile(const mtproto::TL_account_updateProfile& request, std::shared_ptr<mtproto::User>& response) {
  LOG(ERROR) << "account_updateProfile not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_updateStatus(const mtproto::TL_account_updateStatus& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "account_updateStatus not impl";
  return kErrNotImpl;
}

int ZRpcAccountService::account_updateUsername(const mtproto::TL_account_updateUsername& request, std::shared_ptr<mtproto::User>& response) {
  LOG(ERROR) << "account_updateUsername not impl";
  return kErrNotImpl;
}
