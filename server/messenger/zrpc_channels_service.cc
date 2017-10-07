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

#include "messenger/zrpc_channels_service.h"

#include "nebula/base/logger/glog_util.h"
#include "proto/api/error_codes.h"

int ZRpcChannelsService::channels_checkUsername(const mtproto::TL_channels_checkUsername& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "channels_checkUsername not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_createChannel(const mtproto::TL_channels_createChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_createChannel not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_deleteChannel(const mtproto::TL_channels_deleteChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_deleteChannel not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_deleteMessages(const mtproto::TL_channels_deleteMessages& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) {
  LOG(ERROR) << "channels_deleteMessages not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_deleteUserHistory(const mtproto::TL_channels_deleteUserHistory& request, std::shared_ptr<mtproto::messages_AffectedHistory>& response) {
  LOG(ERROR) << "channels_deleteUserHistory not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_editAbout(const mtproto::TL_channels_editAbout& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "channels_editAbout not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_editAdmin(const mtproto::TL_channels_editAdmin& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_editAdmin not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_editPhoto(const mtproto::TL_channels_editPhoto& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_editPhoto not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_editTitle(const mtproto::TL_channels_editTitle& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_editTitle not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_exportInvite(const mtproto::TL_channels_exportInvite& request, std::shared_ptr<mtproto::ExportedChatInvite>& response) {
  LOG(ERROR) << "channels_exportInvite not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_exportMessageLink(const mtproto::TL_channels_exportMessageLink& request, std::shared_ptr<mtproto::ExportedMessageLink>& response) {
  LOG(ERROR) << "channels_exportMessageLink not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_getAdminedPublicChannels(const mtproto::TL_channels_getAdminedPublicChannels& request, std::shared_ptr<mtproto::messages_Chats>& response) {
  LOG(ERROR) << "channels_getAdminedPublicChannels not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_getChannels(const mtproto::TL_channels_getChannels& request, std::shared_ptr<mtproto::messages_Chats>& response) {
  LOG(ERROR) << "channels_getChannels not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_getFullChannel(const mtproto::TL_channels_getFullChannel& request, std::shared_ptr<mtproto::messages_ChatFull>& response) {
  LOG(ERROR) << "channels_getFullChannel not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_getMessages(const mtproto::TL_channels_getMessages& request, std::shared_ptr<mtproto::messages_Messages>& response) {
  LOG(ERROR) << "channels_getMessages not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_getParticipant(const mtproto::TL_channels_getParticipant& request, std::shared_ptr<mtproto::channels_ChannelParticipant>& response) {
  LOG(ERROR) << "channels_getParticipant not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_getParticipants(const mtproto::TL_channels_getParticipants& request, std::shared_ptr<mtproto::channels_ChannelParticipants>& response) {
  LOG(ERROR) << "channels_getParticipants not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_inviteToChannel(const mtproto::TL_channels_inviteToChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_inviteToChannel not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_joinChannel(const mtproto::TL_channels_joinChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_joinChannel not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_kickFromChannel(const mtproto::TL_channels_kickFromChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_kickFromChannel not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_leaveChannel(const mtproto::TL_channels_leaveChannel& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_leaveChannel not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_readHistory(const mtproto::TL_channels_readHistory& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "channels_readHistory not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_reportSpam(const mtproto::TL_channels_reportSpam& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "channels_reportSpam not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_toggleInvites(const mtproto::TL_channels_toggleInvites& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_toggleInvites not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_toggleSignatures(const mtproto::TL_channels_toggleSignatures& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_toggleSignatures not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_updatePinnedMessage(const mtproto::TL_channels_updatePinnedMessage& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "channels_updatePinnedMessage not impl";
  return kErrNotImpl;
}

int ZRpcChannelsService::channels_updateUsername(const mtproto::TL_channels_updateUsername& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "channels_updateUsername not impl";
  return kErrNotImpl;
}
