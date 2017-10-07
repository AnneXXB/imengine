#  Copyright (c) 2016, https://github.com/nebula-im/nebula
#  All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include_directories(. .. ../../nebula)

set (SRC_LIST
  ../base/base_zrpc_service.cc
  ../base/base_zrpc_service.h
  messenger_server.cc
  messenger_server.h
  zrpc_messenger_dispatcher.cc
  zrpc_messenger_dispatcher.h

  zrpc_auth_service.cc
  zrpc_auth_service.h
  auth_service_impl.cc
  auth_service_impl.h

  zrpc_account_service.cc
  zrpc_account_service.h
  account_service_impl.cc
  account_service_impl.h

  zrpc_users_service.cc
  zrpc_users_service.h
  users_service_impl.cc
  users_service_impl.h

  zrpc_contacts_service.cc
  zrpc_contacts_service.h
  contacts_service_impl.cc
  contacts_service_impl.h

  zrpc_messages_service.cc
  zrpc_messages_service.h
  messages_service_impl.cc
  messages_service_impl.h

  zrpc_updates_service.cc
  zrpc_updates_service.h
  updates_service_impl.cc
  updates_service_impl.h

  zrpc_photos_service.cc
  zrpc_photos_service.h
  photos_service_impl.cc
  photos_service_impl.h

  zrpc_upload_service.cc
  zrpc_upload_service.h
  upload_service_impl.cc
  upload_service_impl.h

  zrpc_help_service.cc
  zrpc_help_service.h
  help_service_impl.cc
  help_service_impl.h

  zrpc_channels_service.cc
  zrpc_channels_service.h
  channels_service_impl.cc
  channels_service_impl.h

  zrpc_bots_service.cc
  zrpc_bots_service.h
  bots_service_impl.cc
  bots_service_impl.h

  zrpc_phone_service.cc
  zrpc_phone_service.h
  phone_service_impl.cc
  phone_service_impl.h

  zrpc_payments_service.cc
  zrpc_payments_service.h
  payments_service_impl.cc
  payments_service_impl.h

  # zrpc_dialog_service.cc
  # zrpc_dialog_service.h
  # dialog_service_impl.cc
  # dialog_service_impl.h
  # zrpc_messaging_service.cc
  # zrpc_messaging_service.h
  # messaging_service_impl.cc
  # messaging_service_impl.h
  # zrpc_groups_service.cc
  # zrpc_groups_service.h
  # groups_service_impl.cc
  # groups_service_impl.h
  # zrpc_sequence_service.cc
  # zrpc_sequence_service.h
  # sequence_service_impl.cc
  # sequence_service_impl.h
  # zrpc_weak_service.cc
  # zrpc_weak_service.h
  # weak_service_impl.cc
  # weak_service_impl.h
  # zrpc_privacy_service.cc
  # zrpc_privacy_service.h
  # privacy_service_impl.cc
  # privacy_service_impl.h
  )

add_executable (messenger_server ${SRC_LIST})
target_link_libraries (messenger_server biz_model net base proto)

