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

#include "messenger/payments_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int PaymentsServiceImpl::payments_clearSavedInfo(const mtproto::TL_payments_clearSavedInfo& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "payments_clearSavedInfo - " << request.ToString();
  
  return kErrNotImpl;
}

int PaymentsServiceImpl::payments_getPaymentForm(const mtproto::TL_payments_getPaymentForm& request, std::shared_ptr<mtproto::payments_PaymentForm>& response) {
  LOG(INFO) << "payments_getPaymentForm - " << request.ToString();
  
  return kErrNotImpl;
}

int PaymentsServiceImpl::payments_getPaymentReceipt(const mtproto::TL_payments_getPaymentReceipt& request, std::shared_ptr<mtproto::payments_PaymentReceipt>& response) {
  LOG(INFO) << "payments_getPaymentReceipt - " << request.ToString();
  
  return kErrNotImpl;
}

int PaymentsServiceImpl::payments_getSavedInfo(const mtproto::TL_payments_getSavedInfo& request, std::shared_ptr<mtproto::payments_SavedInfo>& response) {
  LOG(INFO) << "payments_getSavedInfo - " << request.ToString();
  
  return kErrNotImpl;
}

int PaymentsServiceImpl::payments_sendPaymentForm(const mtproto::TL_payments_sendPaymentForm& request, std::shared_ptr<mtproto::payments_PaymentResult>& response) {
  LOG(INFO) << "payments_sendPaymentForm - " << request.ToString();
  
  return kErrNotImpl;
}

int PaymentsServiceImpl::payments_validateRequestedInfo(const mtproto::TL_payments_validateRequestedInfo& request, std::shared_ptr<mtproto::payments_ValidatedRequestedInfo>& response) {
  LOG(INFO) << "payments_validateRequestedInfo - " << request.ToString();
  
  return kErrNotImpl;
}
