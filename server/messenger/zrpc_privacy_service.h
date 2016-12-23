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

#ifndef	MESSENGER_ZRPC_PRIVACY_SERVICE_H_
#define	MESSENGER_ZRPC_PRIVACY_SERVICE_H_

#include "proto/api/cc/misc.pb.h"
#include "proto/api/cc/privacy.pb.h"
#include "base/base_zrpc_service.h"

class ZRpcPrivacyService : public BaseZRpcService {
public:
  virtual ~ZRpcPrivacyService() = default;
  
  ////////////////////////////////////////////////////////////////////////////////////////////////
  virtual int BlockUser(const zproto::BlockUserReq& request, zproto::SeqRsp* response);
  virtual int UnblockUser(const zproto::UnblockUserReq& request, zproto::SeqRsp* response);
  virtual int LoadBlockedUsers(const zproto::LoadBlockedUsersReq& request, zproto::LoadBlockedUsersRsp* response);

};

#endif
