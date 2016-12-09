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

set (PROTO_SRC_LIST
zproto/zproto_api_message_types.h

zproto/cc/auths.pb.cc
zproto/cc/auths.pb.h
zproto/cc/bases.pb.cc
zproto/cc/bases.pb.h
zproto/cc/files.pb.cc
zproto/cc/files.pb.h
zproto/cc/groups.pb.cc
zproto/cc/groups.pb.h
zproto/cc/messages.pb.cc
zproto/cc/messages.pb.h
zproto/cc/servers.pb.cc
zproto/cc/servers.pb.h
zproto/cc/biz_servers.pb.cc
zproto/cc/biz_servers.pb.h

zproto/proto/auths.proto
zproto/proto/bases.proto
zproto/proto/files.proto
zproto/proto/groups.proto
zproto/proto/messages.proto
zproto/proto/servers.proto
zproto/proto/biz_servers.proto
)

add_library(proto STATIC ${PROTO_SRC_LIST})
target_link_libraries(proto protobuf)

#add_subdirectory(base/test)

