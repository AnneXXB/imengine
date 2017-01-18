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

#include "core/auto_buffer_codec.h"

//////////////////////////////////////////////////////////////////////////
uint32_t ByteBufferReader::Seek( uint32_t pos ) const {
  pos = std::min(pos, buffer_len_);
  current_pos_ = pos;
  return current_pos_;
}

uint32_t ByteBufferReader::Skip( uint32_t skip_len ) const {
  uint32_t pos = std::min(current_pos_ + skip_len, buffer_len_);
  current_pos_ += pos;
  return pos;
}

//////////////////////////////////////////////////////////////////////////
bool ByteBufferReader::ReadRawData( void* data, uint32_t data_len ) const {
  if (failed_){
    return false;
  }
  
  if(current_pos_ + data_len > buffer_len_) {
    failed_ = true;
    return false;
  }
  
  memcpy( data, buffer_ + current_pos_, data_len );
  current_pos_ += data_len;
  
  return true;
}

bool ByteBufferReader::ReadString( char* s, uint32_t data_len ) const {
  uint8_t ch[4];
  uint32_t l;
  if( !ReadRawData(ch, sizeof(ch))) {
    return false;
  } else {
    l = (( ch[0] & 0xFF) << 24) | ((ch[1] & 0xFF) << 16) | ((ch[2] & 0xFF) <<  8) | (ch[3] & 0xFF);
    if (l>data_len) {
      l = data_len;
      s[l-1]='\0';
    }
  }
  return ReadRawData(s, l);
}

bool ByteBufferReader::ReadString(std::string& str) const {
  uint8_t ch[4];
  uint32_t l;
  if( !ReadRawData(ch, sizeof(ch))) {
    return false;
  }
  else {
    l = (( ch[0] & 0xFF) << 24) | ((ch[1] & 0xFF) << 16) | ((ch[2] & 0xFF) <<  8) | (ch[3] & 0xFF);
  }
  
  if ( current_pos_ + l > buffer_len_ ) {
    failed_ = true;
    return false;
  }
  str.clear();
  // str.append(buffer_ + current_pos_, 0, l);
  str.append(buffer_ + current_pos_, l);
  current_pos_ += l;
  return true;
}

const ByteBufferReader& ByteBufferReader::operator >> (std::string& str) const {
  ReadString(str);
  return *this;
}

const ByteBufferReader& ByteBufferReader::operator >> ( bool& b ) const {
  if ( current_pos_ + sizeof( char ) > buffer_len_ ) {
    failed_ = true;
  }
  else {
    b = buffer_[ current_pos_++ ] ? true:false;
  }
  return *this;
}

const ByteBufferReader& ByteBufferReader::operator >> ( uint8_t& ch ) const {
  if ( current_pos_ + sizeof( ch ) > buffer_len_ ) {
    failed_ = true;
  }
  else {
    ch = buffer_[ current_pos_++ ];
  }
  return *this;
}

const ByteBufferReader& ByteBufferReader::operator >> ( char& ch ) const {
  if ( current_pos_ + sizeof( ch ) > buffer_len_ ) {
    failed_ = true;
  }
  else {
    ch = buffer_[ current_pos_++ ];
  }
  return *this;
}

const ByteBufferReader& ByteBufferReader::operator >> ( int16_t& s ) const {
  uint8_t ch[2];
  if( ReadRawData( ch, sizeof( ch ) ) ) {
    s = (int16_t)((ch[0] & 0xFF) << 8) | (ch[1] & 0xFF);
  }
  return *this;
}

const ByteBufferReader& ByteBufferReader::operator >> ( uint16_t& s ) const {
  uint8_t ch[2];
  if( ReadRawData( ch, sizeof( ch ) ) ) {
    s = (uint16_t)((ch[0] & 0xFF) << 8) | (ch[1] & 0xFF);
  }
  return *this;
}

const ByteBufferReader& ByteBufferReader::operator >> ( int32_t& l ) const {
  uint8_t ch[4];
  if( ReadRawData( ch, sizeof( ch ) ) ) {
    l = (static_cast<uint32_t>(ch[0]) << 24) |
        (static_cast<uint32_t>(ch[1]) << 16) |
        (static_cast<uint32_t>(ch[2]) <<  8) |
        (static_cast<uint32_t>(ch[3])      );
  }
  return *this;
}

const ByteBufferReader& ByteBufferReader::operator >> ( uint32_t& l ) const {
  uint8_t ch[4];
  if( ReadRawData( ch, sizeof( ch ) ) ) {
    l = (static_cast<uint32_t>(ch[0]) << 24) |
        (static_cast<uint32_t>(ch[1]) << 16) |
        (static_cast<uint32_t>(ch[2]) <<  8) |
        (static_cast<uint32_t>(ch[3])      );
  }
  return *this;
}

const ByteBufferReader& ByteBufferReader::operator >> ( int64_t& l ) const {
  uint8_t ch[8];
  if( ReadRawData( ch, sizeof( ch ) ) ) {
    
    uint32_t l0 = (static_cast<uint32_t>(ch[0]) << 24) |
                  (static_cast<uint32_t>(ch[1]) << 16) |
                  (static_cast<uint32_t>(ch[2]) <<  8) |
                  (static_cast<uint32_t>(ch[3])      );
    uint32_t l1 = (static_cast<uint32_t>(ch[4]) << 24) |
                  (static_cast<uint32_t>(ch[5]) << 16) |
                  (static_cast<uint32_t>(ch[6]) <<  8) |
                  (static_cast<uint32_t>(ch[7])      );
    
    l = static_cast<uint64_t>(l0) << 32 |
        (static_cast<uint64_t>(l1));
  }
  return *this;
}

const ByteBufferReader& ByteBufferReader::operator >> ( uint64_t& l ) const {
  uint8_t ch[8];
  if( ReadRawData( ch, sizeof( ch ) ) ) {
    
    uint32_t l0 = (static_cast<uint32_t>(ch[0]) << 24) |
                  (static_cast<uint32_t>(ch[1]) << 16) |
                  (static_cast<uint32_t>(ch[2]) <<  8) |
                  (static_cast<uint32_t>(ch[3])      );
    uint32_t l1 = (static_cast<uint32_t>(ch[4]) << 24) |
                  (static_cast<uint32_t>(ch[5]) << 16) |
                  (static_cast<uint32_t>(ch[6]) <<  8) |
                  (static_cast<uint32_t>(ch[7])      );
    
    l = static_cast<uint64_t>(l0) << 32 |
        (static_cast<uint64_t>(l1));
  }
  return *this;
}

//////////////////////////////////////////////////////////////////////////
void ByteBufferWriter::WriteRawData( const void* data, uint32_t data_len ) {
  buffer_.Write(data, data_len);
}

void ByteBufferWriter::WriteString( const char* s ) {
  uint32_t	len = strlen( s );
  
  uint8_t ch[4];
  ch[0] = (len >> 24) & 0xff;
  ch[1] = (len >> 16) & 0xff;
  ch[2] = (len >> 8) & 0xff;
  ch[3]= len & 0xff;
  
  WriteRawData(ch, sizeof(ch));
  WriteRawData(s, len);
}

void ByteBufferWriter::WriteString(const std::string& str) {
  uint32_t	len = str.length();
  
  uint8_t ch[4];
  ch[0] = (len >> 24) & 0xff;
  ch[1] = (len >> 16) & 0xff;
  ch[2] = (len >> 8) & 0xff;
  ch[3]= len & 0xff;
  
  WriteRawData(ch, sizeof(ch));
  WriteRawData(str.c_str(), len);
}

ByteBufferWriter& ByteBufferWriter::operator << (const std::string& str) {
  WriteString(str);
  return *this;
}

ByteBufferWriter& ByteBufferWriter::operator << ( bool b ) {
  uint8_t ch = b ? 1:0;
  WriteRawData( &ch, sizeof( ch ) );
  return *this;
}

ByteBufferWriter& ByteBufferWriter::operator << ( uint8_t ch ) {
  WriteRawData( &ch, sizeof( ch ));
  return *this;
}

ByteBufferWriter& ByteBufferWriter::operator << ( char ch ) {
  WriteRawData( &ch, sizeof( ch ));
  return *this;
}

ByteBufferWriter& ByteBufferWriter::operator << ( int16_t s ) {
  uint8_t ch[2];
  ch[0] = (s >> 8) & 0xff;
  ch[1]= s & 0xff;
  WriteRawData( ch, sizeof( ch ));
  return *this;
}

ByteBufferWriter& ByteBufferWriter::operator << ( uint16_t s ) {
  uint8_t ch[2];
  ch[0] = (s >> 8) & 0xff;
  ch[1]= s & 0xff;
  WriteRawData( ch, sizeof( ch ));
  return *this;
}

ByteBufferWriter& ByteBufferWriter::operator << ( int32_t l ) {
  uint8_t ch[4];
  ch[0] = (l >> 24) & 0xff;
  ch[1] = (l >> 16) & 0xff;
  ch[2] = (l >>  8) & 0xff;
  ch[3] = l & 0xff;
  WriteRawData( ch, sizeof( ch ));
  return *this; 
}

ByteBufferWriter& ByteBufferWriter::operator << ( uint32_t l ) {
  uint8_t ch[4];
  ch[0] = (l >> 24) & 0xff;
  ch[1] = (l >> 16) & 0xff;
  ch[2] = (l >>  8) & 0xff;
  ch[3] = l & 0xff;
  WriteRawData( ch, sizeof( ch ));
  return *this; 
}

ByteBufferWriter& ByteBufferWriter::operator << ( int64_t l ) {
  uint8_t ch[8];
  ch[0] = (l >> 56) & 0xff;
  ch[1] = (l >> 48) & 0xff;
  ch[2] = (l >> 40) & 0xff;
  ch[2] = (l >> 32) & 0xff;
  ch[4] = (l >> 24) & 0xff;
  ch[5] = (l >> 16) & 0xff;
  ch[6] = (l >>  8) & 0xff;
  ch[7]=  l & 0xff;
  WriteRawData( ch, sizeof( ch ));
  return *this;
}

ByteBufferWriter& ByteBufferWriter::operator << ( uint64_t l ) {
  uint8_t ch[8];
  ch[0] = (l >> 56) & 0xff;
  ch[1] = (l >> 48) & 0xff;
  ch[2] = (l >> 40) & 0xff;
  ch[2] = (l >> 32) & 0xff;
  ch[4] = (l >> 24) & 0xff;
  ch[5] = (l >> 16) & 0xff;
  ch[6] = (l >>  8) & 0xff;
  ch[7] = l & 0xff;
  WriteRawData( ch, sizeof( ch ));
  return *this;
}
