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

#include "messenger/channels_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int ChannelsServiceImpl::channels_checkUsername(const mtproto::TL_channels_checkUsername& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "channels_checkUsername - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_createChannel(const mtproto::TL_channels_createChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_createChannel - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_deleteChannel(const mtproto::TL_channels_deleteChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_deleteChannel - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_deleteMessages(const mtproto::TL_channels_deleteMessages& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) {
  LOG(INFO) << "channels_deleteMessages - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_deleteUserHistory(const mtproto::TL_channels_deleteUserHistory& request, std::shared_ptr<mtproto::messages_AffectedHistory>& response) {
  LOG(INFO) << "channels_deleteUserHistory - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_editAbout(const mtproto::TL_channels_editAbout& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "channels_editAbout - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_editAdmin(const mtproto::TL_channels_editAdmin& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_editAdmin - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_editPhoto(const mtproto::TL_channels_editPhoto& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_editPhoto - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_editTitle(const mtproto::TL_channels_editTitle& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_editTitle - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_exportInvite(const mtproto::TL_channels_exportInvite& request, std::shared_ptr<mtproto::ExportedChatInvite>& response) {
  LOG(INFO) << "channels_exportInvite - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_exportMessageLink(const mtproto::TL_channels_exportMessageLink& request, std::shared_ptr<mtproto::ExportedMessageLink>& response) {
  LOG(INFO) << "channels_exportMessageLink - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_getAdminedPublicChannels(const mtproto::TL_channels_getAdminedPublicChannels& request, std::shared_ptr<mtproto::messages_Chats>& response) {
  LOG(INFO) << "channels_getAdminedPublicChannels - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_getChannels(const mtproto::TL_channels_getChannels& request, std::shared_ptr<mtproto::messages_Chats>& response) {
  LOG(INFO) << "channels_getChannels - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_getFullChannel(const mtproto::TL_channels_getFullChannel& request, std::shared_ptr<mtproto::messages_ChatFull>& response) {
  LOG(INFO) << "channels_getFullChannel - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_getMessages(const mtproto::TL_channels_getMessages& request, std::shared_ptr<mtproto::messages_Messages>& response) {
  LOG(INFO) << "channels_getMessages - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_getParticipant(const mtproto::TL_channels_getParticipant& request, std::shared_ptr<mtproto::channels_ChannelParticipant>& response) {
  LOG(INFO) << "channels_getParticipant - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_getParticipants(const mtproto::TL_channels_getParticipants& request, std::shared_ptr<mtproto::channels_ChannelParticipants>& response) {
  LOG(INFO) << "channels_getParticipants - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_inviteToChannel(const mtproto::TL_channels_inviteToChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_inviteToChannel - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_joinChannel(const mtproto::TL_channels_joinChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_joinChannel - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_kickFromChannel(const mtproto::TL_channels_kickFromChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_kickFromChannel - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_leaveChannel(const mtproto::TL_channels_leaveChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_leaveChannel - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_readHistory(const mtproto::TL_channels_readHistory& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "channels_readHistory - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_reportSpam(const mtproto::TL_channels_reportSpam& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "channels_reportSpam - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_toggleInvites(const mtproto::TL_channels_toggleInvites& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_toggleInvites - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_toggleSignatures(const mtproto::TL_channels_toggleSignatures& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_toggleSignatures - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_updatePinnedMessage(const mtproto::TL_channels_updatePinnedMessage& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "channels_updatePinnedMessage - " << request.ToString();
  
  return kErrNotImpl;
}

int ChannelsServiceImpl::channels_updateUsername(const mtproto::TL_channels_updateUsername& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "channels_updateUsername - " << request.ToString();
  
  return kErrNotImpl;
}

