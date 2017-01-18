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

#ifndef CORE_MARS_CORE_MANAGER_H_
#define CORE_MARS_CORE_MANAGER_H_

#include <map>

// #include "core/core_api.h"
#include "core/core_api.h"

#include "mars/app/app_logic.h"
#include "mars/sdt/sdt_logic.h"
#include "mars/stn/stn_logic.h"

#include "core/zproto_task_manager.h"


class FrameMessage;
class MarsCoreManager : public mars::app::Callback, public mars::sdt::Callback { // , public mars::stn::Callback {
public:
  virtual ~MarsCoreManager();
  
  static MarsCoreManager& GetInstance();
  
  void Initialize(const CoreAppConfig& app_config);
  
  mars::stn::Callback* GetStnCallback() {
    return &task_manager_;
  }
  ///////////////////////////////////////////////////////////////////////////////////////
  // Override mars::app::Callback
  virtual std::string GetAppFilePath();
  virtual mars::app::AccountInfo GetAccountInfo();
  virtual unsigned int GetClientVersion();
  virtual mars::app::DeviceInfo GetDeviceInfo();

  /*
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
  */
  
  ///////////////////////////////////////////////////////////////////////////////////////
  // Override from mars::sdt::Callback
  // mars::sdt::Callback没有回调函数

protected:
  MarsCoreManager();
  
  CoreAppConfig app_config_;
  
  // TODO(@benqi): 线程同步保护
  // std::map<uint32_t, FrameMessage*> tasks_;
  
  ZProtoTaskManager task_manager_;
};

#endif
