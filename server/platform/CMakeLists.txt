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
  platform_server.cc
  platform_server.h
  platform_service_impl.cc
  platform_service_impl.h
  zrpc_platform_dispatcher.cc
  zrpc_platform_dispatcher.h
  zrpc_platform_service.cc
  zrpc_platform_service.h
  )

add_executable (platform_server ${SRC_LIST})
target_link_libraries (platform_server biz_model net base proto)

