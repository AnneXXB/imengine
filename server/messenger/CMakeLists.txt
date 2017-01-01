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
  zrpc_dialog_service.cc
  zrpc_dialog_service.h
  dialog_service_impl.cc
  dialog_service_impl.h
  zrpc_messaging_service.cc
  zrpc_messaging_service.h
  messaging_service_impl.cc
  messaging_service_impl.h
  zrpc_groups_service.cc
  zrpc_groups_service.h
  groups_service_impl.cc
  groups_service_impl.h
  zrpc_sequence_service.cc
  zrpc_sequence_service.h
  sequence_service_impl.cc
  sequence_service_impl.h
  zrpc_weak_service.cc
  zrpc_weak_service.h
  weak_service_impl.cc
  weak_service_impl.h
  zrpc_privacy_service.cc
  zrpc_privacy_service.h
  privacy_service_impl.cc
  privacy_service_impl.h
  )

add_executable (messenger_server ${SRC_LIST})
target_link_libraries (messenger_server biz_model net base proto)

