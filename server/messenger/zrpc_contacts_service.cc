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

#include "messenger/zrpc_contacts_service.h"

#include "nebula/base/logger/glog_util.h"
#include "proto/api/error_codes.h"

int ZRpcContactsService::contacts_block(const mtproto::TL_contacts_block& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "contacts_block not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_deleteContact(const mtproto::TL_contacts_deleteContact& request, std::shared_ptr<mtproto::contacts_Link>& response) {
  LOG(ERROR) << "contacts_deleteContact not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_deleteContacts(const mtproto::TL_contacts_deleteContacts& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "contacts_deleteContacts not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_exportCard(const mtproto::TL_contacts_exportCard& request, std::shared_ptr<mtproto::TLInt32Vector>& response) {
  LOG(ERROR) << "contacts_exportCard not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_getBlocked(const mtproto::TL_contacts_getBlocked& request, std::shared_ptr<mtproto::contacts_Blocked>& response) {
  LOG(ERROR) << "contacts_getBlocked not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_getContacts(const mtproto::TL_contacts_getContacts& request, std::shared_ptr<mtproto::contacts_Contacts>& response) {
  LOG(ERROR) << "contacts_getContacts not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_getStatuses(const mtproto::TL_contacts_getStatuses& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::ContactStatus>>& response) {
  LOG(ERROR) << "contacts_getStatuses not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_getTopPeers(const mtproto::TL_contacts_getTopPeers& request, std::shared_ptr<mtproto::contacts_TopPeers>& response) {
  LOG(ERROR) << "contacts_getTopPeers not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_importCard(const mtproto::TL_contacts_importCard& request, std::shared_ptr<mtproto::User>& response) {
  LOG(ERROR) << "contacts_importCard not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_importContacts(const mtproto::TL_contacts_importContacts& request, std::shared_ptr<mtproto::contacts_ImportedContacts>& response) {
  LOG(ERROR) << "contacts_importContacts not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_resetTopPeerRating(const mtproto::TL_contacts_resetTopPeerRating& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "contacts_resetTopPeerRating not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_resolveUsername(const mtproto::TL_contacts_resolveUsername& request, std::shared_ptr<mtproto::contacts_ResolvedPeer>& response) {
  LOG(ERROR) << "contacts_resolveUsername not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_search(const mtproto::TL_contacts_search& request, std::shared_ptr<mtproto::contacts_Found>& response) {
  LOG(ERROR) << "contacts_search not impl";
  return kErrNotImpl;
}

int ZRpcContactsService::contacts_unblock(const mtproto::TL_contacts_unblock& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(ERROR) << "contacts_unblock not impl";
  return kErrNotImpl;
}
