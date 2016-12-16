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
  online_status_server.cc
  online_status_server.h
  zrpc_online_dispatcher.cc
  zrpc_online_dispatcher.h
  zrpc_online_service.cc
  zrpc_online_service.h
  online_session_manager.cc
  online_session_manager.h
  http_online_service.cc
  http_online_service.h
  online_service_impl.cc
  online_service_impl.h
  )

add_executable (online_status_server ${SRC_LIST})
target_link_libraries (online_status_server net base proto)

#add_subdirectory(test)

