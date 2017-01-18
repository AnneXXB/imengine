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

#ifndef CORE_CORE_API_H_
#define CORE_CORE_API_H_

#include <stdint.h>
#include <string>
#include <vector>
#include <map>

struct CoreXLogConfig {
  // XLog
  // int xlog_mode;
  std::string xlog_dir;
  std::string xlog_name_prefix;
  // int xlog_enable_console;
};

struct CoreAppConfig {
  CoreAppConfig()
    : clinet_version(100),
      uin(0) {
  }
  unsigned int clinet_version;
  std::string app_filepath;
  
  // AccoutInfo
  int64_t uin;
  std::string user_name;
  
  // DeviceInfo
  std::string device_name;
  std::string device_type;
};

struct CoreStnConfig {
  std::string longlink_hosts;
  std::vector<uint16_t> longlink_ports;
  std::string longlink_debugip;
  std::vector<uint16_t> lowpriority_longlink_ports;
  
  int shortlink_port;
  std::string sg_shortlink_debugip;

  std::string backup_host;
  std::vector<std::string> backup_host_ips;
  std::string backup_debugip;
};

struct CoreSdtConfig {
  
};

void CoreApi_Initialize(const CoreXLogConfig& xlog_config,
                        const CoreAppConfig& app_config,
                        const CoreStnConfig& stn_config,
                        const CoreSdtConfig& sdt_config);
void CoreApi_Run();
void CoreApi_Destrpy();

#endif
