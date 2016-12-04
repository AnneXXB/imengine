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

#ifndef PROTO_ZPROTO_ZPROTO_MESSAGE_TYPES_UTIL_H_
#define PROTO_ZPROTO_ZPROTO_MESSAGE_TYPES_UTIL_H_

#include "proto/base_message_types_util.h"

#include "proto/zproto/cc/method_types.pb.h"

#include "proto/zproto/cc/auths.pb.h"
#include "proto/zproto/cc/servers.pb.h"
#include "proto/zproto/cc/messages.pb.h"

// TODO(@benqi): 使用脚本自动生成

namespace proto {

/////////////////////////////////////////////////////////////////////////////////
template<>
inline uint32_t GetMessageType<zproto::VoidRsp>() {
  return zproto::VOID_RSP;
}
  
/////////////////////////////////////////////////////////////////////////////////
template<>
inline uint32_t GetMessageType<zproto::UserTokenAuthReq>() {
  return zproto::USER_TOKEN_AUTH_REQ;
}

template<>
inline uint32_t GetMessageType<zproto::UserTokenAuthRsp>() {
  return zproto::USER_TOKEN_AUTH_RSP;
}

/////////////////////////////////////////////////////////////////////////////////
// servers
template<>
inline uint32_t GetMessageType<zproto::ServerAuthReq>() {
  return zproto::SERVER_AUTH_REQ;
}

template<>
inline uint32_t GetMessageType<zproto::ServerAuthRsp>() {
  return zproto::SERVER_AUTH_RSP;
}

//template<>
//inline uint32_t GetMessageType<zproto::UserNamePasswordAuthReq>() {
//  return zproto::USER_NAME_PASSWORD_AUTH_REQ;
//}
//
//template<>
//inline uint32_t GetMessageType<zproto::UserNamePasswordAuthRsp>() {
//  return zproto::USER_NAME_PASSWORD_AUTH_RSP;
//}

template<>
inline uint32_t GetMessageType<zproto::ClientOnlineReq>() {
  return zproto::CLIENT_ONLINE_REQ;
}

template<>
inline uint32_t GetMessageType<zproto::ClientOnlineRsp>() {
  return zproto::CLIENT_ONLINE_RSP;
}

template<>
inline uint32_t GetMessageType<zproto::ClientOfflineReq>() {
  return zproto::CLIENT_OFFLINE_REQ;
}

template<>
inline uint32_t GetMessageType<zproto::ClientOfflineRsp>() {
  return zproto::CLIENT_OFFLINE_RSP;
}

template<>
inline uint32_t GetMessageType<zproto::QueryOnlineUserReq>() {
  return zproto::QUERY_ONINE_USER_REQ;
}

template<>
inline uint32_t GetMessageType<zproto::QueryOnlineUserRsp>() {
  return zproto::QUERY_ONINE_USER_RSP;
}
  
template<>
inline uint32_t GetMessageType<zproto::SendMessageReq>() {
  return zproto::SEND_MESSAGE_REQ;
}

template<>
inline uint32_t GetMessageType<zproto::SeqDateRsp>() {
  return zproto::SEQ_DATE_RSP;
}

template<>
inline uint32_t GetMessageType<zproto::MessageNotify>() {
  return zproto::MESSAGE_NOTIFY;
}

template<>
inline uint32_t GetMessageType<zproto::MessageDataNotify>() {
  return zproto::MESSAGE_DATA_NOTIFY;
}

template<>
inline uint32_t GetMessageType<zproto::MessageSyncReq>() {
  return zproto::MESSAGE_SYNC_REQ;
}

template<>
inline uint32_t GetMessageType<zproto::MessageSyncRsp>() {
  return zproto::MESSAGE_SYNC_RSP;
}

template<>
inline uint32_t GetMessageType<zproto::MessageReadReq>() {
  return zproto::MESSAGE_READ_REQ;
}

template<>
inline uint32_t GetMessageType<zproto::LoadHistoryMessageReq>() {
  return zproto::LOAD_HISTORY_MESSAGE_REQ;
}

template<>
inline uint32_t GetMessageType<zproto::LoadHistoryMessageRsp>() {
  return zproto::LOAD_HISTORY_MESSAGE_RSP;
}

template<>
inline uint32_t GetMessageType<zproto::LoadDialogsReq>() {
  return zproto::LOAD_DIALOGS_REQ;
}

template<>
inline uint32_t GetMessageType<zproto::LoadDialogsRsp>() {
  return zproto::LOAD_DIALOGS_RSP;
}

template<>
inline uint32_t GetMessageType<zproto::ForwardMessageReq>() {
  return zproto::FORAWRD_MESSAGE_REQ;
}

}

#endif
