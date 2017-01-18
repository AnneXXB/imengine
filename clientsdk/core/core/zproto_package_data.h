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

#ifndef NUBULA_NET_ZPROTO_ZPROTO_PACKAGE_DATA_H_
#define NUBULA_NET_ZPROTO_ZPROTO_PACKAGE_DATA_H_

#include <list>

#include "core/zproto_frame_data.h"

const uint32_t kPackageHeaderLength = 25; //

class PackageMessage : public ProtoFrame {
public:
  virtual ~PackageMessage() {}

  PROPERTY_BASIC_TYPE_DECLARE(int64_t, auth_id);
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, session_id);
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, message_id);

  //////////////////////////////////////////////////////////////////////////
  virtual std::string ToString() const { return ""; }
  uint32_t GetPackageType() const {
    return GetCommandID() >> 16;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    uint8_t package_type;
    reader >> auth_id_
            >> session_id_
            >> message_id_
            >> package_type;
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    writer << auth_id_
            << session_id_
            << message_id_
            << (uint8_t)((GetCommandID() >> 16) & 0xff);
    return true;
  }

  int64_t auth_id_ {0};
  // random identifier of current session
  int64_t session_id_ {0};
  int64_t message_id_ {0};
};

// using PackageMessagePtr = std::shared_ptr<PackageMessage>;

////////////////////////////////////////////////////////////////////////////////////////////
class AuthIdInvalid : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_AUTH_ID_INVALID,
  };
  
  AuthIdInvalid() {}
  virtual ~AuthIdInvalid() {}

  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
};

class RequestAuthId : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_REQUEST_AUTH_ID,
  };
  
  RequestAuthId() {}
  virtual ~RequestAuthId() {}

  virtual uint32_t GetCommandID() const {
    return HEADER;
  }

protected:
};

class ResponseAuthId : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_RESPONSE_AUTH_ID,
  };

  ResponseAuthId() {}
  virtual ~ResponseAuthId() {}
  
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, rep_auth_id);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> rep_auth_id_;
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << rep_auth_id_;
    return true;
  }

  // HEADER = 0xF1
  int64_t rep_auth_id_;
};

///////////////////////////////////////////////////////////////////////////////////
// Authentication Key

// Before start Client MUST send RequestStartAuth message:
class RequestStartAuth : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_REQUEST_START_AUTH,
  };
  
  RequestStartAuth() {}
  virtual ~RequestStartAuth() {}
  
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, random_id);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
//  bool Decode(Package& package) override {
//    PackageMessage::Decode(package);
//    return true;
//  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> random_id_;
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << random_id_;
    return true;
  }

  int64_t random_id_;
};

// Server MUST return list of truncated to 8 bytes of SHA-256 of available keyss
class ResponseStartAuth : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_RESPONSE_START_AUTH,
  };
  
  ResponseStartAuth() {}
  virtual ~ResponseStartAuth() {}

  PROPERTY_BASIC_TYPE_DECLARE(int64_t, random_id);
  PROPERTY_BASIC_TYPE_ARRAY_DECLARE(int64_t, available_keys);
  PROPERTY_OBJECT_DECLARE(std::string, server_nonce);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> random_id_;
    ReadInt64Vector(reader, available_keys_);
    reader.ReadString(server_nonce_);
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << random_id_;
    WriteInt64Vector(available_keys_, writer);
    writer.WriteString(server_nonce_);
    return true;
  }

  int64_t random_id_;
  std::vector<int64_t> available_keys_;
  std::string server_nonce_;
};

// Client downloads required key. Client can skip downloading keys if it have built-in keys installed.
class RequestGetServerKey : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_REQUEST_GET_SERVER_KEY,
  };
  
  RequestGetServerKey() {}
  virtual ~RequestGetServerKey() {}

  PROPERTY_BASIC_TYPE_DECLARE(int64_t, key_id);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> key_id_;
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << key_id_;
    return true;
  }

  int64_t key_id_;
};

// Server return raw key data. Client MUST to check received key by comparing FULL hash that is hardcoded inside application. Again, DON'T compare truncated hashes - this is insecure.
class ResponseGetServerKey : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_RESPONSE_GET_SERVER_KEY,
  };
  
  ResponseGetServerKey() {}
  virtual ~ResponseGetServerKey() {}

  PROPERTY_BASIC_TYPE_DECLARE(int64_t, key_id);
  PROPERTY_OBJECT_DECLARE(std::string, key);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> key_id_;
    reader.ReadString(key_);
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << key_id_;
    writer.WriteString(key_);
    return true;
  }

  int64_t key_id_;
  std::string key_;
};

// Performing Diffie Hellman
class RequestDH : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_REQUEST_DH,
  };
  
  RequestDH() {}
  virtual ~RequestDH() {}

  PROPERTY_BASIC_TYPE_DECLARE(int64_t, random_id);
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, key_id);
  PROPERTY_OBJECT_DECLARE(std::string, client_nonce);
  PROPERTY_OBJECT_DECLARE(std::string, client_key);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> random_id_
            >> key_id_;
    reader.ReadString(client_nonce_);
    reader.ReadString(client_key_);
    
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << random_id_
            << key_id_;
    writer.WriteString(client_nonce_);
    writer.WriteString(client_key_);
    return true;
  }

  int64_t random_id_;
  
  // Used keyId
  int64_t key_id_;
  
  // Client's 32 securely generated bytes
  std::string client_nonce_;
  // Client's key used for encryption
  std::string client_key_;
};

// master_secret is result encryption key.
// First 128 bytes is US encryption keys and last 128 bytes is Russian encryption keys.
// HEADER_RESPONSE_DO_DH
class ResponseDoDH : public PackageMessage {
public:
  ResponseDoDH() {}
  virtual ~ResponseDoDH() {}

  enum {
    HEADER = PACKAGE_RESPONSE_DO_DH,
  };
  
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, random_id);
  PROPERTY_OBJECT_DECLARE(std::string, verify);
  PROPERTY_OBJECT_DECLARE(std::string, verify_sign);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> random_id_;
    reader.ReadString(verify_);
    reader.ReadString(verify_sign_);
    
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << random_id_;
    writer.WriteString(verify_);
    writer.WriteString(verify_sign_);
    return true;
  }

  int64_t random_id_;
  std::string verify_;
  std::string verify_sign_;
};

/////////////////////////////////////////////////////////////////////////////////////////
// RpcRequest/RpcOk/Push消息的playload
// 提供了一个帮助类包装数据包体内容，并兼容Protobuf(Message)接口
class EncodedMessage {
public:
  EncodedMessage() {}
  
  // const void* GetRawData() const;
  // int GetRawDataLength() const;
  
  // 为了和ProtobufMessage接口兼容
  uint32_t ByteSize() const {
    return payload_.data_len;
  }
  
  bool Decode(const ByteBufferReader& reader) {
    payload_.data_len = reader.PosLength();
    payload_.data = (const uint8_t*)reader.PosData();
    reader.Skip(payload_.data_len);
    return true;
  }
  
  bool Encode(ByteBufferWriter& writer) const {
    // folly::io::Cursor c(payload.get());
    // iobw.push(c, payload_size);
    return true;
  }
  
  std::string Utf8DebugString() const {
    return "{}";
  }
  
  void PrintDebugString() const {}
  
  std::string ToString() const {
    return "{}";
  }

  const uint8_t* GetPayloadData() const {
    return payload_.data;
  }
  
  uint32_t GetPayloadDataLen() const {
    return payload_.data_len;
  }
  
protected:
  ConstByteData payload_;
};

/////////////////////////////////////////////////////////////////////////////////////////
template <typename T>
class ProtoBox  {
public:
  // 通过指针方式直接使用MESSAGE
  T& operator*() {
    return message_;
  }
  
  const T& operator*() const {
    return message_;
  }
  
  T* operator->() {
    return &message_;
  }
  
  const T* operator->() const {
    return &message_;
  }
  
  T* get() {
    return &message_;
  }
  
  const T* get() const {
    return &message_;
  }
  
protected:
  T message_;
};

// RPC用
class ProtoRpcRequest : public PackageMessage {
public:
  virtual ~ProtoRpcRequest() {}
  
  bool CheckPackageType() const {
    return GetPackageType() == PACKAGE_RPC_REQUEST >> 16;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    return true;
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    return true;
  }

  // int64_t req_message_id;
};
  
class ProtoRpcResponse : public PackageMessage {
public:
  ProtoRpcResponse()
    : req_message_id_(0) {}
  
  explicit ProtoRpcResponse(int64_t req_message_id)
    : req_message_id_(req_message_id) {}
  virtual ~ProtoRpcResponse() {}
  
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, req_message_id);

  bool CheckPackageType() const {
    return GetPackageType() == PACKAGE_RPC_OK >> 16 ||
            GetPackageType() == PACKAGE_RPC_ERROR >> 16 ||
            GetPackageType() == PACKAGE_RPC_FLOOD_WAIT >> 16 ||
            GetPackageType() == PACKAGE_RPC_INTERNAL_ERROR >> 16;
  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> req_message_id_;
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << req_message_id_;
    return true;
  }

  int64_t req_message_id_; //  {0};
};
  
class ProtoPush : public PackageMessage {
public:
  virtual ~ProtoPush() {}
  
  bool CheckPackageType() const {
    return GetPackageType() == PACKAGE_PUSH >> 16;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    return true;
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    return true;
  }
};


///////////////////////////////////////////////////////////////////////////////////////
class RpcRequest : public ProtoRpcRequest {
public:
  RpcRequest()
    : method_id_(0) {}
  virtual ~RpcRequest() {}
  
  PROPERTY_BASIC_TYPE_DECLARE(uint32_t, method_id);

  //////////////////////////////////////////////////////////////////////////
//  uint32_t CalcPackageSize() const override {
//    return sizeof(method_id);
//    // + static_cast<uint32_t>(message.ByteSize());
//  }

  virtual uint32_t GetMethodID() const = 0;

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!ProtoRpcRequest::Decode(reader)) return false;
    
    reader >> method_id_;
    return !reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    ProtoRpcRequest::Encode(writer);
    writer << method_id_;
    return true;
  }

  // ID of API Method Request
  uint32_t method_id_; //: int
  // Encoded Request
  // body: bytes
  // mutable std::unique_ptr<folly::IOBuf> body;
};

class EncodedRpcRequest : public RpcRequest, public ProtoBox<EncodedMessage> {
public:
  EncodedRpcRequest() {}
  virtual ~EncodedRpcRequest() {}
  
  enum {
    HEADER = PACKAGE_RPC_REQUEST,
  };
  
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }

  virtual uint32_t GetMethodID() const {
    return method_id_;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!RpcRequest::Decode(reader)) return false;
    return message_.Decode(reader);
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    RpcRequest::Encode(writer);
    message_.Encode(writer);
    return true;
  }
};


// Successful RPC
class RpcOk : public ProtoRpcResponse {
public:
  virtual ~RpcOk() {}
  
  //////////////////////////////////////////////////////////////////////////
  PROPERTY_BASIC_TYPE_DECLARE(uint32_t, method_response_id);
  
  virtual uint32_t GetMethodResponseID() const = 0;

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!ProtoRpcResponse::Decode(reader)) return false;
    
    reader >> method_response_id_;
    return !reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    ProtoRpcResponse::Encode(writer);
    
    writer << method_response_id_;
    return true;
  }

  // ID of API Method Response
  uint32_t method_response_id_; // : int
  // Encoded response
  // body: bytes
  // mutable std::unique_ptr<folly::IOBuf> body;
};

class EncodedRpcOk : public RpcOk, public ProtoBox<EncodedMessage> {
public:
  EncodedRpcOk() {}
  virtual ~EncodedRpcOk() {}
  
  enum {
    HEADER = PACKAGE_RPC_OK,
  };
  
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
  virtual uint32_t GetMethodResponseID() const {
    return method_response_id_;
  }
  

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!RpcOk::Decode(reader)) return false;
    return message_.Decode(reader);
  }
  
  virtual bool Encode(ByteBufferWriter& writer) const {
    RpcOk::Encode(writer);
    message_.Encode(writer);
    return true;
  }
};

// RPC Error
class RpcError : public ProtoRpcResponse {
public:
  enum {
    HEADER = PACKAGE_RPC_ERROR,
  };
  
  virtual ~RpcError() {}
  
  PROPERTY_BASIC_TYPE_DECLARE(int32_t, error_code);
  PROPERTY_OBJECT_DECLARE(std::string, error_tag);
  PROPERTY_OBJECT_DECLARE(std::string, user_message);
  PROPERTY_BASIC_TYPE_DECLARE(bool, can_try_again);
  PROPERTY_OBJECT_DECLARE(std::string, error_data);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
//  virtual std::string ToString() const override {
//    return folly::sformat("{{base: {}, method_response_id: {}, encoded: {{}}}}}",
//                          RpcOk::ToString(),
//                          method_response_id);
//  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!ProtoRpcResponse::Decode(reader)) return false;
    
    reader >> error_code_;
    reader.ReadString(error_tag_);
    reader.ReadString(user_message_);
    reader >> can_try_again_;
    reader.ReadString(error_data_);
    
    return !reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    ProtoRpcResponse::Encode(writer);
    
    writer << error_code_;
    writer.WriteString(error_tag_);
    writer.WriteString(user_message_);
    writer << can_try_again_;
    writer.WriteString(error_data_);

    return true;
  }

  // int64_t req_message_id;

  // Error Code like HTTP Error code
  int32_t error_code_;
  // Error Tag like "ACCESS_DENIED"
  std::string error_tag_;
  
  // User visible error
  std::string user_message_;
  
  // Can user try again
  bool can_try_again_;
  
  // Some additional data of error
  std::string error_data_;
};

// RPC Flood Control.
// Client need to repeat request after delay
class RpcFloodWait : public ProtoRpcResponse {
public:
  enum {
    HEADER = PACKAGE_RPC_FLOOD_WAIT,
  };
  
  RpcFloodWait() {}
  explicit RpcFloodWait(int32_t delay)
    : delay_(delay) {}
  virtual ~RpcFloodWait() {}

  PROPERTY_BASIC_TYPE_DECLARE(int32_t, delay);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!ProtoRpcResponse::Decode(reader)) return false;
    
    reader >> delay_;
    
    return !reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    ProtoRpcResponse::Encode(writer);
    
    writer << delay_;
    
    return true;
  }

  // int64_t req_message_id;
  // Repeat delay on seconds
  int32_t delay_;
};

// Internal Server Error
// Client may try to resend message
class RpcInternalError : public ProtoRpcResponse {
public:
  enum {
    HEADER = PACKAGE_RPC_INTERNAL_ERROR,
  };
  
  RpcInternalError() {}
  
  explicit RpcInternalError(int64_t _req_message_id, int32_t _try_again_delay = 0)
    : ProtoRpcResponse(_req_message_id) {
    if (_try_again_delay>0) {
      can_try_again_ = true;
      try_again_delay_ = _try_again_delay;
    } else {
      can_try_again_ = false;
      try_again_delay_ = 0;
    }
  }

  virtual ~RpcInternalError() {}

  PROPERTY_BASIC_TYPE_DECLARE(int32_t, can_try_again);
  PROPERTY_BASIC_TYPE_DECLARE(int32_t, try_again_delay);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
//  virtual std::string ToString() const override {
//    return folly::sformat("{{req_message_id: {}, can_try_again: {}, try_again_delay: {}}}",
//                          req_message_id,
//                          can_try_again ? "true" : "false",
//                          try_again_delay);
//  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!ProtoRpcResponse::Decode(reader)) return false;
    
    reader >> can_try_again_
            >> try_again_delay_;
    
    return !reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    ProtoRpcResponse::Encode(writer);
    
    writer << can_try_again_
            << try_again_delay_;
    
    return true;
  }

  // int64_t req_message_id;
  bool can_try_again_; //: bool
  int32_t try_again_delay_; //: int
};

class Push : public ProtoPush {
public:
  virtual ~Push() {}
  
  PROPERTY_BASIC_TYPE_DECLARE(int32_t, update_id);

  //////////////////////////////////////////////////////////////////////////
//  bool Decode(Package& package) override {
//    PackageMessage::Decode(package);
//    folly::io::Cursor c(package.message.get());
//    
//    update_id = c.readBE<int32_t>();
//    nebula::io_buf_util::TrimStart(package.message.get(), 4);
//    return true;
//  }
//  
//  uint32_t CalcPackageSize() const override {
//    return sizeof(update_id); // + static_cast<int32_t>(body->computeChainDataLength());
//  }
//  
//  void Encode(IOBufWriter& iobw) const override {
//    PackageMessage::Encode(iobw);
//    iobw.writeBE(update_id);
//    // folly::io::Cursor c(body.get());
//    // iobw.push(c, static_cast<int32_t>(body->computeChainDataLength()));
//  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!ProtoPush::Decode(reader)) return false;
    
    reader >> update_id_;
    
    return !reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    ProtoPush::Encode(writer);
    
    writer << update_id_;
    
    return true;
  }

  // Push Entity Id
  int32_t update_id_; //: int
  // Encoded Push body
  // mutable std::unique_ptr<folly::IOBuf> body;
};

/////////////////////////////////////////////////////////////////////////////////////////////////
class EncodedPush : public Push, public ProtoBox<EncodedMessage> {
public:
  EncodedPush() {}
  virtual ~EncodedPush() {}
  
  enum {
    HEADER = PACKAGE_PUSH,
  };
  
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!Push::Decode(reader)) return false;
    return message_.Decode(reader);
  }
  
  virtual bool Encode(ByteBufferWriter& writer) const {
    Push::Encode(writer);
    message_.Encode(writer);
    return true;
  }
};

class MessageAck : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_MESSAGE_ACK,
  };
  
  virtual ~MessageAck() {}
  
  PROPERTY_BASIC_TYPE_ARRAY_DECLARE(int64_t, message_ids);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    ReadInt64Vector(reader, message_ids_);
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    WriteInt64Vector(message_ids_, writer);
    return true;
  }

  // Message Identificators for confirmation
  std::vector<int64_t> message_ids_;
};

// Notification about unsent message (usually ProtoRpcRequest or ProtoPush)
class UnsentMessage : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_UNSENT_MESSAGE,
  };
  
  virtual ~UnsentMessage() {}
  
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, message_id);
  PROPERTY_BASIC_TYPE_DECLARE(int32_t, len);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> message_id_
            >> len_;
    
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << message_id_
            << len_;
    
    return true;
  }

  // HEADER = 0x07
  // Sent Message Id
  int64_t message_id_;
  // Size of message in bytes
  int32_t len_;
};

// Notification about unsent ProtoRpcResponse
class UnsentResponse : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_UNSENT_RESPONSE,
  };
  
  virtual ~UnsentResponse() {}
  
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, message_id);
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, request_message_id);
  PROPERTY_BASIC_TYPE_DECLARE(int32_t, len);
  
  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> message_id_
            >> request_message_id_
            >> len_;
    
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << message_id_
            << request_message_id_
            << len_;
    
    return true;
  }

  // HEADER = 0x08
  // Sent Message Id
  int64_t message_id_;
  // Request Message Id
  int64_t request_message_id_;
  // Size of message in bytes
  int32_t len_;
};

// Requesting resending of message
class RequestResend : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_REQUEST_RESEND,
  };
  
  virtual ~RequestResend() {}
  
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, message_id);
  
  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> message_id_;
    
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << message_id_;
    
    return true;
  }

  // HEADER = 0x09
  // Message Id for resend
  int64_t message_id_; // : long
};

class NewSession : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_NEW_SESSION,
  };
  
  virtual ~NewSession() {}
  
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, session_id);
  PROPERTY_BASIC_TYPE_DECLARE(int64_t, message_id);

  //////////////////////////////////////////////////////////////////////////
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    if (!PackageMessage::Decode(reader)) return false;
    
    reader >> session_id_
            >> message_id_;
    
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    PackageMessage::Encode(writer);
    
    writer << session_id_
            << message_id_;
    
    return true;
  }

  // HEADER = 0x0C
  // Created Session Id
  int64_t session_id_;
  // Message Id of Message that created session
  int64_t message_id_;
};

class SessionHello : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_SESSION_HELLO,
  };
  
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    return PackageMessage::Decode(reader);
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    return PackageMessage::Encode(writer);
  }
};

class SessionLost : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_SESSION_LOST,
  };

  virtual ~SessionLost() {}
  
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    return PackageMessage::Decode(reader);
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    return PackageMessage::Encode(writer);
  }
};

class Container : public PackageMessage {
public:
  enum {
    HEADER = PACKAGE_CONTAINER,
  };
  
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    return PackageMessage::Decode(reader);
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    return PackageMessage::Encode(writer);
  }

  // Messages count
  // int32_t count;
  // Messages in container
  
  
  // std::list<PackageMessagePtr> data_;
};

// using PackageFactory = nebula::SelfRegisterFactoryManager<PackageMessage, uint8_t>;

#endif // NUBULA_NET_ZPROTO_ZPROTO_PACKAGE_DATA_H_

