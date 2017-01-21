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

#include "core/zproto_task_manager.h"

#import "mars/comm/xlogger/xlogger.h"

boost::shared_ptr<ProtoRpcResponse> MakeRpcResponse(uint32_t& offset, const AutoBuffer& buffer) {
  boost::shared_ptr<ProtoRpcResponse> response;
  
  ByteBufferReader reader(buffer);
  uint32_t rpc_rsp_type;
  reader.ReadRawData(&rpc_rsp_type, sizeof(rpc_rsp_type));
  
  //(AutoBuffer::TSeekS, &rpc_rsp_type, sizeof(rpc_rsp_type));
  
  switch (rpc_rsp_type) {
    case PACKAGE_RPC_OK:
      response = boost::shared_ptr<EncodedRpcOk>(new EncodedRpcOk);
      break;
    case PACKAGE_RPC_ERROR:
      response = boost::shared_ptr<RpcError>(new RpcError);
      break;
    case PACKAGE_RPC_FLOOD_WAIT:
      response = boost::shared_ptr<RpcFloodWait>(new RpcFloodWait);
      break;
    case PACKAGE_RPC_INTERNAL_ERROR:
      response = boost::shared_ptr<RpcInternalError>(new RpcInternalError);
      break;
      
    default:
      break;
  }
  
  return response;
}

FrameMessagePtr MakeResponse(uint32_t request_command_id, const AutoBuffer& buffer) {
  FrameMessagePtr response;
  uint32_t offset = 0;
  
  switch (request_command_id) {
    case FRAME_HANDSHAKE:
      response = boost::shared_ptr<HandshakeResponse>(new HandshakeResponse);
      break;
      
    case PACKAGE_REQUEST_AUTH_ID:
      response = boost::shared_ptr<ResponseAuthId>(new ResponseAuthId);
      break;
    case PACKAGE_REQUEST_START_AUTH:
      response = boost::shared_ptr<ResponseStartAuth>(new ResponseStartAuth);
      break;
    case PACKAGE_REQUEST_GET_SERVER_KEY:
      response = boost::shared_ptr<ResponseGetServerKey>(new ResponseGetServerKey);
      break;
    case PACKAGE_REQUEST_DH:
      response = boost::shared_ptr<ResponseDoDH>(new ResponseDoDH);
      break;
      
    case PACKAGE_RPC_REQUEST:
      response = MakeRpcResponse(offset, buffer);
      break;
      
    default:
      break;
  }
  
  if (response) {
    response->ParseFromBuffer(buffer.Ptr(offset), buffer.PosLength()-offset);
    // TODO(@benqi):
    // CHECK_ERROR
  }
  
  return response;
}

void ZProtoTaskManager::DoCallHandshake(boost::function<int(boost::shared_ptr<HandshakeResponse>)> cb) {
  auto handshake = boost::shared_ptr<Handshake>(new Handshake);
  handshake->set_proto_revision(0x01);
  handshake->set_api_major_version(0x00);
  handshake->set_api_minor_version(0x00);
  handshake->set_random_bytes((const uint8_t*)"012345678901234567890123456789", 32);
  
  MarsTaskWrapper task_wrapper;

  uint32_t cmd_id = handshake->GetCommandID();

  task_wrapper.req = handshake;
  task_wrapper.cb = [cmd_id, cb] (const AutoBuffer& buffer) {
    auto frame_rsp = MakeResponse(cmd_id, buffer);
    if (frame_rsp->GetCommandID() == FRAME_HANDSHAKE_RESPONSE) {
      cb(boost::static_pointer_cast<HandshakeResponse>(frame_rsp));
    } else {
      // TODO(@benqi):
      // LOG()
    }
  };
  
  mars::stn::Task task;
  task.cmdid = cmd_id;

  ScopedLock g(lock_);
  tasks_.insert(std::make_pair(task.taskid, task_wrapper));
  mars::stn::StartTask(task);
}

// Auth
void ZProtoTaskManager::DoCallRequestAuthId(boost::function<int(boost::shared_ptr<ResponseAuthId>)> cb) {
  auto resquest_auth_id = boost::shared_ptr<RequestAuthId>(new RequestAuthId);

  MarsTaskWrapper task_wrapper;
  
  uint32_t cmd_id = resquest_auth_id->GetCommandID();
  
  task_wrapper.req = resquest_auth_id;
  task_wrapper.cb = [cmd_id, cb] (const AutoBuffer& buffer) {
    auto package_rsp = MakeResponse(cmd_id, buffer);
    if (package_rsp->GetCommandID() == PACKAGE_RESPONSE_AUTH_ID) {
      cb(boost::static_pointer_cast<ResponseAuthId>(package_rsp));
    } else {
      // TODO(@benqi):
      // LOG()
    }
  };
  
  mars::stn::Task task;
  task.cmdid = cmd_id;

  ScopedLock g(lock_);
  tasks_.insert(std::make_pair(task.taskid, task_wrapper));
  mars::stn::StartTask(task);
}

void ZProtoTaskManager::DoCallRequestStartAuth(boost::shared_ptr<RequestStartAuth> request,
                                               boost::function<int(boost::shared_ptr<ResponseStartAuth>)> cb) {
  MarsTaskWrapper task_wrapper;
  
  uint32_t cmd_id = request->GetCommandID();
  
  task_wrapper.req = request;
  task_wrapper.cb = [cmd_id, cb] (const AutoBuffer& buffer) {
    auto package_rsp = MakeResponse(cmd_id, buffer);
    if (package_rsp->GetCommandID() == PACKAGE_RESPONSE_START_AUTH) {
      cb(boost::static_pointer_cast<ResponseStartAuth>(package_rsp));
    } else {
      // TODO(@benqi):
      // LOG()
    }
  };
  
  mars::stn::Task task;
  task.cmdid = cmd_id;

  ScopedLock g(lock_);
  tasks_.insert(std::make_pair(task.taskid, task_wrapper));
  mars::stn::StartTask(task);
}

void ZProtoTaskManager::DoCallRequestGetServerKey(boost::shared_ptr<RequestGetServerKey> request,
                                                  boost::function<int(boost::shared_ptr<ResponseGetServerKey>)> cb) {
  MarsTaskWrapper task_wrapper;
  
  uint32_t cmd_id = request->GetCommandID();
  
  task_wrapper.req = request;
  task_wrapper.cb = [cmd_id, cb] (const AutoBuffer& buffer) {
    auto package_rsp = MakeResponse(cmd_id, buffer);
    if (package_rsp->GetCommandID() == PACKAGE_RESPONSE_GET_SERVER_KEY) {
      cb(boost::static_pointer_cast<ResponseGetServerKey>(package_rsp));
    } else {
      // TODO(@benqi):
      // LOG()
    }
  };
  
  mars::stn::Task task;
  task.cmdid = cmd_id;
  ScopedLock g(lock_);
  tasks_.insert(std::make_pair(task.taskid, task_wrapper));
  mars::stn::StartTask(task);
}

void ZProtoTaskManager::DoCallRequestDH(boost::shared_ptr<RequestDH> request,
                                        boost::function<int(boost::shared_ptr<ResponseDoDH>)> cb) {
  mars::stn::Task task;
  MarsTaskWrapper task_wrapper;
  
  uint32_t cmd_id = request->GetCommandID();
  
  task_wrapper.req = request;
  task_wrapper.cb = [cmd_id, cb] (const AutoBuffer& buffer) {
    auto package_rsp = MakeResponse(cmd_id, buffer);
    if (package_rsp->GetCommandID() == PACKAGE_RESPONSE_DO_DH) {
      cb(boost::static_pointer_cast<ResponseDoDH>(package_rsp));
    } else {
      // TODO(@benqi):
      // LOG()
    }
  };
  
  ScopedLock g(lock_);
  tasks_.insert(std::make_pair(task.taskid, task_wrapper));
  mars::stn::StartTask(task);
}


///////////////////////////////////////////////////////////////////////////////////////
// Override from mars::stn::Callback
bool ZProtoTaskManager::MakesureAuthed() {
  ScopedLock g(lock_);
  return logoned_;
}

//流量统计
void ZProtoTaskManager::TrafficData(ssize_t _send, ssize_t _recv) {
  xdebug2(TSF"send:%_, recv:%_", _send, _recv);
}

//底层询问上层该host对应的ip列表
std::vector<std::string> ZProtoTaskManager::OnNewDns(const std::string& host) {
  std::vector<std::string> new_dns_list;
  new_dns_list.push_back("127.0.0.1");
  return new_dns_list;
}

//网络层收到push消息回调
void ZProtoTaskManager::OnPush(int32_t cmdid, const AutoBuffer& msgpayload) {
  
}

//底层获取task要发送的数据
bool ZProtoTaskManager::Req2Buf(int32_t taskid, void* const user_context, AutoBuffer& outbuffer, int& error_code, const int channel_select) {
  // TODO(@benqi): 线程同步保护
  ScopedLock g(lock_);

  TaskIDMessageMap::iterator it = tasks_.find(taskid);
  if (it == tasks_.end()) {
    return false;
  } else {
    MarsTaskWrapper& task_wrapper = it->second;
    // CHECK(message);
    task_wrapper.req->SerializeToBuffer(outbuffer);
    return true;
  }
}

//底层回包返回给上层解析
int ZProtoTaskManager::Buf2Resp(int32_t taskid, void* const user_context, const AutoBuffer& inbuffer, int& error_code, const int channel_select) {
  // TODO(@benqi): 线程同步保护
  ScopedLock g(lock_);

  TaskIDMessageMap::iterator it = tasks_.find(taskid);
  if (it == tasks_.end()) {
    // 由taskid找cmdid，然后反序列化
  } else {
    MarsTaskWrapper& task_wrapper = it->second;
    // CHECK(message);
    task_wrapper.cb(inbuffer);
  }
  
  return 0;
}

//任务执行结束
int  ZProtoTaskManager::OnTaskEnd(int32_t taskid, void* const user_context, int error_type, int error_code) {
  // TODO(@benqi): 线程同步保护
  ScopedLock g(lock_);
  
  TaskIDMessageMap::iterator it = tasks_.find(taskid);
  if (it != tasks_.end()) {
    tasks_.erase(it);
  }
  return 0;
}

//上报流量数据
void ZProtoTaskManager::ReportFlow(int32_t wifi_recv, int32_t wifi_send, int32_t mobile_recv, int32_t mobile_send) {
  
}

//上报网络连接状态
void ZProtoTaskManager::ReportConnectStatus(int status, int longlink_status) {
  xinfo2("ReportConnectStatus - %d] status=%d, longlink_status=%d!!", __LINE__, status, longlink_status);
  
  switch (longlink_status) {
    case mars::stn::kServerFailed:
    case mars::stn::kServerDown:
    case mars::stn::kGateWayFailed:
      break;
    case mars::stn::kConnecting:
      break;
    case mars::stn::kConnected:
      break;
    case mars::stn::kNetworkUnkown:
      return;
    default:
      return;
  }
}

//长连信令校验 ECHECK_NOW = 0, ECHECK_NEXT = 1, ECHECK_NEVER = 2
int  ZProtoTaskManager::GetLonglinkIdentifyCheckBuffer(AutoBuffer& identify_buffer, AutoBuffer& buffer_hash, int32_t& cmdid) {
  // TEST
  Handshake handshake;
  handshake.set_proto_revision(0x01);
  handshake.set_api_major_version(0x00);
  handshake.set_api_minor_version(0x00);
  handshake.set_random_bytes((const uint8_t*)"012345678901234567890123456789", 32);
  
  handshake.SerializeToBuffer(identify_buffer);
  buffer_hash.Write("012345678901234567890123456789", 32);
  
  cmdid = handshake.GetCommandID();
  return 0;
}

//长连信令校验回包
bool ZProtoTaskManager::OnLonglinkIdentifyResponse(const AutoBuffer& response_buffer, const AutoBuffer& identify_buffer_hash) {
  xinfo2("OnLonglinkIdentifyResponse - ");
  
  HandshakeResponse handshake_rsp;
  handshake_rsp.ParseFromBuffer(response_buffer);
  // CHECK()
  
  ByteBufferReader hash_reader(identify_buffer_hash);
  char hash[32];
  hash_reader.ReadRawData(hash, sizeof(hash));
  
  // 开始发登录数据包
  auto start_testing_auth_req = boost::shared_ptr<ApiRpcRequest<zproto::StartTestingAuthReq>>(new ApiRpcRequest<zproto::StartTestingAuthReq>());
  (*start_testing_auth_req)->set_app_id(1);
  (*start_testing_auth_req)->set_user_id("10000");

  DoCallRpcRequest<zproto::AuthRsp>(start_testing_auth_req,
                                    [&] (boost::shared_ptr<ApiRpcOk<zproto::AuthRsp>> rpc_ok,
                                        boost::shared_ptr<ProtoRpcResponse> rpc_error) -> int {
                                      ScopedLock g(lock_);
                                      logoned_ = true;
                                      
                                      return 0;
                                    });
  return true;
}

void ZProtoTaskManager::RequestSync() {
  xinfo2("RequestSync - DoRequestSync!!!");
}

//验证是否已登录
bool ZProtoTaskManager::IsLogoned() {
  ScopedLock g(lock_);
  return logoned_;
}

void ZProtoTaskManager::GetDifferenceSequence(int64_t seq) {
  auto get_difference_req = boost::shared_ptr<ApiRpcRequest<zproto::GetDifferenceReq>>(new ApiRpcRequest<zproto::GetDifferenceReq>());
  (*get_difference_req)->set_seq(seq);
  DoCallRpcRequest<zproto::GetDifferenceRsp>(get_difference_req,
                                             [&] (boost::shared_ptr<ApiRpcOk<zproto::GetDifferenceRsp>> rpc_ok,
                                                  boost::shared_ptr<ProtoRpcResponse> rpc_error) -> int {
                                               if (rpc_error) {
                                                 
                                               } else {
                                                 
                                               }
                                               return 0;
                                             });
}

