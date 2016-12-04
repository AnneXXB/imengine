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


#include "online/online_session_manager.h"

#include <iostream>
#include <string>
#include <folly/Format.h>

#include "nebula/base/logger/glog_util.h"

// 帮助宏
#define MakeSessionID(server_id, conn_id) ((uint64_t)server_id >> 48 | conn_id)
#define MakeAppUserID(app_id, user_id) (user_id + "@" + folly::to<std::string>(app_id))
#define GetConnID(session_id) (session_id & 0xffffffffffff)

folly::Singleton<OnlineSessionManager> g_online_session_manager;

std::string SessionEntry::ToString() const {
  // TODO(@benqi): 输出conn_id, user_id
  return folly::sformat("{{server_id: {}, session_id: {}, app_id: {}, app_user_id: {}, state: {}}}",
                        server_id,
                        session_id,
                        app_id,
                        user_id,
                        state);
}

std::shared_ptr<OnlineSessionManager> OnlineSessionManager::GetInstance() {
  return g_online_session_manager.try_get();
}

void OnlineSessionManager::AddEntry(uint16_t server_id,
                                    uint64_t conn_id,
                                    uint32_t app_id,
                                    const std::string& user_id,
                                    uint16_t state) {
  std::lock_guard<std::mutex> g(sessions_mutex_);
  sessions_.emplace(server_id, conn_id, app_id, user_id, state);
}

void OnlineSessionManager::RemoveEntryBySessionID(uint16_t server_id, uint64_t conn_id) {
  // SessionEntry s;
  // s.conn_id = conn_id;
  std::lock_guard<std::mutex> g(sessions_mutex_);
  sessions_.erase(MakeSessionID(server_id, conn_id));
}

void OnlineSessionManager::RemoveEntrysByServerID(uint16_t server_id) {
  std::lock_guard<std::mutex> g(sessions_mutex_);
  sessions_.get<SERVER_ID>().erase(server_id);
}

size_t OnlineSessionManager::LookupEntrysByServerID(uint32_t server_id, SessionEntryList* sessions) const {
  DCHECK(sessions);
  
  std::lock_guard<std::mutex> g(sessions_mutex_);

  const auto& index=sessions_.get<SERVER_ID>();
  auto r = index.equal_range(server_id);
  sessions->assign(r.first, r.second);
  
  return sessions->size();
}

size_t OnlineSessionManager::LookupEntrysByUserID(uint32_t app_id, const std::string& user_id, SessionEntryList* sessions) const {
  DCHECK(sessions);
  
  std::lock_guard<std::mutex> g(sessions_mutex_);

  const auto& index=sessions_.get<APP_USER_ID>();
  auto r = index.equal_range(MakeAppUserID(app_id, user_id));
  sessions->assign(r.first, r.second);
  
  return sessions->size();
}

size_t OnlineSessionManager::LookupEntrysByUserIDList(const std::list<std::string>& app_user_id_list, SessionEntryList* sessions) const {
  std::lock_guard<std::mutex> g(sessions_mutex_);
  
  for (const auto& v : app_user_id_list) {
    const auto& index=sessions_.get<APP_USER_ID>();
    auto r = index.equal_range(v);
    sessions->insert(sessions->begin(), r.first, r.second);
  }
  
  return sessions->size();
}

size_t OnlineSessionManager::LookupEntrysByAppID(uint32_t app_id, SessionEntryList* sessions) const {
  DCHECK(sessions);

  std::lock_guard<std::mutex> g(sessions_mutex_);

  const auto& index=sessions_.get<APP_ID>();
  auto r = index.equal_range(app_id);
  sessions->assign(r.first, r.second);
  
  return sessions->size();
}

bool OnlineSessionManager::LookupEntryBySessionID(uint16_t server_id, uint64_t conn_id, SessionEntry* session) {
  DCHECK(session);
  
  std::lock_guard<std::mutex> g(sessions_mutex_);

  auto s = LookupEntryBySessionID(server_id, conn_id);
  if (s) {
    *session = *s;
    return true;
  } else {
    return false;
  }
}

const SessionEntry* OnlineSessionManager::LookupEntryBySessionID(uint16_t server_id, uint64_t conn_id) const {
  const SessionEntry* s = nullptr;

  std::lock_guard<std::mutex> g(sessions_mutex_);

  auto it = sessions_.get<SESSION_ID>().find(MakeSessionID(server_id, conn_id));
  if (it!=sessions_.end()) {
    s = &(*it);
  }
  
  return s;
}

uint16_t OnlineSessionManager::UpdateEntryState(uint16_t server_id, uint64_t conn_id, uint16_t state) {
  uint16_t rv = state;
  
  std::lock_guard<std::mutex> g(sessions_mutex_);

  auto s = LookupEntryBySessionID(server_id, conn_id);
  if (s) {
    std::swap(rv, s->state);
  }
  return rv;
}

void OnlineSessionManager::PrintDebug() const {
  std::lock_guard<std::mutex> g(sessions_mutex_);

  std::copy(sessions_.begin(), sessions_.end(), std::ostream_iterator<SessionEntry>(std::cout));
}

