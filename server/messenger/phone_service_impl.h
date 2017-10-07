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

#ifndef	MESSENGER_PHONE_SERVICE_IMPL_H_
#define	MESSENGER_PHONE_SERVICE_IMPL_H_

#include "messenger/zrpc_phone_service.h"

class PhoneServiceImpl : public ZRpcPhoneService {
public:
  PhoneServiceImpl() = default;
  ~PhoneServiceImpl() = default;
  
  // phone.acceptCall#3bd2b4a0 peer:InputPhoneCall g_b:bytes protocol:PhoneCallProtocol = phone.PhoneCall;
  int phone_acceptCall(const mtproto::TL_phone_acceptCall& request, std::shared_ptr<mtproto::phone_PhoneCall>& response) override;
  
  // phone.confirmCall#2efe1722 peer:InputPhoneCall g_a:bytes key_fingerprint:long protocol:PhoneCallProtocol = phone.PhoneCall;
  int phone_confirmCall(const mtproto::TL_phone_confirmCall& request, std::shared_ptr<mtproto::phone_PhoneCall>& response) override;
  
  // phone.discardCall#78d413a6 peer:InputPhoneCall duration:int reason:PhoneCallDiscardReason connection_id:long = Updates;
  int phone_discardCall(const mtproto::TL_phone_discardCall& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // phone.getCallConfig#55451fa9 = DataJSON;
  int phone_getCallConfig(const mtproto::TL_phone_getCallConfig& request, std::shared_ptr<mtproto::DataJSON>& response) override;
  
  // phone.receivedCall#17d54f61 peer:InputPhoneCall = Bool;
  int phone_receivedCall(const mtproto::TL_phone_receivedCall& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // phone.requestCall#5b95b3d4 user_id:InputUser random_id:int g_a_hash:bytes protocol:PhoneCallProtocol = phone.PhoneCall;
  int phone_requestCall(const mtproto::TL_phone_requestCall& request, std::shared_ptr<mtproto::phone_PhoneCall>& response) override;
  
  // phone.saveCallDebug#277add7e peer:InputPhoneCall debug:DataJSON = Bool;
  int phone_saveCallDebug(const mtproto::TL_phone_saveCallDebug& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // phone.setCallRating#1c536a34 peer:InputPhoneCall rating:int comment:string = Updates;
  int phone_setCallRating(const mtproto::TL_phone_setCallRating& request, std::shared_ptr<mtproto::Updates>& response) override;
};

#endif
