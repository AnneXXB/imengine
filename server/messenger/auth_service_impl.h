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

#ifndef	MESSENGER_AUTH_SERVICE_IMPL_H_
#define	MESSENGER_AUTH_SERVICE_IMPL_H_

#include "messenger/zrpc_auth_service.h"

class AuthServiceImpl : public ZRpcAuthService {
public:
  AuthServiceImpl() = default;
  ~AuthServiceImpl() = default;
  
  // auth.bindTempAuthKey#cdd42a05 perm_auth_key_id:long nonce:long expires_at:int encrypted_message:bytes = Bool;
  int auth_bindTempAuthKey(const mtproto::TL_auth_bindTempAuthKey& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // auth.cancelCode#1f040578 phone_number:string phone_code_hash:string = Bool;
  int auth_cancelCode(const mtproto::TL_auth_cancelCode& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // auth.checkPassword#a63011e password_hash:bytes = auth.Authorization;
  int auth_checkPassword(const mtproto::TL_auth_checkPassword& request, std::shared_ptr<mtproto::auth_Authorization>& response) override;
  
  // auth.checkPhone#6fe51dfb phone_number:string = auth.CheckedPhone;
  int auth_checkPhone(const mtproto::TL_auth_checkPhone& request, std::shared_ptr<mtproto::auth_CheckedPhone>& response) override;
  
  // auth.dropTempAuthKeys#8e48a188 except_auth_keys:Vector<long> = Bool;
  int auth_dropTempAuthKeys(const mtproto::TL_auth_dropTempAuthKeys& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // auth.exportAuthorization#e5bfffcd dc_id:int = auth.ExportedAuthorization;
  int auth_exportAuthorization(const mtproto::TL_auth_exportAuthorization& request, std::shared_ptr<mtproto::auth_ExportedAuthorization>& response) override;
  
  // auth.importAuthorization#e3ef9613 id:int bytes:bytes = auth.Authorization;
  int auth_importAuthorization(const mtproto::TL_auth_importAuthorization& request, std::shared_ptr<mtproto::auth_Authorization>& response) override;
  
  // auth.importBotAuthorization#67a3ff2c flags:int api_id:int api_hash:string bot_auth_token:string = auth.Authorization;
  int auth_importBotAuthorization(const mtproto::TL_auth_importBotAuthorization& request, std::shared_ptr<mtproto::auth_Authorization>& response) override;
  
  // auth.logOut#5717da40 = Bool;
  int auth_logOut(const mtproto::TL_auth_logOut& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // auth.recoverPassword#4ea56e92 code:string = auth.Authorization;
  int auth_recoverPassword(const mtproto::TL_auth_recoverPassword& request, std::shared_ptr<mtproto::auth_Authorization>& response) override;
  
  // auth.requestPasswordRecovery#d897bc66 = auth.PasswordRecovery;
  int auth_requestPasswordRecovery(const mtproto::TL_auth_requestPasswordRecovery& request, std::shared_ptr<mtproto::auth_PasswordRecovery>& response) override;
  
  // auth.resendCode#3ef1a9bf phone_number:string phone_code_hash:string = auth.SentCode;
  int auth_resendCode(const mtproto::TL_auth_resendCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) override;
  
  // auth.resetAuthorizations#9fab0d1a = Bool;
  int auth_resetAuthorizations(const mtproto::TL_auth_resetAuthorizations& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // auth.sendCode#86aef0ec flags:# allow_flashcall:flags.0?true phone_number:string current_number:flags.0?Bool api_id:int api_hash:string = auth.SentCode;
  int auth_sendCode(const mtproto::TL_auth_sendCode& request, std::shared_ptr<mtproto::auth_SentCode>& response) override;
  
  // auth.sendInvites#771c1d97 phone_numbers:Vector<string> message:string = Bool;
  int auth_sendInvites(const mtproto::TL_auth_sendInvites& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // auth.signIn#bcd51581 phone_number:string phone_code_hash:string phone_code:string = auth.Authorization;
  int auth_signIn(const mtproto::TL_auth_signIn& request, std::shared_ptr<mtproto::auth_Authorization>& response) override;
  
  // auth.signUp#1b067634 phone_number:string phone_code_hash:string phone_code:string first_name:string last_name:string = auth.Authorization;
  int auth_signUp(const mtproto::TL_auth_signUp& request, std::shared_ptr<mtproto::auth_Authorization>& response) override;
};

#endif
