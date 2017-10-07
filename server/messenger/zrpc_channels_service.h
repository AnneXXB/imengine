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

#ifndef	MESSENGER_ZRPC_CHANNELS_SERVICE_H_
#define	MESSENGER_ZRPC_CHANNELS_SERVICE_H_

#include "base/base_zrpc_service.h"
#include "proto/mtproto/core/mtproto_schema.h"

class ZRpcChannelsService : public BaseZRpcService {
public:
  virtual ~ZRpcChannelsService() = default;

  // channels.checkUsername#10e6bd2c channel:InputChannel username:string = Bool;
  virtual int channels_checkUsername(const mtproto::TL_channels_checkUsername& request, std::shared_ptr<mtproto::Bool>& response);
  
  // channels.createChannel#f4893d7f flags:# broadcast:flags.0?true megagroup:flags.1?true title:string about:string = Updates;
  virtual int channels_createChannel(const mtproto::TL_channels_createChannel& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.deleteChannel#c0111fe3 channel:InputChannel = Updates;
  virtual int channels_deleteChannel(const mtproto::TL_channels_deleteChannel& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.deleteMessages#84c1fd4e channel:InputChannel id:Vector<int> = messages.AffectedMessages;
  virtual int channels_deleteMessages(const mtproto::TL_channels_deleteMessages& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response);
  
  // channels.deleteUserHistory#d10dd71b channel:InputChannel user_id:InputUser = messages.AffectedHistory;
  virtual int channels_deleteUserHistory(const mtproto::TL_channels_deleteUserHistory& request, std::shared_ptr<mtproto::messages_AffectedHistory>& response);
  
  // channels.editAbout#13e27f1e channel:InputChannel about:string = Bool;
  virtual int channels_editAbout(const mtproto::TL_channels_editAbout& request, std::shared_ptr<mtproto::Bool>& response);
  
  // channels.editAdmin#eb7611d0 channel:InputChannel user_id:InputUser role:ChannelParticipantRole = Updates;
  virtual int channels_editAdmin(const mtproto::TL_channels_editAdmin& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.editPhoto#f12e57c9 channel:InputChannel photo:InputChatPhoto = Updates;
  virtual int channels_editPhoto(const mtproto::TL_channels_editPhoto& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.editTitle#566decd0 channel:InputChannel title:string = Updates;
  virtual int channels_editTitle(const mtproto::TL_channels_editTitle& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.exportInvite#c7560885 channel:InputChannel = ExportedChatInvite;
  virtual int channels_exportInvite(const mtproto::TL_channels_exportInvite& request, std::shared_ptr<mtproto::ExportedChatInvite>& response);
  
  // channels.exportMessageLink#c846d22d channel:InputChannel id:int = ExportedMessageLink;
  virtual int channels_exportMessageLink(const mtproto::TL_channels_exportMessageLink& request, std::shared_ptr<mtproto::ExportedMessageLink>& response);
  
  // channels.getAdminedPublicChannels#8d8d82d7 = messages.Chats;
  virtual int channels_getAdminedPublicChannels(const mtproto::TL_channels_getAdminedPublicChannels& request, std::shared_ptr<mtproto::messages_Chats>& response);
  
  // channels.getChannels#a7f6bbb id:Vector<InputChannel> = messages.Chats;
  virtual int channels_getChannels(const mtproto::TL_channels_getChannels& request, std::shared_ptr<mtproto::messages_Chats>& response);
  
  // channels.getFullChannel#8736a09 channel:InputChannel = messages.ChatFull;
  virtual int channels_getFullChannel(const mtproto::TL_channels_getFullChannel& request, std::shared_ptr<mtproto::messages_ChatFull>& response);
  
  // channels.getMessages#93d7b347 channel:InputChannel id:Vector<int> = messages.Messages;
  virtual int channels_getMessages(const mtproto::TL_channels_getMessages& request, std::shared_ptr<mtproto::messages_Messages>& response);
  
  // channels.getParticipant#546dd7a6 channel:InputChannel user_id:InputUser = channels.ChannelParticipant;
  virtual int channels_getParticipant(const mtproto::TL_channels_getParticipant& request, std::shared_ptr<mtproto::channels_ChannelParticipant>& response);
  
  // channels.getParticipants#24d98f92 channel:InputChannel filter:ChannelParticipantsFilter offset:int limit:int = channels.ChannelParticipants;
  virtual int channels_getParticipants(const mtproto::TL_channels_getParticipants& request, std::shared_ptr<mtproto::channels_ChannelParticipants>& response);
  
  // channels.inviteToChannel#199f3a6c channel:InputChannel users:Vector<InputUser> = Updates;
  virtual int channels_inviteToChannel(const mtproto::TL_channels_inviteToChannel& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.joinChannel#24b524c5 channel:InputChannel = Updates;
  virtual int channels_joinChannel(const mtproto::TL_channels_joinChannel& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.kickFromChannel#a672de14 channel:InputChannel user_id:InputUser kicked:Bool = Updates;
  virtual int channels_kickFromChannel(const mtproto::TL_channels_kickFromChannel& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.leaveChannel#f836aa95 channel:InputChannel = Updates;
  virtual int channels_leaveChannel(const mtproto::TL_channels_leaveChannel& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.readHistory#cc104937 channel:InputChannel max_id:int = Bool;
  virtual int channels_readHistory(const mtproto::TL_channels_readHistory& request, std::shared_ptr<mtproto::Bool>& response);
  
  // channels.reportSpam#fe087810 channel:InputChannel user_id:InputUser id:Vector<int> = Bool;
  virtual int channels_reportSpam(const mtproto::TL_channels_reportSpam& request, std::shared_ptr<mtproto::Bool>& response);
  
  // channels.toggleInvites#49609307 channel:InputChannel enabled:Bool = Updates;
  virtual int channels_toggleInvites(const mtproto::TL_channels_toggleInvites& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.toggleSignatures#1f69b606 channel:InputChannel enabled:Bool = Updates;
  virtual int channels_toggleSignatures(const mtproto::TL_channels_toggleSignatures& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.updatePinnedMessage#a72ded52 flags:# silent:flags.0?true channel:InputChannel id:int = Updates;
  virtual int channels_updatePinnedMessage(const mtproto::TL_channels_updatePinnedMessage& request, std::shared_ptr<mtproto::Updates>& response);
  
  // channels.updateUsername#3514b3de channel:InputChannel username:string = Bool;
  virtual int channels_updateUsername(const mtproto::TL_channels_updateUsername& request, std::shared_ptr<mtproto::Bool>& response);
};

#endif

