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

#ifndef	MESSENGER_ZRPC_CONTACTS_SERVICE_H_
#define	MESSENGER_ZRPC_CONTACTS_SERVICE_H_

#include "base/base_zrpc_service.h"
#include "proto/mtproto/core/mtproto_schema.h"

class ZRpcContactsService : public BaseZRpcService {
public:
  virtual ~ZRpcContactsService() = default;

  // contacts.block#332b49fc id:InputUser = Bool;
  virtual int contacts_block(const mtproto::TL_contacts_block& request, std::shared_ptr<mtproto::Bool>& response);
  
  // contacts.deleteContact#8e953744 id:InputUser = contacts.Link;
  virtual int contacts_deleteContact(const mtproto::TL_contacts_deleteContact& request, std::shared_ptr<mtproto::contacts_Link>& response);
  
  // contacts.deleteContacts#59ab389e id:Vector<InputUser> = Bool;
  virtual int contacts_deleteContacts(const mtproto::TL_contacts_deleteContacts& request, std::shared_ptr<mtproto::Bool>& response);
  
  // contacts.exportCard#84e53737 = Vector<int>;
  virtual int contacts_exportCard(const mtproto::TL_contacts_exportCard& request, std::shared_ptr<mtproto::TLInt32Vector>& response);
  
  // contacts.getBlocked#f57c350f offset:int limit:int = contacts.Blocked;
  virtual int contacts_getBlocked(const mtproto::TL_contacts_getBlocked& request, std::shared_ptr<mtproto::contacts_Blocked>& response);
  
  // contacts.getContacts#22c6aa08 hash:string = contacts.Contacts;
  virtual int contacts_getContacts(const mtproto::TL_contacts_getContacts& request, std::shared_ptr<mtproto::contacts_Contacts>& response);
  
  // contacts.getStatuses#c4a353ee = Vector<ContactStatus>;
  virtual int contacts_getStatuses(const mtproto::TL_contacts_getStatuses& request, std::shared_ptr<mtproto::TLObjectVector<mtproto::ContactStatus>>& response);
  
  // contacts.getTopPeers#d4982db5 flags:# correspondents:flags.0?true bots_pm:flags.1?true bots_inline:flags.2?true groups:flags.10?true channels:flags.15?true offset:int limit:int hash:int = contacts.TopPeers;
  virtual int contacts_getTopPeers(const mtproto::TL_contacts_getTopPeers& request, std::shared_ptr<mtproto::contacts_TopPeers>& response);
  
  // contacts.importCard#4fe196fe export_card:Vector<int> = User;
  virtual int contacts_importCard(const mtproto::TL_contacts_importCard& request, std::shared_ptr<mtproto::User>& response);
  
  // contacts.importContacts#da30b32d contacts:Vector<InputContact> replace:Bool = contacts.ImportedContacts;
  virtual int contacts_importContacts(const mtproto::TL_contacts_importContacts& request, std::shared_ptr<mtproto::contacts_ImportedContacts>& response);
  
  // contacts.resetTopPeerRating#1ae373ac category:TopPeerCategory peer:InputPeer = Bool;
  virtual int contacts_resetTopPeerRating(const mtproto::TL_contacts_resetTopPeerRating& request, std::shared_ptr<mtproto::Bool>& response);
  
  // contacts.resolveUsername#f93ccba3 username:string = contacts.ResolvedPeer;
  virtual int contacts_resolveUsername(const mtproto::TL_contacts_resolveUsername& request, std::shared_ptr<mtproto::contacts_ResolvedPeer>& response);
  
  // contacts.search#11f812d8 q:string limit:int = contacts.Found;
  virtual int contacts_search(const mtproto::TL_contacts_search& request, std::shared_ptr<mtproto::contacts_Found>& response);
  
  // contacts.unblock#e54100bd id:InputUser = Bool;
  virtual int contacts_unblock(const mtproto::TL_contacts_unblock& request, std::shared_ptr<mtproto::Bool>& response);
};

#endif

