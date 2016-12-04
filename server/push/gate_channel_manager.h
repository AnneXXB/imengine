/*
 *  Copyright (c) 2016, https://github.com/zhatalk
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

#ifndef	PUSH_GATE_CHANNEL_MANAGER_H_
#define	PUSH_GATE_CHANNEL_MANAGER_H_

#include <map>
#include <mutex>

#include <folly/Singleton.h>

// TODO(@benqi): 使用数组代替
typedef std::map<uint32_t, uint64_t> GateChannelMap;

class GateChannelManager {
public:
  GateChannelManager() = default;
  ~GateChannelManager() = default;
  
  static std::shared_ptr<GateChannelManager> GetInstance();

  void OnNewGateChannel(uint32_t server_id, uint64_t conn_id);
  void OnGateChannelClosed(uint64_t conn_id);
  uint64_t LookupConnID(uint32_t server_id);
  
private:
  friend class folly::Singleton<GateChannelManager>;

  std::mutex mutex_;
  GateChannelMap gate_channels_;
};


#endif // PUSH_GATE_CHANNEL_HANDLER_H_

