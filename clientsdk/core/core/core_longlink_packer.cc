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

#include "core/core_longlink_packer.h"

#include "mars/comm/autobuffer.h"
#include "mars/comm/xlogger/xlogger.h"

#include "core/zproto_frame_data.h"

void longlink_pack(uint32_t _cmdid, uint32_t _seq, const void* _raw, size_t _raw_len, AutoBuffer& _packed) {
  Frame frame(_seq, _cmdid, (const uint8_t*)_raw, (uint32_t)_raw_len);
  _packed.AllocWrite(frame.CalcFrameLength());
  frame.SerializeToBuffer(_packed);
  _packed.Seek(0, AutoBuffer::ESeekStart);
}

int longlink_unpack(const AutoBuffer& _packed, uint32_t& _cmdid, uint32_t& _seq, size_t& _package_len, AutoBuffer& _body) {
  xinfo2("longlink_unpack - packed: %i!!!", _packed.Length());
  Frame frame;
  int ret = frame.ParseFromBuffer(_packed);
  if (ret == Frame::kUnpackOk ||
      ret == Frame::kBodyContinue ||
      ret == Frame::kLengthError ||
      ret == Frame::kCrc32Error) {
    _cmdid = frame.command_id;
    _seq = frame.seq_num;
    _package_len = frame.body.data_len + frame.head_length + Frame::TAILER_LEN;
  } else {
    _package_len = 0;
  }
  
  if (ret == Frame::kHeaderContinue || ret == Frame::kBodyContinue) {
    return LONGLINK_UNPACK_CONTINUE;
  } else if (ret != Frame::kUnpackOk) {
    xinfo2("longlink_unpack - parse error!!!");
    return LONGLINK_UNPACK_FALSE;
  }
  
  // mars的设计原则是假设客户端发送一个请求cmdid后，服务端返回同样的cmdid
  // 但zproto协议设计是: RpcReques -> RpcOk或RpcError或RpcFloodWait或RpcInternealError
  // 需要将_cmdid透传回上层，仅仅_cmdid=PACKAGE_RPC_REQUEST的情况
  if (_cmdid == PACKAGE_RPC_OK ||
      _cmdid == PACKAGE_RPC_ERROR ||
      _cmdid == PACKAGE_RPC_FLOOD_WAIT ||
      _cmdid == PACKAGE_RPC_INTERNAL_ERROR) {
    _body.Write(&_cmdid, sizeof(_cmdid));
  }
  _body.Write(frame.body.data, frame.body.data_len);

  return LONGLINK_UNPACK_OK;
}

/**
 * nooping param
 */
uint32_t longlink_noop_cmdid() {
  return Ping::HEADER;
}

uint32_t longlink_noop_resp_cmdid() {
  return Pong::HEADER;
}

uint32_t signal_keep_cmdid() {
  return FRAME_MARS_SIGNAL;
}

void longlink_noop_req_body(AutoBuffer& _body) {
  xinfo2("longlink_noop_req_body - send ping!!!");
  Ping ping;
  ping.set_random_bytes("nebula-im ping!");
  ping.SerializeToBuffer(_body);
}

void longlink_noop_resp_body(AutoBuffer& _body) {
  xinfo2("longlink_noop_resp_body - recv pong!!!");

  Pong pong;
  pong.ParseFromBuffer(_body);
}

uint32_t longlink_noop_interval() {
  return 10*1000;
}

bool longlink_complexconnect_need_verify() {
  return false;
}

bool is_push_data(uint32_t _cmdid, uint32_t _taskid) {
  return false;
}
