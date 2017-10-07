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

#include "messenger/phone_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int PhoneServiceImpl::phone_acceptCall(const mtproto::TL_phone_acceptCall& request, std::shared_ptr<mtproto::phone_PhoneCall>& response) {
  LOG(INFO) << "phone_acceptCall - " << request.ToString();
  
  return kErrNotImpl;
}

int PhoneServiceImpl::phone_confirmCall(const mtproto::TL_phone_confirmCall& request, std::shared_ptr<mtproto::phone_PhoneCall>& response) {
  LOG(INFO) << "phone_confirmCall - " << request.ToString();
  
  return kErrNotImpl;
}

int PhoneServiceImpl::phone_discardCall(const mtproto::TL_phone_discardCall& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "phone_discardCall - " << request.ToString();
  
  return kErrNotImpl;
}

int PhoneServiceImpl::phone_getCallConfig(const mtproto::TL_phone_getCallConfig& request, std::shared_ptr<mtproto::DataJSON>& response) {
  LOG(INFO) << "phone_getCallConfig - " << request.ToString();
  
  return kErrNotImpl;
}

int PhoneServiceImpl::phone_receivedCall(const mtproto::TL_phone_receivedCall& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "phone_receivedCall - " << request.ToString();
  
  return kErrNotImpl;
}

int PhoneServiceImpl::phone_requestCall(const mtproto::TL_phone_requestCall& request, std::shared_ptr<mtproto::phone_PhoneCall>& response) {
  LOG(INFO) << "phone_requestCall - " << request.ToString();
  
  return kErrNotImpl;
}

int PhoneServiceImpl::phone_saveCallDebug(const mtproto::TL_phone_saveCallDebug& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "phone_saveCallDebug - " << request.ToString();
  
  return kErrNotImpl;
}

int PhoneServiceImpl::phone_setCallRating(const mtproto::TL_phone_setCallRating& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "phone_setCallRating - " << request.ToString();
  
  return kErrNotImpl;
}
