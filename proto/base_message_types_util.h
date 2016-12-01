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

#ifndef PROTO_BASE_MESSAGE_TYPES_UTIL_H_
#define PROTO_BASE_MESSAGE_TYPES_UTIL_H_

#include <stdint.h>

namespace proto {
  
// 通过ServiceID,CommandID组合成uint32_t的MessageType
inline uint32_t ToMessageType(uint16_t sid, uint16_t cid) {
  return static_cast<uint32_t>(sid << 16U) | cid;
}

// 通过PB消息名获得PduType
// 主要用于如下情况
// 如果要代码级别构建Box，比如
// ApiMessageBox<LoginResp> resp;
// 因为ApiMessageBox无法获取resp的message_type
// 里提供了一个GetMessageType的方法，通过GetMessageType<LoginResp>可以获取Mmessage_type
template<class MESSAGE>
inline uint32_t GetMessageType() {
  return -1;
}
  
}

#endif

