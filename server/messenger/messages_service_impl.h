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

#ifndef	MESSENGER_MESSAGES_SERVICE_IMPL_H_
#define	MESSENGER_MESSAGES_SERVICE_IMPL_H_

#include "messenger/zrpc_messages_service.h"

class MessagesServiceImpl : public ZRpcMessagesService {
public:
  MessagesServiceImpl() = default;
  ~MessagesServiceImpl() = default;
  
  // messages.acceptEncryption#3dbc0415 peer:InputEncryptedChat g_b:bytes key_fingerprint:long = EncryptedChat;
  int messages_acceptEncryption(const mtproto::TL_messages_acceptEncryption& request, std::shared_ptr<mtproto::EncryptedChat>& response) override;
  
  // messages.addChatUser#f9a0aa09 chat_id:int user_id:InputUser fwd_limit:int = Updates;
  int messages_addChatUser(const mtproto::TL_messages_addChatUser& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.checkChatInvite#3eadb1bb hash:string = ChatInvite;
  int messages_checkChatInvite(const mtproto::TL_messages_checkChatInvite& request, std::shared_ptr<mtproto::ChatInvite>& response) override;
  
  // messages.clearRecentStickers#8999602d flags:# attached:flags.0?true = Bool;
  int messages_clearRecentStickers(const mtproto::TL_messages_clearRecentStickers& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.createChat#9cb126e users:Vector<InputUser> title:string = Updates;
  int messages_createChat(const mtproto::TL_messages_createChat& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.deleteChatUser#e0611f16 chat_id:int user_id:InputUser = Updates;
  int messages_deleteChatUser(const mtproto::TL_messages_deleteChatUser& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.deleteHistory#1c015b09 flags:# just_clear:flags.0?true peer:InputPeer max_id:int = messages.AffectedHistory;
  int messages_deleteHistory(const mtproto::TL_messages_deleteHistory& request, std::shared_ptr<mtproto::messages_AffectedHistory>& response) override;
  
  // messages.deleteMessages#e58e95d2 flags:# revoke:flags.0?true id:Vector<int> = messages.AffectedMessages;
  int messages_deleteMessages(const mtproto::TL_messages_deleteMessages& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) override;
  
  // messages.discardEncryption#edd923c5 chat_id:int = Bool;
  int messages_discardEncryption(const mtproto::TL_messages_discardEncryption& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.editChatAdmin#a9e69f2e chat_id:int user_id:InputUser is_admin:Bool = Bool;
  int messages_editChatAdmin(const mtproto::TL_messages_editChatAdmin& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.editChatPhoto#ca4c79d8 chat_id:int photo:InputChatPhoto = Updates;
  int messages_editChatPhoto(const mtproto::TL_messages_editChatPhoto& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.editChatTitle#dc452855 chat_id:int title:string = Updates;
  int messages_editChatTitle(const mtproto::TL_messages_editChatTitle& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.editInlineBotMessage#130c2c85 flags:# no_webpage:flags.1?true id:InputBotInlineMessageID message:flags.11?string reply_markup:flags.2?ReplyMarkup entities:flags.3?Vector<MessageEntity> = Bool;
  int messages_editInlineBotMessage(const mtproto::TL_messages_editInlineBotMessage& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.editMessage#ce91e4ca flags:# no_webpage:flags.1?true peer:InputPeer id:int message:flags.11?string reply_markup:flags.2?ReplyMarkup entities:flags.3?Vector<MessageEntity> = Updates;
  int messages_editMessage(const mtproto::TL_messages_editMessage& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.exportChatInvite#7d885289 chat_id:int = ExportedChatInvite;
  int messages_exportChatInvite(const mtproto::TL_messages_exportChatInvite& request, std::shared_ptr<mtproto::ExportedChatInvite>& response) override;
  
  // messages.forwardMessage#33963bf9 peer:InputPeer id:int random_id:long = Updates;
  int messages_forwardMessage(const mtproto::TL_messages_forwardMessage& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.forwardMessages#708e0195 flags:# silent:flags.5?true background:flags.6?true with_my_score:flags.8?true from_peer:InputPeer id:Vector<int> random_id:Vector<long> to_peer:InputPeer = Updates;
  int messages_forwardMessages(const mtproto::TL_messages_forwardMessages& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.getAllChats#eba80ff0 except_ids:Vector<int> = messages.Chats;
  int messages_getAllChats(const mtproto::TL_messages_getAllChats& request, std::shared_ptr<mtproto::messages_Chats>& response) override;
  
  // messages.getAllDrafts#6a3f8d65 = Updates;
  int messages_getAllDrafts(const mtproto::TL_messages_getAllDrafts& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.getAllStickers#1c9618b1 hash:int = messages.AllStickers;
  int messages_getAllStickers(const mtproto::TL_messages_getAllStickers& request, std::shared_ptr<mtproto::messages_AllStickers>& response) override;
  
  // messages.getArchivedStickers#57f17692 flags:# masks:flags.0?true offset_id:long limit:int = messages.ArchivedStickers;
  int messages_getArchivedStickers(const mtproto::TL_messages_getArchivedStickers& request, std::shared_ptr<mtproto::messages_ArchivedStickers>& response) override;
  
  // messages.getAttachedStickers#cc5b67cc media:InputStickeredMedia = Vector<StickerSetCovered>;
  int messages_getAttachedStickers(const mtproto::TL_messages_getAttachedStickers& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::StickerSetCovered>>& response) override;
  
  // messages.getBotCallbackAnswer#810a9fec flags:# game:flags.1?true peer:InputPeer msg_id:int data:flags.0?bytes = messages.BotCallbackAnswer;
  int messages_getBotCallbackAnswer(const mtproto::TL_messages_getBotCallbackAnswer& request, std::shared_ptr<mtproto::messages_BotCallbackAnswer>& response) override;
  
  // messages.getChats#3c6aa187 id:Vector<int> = messages.Chats;
  int messages_getChats(const mtproto::TL_messages_getChats& request, std::shared_ptr<mtproto::messages_Chats>& response) override;
  
  // messages.getCommonChats#d0a48c4 user_id:InputUser max_id:int limit:int = messages.Chats;
  int messages_getCommonChats(const mtproto::TL_messages_getCommonChats& request, std::shared_ptr<mtproto::messages_Chats>& response) override;
  
  // messages.getDhConfig#26cf8950 version:int random_length:int = messages.DhConfig;
  int messages_getDhConfig(const mtproto::TL_messages_getDhConfig& request, std::shared_ptr<mtproto::messages_DhConfig>& response) override;
  
  // messages.getDialogs#191ba9c5 flags:# exclude_pinned:flags.0?true offset_date:int offset_id:int offset_peer:InputPeer limit:int = messages.Dialogs;
  int messages_getDialogs(const mtproto::TL_messages_getDialogs& request, std::shared_ptr<mtproto::messages_Dialogs>& response) override;
  
  // messages.getDocumentByHash#338e2464 sha256:bytes size:int mime_type:string = Document;
  int messages_getDocumentByHash(const mtproto::TL_messages_getDocumentByHash& request, std::shared_ptr<mtproto::Document>& response) override;
  
  // messages.getFeaturedStickers#2dacca4f hash:int = messages.FeaturedStickers;
  int messages_getFeaturedStickers(const mtproto::TL_messages_getFeaturedStickers& request, std::shared_ptr<mtproto::messages_FeaturedStickers>& response) override;
  
  // messages.getFullChat#3b831c66 chat_id:int = messages.ChatFull;
  int messages_getFullChat(const mtproto::TL_messages_getFullChat& request, std::shared_ptr<mtproto::messages_ChatFull>& response) override;
  
  // messages.getGameHighScores#e822649d peer:InputPeer id:int user_id:InputUser = messages.HighScores;
  int messages_getGameHighScores(const mtproto::TL_messages_getGameHighScores& request, std::shared_ptr<mtproto::messages_HighScores>& response) override;
  
  // messages.getHistory#afa92846 peer:InputPeer offset_id:int offset_date:int add_offset:int limit:int max_id:int min_id:int = messages.Messages;
  int messages_getHistory(const mtproto::TL_messages_getHistory& request, std::shared_ptr<mtproto::messages_Messages>& response) override;
  
  // messages.getInlineBotResults#514e999d flags:# bot:InputUser peer:InputPeer geo_point:flags.0?InputGeoPoint query:string offset:string = messages.BotResults;
  int messages_getInlineBotResults(const mtproto::TL_messages_getInlineBotResults& request, std::shared_ptr<mtproto::messages_BotResults>& response) override;
  
  // messages.getInlineGameHighScores#f635e1b id:InputBotInlineMessageID user_id:InputUser = messages.HighScores;
  int messages_getInlineGameHighScores(const mtproto::TL_messages_getInlineGameHighScores& request, std::shared_ptr<mtproto::messages_HighScores>& response) override;
  
  // messages.getMaskStickers#65b8c79f hash:int = messages.AllStickers;
  int messages_getMaskStickers(const mtproto::TL_messages_getMaskStickers& request, std::shared_ptr<mtproto::messages_AllStickers>& response) override;
  
  // messages.getMessageEditData#fda68d36 peer:InputPeer id:int = messages.MessageEditData;
  int messages_getMessageEditData(const mtproto::TL_messages_getMessageEditData& request, std::shared_ptr<mtproto::messages_MessageEditData>& response) override;
  
  // messages.getMessages#4222fa74 id:Vector<int> = messages.Messages;
  int messages_getMessages(const mtproto::TL_messages_getMessages& request, std::shared_ptr<mtproto::messages_Messages>& response) override;
  
  // messages.getMessagesViews#c4c8a55d peer:InputPeer id:Vector<int> increment:Bool = Vector<int>;
  int messages_getMessagesViews(const mtproto::TL_messages_getMessagesViews& request, std::shared_ptr<mtproto::TLInt32Vector>& response) override;
  
  // messages.getPeerDialogs#2d9776b9 peers:Vector<InputPeer> = messages.PeerDialogs;
  int messages_getPeerDialogs(const mtproto::TL_messages_getPeerDialogs& request, std::shared_ptr<mtproto::messages_PeerDialogs>& response) override;
  
  // messages.getPeerSettings#3672e09c peer:InputPeer = PeerSettings;
  int messages_getPeerSettings(const mtproto::TL_messages_getPeerSettings& request, std::shared_ptr<mtproto::PeerSettings>& response) override;
  
  // messages.getPinnedDialogs#e254d64e = messages.PeerDialogs;
  int messages_getPinnedDialogs(const mtproto::TL_messages_getPinnedDialogs& request, std::shared_ptr<mtproto::messages_PeerDialogs>& response) override;
  
  // messages.getRecentStickers#5ea192c9 flags:# attached:flags.0?true hash:int = messages.RecentStickers;
  int messages_getRecentStickers(const mtproto::TL_messages_getRecentStickers& request, std::shared_ptr<mtproto::messages_RecentStickers>& response) override;
  
  // messages.getSavedGifs#83bf3d52 hash:int = messages.SavedGifs;
  int messages_getSavedGifs(const mtproto::TL_messages_getSavedGifs& request, std::shared_ptr<mtproto::messages_SavedGifs>& response) override;
  
  // messages.getStickerSet#2619a90e stickerset:InputStickerSet = messages.StickerSet;
  int messages_getStickerSet(const mtproto::TL_messages_getStickerSet& request, std::shared_ptr<mtproto::messages_StickerSet>& response) override;
  
  // messages.getWebPage#32ca8f91 url:string hash:int = WebPage;
  int messages_getWebPage(const mtproto::TL_messages_getWebPage& request, std::shared_ptr<mtproto::WebPage>& response) override;
  
  // messages.getWebPagePreview#25223e24 message:string = MessageMedia;
  int messages_getWebPagePreview(const mtproto::TL_messages_getWebPagePreview& request, std::shared_ptr<mtproto::MessageMedia>& response) override;
  
  // messages.hideReportSpam#a8f1709b peer:InputPeer = Bool;
  int messages_hideReportSpam(const mtproto::TL_messages_hideReportSpam& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.importChatInvite#6c50051c hash:string = Updates;
  int messages_importChatInvite(const mtproto::TL_messages_importChatInvite& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.installStickerSet#c78fe460 stickerset:InputStickerSet archived:Bool = messages.StickerSetInstallResult;
  int messages_installStickerSet(const mtproto::TL_messages_installStickerSet& request, std::shared_ptr<mtproto::messages_StickerSetInstallResult>& response) override;
  
  // messages.migrateChat#15a3b8e3 chat_id:int = Updates;
  int messages_migrateChat(const mtproto::TL_messages_migrateChat& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.readEncryptedHistory#7f4b690a peer:InputEncryptedChat max_date:int = Bool;
  int messages_readEncryptedHistory(const mtproto::TL_messages_readEncryptedHistory& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.readFeaturedStickers#5b118126 id:Vector<long> = Bool;
  int messages_readFeaturedStickers(const mtproto::TL_messages_readFeaturedStickers& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.readHistory#e306d3a peer:InputPeer max_id:int = messages.AffectedMessages;
  int messages_readHistory(const mtproto::TL_messages_readHistory& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) override;
  
  // messages.readMessageContents#36a73f77 id:Vector<int> = messages.AffectedMessages;
  int messages_readMessageContents(const mtproto::TL_messages_readMessageContents& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) override;
  
  // messages.receivedMessages#5a954c0 max_id:int = Vector<ReceivedNotifyMessage>;
  int messages_receivedMessages(const mtproto::TL_messages_receivedMessages& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::ReceivedNotifyMessage>>& response) override;
  
  // messages.receivedQueue#55a5bb66 max_qts:int = Vector<long>;
  int messages_receivedQueue(const mtproto::TL_messages_receivedQueue& request, std::shared_ptr<mtproto::TLInt64Vector>& response) override;
  
  // messages.reorderPinnedDialogs#959ff644 flags:# force:flags.0?true order:Vector<InputPeer> = Bool;
  int messages_reorderPinnedDialogs(const mtproto::TL_messages_reorderPinnedDialogs& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.reorderStickerSets#78337739 flags:# masks:flags.0?true order:Vector<long> = Bool;
  int messages_reorderStickerSets(const mtproto::TL_messages_reorderStickerSets& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.reportEncryptedSpam#4b0c8c0f peer:InputEncryptedChat = Bool;
  int messages_reportEncryptedSpam(const mtproto::TL_messages_reportEncryptedSpam& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.reportSpam#cf1592db peer:InputPeer = Bool;
  int messages_reportSpam(const mtproto::TL_messages_reportSpam& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.requestEncryption#f64daf43 user_id:InputUser random_id:int g_a:bytes = EncryptedChat;
  int messages_requestEncryption(const mtproto::TL_messages_requestEncryption& request, std::shared_ptr<mtproto::EncryptedChat>& response) override;
  
  // messages.saveDraft#bc39e14b flags:# no_webpage:flags.1?true reply_to_msg_id:flags.0?int peer:InputPeer message:string entities:flags.3?Vector<MessageEntity> = Bool;
  int messages_saveDraft(const mtproto::TL_messages_saveDraft& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.saveGif#327a30cb id:InputDocument unsave:Bool = Bool;
  int messages_saveGif(const mtproto::TL_messages_saveGif& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.saveRecentSticker#392718f8 flags:# attached:flags.0?true id:InputDocument unsave:Bool = Bool;
  int messages_saveRecentSticker(const mtproto::TL_messages_saveRecentSticker& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.search#d4569248 flags:# peer:InputPeer q:string filter:MessagesFilter min_date:int max_date:int offset:int max_id:int limit:int = messages.Messages;
  int messages_search(const mtproto::TL_messages_search& request, std::shared_ptr<mtproto::messages_Messages>& response) override;
  
  // messages.searchGifs#bf9a776b q:string offset:int = messages.FoundGifs;
  int messages_searchGifs(const mtproto::TL_messages_searchGifs& request, std::shared_ptr<mtproto::messages_FoundGifs>& response) override;
  
  // messages.searchGlobal#9e3cacb0 q:string offset_date:int offset_peer:InputPeer offset_id:int limit:int = messages.Messages;
  int messages_searchGlobal(const mtproto::TL_messages_searchGlobal& request, std::shared_ptr<mtproto::messages_Messages>& response) override;
  
  // messages.sendEncrypted#a9776773 peer:InputEncryptedChat random_id:long data:bytes = messages.SentEncryptedMessage;
  int messages_sendEncrypted(const mtproto::TL_messages_sendEncrypted& request, std::shared_ptr<mtproto::messages_SentEncryptedMessage>& response) override;
  
  // messages.sendEncryptedFile#9a901b66 peer:InputEncryptedChat random_id:long data:bytes file:InputEncryptedFile = messages.SentEncryptedMessage;
  int messages_sendEncryptedFile(const mtproto::TL_messages_sendEncryptedFile& request, std::shared_ptr<mtproto::messages_SentEncryptedMessage>& response) override;
  
  // messages.sendEncryptedService#32d439a4 peer:InputEncryptedChat random_id:long data:bytes = messages.SentEncryptedMessage;
  int messages_sendEncryptedService(const mtproto::TL_messages_sendEncryptedService& request, std::shared_ptr<mtproto::messages_SentEncryptedMessage>& response) override;
  
  // messages.sendInlineBotResult#b16e06fe flags:# silent:flags.5?true background:flags.6?true clear_draft:flags.7?true peer:InputPeer reply_to_msg_id:flags.0?int random_id:long query_id:long id:string = Updates;
  int messages_sendInlineBotResult(const mtproto::TL_messages_sendInlineBotResult& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.sendMedia#c8f16791 flags:# silent:flags.5?true background:flags.6?true clear_draft:flags.7?true peer:InputPeer reply_to_msg_id:flags.0?int media:InputMedia random_id:long reply_markup:flags.2?ReplyMarkup = Updates;
  int messages_sendMedia(const mtproto::TL_messages_sendMedia& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.sendMessage#fa88427a flags:# no_webpage:flags.1?true silent:flags.5?true background:flags.6?true clear_draft:flags.7?true peer:InputPeer reply_to_msg_id:flags.0?int message:string random_id:long reply_markup:flags.2?ReplyMarkup entities:flags.3?Vector<MessageEntity> = Updates;
  int messages_sendMessage(const mtproto::TL_messages_sendMessage& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.setBotCallbackAnswer#d58f130a flags:# alert:flags.1?true query_id:long message:flags.0?string url:flags.2?string cache_time:int = Bool;
  int messages_setBotCallbackAnswer(const mtproto::TL_messages_setBotCallbackAnswer& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.setBotPrecheckoutResults#9c2dd95 flags:# success:flags.1?true query_id:long error:flags.0?string = Bool;
  int messages_setBotPrecheckoutResults(const mtproto::TL_messages_setBotPrecheckoutResults& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.setBotShippingResults#e5f672fa flags:# query_id:long error:flags.0?string shipping_options:flags.1?Vector<ShippingOption> = Bool;
  int messages_setBotShippingResults(const mtproto::TL_messages_setBotShippingResults& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.setEncryptedTyping#791451ed peer:InputEncryptedChat typing:Bool = Bool;
  int messages_setEncryptedTyping(const mtproto::TL_messages_setEncryptedTyping& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.setGameScore#8ef8ecc0 flags:# edit_message:flags.0?true force:flags.1?true peer:InputPeer id:int user_id:InputUser score:int = Updates;
  int messages_setGameScore(const mtproto::TL_messages_setGameScore& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.setInlineBotResults#eb5ea206 flags:# gallery:flags.0?true private:flags.1?true query_id:long results:Vector<InputBotInlineResult> cache_time:int next_offset:flags.2?string switch_pm:flags.3?InlineBotSwitchPM = Bool;
  int messages_setInlineBotResults(const mtproto::TL_messages_setInlineBotResults& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.setInlineGameScore#15ad9f64 flags:# edit_message:flags.0?true force:flags.1?true id:InputBotInlineMessageID user_id:InputUser score:int = Bool;
  int messages_setInlineGameScore(const mtproto::TL_messages_setInlineGameScore& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.setTyping#a3825e50 peer:InputPeer action:SendMessageAction = Bool;
  int messages_setTyping(const mtproto::TL_messages_setTyping& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.startBot#e6df7378 bot:InputUser peer:InputPeer random_id:long start_param:string = Updates;
  int messages_startBot(const mtproto::TL_messages_startBot& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.toggleChatAdmins#ec8bd9e1 chat_id:int enabled:Bool = Updates;
  int messages_toggleChatAdmins(const mtproto::TL_messages_toggleChatAdmins& request, std::shared_ptr<mtproto::Updates>& response) override;
  
  // messages.toggleDialogPin#3289be6a flags:# pinned:flags.0?true peer:InputPeer = Bool;
  int messages_toggleDialogPin(const mtproto::TL_messages_toggleDialogPin& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // messages.uninstallStickerSet#f96e55de stickerset:InputStickerSet = Bool;
  int messages_uninstallStickerSet(const mtproto::TL_messages_uninstallStickerSet& request, std::shared_ptr<mtproto::Bool>& response) override;
};

#endif
