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

#include "messenger/updates_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int UpdatesServiceImpl::updates_getChannelDifference(const mtproto::TL_updates_getChannelDifference& request, std::shared_ptr<mtproto::updates_ChannelDifference>& response) {
  LOG(INFO) << "updates_getChannelDifference - " << request.ToString();
  
  return kErrNotImpl;
}

int UpdatesServiceImpl::updates_getDifference(const mtproto::TL_updates_getDifference& request, std::shared_ptr<mtproto::updates_Difference>& response) {
  LOG(INFO) << "updates_getDifference - " << request.ToString();
  
  return kErrNotImpl;
}

int UpdatesServiceImpl::updates_getState(const mtproto::TL_updates_getState& request, std::shared_ptr<mtproto::updates_State>& response) {
  LOG(INFO) << "updates_getState - " << request.ToString();
  
  return kErrNotImpl;
}
