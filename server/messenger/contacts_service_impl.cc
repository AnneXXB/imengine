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

#include "messenger/contacts_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int ContactsServiceImpl::contacts_block(const mtproto::TL_contacts_block& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "contacts_block - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_deleteContact(const mtproto::TL_contacts_deleteContact& request, std::shared_ptr<mtproto::contacts_Link>& response) {
  LOG(INFO) << "contacts_deleteContact - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_deleteContacts(const mtproto::TL_contacts_deleteContacts& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "contacts_deleteContacts - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_exportCard(const mtproto::TL_contacts_exportCard& request, std::shared_ptr<mtproto::TLInt32Vector>& response) {
  LOG(INFO) << "contacts_exportCard - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_getBlocked(const mtproto::TL_contacts_getBlocked& request, std::shared_ptr<mtproto::contacts_Blocked>& response) {
  LOG(INFO) << "contacts_getBlocked - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_getContacts(const mtproto::TL_contacts_getContacts& request, std::shared_ptr<mtproto::contacts_Contacts>& response) {
  LOG(INFO) << "contacts_getContacts - " << request.ToString();
  
  // contacts.contactsNotModified#b74ba9d2 = contacts.Contacts;
  // contacts.contacts#6f8b8cb2 contacts:Vector<Contact> users:Vector<User> = contacts.Contacts;

  auto contacts = std::make_shared<mtproto::TL_contacts_contacts>();
  auto contact = contacts->add_contacts<mtproto::TL_contact>();
  contact->set_user_id(2);
  contact->set_mutual(std::make_unique<mtproto::TL_boolTrue>());
  
  auto user = contacts->add_users<mtproto::TL_user>();
  user->set_id(2);
  user->set_access_hash(2);
  user->set_first_name("yu");
  user->set_first_name("bijun");
  user->set_username("bijun");
  user->set_phone("8613588021430");

  response = contacts;
  
  return kErrOK;
}

int ContactsServiceImpl::contacts_getStatuses(const mtproto::TL_contacts_getStatuses& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::ContactStatus>>& response) {
  LOG(INFO) << "contacts_getStatuses - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_getTopPeers(const mtproto::TL_contacts_getTopPeers& request, std::shared_ptr<mtproto::contacts_TopPeers>& response) {
  LOG(INFO) << "contacts_getTopPeers - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_importCard(const mtproto::TL_contacts_importCard& request, std::shared_ptr<mtproto::User>& response) {
  LOG(INFO) << "contacts_importCard - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_importContacts(const mtproto::TL_contacts_importContacts& request, std::shared_ptr<mtproto::contacts_ImportedContacts>& response) {
  LOG(INFO) << "contacts_importContacts - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_resetTopPeerRating(const mtproto::TL_contacts_resetTopPeerRating& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "contacts_resetTopPeerRating - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_resolveUsername(const mtproto::TL_contacts_resolveUsername& request, std::shared_ptr<mtproto::contacts_ResolvedPeer>& response) {
  LOG(INFO) << "contacts_resolveUsername - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_search(const mtproto::TL_contacts_search& request, std::shared_ptr<mtproto::contacts_Found>& response) {
  LOG(INFO) << "contacts_search - " << request.ToString();
  
  return kErrNotImpl;
}

int ContactsServiceImpl::contacts_unblock(const mtproto::TL_contacts_unblock& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "contacts_unblock - " << request.ToString();
  
  return kErrNotImpl;
}
