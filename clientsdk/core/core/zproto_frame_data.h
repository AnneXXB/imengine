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

#ifndef NUBULA_NET_ZPROTO_ZPROTO_FRAME_DATA_H_
#define NUBULA_NET_ZPROTO_ZPROTO_FRAME_DATA_H_

#include <string>
#include <list>
#include <map>
#include <vector>

#include "core/auto_buffer_codec.h"
#include "core/zproto_command_ids.h"

//////////////////////////////////////////////////////////////////////
#define SIZEOF sizeof
// string序列化占用长度
#define SIZEOF_STRING(s) (sizeof(uint32_t)+static_cast<uint32_t>((s).length()))

#define CAST_PROTO_MESSAGE(MESSAGE, value) \
  auto value = std::static_pointer_cast<MESSAGE>(message); \
  if (!value) { \
    LOG(ERROR) << "recv a valid " << #MESSAGE << " data."; \
    return; \
  }

// 定义成员宏
// 普通对象，例如string等不需要自己管理内存的对象
#define PROPERTY_OBJECT_DECLARE(class_name, proterty) \
  inline const class_name & proterty() const { return proterty##_; } \
  inline void set_##proterty(const class_name & val) { proterty##_ = val; } \
  inline class_name * mutable_##proterty() { return &proterty##_; }

// 自定义对象，存储的是对象指针，分配和释放需要自己管理
#define PROPERTY_OBJECTPTR_DECLARE(class_name, proterty) \
  inline const class_name & proterty() const { return *proterty##_; } \
  inline void set_##proterty(const class_name & val) { *(mutable_##proterty()) = val; } \
  inline class_name * mutable_##proterty() { if (proterty##_ == NULL) proterty##_ = new class_name(); return proterty##_; }

// 基本类型，如int
#define PROPERTY_BASIC_TYPE_DECLARE(class_type, proterty) \
  inline class_type proterty() const { return proterty##_; } \
  inline void set_##proterty( class_type val ) { proterty##_ = val; }

//////////////////////////////////////////////////////////////////////////
// 普通对象，例如string等不需要自己管理内存的对象
#define PROPERTY_OBJECT_ARRAY_DECLARE(class_name, proterty) \
  inline int proterty_##size() const { return proterty##_.size(); } \
  inline const class_name##& proterty(int index) const { return proterty##_[index]; } \
  inline void add_##proterty( const class_name& val ) { proterty##_.push_back(val); } \
  inline std::vector<class_name##*>* mutable_##proterty() { return &proterty##_; }

// 自定义对象，存储的是对象指针，分配和释放需要自己管理
#define PROPERTY_OBJECTPTR_ARRAY_DECLARE(class_name, proterty) \
  inline int proterty_##size() const { return proterty##_.size(); } \
  inline const std::vector<class_name *> & proterty() const { return proterty##_; } \
  inline const class_name & proterty(int index) const { return *proterty##_[index]; } \
  inline class_name * add_##proterty() { class_name * val = new class_name(); proterty##_.push_back(val); return val; } \
  inline std::vector<class_name *>* mutable_##proterty() { return &proterty##_; }

// 基本类型，如int
#define PROPERTY_BASIC_TYPE_ARRAY_DECLARE(class_type, proterty) \
  inline int proterty_##size() const { return proterty##_.size(); } \
  inline const std::vector<class_type>& proterty() const { return proterty##_; } \
  inline class_type proterty(int index) const { return proterty##_[index]; } \
  inline void add_##proterty( class_type val ) { proterty##_.push_back(val); } \
  inline std::vector<class_type>* mutable_##proterty() { return &proterty##_; }


#define CalculateContainerByteSize2(size, arr)  \
  do { \
    size += sizeof(uint32_t); \
    for (size_t i=0; i<arr.size(); ++i) { \
    size += ::ByteSize(*arr[i]); \
    } \
  } while (0);

// template <class T>
// uint32 CalculateContainerByteSize(const T& container) {
//   uint32 size = sizeof(uint32);
//   for (typename T::const_iterator i(container.begin()); i != container.end(); ++i)
//     size += ::ByteSize( *(*i));//->ByteSize();
// 
//   return size;
// }
// 
// template <>
// uint32_t CalculateContainerByteSize(const std::vector<uint32_t>& container);

//////////////////////////////////////////////////////////////////////////
#define PARSE_OBJECTPTR_ARRAY_IMPLICIT(class_name, arr) \
  do { \
    uint32_t array_size =0; \
    is >> array_size; \
    for (uint32_t i=0; i<array_size; ++i) { \
      class_name* obj = new class_name(); \
      ::ParseFromByteStream(obj, is); \
      arr.push_back(obj); \
    } \
  } while (0);

#define SERIALIZE_OBJECTPTR_ARRAY_IMPLICIT(arr) \
  do { \
    (*os) << static_cast<uint32_t>(arr.size()); \
    for (size_t i=0; i<arr.size(); ++i) { \
    ::SerializeToByteStream(*arr[i], os); \
    } \
  } while (0);


#define PARSE_BASICTYPE_ARRAY_IMPLICIT(class_type, arr) \
  do { \
    uint32_t array_size =0; \
    is >> array_size; \
    for (uint32_t i=0; i<array_size; ++i) { \
      class_type v; \
      is >> v; \
      arr.push_back(v); \
    } \
  } while (0);

#define SERIALIZE_BASICTYPE_ARRAY_IMPLICIT(arr) \
  do { \
    (*os) << static_cast<uint32_t>(arr.size()); \
    for (size_t i=0; i<arr.size(); ++i) { \
      (*os) << arr[i]; \
    } \
  } while (0);


////////////////////////////////////////////////////////////////////////////
struct ConstByteData {
  ConstByteData() = default;
  ConstByteData(const uint8_t* _data, uint32_t _data_len)
    : data(_data),
      data_len(_data_len) {}
  
  const uint8_t* data{nullptr};
  uint32_t data_len{0};
};

// zproto's MagicNumber
const uint16_t kMagicNumber = 0x5342;
// 数据包体最大长度
const uint32_t kMaxFrameLength = 1024*1024; // 1MB
const uint16_t kClientVersion = 200; // 

// Connection Level
struct Frame {
  static bool CheckFrameType(uint32_t header) {
    header = header >> 24;
    if ((header >> 24 == FRAME_PROTO >> 24) ||
        header == FRAME_PING ||
        header == FRAME_PONG ||
        header == FRAME_DROP ||
        header == FRAME_REDIRECT ||
        header == FRAME_ACK ||
        header == FRAME_HANDSHAKE ||
        header == FRAME_HANDSHAKE_RESPONSE) {
      return true;
    } else {
      return false;
    }
  }
  
  enum {
    MIN_HEADER_LEN = 20,
    MAX_HEADER_LEN = 1024,  // 给1K吧
    TAILER_LEN = 4, // crc32
  };

  Frame() = default;
  Frame(uint32_t _seq_num, uint32_t _command_id, const uint8_t* _raw, uint32_t _raw_len)
    : seq_num(_seq_num),
      command_id(_command_id),
      body(_raw, _raw_len) {}

  // ParseFromBuffer返回值
  enum {
    kUnpackOk = 0,
    kHeaderContinue = 1,
    kBodyContinue = 2,
    kMagicNumberError = -1,
    kHeadLengError = -2,
    kClientVersionError = -3,
    kFrameIndexError = -4,
    kFrameTypeError = -5,
    kCrc32Error = -6,
    kLengthError = -7,
  };
  int ParseFromBuffer(const AutoBuffer& buffer);
  bool SerializeToBuffer(AutoBuffer& buffer) const;

  inline uint32_t CalcFrameLength() const {
    return head_length + TAILER_LEN + body.data_len;
  }
  
  // bool Decode(std::unique_ptr<folly::IOBuf> frame_data);
  
  std::string ToString() const;
  
  uint16_t magic_number{kMagicNumber};    // {0x5342}; // 两傻逼，给两字节('SB')
  uint16_t head_length{MIN_HEADER_LEN};     // 头长度
  uint16_t client_version{kClientVersion};  // 客户端版本号
  uint16_t frame_index{0};     // 包序号
  uint32_t seq_num{0};         // {0};
  uint32_t command_id{0xffffffff};      // 命令ID
  
  ConstByteData head_option_data;   // 其它header_data
  ConstByteData body;       // body长度和数据
  // CRC32 of body
  uint32_t crc32{0};           // {0};
};

class FrameMessage {
public:
  virtual ~FrameMessage() = default;
  
  void SetSeqNumber(uint32_t v) {
    seq_number_ = v;
  }
  
  uint32_t GetSeqNumber() const {
    return seq_number_;
  }
  
  // virtual uint32_t GetPackageType() const = 0;
  virtual uint32_t GetCommandID() const = 0;
  
  uint32_t GetFrameType() const {
    return GetCommandID() >> 24;
  }

  // virtual bool Decode(Frame& frame) { return true; }
  
  virtual std::string ToString() const { return ""; }
  
  virtual uint32_t CalcFrameBodySize() const {
    return 0;
  }

  // 序列化和反序列化
  bool SerializeToBuffer(AutoBuffer& buffer) const;
  bool ParseFromBuffer(const AutoBuffer& buffer);
  bool ParseFromBuffer(const void* buffer, uint32_t buffer_len);

protected:
  virtual bool Decode(const ByteBufferReader& reader) { return false; }
  virtual bool Encode(ByteBufferWriter& writer) const { return false; }
  
  uint32_t seq_number_{0};
};

// HEADER_PROTO = 0;
class ProtoFrame : public FrameMessage {
public:
  enum {
    HEADER = FRAME_PROTO,
  };

  virtual ~ProtoFrame() override = default;

  uint32_t GetCommandID() const override {
    return HEADER;
  }
};

// Ping message can be sent from both sides
class Ping : public FrameMessage {
public:
  enum {
    HEADER = FRAME_PING,
  };

  Ping() = default;
  explicit Ping(std::string& ping_data) {
    random_bytes_.swap(ping_data);
  }
  virtual ~Ping() override = default;

  PROPERTY_OBJECT_DECLARE(std::string, random_bytes);
  
  uint32_t GetCommandID() const override {
    return HEADER;
  }
  
  uint32_t CalcFrameBodySize() const override {
    return random_bytes_.length();
  }
  
protected:
  bool Decode(const ByteBufferReader& reader) override {
    random_bytes_.assign(reader.Data(), reader.Length());
    return true;
  }
  bool Encode(ByteBufferWriter& writer) const override {
    writer.WriteRawData(random_bytes_.data(), random_bytes_.length());
    return true;
  }

  std::string random_bytes_;
};

// Pong message need to be sent immediately after receving Ping message
class Pong : public FrameMessage {
public:
  enum {
    HEADER = FRAME_PONG
  };

  Pong() = default;
  explicit Pong(std::string& pong_data) {
    random_bytes_.swap(pong_data);
  }
  virtual ~Pong() = default;

  PROPERTY_OBJECT_DECLARE(std::string, random_bytes);

  virtual uint32_t GetCommandID() const {
    return HEADER;
  }

  virtual uint32_t CalcFrameBodySize() const {
    return random_bytes_.length();
  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    random_bytes_.assign(reader.Data(), reader.Length());
    return true;
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    writer.WriteRawData(random_bytes_.data(), random_bytes_.length());
    return true;
  }

  // Same bytes as in Ping package
  std::string random_bytes_;
};

// header = 3
// Notification about connection drop
class Drop : public FrameMessage {
public:
  enum {
    HEADER = FRAME_DROP,
  };

  Drop() {}
  Drop(int64_t message_id, uint8_t error_code, const std::string& error_message)
    : message_id_(message_id),
      error_code_(error_code),
      error_message_(error_message) {}
  virtual ~Drop() {}

  PROPERTY_BASIC_TYPE_DECLARE(int64_t, message_id);
  PROPERTY_BASIC_TYPE_DECLARE(uint8_t, error_code);
  PROPERTY_OBJECT_DECLARE(std::string, error_message);

  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
  virtual uint32_t CalcFrameBodySize() const {
    return (sizeof(message_id_) +
            sizeof(error_code_) +
            SIZEOF_STRING(error_message_));
  }
  
protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    reader >> message_id_
            >> error_code_;
    reader.ReadString(error_message_);
    return !reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    writer << message_id_
            << error_code_;
    writer.WriteString(error_message_);
    return true;
  }

  // Same bytes as in Ping package
  int64_t message_id_;
  uint8_t error_code_;
  std::string error_message_;
};

// header = 4
// Sent by server when we need to temporary redirect to another server
class Redirect : public FrameMessage {
public:
  enum {
    HEADER = FRAME_REDIRECT,
  };
  
  Redirect() {}
  Redirect(const std::string& host, int port, int timeout)
    : host_(host),
      port_(port),
      timeout_(timeout) {}
  virtual ~Redirect() {}

  PROPERTY_OBJECT_DECLARE(std::string, host);
  PROPERTY_BASIC_TYPE_DECLARE(int, port);
  PROPERTY_BASIC_TYPE_DECLARE(int, timeout);

  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
  virtual uint32_t CalcFrameBodySize() const {
    return (SIZEOF_STRING(host_) +
            sizeof(port_) +
            sizeof(timeout_));
  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    reader.ReadString(host_);
    reader >> port_
            >> timeout_;
    return !reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    writer.WriteString(host_);
    writer << host_
            << timeout_;
    return true;
  }

  std::string host_;
  int port_;
  // Redirection timeout
  int timeout_;
};

// header = 6
// Proto package is received by destination peer. Used for determening of connection state
class Ack : public FrameMessage {
public:
  enum {
    HEADER = FRAME_ACK,
  };
  
  Ack() {}
  Ack(int received_package_index)
    : received_package_index_(received_package_index) {}
  virtual ~Ack() {}

  PROPERTY_BASIC_TYPE_DECLARE(int, received_package_index);

  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
  virtual uint32_t CalcFrameBodySize() const {
    return (sizeof(received_package_index_));
  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    reader >> received_package_index_;
    return !reader.Fail();
  }
  
  virtual bool Encode(ByteBufferWriter& writer) const {
    writer << received_package_index_;
    return true;
  }

  int received_package_index_;
};

class Handshake : public FrameMessage {
public:
  enum {
    HEADER = FRAME_HANDSHAKE,
  };

  Handshake() {}
  virtual ~Handshake() {}

  PROPERTY_BASIC_TYPE_DECLARE(uint8_t, proto_revision);
  PROPERTY_BASIC_TYPE_DECLARE(uint8_t, api_major_version);
  PROPERTY_BASIC_TYPE_DECLARE(uint8_t, api_minor_version);
  
  inline void set_random_bytes(const uint8_t* data, int len = 32) {
    memcpy(random_bytes_, data, std::min(len, 32));
  }
  
  inline ConstByteData random_bytes() const {
    return ConstByteData(random_bytes_, 32);
  }
  
  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
  virtual uint32_t CalcFrameBodySize() const {
    return (sizeof(proto_revision_) +
            sizeof(api_major_version_) +
            sizeof(api_minor_version_) +
            sizeof(random_bytes_));
  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    reader >> proto_revision_
            >> api_major_version_
            >> api_minor_version_;
    reader.ReadRawData(random_bytes_, sizeof(random_bytes_));
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    writer << proto_revision_
            << api_major_version_
            << api_minor_version_;
    writer.WriteRawData(random_bytes_, sizeof(random_bytes_));
    return true;
  }

  // Current MTProto revision
  // For Rev 2 need to eq 1
  uint8_t proto_revision_;
  // API Major and Minor version
  uint8_t api_major_version_;
  uint8_t api_minor_version_;
  
  // Some Random Bytes (suggested size is 32 bytes)
  uint8_t random_bytes_[32];
};

class HandshakeResponse : public FrameMessage {
public:
  enum {
    HEADER = FRAME_HANDSHAKE_RESPONSE,
  };

  HandshakeResponse() {}
  virtual ~HandshakeResponse() {}

  PROPERTY_BASIC_TYPE_DECLARE(uint8_t, proto_revision);
  PROPERTY_BASIC_TYPE_DECLARE(uint8_t, api_major_version);
  PROPERTY_BASIC_TYPE_DECLARE(uint8_t, api_minor_version);
  
  inline ConstByteData sha1() const {
    return ConstByteData(sha1_, 32);
  }

  virtual uint32_t GetCommandID() const {
    return HEADER;
  }
  
  virtual uint32_t CalcFrameBodySize() const {
    return (sizeof(proto_revision_) +
            sizeof(api_major_version_) +
            sizeof(api_minor_version_) +
            sizeof(sha1_));
  }

protected:
  virtual bool Decode(const ByteBufferReader& reader) {
    reader >> proto_revision_
            >> api_major_version_
            >> api_minor_version_;
    reader.ReadRawData(sha1_, sizeof(sha1_));
    return reader.Fail();
  }
  virtual bool Encode(ByteBufferWriter& writer) const {
    writer << proto_revision_
            << api_major_version_
            << api_minor_version_;
    writer.WriteRawData(sha1_, sizeof(sha1_));
    return true;
  }

  // return same versions as request, 0 - version is not supported
  uint8_t proto_revision_;
  uint8_t api_major_version_;
  uint8_t api_minor_version_;
  
  // SHA256 of randomBytes from request
  uint8_t sha1_[32];
};

// TODO(@benqi): 模板
bool ReadMapStringString(const ByteBufferReader& reader, std::map<std::string, std::string>& maps);
bool WriteMapStringString(const std::map<std::string, std::string>& maps, ByteBufferWriter& writer);

bool ReadInt64Vector(const ByteBufferReader& reader, std::vector<int64_t>& v);
bool WriteInt64Vector(const std::vector<int64_t>& v, ByteBufferWriter& writer);

#endif // NUBULA_NET_ZPROTO_ZPROTO_FRAME_DATA_H_

