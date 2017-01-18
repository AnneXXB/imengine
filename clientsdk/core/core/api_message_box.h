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

#ifndef NUBULA_NET_ZPROTO_API_API_MESSAGE_BOX_H_
#define	NUBULA_NET_ZPROTO_API_API_MESSAGE_BOX_H_

// #include "proto/zproto/zproto_message_types_util.h"
#include <google/protobuf/message.h>

#include <boost/shared_ptr.hpp>

#include "core/checksum.h"
#include "core/zproto_package_data.h"

template <class T>
typename std::enable_if<std::is_base_of<google::protobuf::Message, T>::value>::type*
Decode(T& protobuf_message, const ByteBufferReader& reader) {
  protobuf_message.ParseFromArray(reader.PosData(), reader.PosLength());
  return nullptr;
}

template<typename T>
typename std::enable_if<std::is_base_of<google::protobuf::Message, T>::value>::type*
Encode(T& protobuf_message, ByteBufferWriter& writer) {
  int protobuf_message_size = protobuf_message.ByteSize();
  writer.AllocWrite(protobuf_message_size);
  protobuf_message.SerializeToArray(writer.MutablePosData(), protobuf_message_size);
  return nullptr;
}

inline uint32_t CRC32(const std::string& data) {
  return crc32c((const unsigned char*)data.data(), data.length());
}

template <typename T>
class ApiRpcRequest : public ProtoBox<T>, public RpcRequest {
public:
  enum {
    HEADER = PACKAGE_RPC_REQUEST,
  };
  
  ApiRpcRequest() {
    method_id_ = CRC32(ProtoBox<T>::message_.GetTypeName());
  }
  virtual ~ApiRpcRequest() {}
  
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }

  virtual uint32_t GetMethodID() const {
    return method_id_;
  }

//  virtual std::string ToString() const override {
//    return folly::sformat("{{base: {}, method_id: {}, payload: {}}}",
//                          RpcRequest::ToString(),
//                          GetMethodID(),
//                          ProtoBox<T>::message.Utf8DebugString());
//  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!RpcRequest::Decode(reader)) return false;
    return ::Decode(ProtoBox<T>::message_, reader);
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    RpcRequest::Encode(writer);
    ::Encode(ProtoBox<T>::message_, writer);
    return true;
  }
};

#if 0
// TODO(@benqi): Handle convert error!!!!
template <typename T>
std::shared_ptr<ApiRpcRequest<T>> ToApiRpcRequest(const std::shared_ptr<EncodedRpcRequest>& encoded) {
  auto api = std::make_shared<ApiRpcRequest<T>>();
  api->package_header = encoded->package_header;
  // api->method
  // message_boxed->CopyHeaderFrom(*this);
  folly::io::Cursor c(encoded->message.payload.get());
  int length = (int)(encoded->message.payload_size);
  char* data = new char[length];
  c.pull(data, length);
  // rv = message_.ParseFromArray(data, message_.ByteSize());
  bool rv = (*api)->ParseFromArray(data, length);
  if (!rv) {
    LOG(ERROR) << "ToApiRpcRequest - Parse message error: " << encoded->ToString();
  }
  delete [] data;
  
  return api;
}

template <typename T>
std::shared_ptr<ApiRpcRequest<T>> ToApiRpcRequest(const std::shared_ptr<RpcRequest>& request) {
  auto encoded = std::static_pointer_cast<EncodedRpcRequest>(request);
  DCHECK(encoded);
  return ToApiRpcRequest<T>(encoded);
}
#endif

template <typename T>
class ApiRpcOk : public RpcOk, public ProtoBox<T> {
public:
  enum {
    HEADER = PACKAGE_RPC_OK,
  };
  
  ApiRpcOk() {
    method_response_id_ = CRC32(ProtoBox<T>::message.GetTypeName());
  }

  explicit ApiRpcOk(const RpcOk& rpc_ok) {
    // method_response_id_ = CRC32(ProtoBox<T>::message.GetTypeName());
    auth_id_ = rpc_ok.auth_id();
    session_id_ = rpc_ok.session_id();
    message_id_ = rpc_ok.message_id();
    req_message_id_ = rpc_ok.req_message_id();
    method_response_id_ = rpc_ok.GetMethodResponseID();
  }

  virtual ~ApiRpcOk() {}
  
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }

  virtual uint32_t GetMethodResponseID() const {
    return method_response_id_;
  }
  
//  uint32_t CalcPackageSize() const override {
//    return RpcOk::CalcPackageSize() + ProtoBox<T>::message.ByteSize();
//  }
//
//  virtual std::string ToString() const override {
//    return folly::sformat("{{base: {}, req_message_id: {}, method_response_id: {}, payload: {}}}",
//                          RpcOk::ToString(),
//                          req_message_id,
//                          GetMethodResponseID(),
//                          ProtoBox<T>::message.Utf8DebugString());
//  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!RpcOk::Decode(reader)) return false;
    return ::Decode(ProtoBox<T>::message_, reader);
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    RpcOk::Encode(writer);
    ::Encode(ProtoBox<T>::message_, writer);
    return true;
  }
};

template <typename T>
boost::shared_ptr<ApiRpcOk<T>> ToApiRpcOk(const boost::shared_ptr<EncodedRpcOk>& encoded) {
  boost::shared_ptr<ApiRpcOk<T>> api(new ApiRpcOk<T>(*encoded));
  (*api)->ParseFromArray((*encoded)->GetPayloadData(), (*encoded)->GetPayloadDataLen());
  return api;
  /*
  auto api = std::make_shared<ApiRpcOk<T>>();
  api->package_header = encoded->package_header;
  api->req_message_id = encoded->req_message_id;
  
  // api->method
  // message_boxed->CopyHeaderFrom(*this);
  folly::io::Cursor c(encoded->message.payload.get());
  int length = (int)(encoded->message.payload_size);
  char* data = new char[length];
  c.pull(data, length);
  // rv = message_.ParseFromArray(data, message_.ByteSize());
  (*api)->ParseFromArray(data, length);
  delete [] data;
  
  return api;
   */
}

#if 0
template <typename T>
std::shared_ptr<ApiRpcOk<T>> ToApiRpcOk(const std::shared_ptr<ProtoRpcResponse>& response) {
  auto encoded = std::static_pointer_cast<EncodedRpcOk>(response);
  DCHECK(encoded);
  return ToApiRpcOk<T>(encoded);
}
#endif

template <typename T>
class ApiPush : public Push, public ProtoBox<T> {
public:
  enum {
    HEADER = PACKAGE_PUSH,
  };
  
  ApiPush() {}
  virtual ~ApiPush() {}
  
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }

//  uint32_t CalcPackageSize() const override {
//    return Push::CalcPackageSize() + ProtoBox<T>::message.ByteSize();
//  }
//  
//  virtual std::string ToString() const override {
//    return folly::sformat("{{base: {}, payload: {}}}",
//                          Push::ToString(),
//                          ProtoBox<T>::message.Utf8DebugString());
//  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!RpcRequest::Decode(reader)) return false;
    return ::Decode(ProtoBox<T>::message_, reader);
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    RpcRequest::Encode(writer);
    ::Encode(ProtoBox<T>::message_, writer);
    return true;
  }
};

#if 0
template <typename T>
std::shared_ptr<ApiPush<T>> ToApiPush(const std::shared_ptr<EncodedPush>& encoded) {
  auto api = std::make_shared<ApiPush<T>>();
  api->package_header = encoded->package_header;
  api->update_id = encoded->update_id;
  
  folly::io::Cursor c(encoded->message.payload.get());
  int length = (int)(encoded->message.payload_size);
  char* data = new char[length];
  c.pull(data, length);
  // rv = message_.ParseFromArray(data, message_.ByteSize());
  (*api)->ParseFromArray(data, length);
  delete [] data;
  
  return api;
}

// TODO(@benqi):
//  RpcOk可以不用关注具体的Message
//  可以直接生成EncodedRpcOk
template<typename MESSAGE>
inline RpcRequestPtr MakeRpcRequest(MESSAGE& message) {
  static_assert(std::is_base_of<google::protobuf::Message, MESSAGE>::value,
                "MessaegType must be google::protobuf::Message");

  auto request = std::make_shared<ApiRpcRequest<MESSAGE>>();
  (*request)->Swap(&message);
  return request;
}

// 构建RpcOK
// TODO(@benqi):
//  RpcOk可以不用关注具体的Message
//  可以直接生成EncodedRpcOk
template<typename MESSAGE>
inline ProtoRpcResponsePtr MakeRpcOK(MESSAGE& message) {
  static_assert(std::is_base_of<google::protobuf::Message, MESSAGE>::value,
                "MessaegType must be google::protobuf::Message");
  
  auto rsp = std::make_shared<ApiRpcOk<MESSAGE>>();
  (*rsp)->Swap(&message);
  return rsp;
}

// TODO(@benqi):
//  添加详细出错信息
inline ProtoRpcResponsePtr MakeRpcError() {
  // TODO(@benqi):
  /*
   int32_t error_code;
   // Error Tag like "ACCESS_DENIED"
   std::string error_tag;
   
   // User visible error
   std::string user_message;
   
   // Can user try again
   bool can_try_again;
   
   // Some additional data of error
   std::string error_data;
   */
  return std::make_shared<RpcFloodWait>();
}

// TODO(@benqi):
//  添加Delay时间
inline ProtoRpcResponsePtr MakeRpcFloodWait() {
  return std::make_shared<RpcError>();
}
// TODO(@benqi):
// bool can_try_again;      //: bool
// int32_t try_again_delay; //: int
inline ProtoRpcResponsePtr MakeRpcInternalError() {
  // TODO(@benqi):
  return std::make_shared<RpcInternalError>();
}

inline bool ToRpcRequestMessage(const std::shared_ptr<RpcRequest>& request,
                                google::protobuf::Message* message) {
  auto encoded = std::static_pointer_cast<EncodedRpcRequest>(request);
  DCHECK(encoded);
  
  // TODO(@benqi)
  //  ZeroCopy性能优化
  folly::io::Cursor c(encoded->message.payload.get());
  int length = (int)(encoded->message.payload_size);
  char* data = new char[length];
  c.pull(data, length);
  // rv = message_.ParseFromArray(data, message_.ByteSize());
  bool rv = message->ParseFromArray(data, length);
  delete [] data;
  
  return rv;
}

// TODO(@benqi):
//  RpcOk可以不用关注具体的Message
//  可以直接生成EncodedPush
template<typename MESSAGE>
inline PushPtr MakePush(MESSAGE& message) {
  static_assert(std::is_base_of<google::protobuf::Message, MESSAGE>::value,
                "MessaegType must be google::protobuf::Message");
  
  auto request = std::make_shared<ApiPush<MESSAGE>>();
  (*request)->Swap(&message);
  return request;
}

///////////////////////////////////////////////////////////////////////////////////
#define CAST_RPC_REQUEST(MESSAGE, message_req) \
  zproto::MESSAGE message_req; \
  bool c_r = ToRpcRequestMessage(request, &message_req); \
  if (!c_r) { \
    LOG(ERROR) << "ToRpcRequestMessage error: " << request->ToString(); \
    return MakeRpcInternalError(); \
  }
#endif

#endif // NUBULA_NET_ZPROTO_API_API_MESSAGE_BOX_H_

