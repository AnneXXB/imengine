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

#include "core/mars_core_manager.h"

#import "mars/comm/autobuffer.h"
#import "mars/comm/xlogger/xlogger.h"
#import "mars/stn/stn.h"

// #include "core/zproto_package_data.h"
#include "proto/api/cc/auth.pb.h"
#include "proto/api/cc/dialogs.pb.h"
#include "proto/api/cc/misc.pb.h"
#include "proto/api/cc/messaging.pb.h"
#include "proto/api/cc/groups.pb.h"

#include "core/api_message_box.h"

MarsCoreManager::MarsCoreManager() {
}

MarsCoreManager::~MarsCoreManager() {
}

MarsCoreManager& MarsCoreManager::GetInstance() {
  static MarsCoreManager g_mars_core_manager;
  return g_mars_core_manager;
}

void MarsCoreManager::Initialize(const CoreAppConfig& app_config) {
  app_config_ = app_config;
}

///////////////////////////////////////////////////////////////////////////////////////
// Override mars::app::Callback
std::string MarsCoreManager::GetAppFilePath() {
  return app_config_.app_filepath;
}

mars::app::AccountInfo MarsCoreManager::GetAccountInfo() {
  mars::app::AccountInfo account;
  account.uin = app_config_.uin;
  account.username = app_config_.user_name;
  return account;
}

unsigned int MarsCoreManager::GetClientVersion() {
  return app_config_.clinet_version;
}

mars::app::DeviceInfo MarsCoreManager::GetDeviceInfo() {
  mars::app::DeviceInfo device_info;
  device_info.devicetype = app_config_.device_type;
  device_info.devicename = app_config_.device_name;
  return device_info;
}
