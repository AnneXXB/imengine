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

#include "core/zproto_frame_data.h"

int Frame::ParseFromBuffer(const AutoBuffer& buffer) {
  uint32_t buffer_len = buffer.Length();
  
  if (buffer_len < MIN_HEADER_LEN) {
    // TODO(@benqi): XLOG
    return kHeaderContinue;
  }
  
  ByteBufferReader r(buffer);
  r >> magic_number
    >> head_length
    >> client_version
    >> frame_index
    >> seq_num
    >> command_id
    >> body.data_len;

  if (magic_number!=kMagicNumber) {
    // TODO(@benqi): XLOG
    return kMagicNumberError;
  }

  if (head_length<MIN_HEADER_LEN || head_length > MAX_HEADER_LEN) {
    // TODO(@benqi): XLOG
    return kHeadLengError;
  }

  if (client_version!=kClientVersion) {
    // TODO(@benqi): XLOG
    return kClientVersionError;
  }

  // TODO(@benqi): Check frame_index
  // if (frame_index!=last_frame_index) {
  //   // TODO(@benqi): XLOG
  //   return kFrameIndexError;
  // }
  
  if (!CheckFrameType(command_id)) {
    // TODO(@benqi): XLOG
    return kFrameTypeError;
  }
  
  if (buffer_len < head_length) {
    // TODO(@benqi): XLOG
    return kHeaderContinue;
  }
  head_option_data.data_len = head_length - MIN_HEADER_LEN;
  head_option_data.data = (const uint8_t*)r.PosData();
  
  r.Seek(head_length);
  // if (frame_type)
  // body.data_len = tmp & 0xffffff;
  body.data = (const uint8_t*)(r.PosData());
  
  if (body.data_len+head_length+TAILER_LEN > kMaxFrameLength) {
    // TODO(@benqi): XLOG
    return kLengthError;
  }
  
  if (body.data_len + head_length + TAILER_LEN > buffer_len) {
    // TODO(@benqi): XLOG
    return kBodyContinue;
  }
  
  r.Skip(r.Tell() + body.data_len);
  
  r >> crc32;
  
  // TODO(@benqi): Check crc32
  // if (crc(body.data, body.data_len) != crc32) {
  //   // TODO(@benqi): XLOG
  //   return kCrc32Error;
  // }
  
  return kUnpackOk;;
}

bool Frame::SerializeToBuffer(AutoBuffer& buffer) const {
  ByteBufferWriter writer(buffer);
  
  writer << magic_number
          << static_cast<uint16_t>(head_option_data.data_len + MIN_HEADER_LEN)
          << client_version
          << frame_index
          << seq_num
          << command_id
          << body.data_len;
  
  if (head_option_data.data_len > 0) {
    writer.WriteRawData(head_option_data.data, head_option_data.data_len);
  }
  if (body.data_len>0) {
    writer.WriteRawData(body.data, body.data_len);
  }
  
  writer << crc32;
  return true;
}


bool FrameMessage::SerializeToBuffer(AutoBuffer& buffer) const {
  ByteBufferWriter writer(buffer);
  return Encode(writer);
}

bool FrameMessage::ParseFromBuffer(const AutoBuffer& buffer) {
  ByteBufferReader reader(buffer);
  return Decode(reader);
}

bool FrameMessage::ParseFromBuffer(const void* buffer, uint32_t buffer_len) {
  ByteBufferReader reader((const char*)buffer, buffer_len);
  return Decode(reader);
}

bool ReadMapStringString(const ByteBufferReader& reader, std::map<std::string, std::string>& maps) {
  uint32_t l;
  reader >> l;
  for (uint32_t i=0; i<l; ++i) {
    std::string k, v;
    reader.ReadString(k);
    reader.ReadString(v);
    maps.insert(std::make_pair(k, v));
  }
  
  return !reader.Fail();
}

bool WriteMapStringString(const std::map<std::string, std::string>& maps, ByteBufferWriter& writer) {
  writer << (static_cast<uint32_t>(maps.size()));
  for (std::map<std::string, std::string>::const_iterator it = maps.begin(); it!=maps.end(); ++it) {
    writer.WriteString(it->first);
    writer.WriteString(it->second);
  }
  return true;
}

bool ReadInt64Vector(const ByteBufferReader& reader, std::vector<int64_t>& v) {
  uint32_t l;
  reader >> l;
  for (uint32_t i=0; i<l; ++i) {
    int64_t v2;
    reader >> v2;
    v.push_back(v2);
  }
  
  return !reader.Fail();
}

bool WriteInt64Vector(const std::vector<int64_t>& v, ByteBufferWriter& writer) {
  writer << (static_cast<uint32_t>(v.size()));
  for (size_t i=0; i<v.size(); ++i) {
    writer << v[i];
  }
  return true;
}

