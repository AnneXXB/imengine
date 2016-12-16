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
  push_server.cc
  push_server.h
  zrpc_push_dispatcher.cc
  zrpc_push_dispatcher.h
  zrpc_push_service.cc
  zrpc_push_service.h
  gate_channel_handler.cc
  gate_channel_handler.h
  gate_channel_manager.cc
  gate_channel_manager.h
  push_service_impl.cc
  push_service_impl.h
  )

add_executable (push_server ${SRC_LIST})
target_link_libraries (push_server dal net base proto)

