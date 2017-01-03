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
project(proto)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_VERBOSE_MAKEFILE ON)

#file(GLOB_RECURSE PROTO_FILES "./*.proto")
set(PROTO_FILES
    api/proto/auth.proto
    api/proto/configs.proto
    api/proto/counters.proto
    api/proto/device.proto
    api/proto/files.proto
    api/proto/group_base.proto
    api/proto/groups.proto
    api/proto/invites.proto
    api/proto/messaging_base.proto
    api/proto/messaging.proto
    api/proto/misc.proto
    api/proto/peers.proto
    api/proto/privacy.proto
    api/proto/sequence.proto
    api/proto/stats.proto
    api/proto/users.proto
    api/proto/weak.proto
    api/proto/types.proto

    s2s/proto/servers.proto
    s2s/proto/presences.proto
    )
 
find_package(Protobuf REQUIRED)
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})


add_library(proto STATIC ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(proto ${PROTOBUF_LIBRARIES} pthread)
