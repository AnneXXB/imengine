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

#ifndef	ONLINE_ONLINE_SERVICE_IMPL_H_
#define	ONLINE_ONLINE_SERVICE_IMPL_H_

#include "online/zrpc_online_service.h"

class OnlineServiceImpl : public ZRpcOnlineService {
public:
  OnlineServiceImpl() = default;
  ~OnlineServiceImpl() = default;
  
  int ClientOnline(const zproto::ClientOnlineReq& request, zproto::ClientOnlineRsp* response) override;
  int ClientOffline(const zproto::ClientOfflineReq& request, zproto::ClientOfflineRsp* response) override;
  int QueryOnlineUser(const zproto::QueryOnlineUserReq& request, zproto::QueryOnlineUserRsp* response) override;

};

#endif
