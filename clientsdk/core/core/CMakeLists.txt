#  Copyright (c) 2016, https://github.com/nebula-im
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

include_directories(. ..)

set (SRC_LIST
 checksum.cc
 checksum.h
 crc.hpp
 zproto_command_ids.h
 auto_buffer_codec.cc
 auto_buffer_codec.h
 core_api.cc
 core_api.h
 mars_core_manager.cc
 mars_core_manager.h
 core_longlink_packer.cc
 core_longlink_packer.h
 log_crypt.cc
 log_crypt.h
 core_shortlink_packer.cc
 core_shortlink_packer.h

 api_message_box.h
 zproto_frame_data.cc
 zproto_frame_data.h
 zproto_package_data.cc
 zproto_package_data.h
 zproto_task_manager.cc
 zproto_task_manager.h
)

add_library(core STATIC ${SRC_LIST})

target_link_libraries(core proto
 libmars.a z resolv
 ${COREFOUNDATION_LIBRARY}
 ${FOUNDATION_LIBRARY}
 ${SYSTEMCONFIGURATION_LIBRARY}
 ${NETWORKEXTENSION_LIBRARY}
 ${CFNETWORK_LIBRARY}
 ${COREWLAN_LIBRARY}
)

add_subdirectory(test)

