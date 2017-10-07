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

#include "messenger/zrpc_messages_service.h"

#include "nebula/base/logger/glog_util.h"
#include "proto/api/error_codes.h"

int ZRpcMessagesService::messages_acceptEncryption(const mtproto::TL_messages_acceptEncryption& request, std::shared_ptr<mtproto::EncryptedChat>& response) {
  LOG(ERROR) << "messages_acceptEncryption not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_addChatUser(const mtproto::TL_messages_addChatUser& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_addChatUser not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_checkChatInvite(const mtproto::TL_messages_checkChatInvite& request, std::shared_ptr<mtproto::ChatInvite>& response) {
  LOG(ERROR) << "messages_checkChatInvite not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_clearRecentStickers(const mtproto::TL_messages_clearRecentStickers& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_clearRecentStickers not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_createChat(const mtproto::TL_messages_createChat& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_createChat not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_deleteChatUser(const mtproto::TL_messages_deleteChatUser& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_deleteChatUser not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_deleteHistory(const mtproto::TL_messages_deleteHistory& request, std::shared_ptr<mtproto::messages_AffectedHistory>& response) {
  LOG(ERROR) << "messages_deleteHistory not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_deleteMessages(const mtproto::TL_messages_deleteMessages& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) {
  LOG(ERROR) << "messages_deleteMessages not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_discardEncryption(const mtproto::TL_messages_discardEncryption& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_discardEncryption not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_editChatAdmin(const mtproto::TL_messages_editChatAdmin& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_editChatAdmin not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_editChatPhoto(const mtproto::TL_messages_editChatPhoto& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_editChatPhoto not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_editChatTitle(const mtproto::TL_messages_editChatTitle& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_editChatTitle not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_editInlineBotMessage(const mtproto::TL_messages_editInlineBotMessage& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_editInlineBotMessage not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_editMessage(const mtproto::TL_messages_editMessage& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_editMessage not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_exportChatInvite(const mtproto::TL_messages_exportChatInvite& request, std::shared_ptr<mtproto::ExportedChatInvite>& response) {
  LOG(ERROR) << "messages_exportChatInvite not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_forwardMessage(const mtproto::TL_messages_forwardMessage& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_forwardMessage not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_forwardMessages(const mtproto::TL_messages_forwardMessages& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_forwardMessages not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getAllChats(const mtproto::TL_messages_getAllChats& request, std::shared_ptr<mtproto::messages_Chats>& response) {
  LOG(ERROR) << "messages_getAllChats not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getAllDrafts(const mtproto::TL_messages_getAllDrafts& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_getAllDrafts not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getAllStickers(const mtproto::TL_messages_getAllStickers& request, std::shared_ptr<mtproto::messages_AllStickers>& response) {
  LOG(ERROR) << "messages_getAllStickers not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getArchivedStickers(const mtproto::TL_messages_getArchivedStickers& request, std::shared_ptr<mtproto::messages_ArchivedStickers>& response) {
  LOG(ERROR) << "messages_getArchivedStickers not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getAttachedStickers(const mtproto::TL_messages_getAttachedStickers& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::StickerSetCovered>>& response) {
  LOG(ERROR) << "messages_getAttachedStickers not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getBotCallbackAnswer(const mtproto::TL_messages_getBotCallbackAnswer& request, std::shared_ptr<mtproto::messages_BotCallbackAnswer>& response) {
  LOG(ERROR) << "messages_getBotCallbackAnswer not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getChats(const mtproto::TL_messages_getChats& request, std::shared_ptr<mtproto::messages_Chats>& response) {
  LOG(ERROR) << "messages_getChats not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getCommonChats(const mtproto::TL_messages_getCommonChats& request, std::shared_ptr<mtproto::messages_Chats>& response) {
  LOG(ERROR) << "messages_getCommonChats not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getDhConfig(const mtproto::TL_messages_getDhConfig& request, std::shared_ptr<mtproto::messages_DhConfig>& response) {
  LOG(ERROR) << "messages_getDhConfig not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getDialogs(const mtproto::TL_messages_getDialogs& request, std::shared_ptr<mtproto::messages_Dialogs>& response) {
  LOG(ERROR) << "messages_getDialogs not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getDocumentByHash(const mtproto::TL_messages_getDocumentByHash& request, std::shared_ptr<mtproto::Document>& response) {
  LOG(ERROR) << "messages_getDocumentByHash not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getFeaturedStickers(const mtproto::TL_messages_getFeaturedStickers& request, std::shared_ptr<mtproto::messages_FeaturedStickers>& response) {
  LOG(ERROR) << "messages_getFeaturedStickers not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getFullChat(const mtproto::TL_messages_getFullChat& request, std::shared_ptr<mtproto::messages_ChatFull>& response) {
  LOG(ERROR) << "messages_getFullChat not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getGameHighScores(const mtproto::TL_messages_getGameHighScores& request, std::shared_ptr<mtproto::messages_HighScores>& response) {
  LOG(ERROR) << "messages_getGameHighScores not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getHistory(const mtproto::TL_messages_getHistory& request, std::shared_ptr<mtproto::messages_Messages>& response) {
  LOG(ERROR) << "messages_getHistory not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getInlineBotResults(const mtproto::TL_messages_getInlineBotResults& request, std::shared_ptr<mtproto::messages_BotResults>& response) {
  LOG(ERROR) << "messages_getInlineBotResults not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getInlineGameHighScores(const mtproto::TL_messages_getInlineGameHighScores& request, std::shared_ptr<mtproto::messages_HighScores>& response) {
  LOG(ERROR) << "messages_getInlineGameHighScores not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getMaskStickers(const mtproto::TL_messages_getMaskStickers& request, std::shared_ptr<mtproto::messages_AllStickers>& response) {
  LOG(ERROR) << "messages_getMaskStickers not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getMessageEditData(const mtproto::TL_messages_getMessageEditData& request, std::shared_ptr<mtproto::messages_MessageEditData>& response) {
  LOG(ERROR) << "messages_getMessageEditData not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getMessages(const mtproto::TL_messages_getMessages& request, std::shared_ptr<mtproto::messages_Messages>& response) {
  LOG(ERROR) << "messages_getMessages not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getMessagesViews(const mtproto::TL_messages_getMessagesViews& request, std::shared_ptr<mtproto::TLInt32Vector>& response) {
  LOG(ERROR) << "messages_getMessagesViews not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getPeerDialogs(const mtproto::TL_messages_getPeerDialogs& request, std::shared_ptr<mtproto::messages_PeerDialogs>& response) {
  LOG(ERROR) << "messages_getPeerDialogs not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getPeerSettings(const mtproto::TL_messages_getPeerSettings& request, std::shared_ptr<mtproto::PeerSettings>& response) {
  LOG(ERROR) << "messages_getPeerSettings not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getPinnedDialogs(const mtproto::TL_messages_getPinnedDialogs& request, std::shared_ptr<mtproto::messages_PeerDialogs>& response) {
  LOG(ERROR) << "messages_getPinnedDialogs not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getRecentStickers(const mtproto::TL_messages_getRecentStickers& request, std::shared_ptr<mtproto::messages_RecentStickers>& response) {
  LOG(ERROR) << "messages_getRecentStickers not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getSavedGifs(const mtproto::TL_messages_getSavedGifs& request, std::shared_ptr<mtproto::messages_SavedGifs>& response) {
  LOG(ERROR) << "messages_getSavedGifs not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getStickerSet(const mtproto::TL_messages_getStickerSet& request, std::shared_ptr<mtproto::messages_StickerSet>& response) {
  LOG(ERROR) << "messages_getStickerSet not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getWebPage(const mtproto::TL_messages_getWebPage& request, std::shared_ptr<mtproto::WebPage>& response) {
  LOG(ERROR) << "messages_getWebPage not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_getWebPagePreview(const mtproto::TL_messages_getWebPagePreview& request, std::shared_ptr<mtproto::MessageMedia>& response) {
  LOG(ERROR) << "messages_getWebPagePreview not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_hideReportSpam(const mtproto::TL_messages_hideReportSpam& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_hideReportSpam not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_importChatInvite(const mtproto::TL_messages_importChatInvite& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_importChatInvite not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_installStickerSet(const mtproto::TL_messages_installStickerSet& request, std::shared_ptr<mtproto::messages_StickerSetInstallResult>& response) {
  LOG(ERROR) << "messages_installStickerSet not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_migrateChat(const mtproto::TL_messages_migrateChat& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_migrateChat not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_readEncryptedHistory(const mtproto::TL_messages_readEncryptedHistory& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_readEncryptedHistory not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_readFeaturedStickers(const mtproto::TL_messages_readFeaturedStickers& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_readFeaturedStickers not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_readHistory(const mtproto::TL_messages_readHistory& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) {
  LOG(ERROR) << "messages_readHistory not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_readMessageContents(const mtproto::TL_messages_readMessageContents& request, std::shared_ptr<mtproto::messages_AffectedMessages>& response) {
  LOG(ERROR) << "messages_readMessageContents not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_receivedMessages(const mtproto::TL_messages_receivedMessages& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::ReceivedNotifyMessage>>& response) {
  LOG(ERROR) << "messages_receivedMessages not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_receivedQueue(const mtproto::TL_messages_receivedQueue& request, std::shared_ptr<mtproto::TLInt64Vector>& response) {
  LOG(ERROR) << "messages_receivedQueue not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_reorderPinnedDialogs(const mtproto::TL_messages_reorderPinnedDialogs& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_reorderPinnedDialogs not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_reorderStickerSets(const mtproto::TL_messages_reorderStickerSets& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_reorderStickerSets not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_reportEncryptedSpam(const mtproto::TL_messages_reportEncryptedSpam& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_reportEncryptedSpam not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_reportSpam(const mtproto::TL_messages_reportSpam& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_reportSpam not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_requestEncryption(const mtproto::TL_messages_requestEncryption& request, std::shared_ptr<mtproto::EncryptedChat>& response) {
  LOG(ERROR) << "messages_requestEncryption not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_saveDraft(const mtproto::TL_messages_saveDraft& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_saveDraft not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_saveGif(const mtproto::TL_messages_saveGif& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_saveGif not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_saveRecentSticker(const mtproto::TL_messages_saveRecentSticker& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_saveRecentSticker not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_search(const mtproto::TL_messages_search& request, std::shared_ptr<mtproto::messages_Messages>& response) {
  LOG(ERROR) << "messages_search not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_searchGifs(const mtproto::TL_messages_searchGifs& request, std::shared_ptr<mtproto::messages_FoundGifs>& response) {
  LOG(ERROR) << "messages_searchGifs not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_searchGlobal(const mtproto::TL_messages_searchGlobal& request, std::shared_ptr<mtproto::messages_Messages>& response) {
  LOG(ERROR) << "messages_searchGlobal not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_sendEncrypted(const mtproto::TL_messages_sendEncrypted& request, std::shared_ptr<mtproto::messages_SentEncryptedMessage>& response) {
  LOG(ERROR) << "messages_sendEncrypted not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_sendEncryptedFile(const mtproto::TL_messages_sendEncryptedFile& request, std::shared_ptr<mtproto::messages_SentEncryptedMessage>& response) {
  LOG(ERROR) << "messages_sendEncryptedFile not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_sendEncryptedService(const mtproto::TL_messages_sendEncryptedService& request, std::shared_ptr<mtproto::messages_SentEncryptedMessage>& response) {
  LOG(ERROR) << "messages_sendEncryptedService not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_sendInlineBotResult(const mtproto::TL_messages_sendInlineBotResult& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_sendInlineBotResult not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_sendMedia(const mtproto::TL_messages_sendMedia& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_sendMedia not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_sendMessage(const mtproto::TL_messages_sendMessage& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_sendMessage not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_setBotCallbackAnswer(const mtproto::TL_messages_setBotCallbackAnswer& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_setBotCallbackAnswer not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_setBotPrecheckoutResults(const mtproto::TL_messages_setBotPrecheckoutResults& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_setBotPrecheckoutResults not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_setBotShippingResults(const mtproto::TL_messages_setBotShippingResults& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_setBotShippingResults not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_setEncryptedTyping(const mtproto::TL_messages_setEncryptedTyping& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_setEncryptedTyping not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_setGameScore(const mtproto::TL_messages_setGameScore& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_setGameScore not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_setInlineBotResults(const mtproto::TL_messages_setInlineBotResults& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_setInlineBotResults not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_setInlineGameScore(const mtproto::TL_messages_setInlineGameScore& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_setInlineGameScore not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_setTyping(const mtproto::TL_messages_setTyping& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_setTyping not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_startBot(const mtproto::TL_messages_startBot& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_startBot not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_toggleChatAdmins(const mtproto::TL_messages_toggleChatAdmins& request, std::shared_ptr<mtproto::Updates>& response) {
  LOG(ERROR) << "messages_toggleChatAdmins not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_toggleDialogPin(const mtproto::TL_messages_toggleDialogPin& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_toggleDialogPin not impl";
  return kErrNotImpl;
}

int ZRpcMessagesService::messages_uninstallStickerSet(const mtproto::TL_messages_uninstallStickerSet& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "messages_uninstallStickerSet not impl";
  return kErrNotImpl;
}
