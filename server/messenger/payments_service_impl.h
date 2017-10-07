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

#ifndef	MESSENGER_PAYMENTS_SERVICE_IMPL_H_
#define	MESSENGER_PAYMENTS_SERVICE_IMPL_H_

#include "messenger/zrpc_payments_service.h"

class PaymentsServiceImpl : public ZRpcPaymentsService {
public:
  PaymentsServiceImpl() = default;
  ~PaymentsServiceImpl() = default;
  
  // payments.clearSavedInfo#d83d70c1 flags:# credentials:flags.0?true info:flags.1?true = Bool;
  int payments_clearSavedInfo(const mtproto::TL_payments_clearSavedInfo& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // payments.getPaymentForm#99f09745 msg_id:int = payments.PaymentForm;
  int payments_getPaymentForm(const mtproto::TL_payments_getPaymentForm& request, std::shared_ptr<mtproto::payments_PaymentForm>& response) override;
  
  // payments.getPaymentReceipt#a092a980 msg_id:int = payments.PaymentReceipt;
  int payments_getPaymentReceipt(const mtproto::TL_payments_getPaymentReceipt& request, std::shared_ptr<mtproto::payments_PaymentReceipt>& response) override;
  
  // payments.getSavedInfo#227d824b = payments.SavedInfo;
  int payments_getSavedInfo(const mtproto::TL_payments_getSavedInfo& request, std::shared_ptr<mtproto::payments_SavedInfo>& response) override;
  
  // payments.sendPaymentForm#2b8879b3 flags:# msg_id:int requested_info_id:flags.0?string shipping_option_id:flags.1?string credentials:InputPaymentCredentials = payments.PaymentResult;
  int payments_sendPaymentForm(const mtproto::TL_payments_sendPaymentForm& request, std::shared_ptr<mtproto::payments_PaymentResult>& response) override;
  
  // payments.validateRequestedInfo#770a8e74 flags:# save:flags.0?true msg_id:int info:PaymentRequestedInfo = payments.ValidatedRequestedInfo;
  int payments_validateRequestedInfo(const mtproto::TL_payments_validateRequestedInfo& request, std::shared_ptr<mtproto::payments_ValidatedRequestedInfo>& response) override;
};

#endif
