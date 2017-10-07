/*
 *  Copyright (c) 2016, https://github.com/nebula-im
 *  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License") override;
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

#ifndef	MESSENGER_ACCOUNT_SERVICE_IMPL_H_
#define	MESSENGER_ACCOUNT_SERVICE_IMPL_H_

#include "messenger/zrpc_account_service.h"

class AccountServiceImpl : public ZRpcAccountService {
public:
  AccountServiceImpl() = default;
  ~AccountServiceImpl() = default;
  
  // account.changePhone#70c32edb phone_number:string phone_code_hash:string phone_code:string = User;
  int account_changePhone(const mtproto::TL_account_changePhone& request, std::shared_ptr<mtproto::User>& response) override;
  
  // account.checkUsername#2714d86c username:string = Bool;
  int account_checkUsername(const mtproto::TL_account_checkUsername& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.confirmPhone#5f2178c3 phone_code_hash:string phone_code:string = Bool;
  int account_confirmPhone(const mtproto::TL_account_confirmPhone& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.deleteAccount#418d4e0b reason:string = Bool;
  int account_deleteAccount(const mtproto::TL_account_deleteAccount& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.getAccountTTL#8fc711d = AccountDaysTTL;
  int account_getAccountTTL(const mtproto::TL_account_getAccountTTL& request, std::shared_ptr<mtproto::AccountDaysTTL>& response) override;
  
  // account.getAuthorizations#e320c158 = account.Authorizations;
  int account_getAuthorizations(const mtproto::TL_account_getAuthorizations& request, std::shared_ptr<mtproto::account_Authorizations>& response) override;
  
  // account.getNotifySettings#12b3ad31 peer:InputNotifyPeer = PeerNotifySettings;
  int account_getNotifySettings(const mtproto::TL_account_getNotifySettings& request, std::shared_ptr<mtproto::PeerNotifySettings>& response) override;
  
  // account.getPassword#548a30f5 = account.Password;
  int account_getPassword(const mtproto::TL_account_getPassword& request, std::shared_ptr<mtproto::account_Password>& response) override;
  
  // account.getPasswordSettings#bc8d11bb current_password_hash:bytes = account.PasswordSettings;
  int account_getPasswordSettings(const mtproto::TL_account_getPasswordSettings& request, std::shared_ptr<mtproto::account_PasswordSettings>& response) override;
  
  // account.getPrivacy#dadbc950 key:InputPrivacyKey = account.PrivacyRules;
  int account_getPrivacy(const mtproto::TL_account_getPrivacy& request, std::shared_ptr<mtproto::account_PrivacyRules>& response) override;
  
  // account.getTmpPassword#4a82327e password_hash:bytes period:int = account.TmpPassword;
  int account_getTmpPassword(const mtproto::TL_account_getTmpPassword& request, std::shared_ptr<mtproto::account_TmpPassword>& response) override;
  
  // account.getWallPapers#c04cfac2 = Vector<WallPaper>;
  int account_getWallPapers(const mtproto::TL_account_getWallPapers& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::WallPaper>>& response) override;
  
  // account.registerDevice#637ea878 token_type:int token:string = Bool;
  int account_registerDevice(const mtproto::TL_account_registerDevice& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.reportPeer#ae189d5f peer:InputPeer reason:ReportReason = Bool;
  int account_reportPeer(const mtproto::TL_account_reportPeer& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.resetAuthorization#df77f3bc hash:long = Bool;
  int account_resetAuthorization(const mtproto::TL_account_resetAuthorization& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.resetNotifySettings#db7e1747 = Bool;
  int account_resetNotifySettings(const mtproto::TL_account_resetNotifySettings& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.sendChangePhoneCode#8e57deb flags:# allow_flashcall:flags.0?true phone_number:string current_number:flags.0?Bool = auth.SentCode;
  int account_sendChangePhoneCode(const mtproto::TL_account_sendChangePhoneCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) override;
  
  // account.sendConfirmPhoneCode#1516d7bd flags:# allow_flashcall:flags.0?true hash:string current_number:flags.0?Bool = auth.SentCode;
  int account_sendConfirmPhoneCode(const mtproto::TL_account_sendConfirmPhoneCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) override;
  
  // account.setAccountTTL#2442485e ttl:AccountDaysTTL = Bool;
  int account_setAccountTTL(const mtproto::TL_account_setAccountTTL& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.setPrivacy#c9f81ce8 key:InputPrivacyKey rules:Vector<InputPrivacyRule> = account.PrivacyRules;
  int account_setPrivacy(const mtproto::TL_account_setPrivacy& request, std::shared_ptr<mtproto::account_PrivacyRules>& response) override;
  
  // account.unregisterDevice#65c55b40 token_type:int token:string = Bool;
  int account_unregisterDevice(const mtproto::TL_account_unregisterDevice& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.updateDeviceLocked#38df3532 period:int = Bool;
  int account_updateDeviceLocked(const mtproto::TL_account_updateDeviceLocked& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.updateNotifySettings#84be5b93 peer:InputNotifyPeer settings:InputPeerNotifySettings = Bool;
  int account_updateNotifySettings(const mtproto::TL_account_updateNotifySettings& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.updatePasswordSettings#fa7c4b86 current_password_hash:bytes new_settings:account.PasswordInputSettings = Bool;
  int account_updatePasswordSettings(const mtproto::TL_account_updatePasswordSettings& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.updateProfile#78515775 flags:# first_name:flags.0?string last_name:flags.1?string about:flags.2?string = User;
  int account_updateProfile(const mtproto::TL_account_updateProfile& request, std::shared_ptr<mtproto::User>& response) override;
  
  // account.updateStatus#6628562c offline:Bool = Bool;
  int account_updateStatus(const mtproto::TL_account_updateStatus& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // account.updateUsername#3e0bdd7c username:string = User;
  int account_updateUsername(const mtproto::TL_account_updateUsername& request, std::shared_ptr<mtproto::User>& response) override;
};

#endif
