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

#ifndef	MESSENGER_ZRPC_ACCOUNT_SERVICE_H_
#define	MESSENGER_ZRPC_ACCOUNT_SERVICE_H_

#include "base/base_zrpc_service.h"
#include "proto/mtproto/core/mtproto_schema.h"

class ZRpcAccountService : public BaseZRpcService {
public:
  virtual ~ZRpcAccountService() = default;

  // account.changePhone#70c32edb phone_number:string phone_code_hash:string phone_code:string = User;
  virtual int account_changePhone(const mtproto::TL_account_changePhone& request, std::shared_ptr<mtproto::User>& response);
  
  // account.checkUsername#2714d86c username:string = Bool;
  virtual int account_checkUsername(const mtproto::TL_account_checkUsername& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.confirmPhone#5f2178c3 phone_code_hash:string phone_code:string = Bool;
  virtual int account_confirmPhone(const mtproto::TL_account_confirmPhone& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.deleteAccount#418d4e0b reason:string = Bool;
  virtual int account_deleteAccount(const mtproto::TL_account_deleteAccount& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.getAccountTTL#8fc711d = AccountDaysTTL;
  virtual int account_getAccountTTL(const mtproto::TL_account_getAccountTTL& request, std::shared_ptr<mtproto::AccountDaysTTL>& response);
  
  // account.getAuthorizations#e320c158 = account.Authorizations;
  virtual int account_getAuthorizations(const mtproto::TL_account_getAuthorizations& request, std::shared_ptr<mtproto::account_Authorizations>& response);
  
  // account.getNotifySettings#12b3ad31 peer:InputNotifyPeer = PeerNotifySettings;
  virtual int account_getNotifySettings(const mtproto::TL_account_getNotifySettings& request, std::shared_ptr<mtproto::PeerNotifySettings>& response);
  
  // account.getPassword#548a30f5 = account.Password;
  virtual int account_getPassword(const mtproto::TL_account_getPassword& request, std::shared_ptr<mtproto::account_Password>& response);
  
  // account.getPasswordSettings#bc8d11bb current_password_hash:bytes = account.PasswordSettings;
  virtual int account_getPasswordSettings(const mtproto::TL_account_getPasswordSettings& request, std::shared_ptr<mtproto::account_PasswordSettings>& response);
  
  // account.getPrivacy#dadbc950 key:InputPrivacyKey = account.PrivacyRules;
  virtual int account_getPrivacy(const mtproto::TL_account_getPrivacy& request, std::shared_ptr<mtproto::account_PrivacyRules>& response);
  
  // account.getTmpPassword#4a82327e password_hash:bytes period:int = account.TmpPassword;
  virtual int account_getTmpPassword(const mtproto::TL_account_getTmpPassword& request, std::shared_ptr<mtproto::account_TmpPassword>& response);
  
  // account.getWallPapers#c04cfac2 = Vector<WallPaper>;
  virtual int account_getWallPapers(const mtproto::TL_account_getWallPapers& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::WallPaper>>& response);
  
  // account.registerDevice#637ea878 token_type:int token:string = Bool;
  virtual int account_registerDevice(const mtproto::TL_account_registerDevice& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.reportPeer#ae189d5f peer:InputPeer reason:ReportReason = Bool;
  virtual int account_reportPeer(const mtproto::TL_account_reportPeer& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.resetAuthorization#df77f3bc hash:long = Bool;
  virtual int account_resetAuthorization(const mtproto::TL_account_resetAuthorization& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.resetNotifySettings#db7e1747 = Bool;
  virtual int account_resetNotifySettings(const mtproto::TL_account_resetNotifySettings& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.sendChangePhoneCode#8e57deb flags:# allow_flashcall:flags.0?true phone_number:string current_number:flags.0?Bool = auth.SentCode;
  virtual int account_sendChangePhoneCode(const mtproto::TL_account_sendChangePhoneCode& request, std::shared_ptr<mtproto::auth_SentCode>& response);
  
  // account.sendConfirmPhoneCode#1516d7bd flags:# allow_flashcall:flags.0?true hash:string current_number:flags.0?Bool = auth.SentCode;
  virtual int account_sendConfirmPhoneCode(const mtproto::TL_account_sendConfirmPhoneCode& request, std::shared_ptr<mtproto::auth_SentCode>& response);
  
  // account.setAccountTTL#2442485e ttl:AccountDaysTTL = Bool;
  virtual int account_setAccountTTL(const mtproto::TL_account_setAccountTTL& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.setPrivacy#c9f81ce8 key:InputPrivacyKey rules:Vector<InputPrivacyRule> = account.PrivacyRules;
  virtual int account_setPrivacy(const mtproto::TL_account_setPrivacy& request, std::shared_ptr<mtproto::account_PrivacyRules>& response);
  
  // account.unregisterDevice#65c55b40 token_type:int token:string = Bool;
  virtual int account_unregisterDevice(const mtproto::TL_account_unregisterDevice& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.updateDeviceLocked#38df3532 period:int = Bool;
  virtual int account_updateDeviceLocked(const mtproto::TL_account_updateDeviceLocked& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.updateNotifySettings#84be5b93 peer:InputNotifyPeer settings:InputPeerNotifySettings = Bool;
  virtual int account_updateNotifySettings(const mtproto::TL_account_updateNotifySettings& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.updatePasswordSettings#fa7c4b86 current_password_hash:bytes new_settings:account.PasswordInputSettings = Bool;
  virtual int account_updatePasswordSettings(const mtproto::TL_account_updatePasswordSettings& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.updateProfile#78515775 flags:# first_name:flags.0?string last_name:flags.1?string about:flags.2?string = User;
  virtual int account_updateProfile(const mtproto::TL_account_updateProfile& request, std::shared_ptr<mtproto::User>& response);
  
  // account.updateStatus#6628562c offline:Bool = Bool;
  virtual int account_updateStatus(const mtproto::TL_account_updateStatus& request, std::shared_ptr<mtproto::Bool>& response);
  
  // account.updateUsername#3e0bdd7c username:string = User;
  virtual int account_updateUsername(const mtproto::TL_account_updateUsername& request, std::shared_ptr<mtproto::User>& response);
};

#endif

