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

#ifndef	ONLINE_ONLINE_SESSION_MANAGER_H_
#define	ONLINE_ONLINE_SESSION_MANAGER_H_

#include <string>
#include <list>
#include <mutex>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/hashed_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/member.hpp>

#include <folly/Conv.h>
#include <folly/Singleton.h>


// 使用boost::multi_index_container实现，要做性能测试
// 在线状态管理器提供的功能
//  1. 客户端验证成功以后添加到状态列表里，
//     输入<app_id, user_id, server_id, conn_id>
//  2. 客户端下线后从状态列表里移除
//     输入<app_id, user_id, server_id, conn_id>
//  3. 网关连接断开移除所有隶属于所有联入网关的客户端
//     输入<server_id>
//  4. 客户端主动修改在线状态
//     输入<app_id, user_id, server_id, conn_id>
//  5. 提供在线状态查询功能
//     输入<app_id, user_id>
//  6. 提供其它查询功能

///////////////////////////////////////////////////////////////////////////////////////
// 在线状态
enum OnlineState {
  ONLINE_STATE_NONE       = 0,	// None
  ONLINE_STATE_ONLINE     = 1,	// 在线
  ONLINE_STATE_LEAVE      = 2,	// 离开
  ONLINE_STATE_INVISIBLE 	= 3,	// 隐身
  ONLINE_STATE_OFFLINE    = 4,	// 离线
};

// 会话状态信息
struct SessionEntry {
  SessionEntry() {}
  
  SessionEntry(uint16_t _server_id,
               uint64_t _conn_id,
               uint32_t _app_id,
               std::string _user_id,
               uint16_t _state)
   : server_id(_server_id),
     session_id((uint64_t)_server_id >> 48 | _conn_id),
     app_id(_app_id),
     user_id(_user_id),
     state(_state) {
    
    app_user_id = user_id + "@" + folly::to<std::string>(_app_id);
  }
  
  void set_state(uint16_t _state) const {
    state = _state;
  }
  
  uint16_t server_id;       // 客户端连入服务器ID
  
  // session_id: server_id >> 48 | _conn_id
  // 客户端唯一ID为二元组：<server_id, conn_id>
  // 但是二元组做为key有点繁琐，
  // 在nebula网络框架里，conn_id的高32位值为线程ID，线程ID是有限的，不会超过16位
  // 所以conn_id的高16位未使用
  // 而server_id也不会超过16位
  // 在这里，将server_id放在conn_id的高16位里，组成一个唯一的session_id
  // 做为容器的主键
  // |               session_id               |
  // ------------------------------------------
  // |    0~15   |   15~31   |      32~63     |
  // ------------------------------------------
  // | server_id | thread_id | thread_conn_id |
  //
  uint64_t session_id;
  
  uint32_t app_id;          // app_id
  // user_id的key
  std::string user_id;      // app_id >> 32 | 用户ID
  
  std::string app_user_id;  // app_id >> 32 | 用户ID

  // 可变值，一旦创建，只有state字段会变
  // boost::multi_index_container的find结果是const值
  // 必须mutable，否则不能修改state值
  mutable uint16_t  state;       // 状态
  
  // TODO(@benqi): 看是否要附带device_hash
  // int64_t  device_hash; // device_hash
  
  // <server, conn_id>做为1个key
  bool operator < (const SessionEntry& session) const {
    return session_id < session.session_id;
  }
  
  std::string ToString() const;
};

typedef std::list<SessionEntry> SessionEntryList;

inline std::ostream& operator<<(std::ostream& o, const SessionEntry& e) {
  o << e.ToString() << "\n";
  return o;
}

///////////////////////////////////////////////////////////////////////////////////////
// 用户在线状态服务
// 提供服务：
// 1. 按照用户ID查
// 2. 内部ID查
//  server_id
//  server_id, conn_id
//  app_id
//  app_id, user_id
class OnlineSessionManager {
public:
  // 单件
  static std::shared_ptr<OnlineSessionManager> GetInstance();
  
  void AddEntry(uint16_t server_id,
                uint64_t conn_id,
                uint32_t app_id,
                const std::string& user_id,
                uint16_t state);
  
  // 客户端断线
  void RemoveEntryBySessionID(uint16_t server_id, uint64_t conn_id);
  // 网关失联
  void RemoveEntrysByServerID(uint16_t server_id);

  // 通过ServerID查询
  // return: 结果数
  size_t LookupEntrysByServerID(uint32_t server_id, SessionEntryList* sessions) const;
  // 通过ServerID查询
  // return: 结果数
  size_t LookupEntrysByAppID(uint32_t app_id, SessionEntryList* sessions) const;
  // 通过AppID查询
  // return: 结果数
  size_t LookupEntrysByUserID(uint32_t app_id, const std::string& user_id, SessionEntryList* sessions) const;

  size_t LookupEntrysByUserIDList(const std::list<std::string>& app_user_id_list, SessionEntryList* sessions) const;

  // 通过主键<server_id, conn_id>查找
  // 未找到返回false，找到返回true，session为返回参数
  bool LookupEntryBySessionID(uint16_t server_id, uint64_t conn_id, SessionEntry* session);

  // 更新状态
  // Online->Leave->Invisible
  // return: 切换前状态
  uint16_t UpdateEntryState(uint16_t server_id, uint64_t conn_id, uint16_t state);

  void PrintDebug() const;
  
private:
  friend class folly::Singleton<OnlineSessionManager>;
  
  OnlineSessionManager() = default;

  // 后续要支持多线程，私有
  // 通过主键<server_id, conn_id>查找
  // return: 未找到为nullptr
  const SessionEntry* LookupEntryBySessionID(uint16_t server_id, uint64_t conn_id) const;
  

  ////////////////////////////////////////////////////////////////////////////////////
  // multi_index用法参考：
  // SessionEntry容器定义
  typedef boost::multi_index_container<
    SessionEntry,
    boost::multi_index::indexed_by<
      // 以 SessionEntry::operator< 排序, get<0>
      boost::multi_index::hashed_unique<boost::multi_index::member<
        SessionEntry, uint64_t, &SessionEntry::session_id
      >>,
      // 以 less<uint16_t> 在server_id上排序, get<1>
      boost::multi_index::hashed_non_unique<boost::multi_index::member<
        SessionEntry, uint16_t, &SessionEntry::server_id
      >>,
      // 以 less<uint32_t> 在app_id上排序, get<2>
      boost::multi_index::hashed_non_unique<boost::multi_index::member<
        SessionEntry, uint32_t, &SessionEntry::app_id
      >>,
      // 以 less<uint64_t> 在user_id上排序, get<3>
      boost::multi_index::hashed_non_unique<boost::multi_index::member<
        SessionEntry, std::string, &SessionEntry::app_user_id
      >>
    >
  > SessionContainer;
  
  mutable std::mutex sessions_mutex_;
  //
  SessionContainer sessions_;
  
  // 使用名字来替换sessions_.get<0>里的数字
  enum {
    SESSION_ID = 0,
    SERVER_ID,
    APP_ID,
    APP_USER_ID,
  };
};

#endif // ONLINE_ONLINE_SESSION_MANAGER_H_


