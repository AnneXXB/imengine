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

#ifndef	MESSENGER_HELP_SERVICE_IMPL_H_
#define	MESSENGER_HELP_SERVICE_IMPL_H_

#include "messenger/zrpc_help_service.h"

class HelpServiceImpl : public ZRpcHelpService {
public:
  HelpServiceImpl() = default;
  ~HelpServiceImpl() = default;
  
  // help.getAppChangelog#9010ef6f prev_app_version:string = Updates;
  int help_getAppChangelog(const mtproto::TL_help_getAppChangelog& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // help.getAppUpdate#ae2de196 = help.AppUpdate;
  int help_getAppUpdate(const mtproto::TL_help_getAppUpdate& request, std::shared_ptr<mtproto::help_AppUpdate>& response) override;
  
  // help.getCdnConfig#52029342 = CdnConfig;
  int help_getCdnConfig(const mtproto::TL_help_getCdnConfig& request, std::shared_ptr<mtproto::CdnConfig>& response) override;
  
  // help.getConfig#c4f9186b = Config;
  int help_getConfig(const mtproto::TL_help_getConfig& request, std::shared_ptr<mtproto::Config>& response) override;
  
  // help.getInviteText#4d392343 = help.InviteText;
  int help_getInviteText(const mtproto::TL_help_getInviteText& request, std::shared_ptr<mtproto::help_InviteText>& response) override;
  
  // help.getNearestDc#1fb33026 = NearestDc;
  int help_getNearestDc(const mtproto::TL_help_getNearestDc& request, std::shared_ptr<mtproto::NearestDc>& response) override;
  
  // help.getSupport#9cdf08cd = help.Support;
  int help_getSupport(const mtproto::TL_help_getSupport& request, std::shared_ptr<mtproto::help_Support>& response) override;
  
  // help.getTermsOfService#350170f3 = help.TermsOfService;
  int help_getTermsOfService(const mtproto::TL_help_getTermsOfService& request, std::shared_ptr<mtproto::help_TermsOfService>& response) override;
  
  // help.saveAppLog#6f02f748 events:Vector<InputAppEvent> = Bool;
  int help_saveAppLog(const mtproto::TL_help_saveAppLog& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // help.setBotUpdatesStatus#ec22cfcd pending_updates_count:int message:string = Bool;
  int help_setBotUpdatesStatus(const mtproto::TL_help_setBotUpdatesStatus& request, std::shared_ptr<mtproto::Bool>& response) override;
};

#endif
