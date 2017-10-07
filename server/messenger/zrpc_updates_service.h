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

#ifndef	MESSENGER_ZRPC_UPDATES_SERVICE_H_
#define	MESSENGER_ZRPC_UPDATES_SERVICE_H_

#include "base/base_zrpc_service.h"
#include "proto/mtproto/core/mtproto_schema.h"

class ZRpcUpdatesService : public BaseZRpcService {
public:
  virtual ~ZRpcUpdatesService() = default;

  // updates.getChannelDifference#3173d78 flags:# force:flags.0?true channel:InputChannel filter:ChannelMessagesFilter pts:int limit:int = updates.ChannelDifference;
  virtual int updates_getChannelDifference(const mtproto::TL_updates_getChannelDifference& request, std::shared_ptr<mtproto::updates_ChannelDifference>& response);
  
  // updates.getDifference#25939651 flags:# pts:int pts_total_limit:flags.0?int date:int qts:int = updates.Difference;
  virtual int updates_getDifference(const mtproto::TL_updates_getDifference& request, std::shared_ptr<mtproto::updates_Difference>& response);
  
  // updates.getState#edd4882a = updates.State;
  virtual int updates_getState(const mtproto::TL_updates_getState& request, std::shared_ptr<mtproto::updates_State>& response);
};

#endif

