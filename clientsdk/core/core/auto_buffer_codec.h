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

#ifndef CORE_AUTO_BUFFER_CODEC_H_
#define CORE_AUTO_BUFFER_CODEC_H_

#include <stdint.h>
#include <string>
#include "mars/comm/autobuffer.h"

class ByteBufferReader {
public:
  ByteBufferReader(const char* buffer, uint32_t buffer_len)
  : buffer_(buffer),
    buffer_len_(buffer_len),
    current_pos_(0),
    failed_(false) {}

  explicit ByteBufferReader(const AutoBuffer& buffer)
  : buffer_((const char*)buffer.Ptr()),
    buffer_len_(buffer.Length()),
    current_pos_(0),
    failed_(false) {}
  
  /**
   * 将内部指针定位到某一位置
   * @param pos 将内部指针定位到的位置,此位置相对于开始位置(0)
   * @return 成功返回当前内部指针指的位置,否则返回-1
   */
  uint32_t Seek(uint32_t pos) const;
  
  /**
   * 返回内部指针所指的位置
   * @return 不成功返回-1
   */
  uint32_t Tell(void) const {
    return current_pos_;
  }
  
  /**
   * 跳过几个字节
   * @param pos 要跳过的字节数
   * @return 成功返回0
   */
  uint32_t Skip(uint32_t skip_len) const;
  
  /**
   * 判断operator << 与operator >>操作 是否成功
   * @return 若不成功,则返回true
   */
  bool Fail(void) const {
    return failed_;
  }
  
  /**
   * 返回底层的缓冲区指针
   */
  const char* Data(void) const {
    return buffer_;
  }
  
  /**
   * 返回底层的数据的长度
   */
  uint32_t Length(void) const {
    return buffer_len_;
  }

  /**
   * 返回当前位置的缓冲区指针
   */
  const char* PosData(void) const {
    return buffer_ + current_pos_;
  }
  
  /**
   * 返回从当前位置计算的数据的长度
   */
  uint32_t PosLength(void) const {
    return buffer_len_ - current_pos_;
  }

  /**
   * 读出几个字节
   * @param pdata 存放读出的数据,应当确保此指针至少能够容纳dataLen个字节
   * @param dataLen 要读出的字节数
   * @return 成功返回0
   */
  bool ReadRawData(void* data, uint32_t data_len) const;
  
  /**
   * 读出一个字符串(以'\0'结尾)
   * @param pdata 存放读出的字符串,应当确保此指针至少能够容纳dataLen个字节
   * @param dataLen 要读出的字节数,包括结尾字符'\0'
   * @return 成功返回0
   */
  bool ReadString(char* s, uint32_t data_len) const;
  bool ReadString(std::string& str) const;
  const ByteBufferReader& operator >> (std::string& str) const;
  
  /**
   * 读出一个bool
   * @param b 存放读出的bool
   * @return 不成功,则fail() == true
   */
  const ByteBufferReader& operator >> (bool& b) const;
  
  /**
   * 读出一个char
   * @param ch 存放读出的char
   * @return 不成功,则fail() == true
   */
  const ByteBufferReader& operator >> (char& ch) const;
  
  /**
   * 读出一个uint8
   * @param ch 存放读出的uint8
   * @return 不成功,则fail() == true
   */
  const ByteBufferReader& operator >> (uint8_t& ch) const;
  
  /**
   * 读出一个int16
   * @param s 存放读出的int16
   * @return 不成功,则fail() == true
   */
  const ByteBufferReader& operator >> (int16_t& s) const;
  
  /**
   * 读出一个uint16
   * @param s 存放读出的uint16
   * @return 不成功,则fail() == true
   */
  const ByteBufferReader& operator >> (uint16_t& s) const;
  
  /**
   * 读出一个int32
   * @param l 存放读出的int32
   * @return 不成功,则fail() == true
   */
  const ByteBufferReader& operator >> (int32_t& l) const;
  
  /**
   * 读出一个int32
   * @param l 存放读出的int32
   * @return 不成功,则fail() == true
   */
  const ByteBufferReader& operator >> (uint32_t& l) const;

  /**
   * 读出一个int64_t
   * @param l 存放读出的int64_t
   * @return 不成功,则fail() == true
   */
  const ByteBufferReader& operator >> (int64_t& l) const;
  
  /**
   * 读出一个uint64_t
   * @param l 存放读出的uint64_t
   * @return 不成功,则fail() == true
   */
  const ByteBufferReader& operator >> (uint64_t& l) const;

//  operator bool () const {
//    return 0 == failed_;
//  }
//  bool operator!() const {
//    return 0 != failed_;
//  }

private:
  // const AutoBuffer& buffer_;
  const char* buffer_;	/**< 实际用于读写的缓冲区 */
  uint32_t	buffer_len_;	/**< 缓冲区中的数据长度 */
  mutable  uint32_t	current_pos_;	/**< 缓冲区中读写的当前位置 */
  mutable  bool	failed_;	/**< 指示读写操作是否成功 */

};

class ByteBufferWriter {
public:
  explicit ByteBufferWriter(AutoBuffer& buffer)
    : buffer_(buffer) {}
  
  void AllocWrite(size_t readytowrite) {
    buffer_.AllocWrite(readytowrite);
  }

  /**
   * 将内部指针定位到某一位置
   * @param pos 将内部指针定位到的位置,此位置相对于开始位置(0)
   */
  void Seek(uint32_t pos) {
    buffer_.Seek(pos, AutoBuffer::ESeekStart);
  }
  
  /**
   * 返回内部指针所指的位置
   */
  int Tell(void) const {
    return buffer_.Pos();
  }
  
  /**
   * 跳过几个字节
   * @param pos 要跳过的字节数
   */
  void Skip(uint32_t pos) const {
    buffer_.Seek(pos, AutoBuffer::ESeekCur);
  }
  
  /**
   * 返回底层的缓冲区指针
   */
  const char* Data(void) const {
    const void* ptr = buffer_.Ptr();
    return (const char*)ptr;
  }
  
  char* MutableData(void) {
    void* ptr = buffer_.Ptr();
    return (char*)ptr;
  }
  
  /**
   * 返回底层的数据的长度
   */
  uint32_t Length(void) const {
    return buffer_.Length();
  }

  /**
   * 返回当前位置的缓冲区指针
   */
  const char* PosData(void) const {
    const void* ptr = buffer_.PosPtr();
    return (const char*)ptr;
  }

  char* MutablePosData(void) {
    void* ptr = buffer_.PosPtr();
    return (char*)ptr;
  }

  /**
   * 返回从当前位置计算的数据的长度
   */
  uint32_t PosLength(void) const {
    return buffer_.PosLength();
  }

  /**
   * 写入几个字节
   * @param pdata 要写入的数据,应当确保此指针至少拥有dataLen个字节
   * @param dataLen 要写入的字节数
   */
  void WriteRawData(const void* data, uint32_t data_len);
  
  /**
   * 写入一个字符串(以'\0'结尾)
   * @param pdata 要写入的字符串
   */
  void WriteString(const char* s);
  void WriteString(const std::string& str);
  ByteBufferWriter& operator << (const std::string& str);
  
  /**
   * 写入一个bool数据
   * @param b 要写入的bool
   * @return 不成功,则fail() == true
   */
  ByteBufferWriter& operator << (bool b);
  
  /**
   * 写入一个char据
   * @param ch 要写入的ch
   * @return 不成功,则fail() == true
   */
  ByteBufferWriter& operator << (char ch);
  
  /**
   * 写入一个uint8据
   * @param ch 要写入的uint8
   * @return 不成功,则fail() == true
   */
  ByteBufferWriter& operator << (uint8_t ch);
  
  /**
   * 写入一个int16据
   * @param s 要写入的int16
   * @return 不成功,则fail() == true
   */
  ByteBufferWriter& operator << (int16_t s);
  
  /**
   * 写入一个uint16据
   * @param s 要写入的uint16
   * @return 不成功,则fail() == true
   */
  ByteBufferWriter& operator << (uint16_t s);
  
  /**
   * 写入一个int32据
   * @param l 要写入的int32
   * @return 不成功,则fail() == true
   */
  ByteBufferWriter& operator << (int32_t l);
  
  /**
   * 写入一个uint32据
   * @param l 要写入的uint32
   * @return 不成功,则fail() == true
   */
  ByteBufferWriter& operator << (uint32_t l);

  /**
   * 写入一个int64据
   * @param l 要写入的int32
   * @return 不成功,则fail() == true
   */
  ByteBufferWriter& operator << (int64_t l);
  
  /**
   * 写入一个uint64据
   * @param l 要写入的uint32
   * @return 不成功,则fail() == true
   */
  ByteBufferWriter& operator << (uint64_t l);

private:
  AutoBuffer& buffer_;
};

#endif
