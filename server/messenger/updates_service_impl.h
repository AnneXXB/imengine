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

#ifndef	MESSENGER_UPDATES_SERVICE_IMPL_H_
#define	MESSENGER_UPDATES_SERVICE_IMPL_H_

#include "messenger/zrpc_updates_service.h"

class UpdatesServiceImpl : public ZRpcUpdatesService {
public:
  UpdatesServiceImpl() = default;
  ~UpdatesServiceImpl() = default;
  
  // updates.getChannelDifference#3173d78 flags:# force:flags.0?true channel:InputChannel filter:ChannelMessagesFilter pts:int limit:int = updates.ChannelDifference;
  int updates_getChannelDifference(const mtproto::TL_updates_getChannelDifference& request, std::shared_ptr<mtproto::updates_ChannelDifference>& response) override;
  
  // updates.getDifference#25939651 flags:# pts:int pts_total_limit:flags.0?int date:int qts:int = updates.Difference;
  int updates_getDifference(const mtproto::TL_updates_getDifference& request, std::shared_ptr<mtproto::updates_Difference>& response) override;
  
  // updates.getState#edd4882a = updates.State;
  int updates_getState(const mtproto::TL_updates_getState& request, std::shared_ptr<mtproto::updates_State>& response) override;
};

#endif
