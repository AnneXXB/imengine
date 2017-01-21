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

#ifndef CORE_ZPROTO_TASK_MANAGER_H_
#define CORE_ZPROTO_TASK_MANAGER_H_

#include <map>
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>

#include "mars/comm/thread/lock.h"
#include "mars/stn/stn_logic.h"

#include "core/zproto_package_data.h"

// #include "core/zproto_package_data.h"
#include "proto/api/cc/auth.pb.h"
#include "proto/api/cc/dialogs.pb.h"
#include "proto/api/cc/misc.pb.h"
#include "proto/api/cc/messaging.pb.h"
#include "proto/api/cc/groups.pb.h"
#include "proto/api/cc/sequence.pb.h"

#include "core/api_message_box.h"

typedef boost::shared_ptr<FrameMessage> FrameMessagePtr;
typedef boost::shared_ptr<PackageMessage> PackageMessagePtr;

typedef boost::function<void(const AutoBuffer& buffer)> ResponseCallback;
                    
// req->rsp
struct MarsTaskWrapper {
  MarsTaskWrapper() = default;

  // uint32_t request_command_id{0};    //
  FrameMessagePtr req;
  // FrameMessagePtr response;   //
  ResponseCallback cb;
};

// request_command_id --> response
FrameMessagePtr MakeResponse(uint32_t request_command_id, const AutoBuffer& buffer);

typedef std::map<uint32_t, MarsTaskWrapper> TaskIDMessageMap;

FrameMessagePtr MakeResponse(uint32_t request_command_id, const AutoBuffer& buffer);

class ZProtoTaskManager : public mars::stn::Callback {
public:
  ZProtoTaskManager() {}
  ~ZProtoTaskManager() {}

  // Handshake
  void DoCallHandshake(boost::function<int(boost::shared_ptr<HandshakeResponse>)> cb);
  
  // Auth
  void DoCallRequestAuthId(boost::function<int(boost::shared_ptr<ResponseAuthId>)> cb);
  
  void DoCallRequestStartAuth(boost::shared_ptr<RequestStartAuth> request,
                              boost::function<int(boost::shared_ptr<ResponseStartAuth>)> cb);
  void DoCallRequestGetServerKey(boost::shared_ptr<RequestGetServerKey> request,
                                 boost::function<int(boost::shared_ptr<ResponseGetServerKey>)> cb);
  void DoCallRequestDH(boost::shared_ptr<RequestDH> request,
                       boost::function<int(boost::shared_ptr<ResponseDoDH>)> cb);

  // Rpc
  template<typename MESSAGE>
  void DoCallRpcRequest(boost::shared_ptr<RpcRequest> request,
                        boost::function<int(boost::shared_ptr<ApiRpcOk<MESSAGE>>, boost::shared_ptr<ProtoRpcResponse>)> cb) {
    static boost::shared_ptr<ProtoRpcResponse> kEmptyRpcError;
    static boost::shared_ptr<ApiRpcOk<MESSAGE>> kEmptyRpcOk;

    MarsTaskWrapper task_wrapper;
    uint32_t cmd_id = request->GetCommandID();
    
    // task_wrapper.request_command_id = cmd_id;
    task_wrapper.req = request;
    task_wrapper.cb = [cmd_id, cb] (const AutoBuffer& buffer) {
      auto rpc_rsp = MakeResponse(cmd_id, buffer);
      if (rpc_rsp->GetCommandID() == PACKAGE_RPC_OK) {
        // auto encoded_rpc
      } else if (rpc_rsp->GetCommandID() == PACKAGE_RPC_ERROR ||
                 rpc_rsp->GetCommandID() == PACKAGE_RPC_FLOOD_WAIT ||
                 rpc_rsp->GetCommandID() == PACKAGE_RPC_INTERNAL_ERROR) {
        cb(kEmptyRpcOk, boost::static_pointer_cast<ProtoRpcResponse>(rpc_rsp));
      } else {
        auto encoded_rpc_ok = boost::static_pointer_cast<EncodedRpcOk>(rpc_rsp);
        auto rcp_ok = ToApiRpcOk<MESSAGE>(encoded_rpc_ok);
        cb(rcp_ok, kEmptyRpcError);
      }
    };
    
    mars::stn::Task task;
    task.cmdid = cmd_id;
    task.channel_select = mars::stn::Task::kChannelLong;
    ScopedLock g(lock_);
    tasks_.insert(std::make_pair(task.taskid, task_wrapper));
    mars::stn::StartTask(task);
  }
  
  // void OnTaskExecuted(uint32_t task_id, const AutoBuffer& buf);
  
  ///////////////////////////////////////////////////////////////////////////////////////
  // Override from mars::stn::Callback
  virtual bool MakesureAuthed();
  
  //流量统计
  virtual void TrafficData(ssize_t _send, ssize_t _recv);
  
  //底层询问上层该host对应的ip列表
  virtual std::vector<std::string> OnNewDns(const std::string& host);
  //网络层收到push消息回调
  virtual void OnPush(int32_t cmdid, const AutoBuffer& msgpayload);
  //底层获取task要发送的数据
  virtual bool Req2Buf(int32_t taskid, void* const user_context, AutoBuffer& outbuffer, int& error_code, const int channel_select);
  //底层回包返回给上层解析
  virtual int Buf2Resp(int32_t taskid, void* const user_context, const AutoBuffer& inbuffer, int& error_code, const int channel_select);
  //任务执行结束
  virtual int  OnTaskEnd(int32_t taskid, void* const user_context, int error_type, int error_code);
  //上报流量数据
  virtual void ReportFlow(int32_t wifi_recv, int32_t wifi_send, int32_t mobile_recv, int32_t mobile_send);
  
  //上报网络连接状态
  virtual void ReportConnectStatus(int status, int longlink_status);
  //长连信令校验 ECHECK_NOW = 0, ECHECK_NEXT = 1, ECHECK_NEVER = 2
  virtual int  GetLonglinkIdentifyCheckBuffer(AutoBuffer& identify_buffer, AutoBuffer& buffer_hash, int32_t& cmdid);
  //长连信令校验回包
  virtual bool OnLonglinkIdentifyResponse(const AutoBuffer& response_buffer, const AutoBuffer& identify_buffer_hash);
  
  
  virtual void RequestSync();
  
  //验证是否已登录
  virtual bool IsLogoned();

private:
  void GetDifferenceSequence(int64_t seq);
  
  
  Mutex lock_;
  TaskIDMessageMap tasks_;
  bool logoned_{false};
};
// mars::stn::Task* MakeTask(PackageMessage* package_message);

#endif

