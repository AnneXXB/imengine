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

#ifndef	GATE_GATE_SERVER_UTIL_H_
#define	GATE_GATE_SERVER_UTIL_H_

/*
#include "nebula/net/handler/nebula_base_handler.h"
#include "nebula/net/zproto/zproto_package_data.h"
// #include "nebula/net/handler/teamtalk/teamtalk_package_data.h"
#include "nebula/net/handler/nebula_handler_util.h"


// 客户端连接成功后
// 1. 10秒内没收到数据包则断开
// 2. 收到的第一个包必须是用户认证包
// 3. 认证包转发给auth服务器处理
// 4. 认证必须在15秒内返回
// 5. 认证成功后通知状态服务器客户端上线
// 6. 通知成功后返回后认证成功
// 7. 可以接收客户端消息
// 8. 收到消息后转发给router
struct ClientConnContext : public nebula::ConnAttachData {
  enum class State : int
  {
    NONE = 0,
    CONNECTED = 1,
    HANDSHAKE = 2,
    AUTH = 3,
    FORWARD_TO_STATUS = 4,
    WORKING = 5,
    ERROR = 6
  };
  
  State state{State::NONE};
  
  // 用户基本信息
  uint32_t app_id{1};
  std::string user_id;
  // uint32_t user_id;
  std::string nick;
  std::string avatar;
};

inline folly::Future<folly::Unit> WritePackage(const std::string& service_name, std::shared_ptr<PackageMessage> message_data) {
  std::unique_ptr<folly::IOBuf> data;
  message_data->SerializeToIOBuf(data);
  return WriterUtil::Write(service_name, std::move(data));
}

inline folly::Future<folly::Unit> WritePackage(uint64_t conn_id, std::shared_ptr<PackageMessage> message_data) {
  std::unique_ptr<folly::IOBuf> data;
  message_data->SerializeToIOBuf(data);
  return WriterUtil::Write(conn_id, std::move(data));
}
*/

inline uint32_t GetServerID() {
  return 1;
}

#endif
