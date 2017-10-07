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

// TODO(@benqi): 使用zrpc-code-gen代码生成工具自动生成

#include "messenger/zrpc_help_service.h"

#include "nebula/base/logger/glog_util.h"
#include "proto/api/error_codes.h"

int ZRpcHelpService::help_getAppChangelog(const mtproto::TL_help_getAppChangelog& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "help_getAppChangelog not impl";
  return kErrNotImpl;
}

int ZRpcHelpService::help_getAppUpdate(const mtproto::TL_help_getAppUpdate& request, std::shared_ptr<mtproto::help_AppUpdate>& response) {
  LOG(ERROR) << "help_getAppUpdate not impl";
  return kErrNotImpl;
}

int ZRpcHelpService::help_getCdnConfig(const mtproto::TL_help_getCdnConfig& request, std::shared_ptr<mtproto::CdnConfig>& response) {
  LOG(ERROR) << "help_getCdnConfig not impl";
  return kErrNotImpl;
}

int ZRpcHelpService::help_getConfig(const mtproto::TL_help_getConfig& request, std::shared_ptr<mtproto::Config>& response) {
  LOG(ERROR) << "help_getConfig not impl";
  return kErrNotImpl;
}

int ZRpcHelpService::help_getInviteText(const mtproto::TL_help_getInviteText& request, std::shared_ptr<mtproto::help_InviteText>& response) {
  LOG(ERROR) << "help_getInviteText not impl";
  return kErrNotImpl;
}

int ZRpcHelpService::help_getNearestDc(const mtproto::TL_help_getNearestDc& request, std::shared_ptr<mtproto::NearestDc>& response) {
  LOG(ERROR) << "help_getNearestDc not impl";
  return kErrNotImpl;
}

int ZRpcHelpService::help_getSupport(const mtproto::TL_help_getSupport& request, std::shared_ptr<mtproto::help_Support>& response) {
  LOG(ERROR) << "help_getSupport not impl";
  return kErrNotImpl;
}

int ZRpcHelpService::help_getTermsOfService(const mtproto::TL_help_getTermsOfService& request, std::shared_ptr<mtproto::help_TermsOfService>& response) {
  LOG(ERROR) << "help_getTermsOfService not impl";
  return kErrNotImpl;
}

int ZRpcHelpService::help_saveAppLog(const mtproto::TL_help_saveAppLog& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "help_saveAppLog not impl";
  return kErrNotImpl;
}

int ZRpcHelpService::help_setBotUpdatesStatus(const mtproto::TL_help_setBotUpdatesStatus& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "help_setBotUpdatesStatus not impl";
  return kErrNotImpl;
}

