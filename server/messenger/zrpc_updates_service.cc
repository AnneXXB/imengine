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

#include "messenger/zrpc_updates_service.h"

#include "nebula/base/logger/glog_util.h"
#include "proto/api/error_codes.h"

int ZRpcUpdatesService::updates_getChannelDifference(const mtproto::TL_updates_getChannelDifference& request, std::shared_ptr<mtproto::updates_ChannelDifference>& response) {
  LOG(ERROR) << "updates_getChannelDifference not impl";
  return kErrNotImpl;
}

int ZRpcUpdatesService::updates_getDifference(const mtproto::TL_updates_getDifference& request, std::shared_ptr<mtproto::updates_Difference>& response) {
  LOG(ERROR) << "updates_getDifference not impl";
  return kErrNotImpl;
}

int ZRpcUpdatesService::updates_getState(const mtproto::TL_updates_getState& request, std::shared_ptr<mtproto::updates_State>& response) {
  LOG(ERROR) << "updates_getState not impl";
  return kErrNotImpl;
}

