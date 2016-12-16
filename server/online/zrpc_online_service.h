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

#ifndef	ONLINE_ZRPC_ONLINE_SERVICE_H_
#define	ONLINE_ZRPC_ONLINE_SERVICE_H_

// #include "proto/zproto/zproto_api_message_types.h"

#include "proto/s2s/cc/presences.pb.h"
#include "nebula/net/zproto/api_message_box.h"

class ZRpcOnlineService {
public:
  virtual ~ZRpcOnlineService() = default;
  
  virtual int ClientOnline(const zproto::ClientOnlineReq& request, zproto::ClientOnlineRsp* response);
  virtual int ClientOffline(const zproto::ClientOfflineReq& request, zproto::ClientOfflineRsp* response);
  virtual int QueryOnlineUser(const zproto::QueryOnlineUserReq& request, zproto::QueryOnlineUserRsp* response);

};

#endif

