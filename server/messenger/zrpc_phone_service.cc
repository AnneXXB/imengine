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

#include "messenger/zrpc_phone_service.h"

#include "nebula/base/logger/glog_util.h"
#include "proto/api/error_codes.h"

int ZRpcPhoneService::phone_acceptCall(const mtproto::TL_phone_acceptCall& request, std::shared_ptr<mtproto::phone_PhoneCall>& response) {
  LOG(ERROR) << "phone_acceptCall not impl";
  return kErrNotImpl;
}

int ZRpcPhoneService::phone_confirmCall(const mtproto::TL_phone_confirmCall& request, std::shared_ptr<mtproto::phone_PhoneCall>& response) {
  LOG(ERROR) << "phone_confirmCall not impl";
  return kErrNotImpl;
}

int ZRpcPhoneService::phone_discardCall(const mtproto::TL_phone_discardCall& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "phone_discardCall not impl";
  return kErrNotImpl;
}

int ZRpcPhoneService::phone_getCallConfig(const mtproto::TL_phone_getCallConfig& request, std::shared_ptr<mtproto::DataJSON>& response) {
  LOG(ERROR) << "phone_getCallConfig not impl";
  return kErrNotImpl;
}

int ZRpcPhoneService::phone_receivedCall(const mtproto::TL_phone_receivedCall& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "phone_receivedCall not impl";
  return kErrNotImpl;
}

int ZRpcPhoneService::phone_requestCall(const mtproto::TL_phone_requestCall& request, std::shared_ptr<mtproto::phone_PhoneCall>& response) {
  LOG(ERROR) << "phone_requestCall not impl";
  return kErrNotImpl;
}

int ZRpcPhoneService::phone_saveCallDebug(const mtproto::TL_phone_saveCallDebug& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "phone_saveCallDebug not impl";
  return kErrNotImpl;
}

int ZRpcPhoneService::phone_setCallRating(const mtproto::TL_phone_setCallRating& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "phone_setCallRating not impl";
  return kErrNotImpl;
}


