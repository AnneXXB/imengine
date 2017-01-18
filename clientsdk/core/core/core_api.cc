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

#include "core/core_api.h"

#include "mars/log/appender.h"
#include "mars/comm/xlogger/xlogger.h"
#include "mars/baseevent/base_logic.h"
#include "mars/stn/stn.h"

#include "core/mars_core_manager.h"

void XLogInitialize(const CoreXLogConfig& xlog_config) {
  xlogger_SetLevel(kLevelAll);
  appender_open(kAppednerAsync, xlog_config.xlog_dir.c_str(), xlog_config.xlog_name_prefix.c_str());
  appender_set_console_log(true);
}

void AppInitialize(const CoreAppConfig& app_config) {
  MarsCoreManager& core = MarsCoreManager::GetInstance();
  core.Initialize(app_config);
}

void StnInitialize(const CoreStnConfig& stn_config) {
  // TODO(@benqi): 检查debug_ip是否有效
  mars::stn::SetLonglinkSvrAddr(stn_config.longlink_hosts, stn_config.longlink_ports);
  
  //debug longlink ip
  //mars::stn::SetLonglinkSvrAddr("localhost", ports, "127.0.0.1");
  mars::stn::SetShortlinkSvrAddr(stn_config.shortlink_port);
  //debug shortlink ip
  //mars::stn::SetShortlinkSvrAddr(80, "127.0.0.1");
  // std::vector<std::string> backup_ips;
  mars::stn::SetBackupIPs(stn_config.backup_host, stn_config.backup_host_ips);
}

void SdtInitialize(const CoreSdtConfig& sdt_config) {
  
}

void CoreApi_Initialize(const CoreXLogConfig& xlog_config,
                        const CoreAppConfig& app_config,
                        const CoreStnConfig& stn_config,
                        const CoreSdtConfig& sdt_config) {
  XLogInitialize(xlog_config);
  AppInitialize(app_config);
  StnInitialize(stn_config);
  SdtInitialize(sdt_config);
  
  MarsCoreManager& core = MarsCoreManager::GetInstance();

  mars::app::SetCallback(&core);
  mars::stn::SetCallback(core.GetStnCallback());
  mars::sdt::SetCallBack(&core);
  
  mars::baseevent::OnCreate();
  mars::baseevent::OnForeground(true);
}

void CoreApi_Run() {
  // TODO(@benqi): 循环
  getchar();
}

void CoreApi_Destrpy() {
  appender_close();
}
