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

#include "messenger/zrpc_payments_service.h"

#include "nebula/base/logger/glog_util.h"
#include "proto/api/error_codes.h"

int ZRpcPaymentsService::payments_clearSavedInfo(const mtproto::TL_payments_clearSavedInfo& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "payments_clearSavedInfo not impl";
  return kErrNotImpl;
}

int ZRpcPaymentsService::payments_getPaymentForm(const mtproto::TL_payments_getPaymentForm& request, std::shared_ptr<mtproto::payments_PaymentForm>& response) {
  LOG(ERROR) << "payments_getPaymentForm not impl";
  return kErrNotImpl;
}

int ZRpcPaymentsService::payments_getPaymentReceipt(const mtproto::TL_payments_getPaymentReceipt& request, std::shared_ptr<mtproto::payments_PaymentReceipt>& response) {
  LOG(ERROR) << "payments_getPaymentReceipt not impl";
  return kErrNotImpl;
}

int ZRpcPaymentsService::payments_getSavedInfo(const mtproto::TL_payments_getSavedInfo& request, std::shared_ptr<mtproto::payments_SavedInfo>& response) {
  LOG(ERROR) << "payments_getSavedInfo not impl";
  return kErrNotImpl;
}

int ZRpcPaymentsService::payments_sendPaymentForm(const mtproto::TL_payments_sendPaymentForm& request, std::shared_ptr<mtproto::payments_PaymentResult>& response) {
  LOG(ERROR) << "payments_sendPaymentForm not impl";
  return kErrNotImpl;
}

int ZRpcPaymentsService::payments_validateRequestedInfo(const mtproto::TL_payments_validateRequestedInfo& request, std::shared_ptr<mtproto::payments_ValidatedRequestedInfo>& response) {
  LOG(ERROR) << "payments_validateRequestedInfo not impl";
  return kErrNotImpl;
}

