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

#ifndef	MESSENGER_ZRPC_AUTH_SERVICE_H_
#define	MESSENGER_ZRPC_AUTH_SERVICE_H_

#include "base/base_zrpc_service.h"
#include "proto/mtproto/core/mtproto_schema.h"

class ZRpcAuthService : public BaseZRpcService {
public:
  virtual ~ZRpcAuthService() = default;

  // auth.bindTempAuthKey#cdd42a05 perm_auth_key_id:long nonce:long expires_at:int encrypted_message:bytes = Bool;
  virtual int auth_bindTempAuthKey(const mtproto::TL_auth_bindTempAuthKey& request, std::shared_ptr<mtproto::Bool>& response);
  
  // auth.cancelCode#1f040578 phone_number:string phone_code_hash:string = Bool;
  virtual int auth_cancelCode(const mtproto::TL_auth_cancelCode& request, std::shared_ptr<mtproto::Bool>& response);
  
  // auth.checkPassword#a63011e password_hash:bytes = auth.Authorization;
  virtual int auth_checkPassword(const mtproto::TL_auth_checkPassword& request, std::shared_ptr<mtproto::auth_Authorization>& response);
  
  // auth.checkPhone#6fe51dfb phone_number:string = auth.CheckedPhone;
  virtual int auth_checkPhone(const mtproto::TL_auth_checkPhone& request, std::shared_ptr<mtproto::auth_CheckedPhone>& response);
  
  // auth.dropTempAuthKeys#8e48a188 except_auth_keys:Vector<long> = Bool;
  virtual int auth_dropTempAuthKeys(const mtproto::TL_auth_dropTempAuthKeys& request, std::shared_ptr<mtproto::Bool>& response);
  
  // auth.exportAuthorization#e5bfffcd dc_id:int = auth.ExportedAuthorization;
  virtual int auth_exportAuthorization(const mtproto::TL_auth_exportAuthorization& request, std::shared_ptr<mtproto::auth_ExportedAuthorization>& response);
  
  // auth.importAuthorization#e3ef9613 id:int bytes:bytes = auth.Authorization;
  virtual int auth_importAuthorization(const mtproto::TL_auth_importAuthorization& request, std::shared_ptr<mtproto::auth_Authorization>& response);
  
  // auth.importBotAuthorization#67a3ff2c flags:int api_id:int api_hash:string bot_auth_token:string = auth.Authorization;
  virtual int auth_importBotAuthorization(const mtproto::TL_auth_importBotAuthorization& request, std::shared_ptr<mtproto::auth_Authorization>& response);
  
  // auth.logOut#5717da40 = Bool;
  virtual int auth_logOut(const mtproto::TL_auth_logOut& request, std::shared_ptr<mtproto::Bool>& response);
  
  // auth.recoverPassword#4ea56e92 code:string = auth.Authorization;
  virtual int auth_recoverPassword(const mtproto::TL_auth_recoverPassword& request, std::shared_ptr<mtproto::auth_Authorization>& response);
  
  // auth.requestPasswordRecovery#d897bc66 = auth.PasswordRecovery;
  virtual int auth_requestPasswordRecovery(const mtproto::TL_auth_requestPasswordRecovery& request, std::shared_ptr<mtproto::auth_PasswordRecovery>& response);
  
  // auth.resendCode#3ef1a9bf phone_number:string phone_code_hash:string = auth.SentCode;
  virtual int auth_resendCode(const mtproto::TL_auth_resendCode& request, std::shared_ptr<mtproto::auth_SentCode>& response);
  
  // auth.resetAuthorizations#9fab0d1a = Bool;
  virtual int auth_resetAuthorizations(const mtproto::TL_auth_resetAuthorizations& request, std::shared_ptr<mtproto::Bool>& response);
  
  // auth.sendCode#86aef0ec flags:# allow_flashcall:flags.0?true phone_number:string current_number:flags.0?Bool api_id:int api_hash:string = auth.SentCode;
  virtual int auth_sendCode(const mtproto::TL_auth_sendCode& request, std::shared_ptr<mtproto::auth_SentCode>& response);
  
  // auth.sendInvites#771c1d97 phone_numbers:Vector<string> message:string = Bool;
  virtual int auth_sendInvites(const mtproto::TL_auth_sendInvites& request, std::shared_ptr<mtproto::Bool>& response);
  
  // auth.signIn#bcd51581 phone_number:string phone_code_hash:string phone_code:string = auth.Authorization;
  virtual int auth_signIn(const mtproto::TL_auth_signIn& request, std::shared_ptr<mtproto::auth_Authorization>& response);
  
  // auth.signUp#1b067634 phone_number:string phone_code_hash:string phone_code:string first_name:string last_name:string = auth.Authorization;
  virtual int auth_signUp(const mtproto::TL_auth_signUp& request, std::shared_ptr<mtproto::auth_Authorization>& response);
};

#endif

