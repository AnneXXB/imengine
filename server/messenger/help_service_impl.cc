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

// TODO(@benqi): 使用zrpc-code-gen代码生成工具自动生成服务框架代码

#include "messenger/help_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int HelpServiceImpl::help_getAppChangelog(const mtproto::TL_help_getAppChangelog& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "help_getAppChangelog - " << request.ToString();
  
  return kErrNotImpl;
}

int HelpServiceImpl::help_getAppUpdate(const mtproto::TL_help_getAppUpdate& request, std::shared_ptr<mtproto::help_AppUpdate>& response) {
  LOG(INFO) << "help_getAppUpdate - " << request.ToString();
  
  return kErrNotImpl;
}

int HelpServiceImpl::help_getCdnConfig(const mtproto::TL_help_getCdnConfig& request, std::shared_ptr<mtproto::CdnConfig>& response) {
  LOG(INFO) << "help_getCdnConfig - " << request.ToString();
  
  return kErrNotImpl;
}

int HelpServiceImpl::help_getConfig(const mtproto::TL_help_getConfig& request, std::shared_ptr<mtproto::Config>& response) {
  LOG(INFO) << "help_getConfig - " << request.ToString();
  
  auto config = std::make_shared<mtproto::TL_config>();
  
  config->set_date(1497279323);
  config->set_expires(1497283400);
  config->mutable_test_mode<mtproto::TL_boolFalse>();
  config->set_this_dc(5);
  auto dc_option = config->add_dc_options<mtproto::TL_dcOption>();
  // dc_option->set_flags(0);
  dc_option->set_id(6);
  dc_option->set_ip_address("192.168.48.184");
  dc_option->set_port(12345);
  config->set_chat_size_max(200);
  config->set_megagroup_size_max(5000);
  config->set_forwarded_count_max(100);
  config->set_forwarded_count_max(100);
  config->set_online_update_period_ms(120000);
  config->set_offline_blur_timeout_ms(5000);
  config->set_offline_idle_timeout_ms(30000);
  config->set_online_cloud_timeout_ms(300000);
  config->set_notify_cloud_delay_ms(1500);
  config->set_chat_big_size(10);
  config->set_push_chat_period_ms(60000);
  config->set_push_chat_limit(2);
  config->set_saved_gifs_limit(200);
  config->set_edit_time_limit(172800);
  config->set_rating_e_decay(2419200);
  config->set_stickers_recent_limit(30);
  config->set_tmp_sessions(0);
  config->set_pinned_dialogs_count_max(5);
  config->set_call_receive_timeout_ms(20000);
  config->set_call_ring_timeout_ms(90000);
  config->set_call_connect_timeout_ms(30000);
  config->set_call_packet_timeout_ms(10000);
  config->set_me_url_prefix("https://t.me/");
  
  response = config;
  return kErrOK;
}

int HelpServiceImpl::help_getInviteText(const mtproto::TL_help_getInviteText& request, std::shared_ptr<mtproto::help_InviteText>& response) {
  LOG(INFO) << "help_getInviteText - " << request.ToString();
  
  auto invite_text = std::make_shared<mtproto::TL_help_inviteText>();
  invite_text->set_message("Invited by @benqi");
  
  response = invite_text;
  return kErrOK;
}

int HelpServiceImpl::help_getNearestDc(const mtproto::TL_help_getNearestDc& request, std::shared_ptr<mtproto::NearestDc>& response) {
  LOG(INFO) << "help_getNearestDc - " << request.ToString();
  
  return kErrNotImpl;
}

int HelpServiceImpl::help_getSupport(const mtproto::TL_help_getSupport& request, std::shared_ptr<mtproto::help_Support>& response) {
  LOG(INFO) << "help_getSupport - " << request.ToString();
  
  return kErrNotImpl;
}

int HelpServiceImpl::help_getTermsOfService(const mtproto::TL_help_getTermsOfService& request, std::shared_ptr<mtproto::help_TermsOfService>& response) {
  LOG(INFO) << "help_getTermsOfService - " << request.ToString();
  
  return kErrNotImpl;
}

int HelpServiceImpl::help_saveAppLog(const mtproto::TL_help_saveAppLog& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "help_saveAppLog - " << request.ToString();
  
  return kErrNotImpl;
}

int HelpServiceImpl::help_setBotUpdatesStatus(const mtproto::TL_help_setBotUpdatesStatus& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "help_setBotUpdatesStatus - " << request.ToString();
  
  return kErrNotImpl;
}

