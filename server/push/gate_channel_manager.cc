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

#include "push/gate_channel_manager.h"

#include "nebula/base/map_util.h"

folly::Singleton<GateChannelManager> g_gate_channel_manager;

std::shared_ptr<GateChannelManager> GateChannelManager::GetInstance() {
  return g_gate_channel_manager.try_get();
}

void GateChannelManager::OnNewGateChannel(uint32_t server_id, uint64_t conn_id) {
  std::lock_guard<std::mutex> g(mutex_);
  gate_channels_[server_id] = conn_id;
}

void GateChannelManager::OnGateChannelClosed(uint64_t conn_id) {
  std::lock_guard<std::mutex> g(mutex_);
  for (auto it : gate_channels_) {
    if (it.second == conn_id) {
      gate_channels_.erase(it.first);
      break;
    }
  }
}

uint64_t GateChannelManager::LookupConnID(uint32_t server_id) {
  std::lock_guard<std::mutex> g(mutex_);
  return FindWithDefault(gate_channels_, server_id, 0);
}
