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

#include "messenger/messages_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int MessagesServiceImpl::messages_acceptEncryption(const mtproto::TL_messages_acceptEncryption& request, std::shared_ptr<mtproto::EncryptedChat>& response) {
  LOG(INFO) << "messages_acceptEncryption - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_addChatUser(const mtproto::TL_messages_addChatUser& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_addChatUser - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_checkChatInvite(const mtproto::TL_messages_checkChatInvite& request, std::shared_ptr<mtproto::ChatInvite>& response) {
  LOG(INFO) << "messages_checkChatInvite - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_clearRecentStickers(const mtproto::TL_messages_clearRecentStickers& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_clearRecentStickers - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_createChat(const mtproto::TL_messages_createChat& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_createChat - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_deleteChatUser(const mtproto::TL_messages_deleteChatUser& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_deleteChatUser - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_deleteHistory(const mtproto::TL_messages_deleteHistory& request, std::shared_ptr<mtproto::messages_AffectedHistory>& response) {
  LOG(INFO) << "messages_deleteHistory - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_deleteMessages(const mtproto::TL_messages_deleteMessages& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) {
  LOG(INFO) << "messages_deleteMessages - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_discardEncryption(const mtproto::TL_messages_discardEncryption& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_discardEncryption - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_editChatAdmin(const mtproto::TL_messages_editChatAdmin& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_editChatAdmin - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_editChatPhoto(const mtproto::TL_messages_editChatPhoto& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_editChatPhoto - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_editChatTitle(const mtproto::TL_messages_editChatTitle& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_editChatTitle - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_editInlineBotMessage(const mtproto::TL_messages_editInlineBotMessage& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_editInlineBotMessage - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_editMessage(const mtproto::TL_messages_editMessage& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_editMessage - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_exportChatInvite(const mtproto::TL_messages_exportChatInvite& request, std::shared_ptr<mtproto::ExportedChatInvite>& response) {
  LOG(INFO) << "messages_exportChatInvite - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_forwardMessage(const mtproto::TL_messages_forwardMessage& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_forwardMessage - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_forwardMessages(const mtproto::TL_messages_forwardMessages& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_forwardMessages - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getAllChats(const mtproto::TL_messages_getAllChats& request, std::shared_ptr<mtproto::messages_Chats>& response) {
  LOG(INFO) << "messages_getAllChats - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getAllDrafts(const mtproto::TL_messages_getAllDrafts& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_getAllDrafts - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getAllStickers(const mtproto::TL_messages_getAllStickers& request, std::shared_ptr<mtproto::messages_AllStickers>& response) {
  LOG(INFO) << "messages_getAllStickers - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getArchivedStickers(const mtproto::TL_messages_getArchivedStickers& request, std::shared_ptr<mtproto::messages_ArchivedStickers>& response) {
  LOG(INFO) << "messages_getArchivedStickers - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getAttachedStickers(const mtproto::TL_messages_getAttachedStickers& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::StickerSetCovered>>& response) {
  LOG(INFO) << "messages_getAttachedStickers - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getBotCallbackAnswer(const mtproto::TL_messages_getBotCallbackAnswer& request, std::shared_ptr<mtproto::messages_BotCallbackAnswer>& response) {
  LOG(INFO) << "messages_getBotCallbackAnswer - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getChats(const mtproto::TL_messages_getChats& request, std::shared_ptr<mtproto::messages_Chats>& response) {
  LOG(INFO) << "messages_getChats - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getCommonChats(const mtproto::TL_messages_getCommonChats& request, std::shared_ptr<mtproto::messages_Chats>& response) {
  LOG(INFO) << "messages_getCommonChats - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getDhConfig(const mtproto::TL_messages_getDhConfig& request, std::shared_ptr<mtproto::messages_DhConfig>& response) {
  LOG(INFO) << "messages_getDhConfig - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getDialogs(const mtproto::TL_messages_getDialogs& request, std::shared_ptr<mtproto::messages_Dialogs>& response) {
  LOG(INFO) << "messages_getDialogs - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getDocumentByHash(const mtproto::TL_messages_getDocumentByHash& request, std::shared_ptr<mtproto::Document>& response) {
  LOG(INFO) << "messages_getDocumentByHash - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getFeaturedStickers(const mtproto::TL_messages_getFeaturedStickers& request, std::shared_ptr<mtproto::messages_FeaturedStickers>& response) {
  LOG(INFO) << "messages_getFeaturedStickers - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getFullChat(const mtproto::TL_messages_getFullChat& request, std::shared_ptr<mtproto::messages_ChatFull>& response) {
  LOG(INFO) << "messages_getFullChat - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getGameHighScores(const mtproto::TL_messages_getGameHighScores& request, std::shared_ptr<mtproto::messages_HighScores>& response) {
  LOG(INFO) << "messages_getGameHighScores - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getHistory(const mtproto::TL_messages_getHistory& request, std::shared_ptr<mtproto::messages_Messages>& response) {
  LOG(INFO) << "messages_getHistory - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getInlineBotResults(const mtproto::TL_messages_getInlineBotResults& request, std::shared_ptr<mtproto::messages_BotResults>& response) {
  LOG(INFO) << "messages_getInlineBotResults - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getInlineGameHighScores(const mtproto::TL_messages_getInlineGameHighScores& request, std::shared_ptr<mtproto::messages_HighScores>& response) {
  LOG(INFO) << "messages_getInlineGameHighScores - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getMaskStickers(const mtproto::TL_messages_getMaskStickers& request, std::shared_ptr<mtproto::messages_AllStickers>& response) {
  LOG(INFO) << "messages_getMaskStickers - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getMessageEditData(const mtproto::TL_messages_getMessageEditData& request, std::shared_ptr<mtproto::messages_MessageEditData>& response) {
  LOG(INFO) << "messages_getMessageEditData - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getMessages(const mtproto::TL_messages_getMessages& request, std::shared_ptr<mtproto::messages_Messages>& response) {
  LOG(INFO) << "messages_getMessages - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getMessagesViews(const mtproto::TL_messages_getMessagesViews& request, std::shared_ptr<mtproto::TLInt32Vector>& response) {
  LOG(INFO) << "messages_getMessagesViews - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getPeerDialogs(const mtproto::TL_messages_getPeerDialogs& request, std::shared_ptr<mtproto::messages_PeerDialogs>& response) {
  LOG(INFO) << "messages_getPeerDialogs - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getPeerSettings(const mtproto::TL_messages_getPeerSettings& request, std::shared_ptr<mtproto::PeerSettings>& response) {
  LOG(INFO) << "messages_getPeerSettings - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getPinnedDialogs(const mtproto::TL_messages_getPinnedDialogs& request, std::shared_ptr<mtproto::messages_PeerDialogs>& response) {
  LOG(INFO) << "messages_getPinnedDialogs - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getRecentStickers(const mtproto::TL_messages_getRecentStickers& request, std::shared_ptr<mtproto::messages_RecentStickers>& response) {
  LOG(INFO) << "messages_getRecentStickers - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getSavedGifs(const mtproto::TL_messages_getSavedGifs& request, std::shared_ptr<mtproto::messages_SavedGifs>& response) {
  LOG(INFO) << "messages_getSavedGifs - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getStickerSet(const mtproto::TL_messages_getStickerSet& request, std::shared_ptr<mtproto::messages_StickerSet>& response) {
  LOG(INFO) << "messages_getStickerSet - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getWebPage(const mtproto::TL_messages_getWebPage& request, std::shared_ptr<mtproto::WebPage>& response) {
  LOG(INFO) << "messages_getWebPage - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_getWebPagePreview(const mtproto::TL_messages_getWebPagePreview& request, std::shared_ptr<mtproto::MessageMedia>& response) {
  LOG(INFO) << "messages_getWebPagePreview - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_hideReportSpam(const mtproto::TL_messages_hideReportSpam& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_hideReportSpam - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_importChatInvite(const mtproto::TL_messages_importChatInvite& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_importChatInvite - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_installStickerSet(const mtproto::TL_messages_installStickerSet& request, std::shared_ptr<mtproto::messages_StickerSetInstallResult>& response) {
  LOG(INFO) << "messages_installStickerSet - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_migrateChat(const mtproto::TL_messages_migrateChat& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_migrateChat - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_readEncryptedHistory(const mtproto::TL_messages_readEncryptedHistory& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_readEncryptedHistory - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_readFeaturedStickers(const mtproto::TL_messages_readFeaturedStickers& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_readFeaturedStickers - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_readHistory(const mtproto::TL_messages_readHistory& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) {
  LOG(INFO) << "messages_readHistory - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_readMessageContents(const mtproto::TL_messages_readMessageContents& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) {
  LOG(INFO) << "messages_readMessageContents - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_receivedMessages(const mtproto::TL_messages_receivedMessages& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::ReceivedNotifyMessage>>& response) {
  LOG(INFO) << "messages_receivedMessages - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_receivedQueue(const mtproto::TL_messages_receivedQueue& request, std::shared_ptr<mtproto::TLInt64Vector>& response) {
  LOG(INFO) << "messages_receivedQueue - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_reorderPinnedDialogs(const mtproto::TL_messages_reorderPinnedDialogs& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_reorderPinnedDialogs - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_reorderStickerSets(const mtproto::TL_messages_reorderStickerSets& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_reorderStickerSets - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_reportEncryptedSpam(const mtproto::TL_messages_reportEncryptedSpam& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_reportEncryptedSpam - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_reportSpam(const mtproto::TL_messages_reportSpam& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_reportSpam - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_requestEncryption(const mtproto::TL_messages_requestEncryption& request, std::shared_ptr<mtproto::EncryptedChat>& response) {
  LOG(INFO) << "messages_requestEncryption - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_saveDraft(const mtproto::TL_messages_saveDraft& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_saveDraft - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_saveGif(const mtproto::TL_messages_saveGif& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_saveGif - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_saveRecentSticker(const mtproto::TL_messages_saveRecentSticker& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_saveRecentSticker - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_search(const mtproto::TL_messages_search& request, std::shared_ptr<mtproto::messages_Messages>& response) {
  LOG(INFO) << "messages_search - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_searchGifs(const mtproto::TL_messages_searchGifs& request, std::shared_ptr<mtproto::messages_FoundGifs>& response) {
  LOG(INFO) << "messages_searchGifs - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_searchGlobal(const mtproto::TL_messages_searchGlobal& request, std::shared_ptr<mtproto::messages_Messages>& response) {
  LOG(INFO) << "messages_searchGlobal - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_sendEncrypted(const mtproto::TL_messages_sendEncrypted& request, std::shared_ptr<mtproto::messages_SentEncryptedMessage>& response) {
  LOG(INFO) << "messages_sendEncrypted - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_sendEncryptedFile(const mtproto::TL_messages_sendEncryptedFile& request, std::shared_ptr<mtproto::messages_SentEncryptedMessage>& response) {
  LOG(INFO) << "messages_sendEncryptedFile - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_sendEncryptedService(const mtproto::TL_messages_sendEncryptedService& request, std::shared_ptr<mtproto::messages_SentEncryptedMessage>& response) {
  LOG(INFO) << "messages_sendEncryptedService - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_sendInlineBotResult(const mtproto::TL_messages_sendInlineBotResult& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_sendInlineBotResult - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_sendMedia(const mtproto::TL_messages_sendMedia& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_sendMedia - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_sendMessage(const mtproto::TL_messages_sendMessage& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_sendMessage - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_setBotCallbackAnswer(const mtproto::TL_messages_setBotCallbackAnswer& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_setBotCallbackAnswer - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_setBotPrecheckoutResults(const mtproto::TL_messages_setBotPrecheckoutResults& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_setBotPrecheckoutResults - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_setBotShippingResults(const mtproto::TL_messages_setBotShippingResults& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_setBotShippingResults - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_setEncryptedTyping(const mtproto::TL_messages_setEncryptedTyping& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_setEncryptedTyping - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_setGameScore(const mtproto::TL_messages_setGameScore& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_setGameScore - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_setInlineBotResults(const mtproto::TL_messages_setInlineBotResults& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_setInlineBotResults - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_setInlineGameScore(const mtproto::TL_messages_setInlineGameScore& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_setInlineGameScore - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_setTyping(const mtproto::TL_messages_setTyping& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_setTyping - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_startBot(const mtproto::TL_messages_startBot& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_startBot - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_toggleChatAdmins(const mtproto::TL_messages_toggleChatAdmins& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(INFO) << "messages_toggleChatAdmins - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_toggleDialogPin(const mtproto::TL_messages_toggleDialogPin& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_toggleDialogPin - " << request.ToString();
  
  return kErrNotImpl;
}

int MessagesServiceImpl::messages_uninstallStickerSet(const mtproto::TL_messages_uninstallStickerSet& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "messages_uninstallStickerSet - " << request.ToString();
  
  return kErrNotImpl;
}

