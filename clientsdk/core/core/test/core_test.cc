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

unsigned int clinet_version;
std::string app_filepath;

// AccoutInfo
int64_t uin;
std::string user_name;

// DeviceInfo
std::string device_name;
std::string device_type;

int main(int argc, char* argv[]) {
  // 配置初始化
  CoreXLogConfig xlog_config;
  xlog_config.xlog_dir = "/tmp/test";
  xlog_config.xlog_name_prefix = "client";

  CoreAppConfig app_config;
  app_config.app_filepath = "./";
  app_config.uin = 1;
  app_config.user_name = "benqi";
  app_config.device_name = "cmdline-xxxxxxxxx";
  app_config.device_type = "cmdline";

  CoreStnConfig stn_config;
  stn_config.shortlink_port = 12346;
  stn_config.longlink_hosts = "localhost";
  stn_config.longlink_ports.push_back(12345);
  stn_config.backup_host_ips.push_back("0.0.0.0");
  stn_config.backup_host = "localhost";
  stn_config.backup_host_ips.push_back("0.0.0.0");

  CoreSdtConfig sdt_config;

  CoreApi_Initialize(xlog_config, app_config, stn_config, sdt_config);
  CoreApi_Run();
  CoreApi_Destrpy();
}

