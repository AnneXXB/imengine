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
  gate_server.cc
  gate_server.h
  gate_handler.cc
  gate_handler.h
  gate_base_handler.cc
  gate_base_handler.h
  gate_server_util.h
  gate_server_handler.cc
  gate_server_handler.h
  push_channel_client_handler.cc
  push_channel_client_handler.h
  messenger_client_handler.cc
  messenger_client_handler.h
  online_status_client_handler.cc
  online_status_client_handler.h
  auth_client_handler.cc
  auth_client_handler.h
  ../base/message_handler_util.h
)

add_executable (gate_server ${SRC_LIST})
target_link_libraries (gate_server net base proto)

