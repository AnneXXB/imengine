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

zproto/proto/auths.proto
zproto/proto/bases.proto
zproto/proto/files.proto
zproto/proto/groups.proto
zproto/proto/messages.proto
#zproto/proto/servers.proto
zproto/proto/peers.proto
#zproto/proto/presences.proto

# 客户端交互协议
api/cc/api_method_ids.pb.cc
api/cc/api_method_ids.pb.h
api/cc/auth.pb.cc
api/cc/auth.pb.h
api/cc/configs.pb.cc
api/cc/configs.pb.h
api/cc/counters.pb.cc
api/cc/counters.pb.h
api/cc/device.pb.cc
api/cc/device.pb.h
api/cc/files.pb.cc
api/cc/files.pb.h
api/cc/dialogs.pb.cc
api/cc/dialogs.pb.h
api/cc/group_base.pb.cc
api/cc/group_base.pb.h
api/cc/groups.pb.cc
api/cc/groups.pb.h
api/cc/invites.pb.cc
api/cc/invites.pb.h
api/cc/messaging.pb.cc
api/cc/messaging.pb.h
api/cc/messaging_base.pb.cc
api/cc/messaging_base.pb.h
api/cc/misc.pb.cc
api/cc/misc.pb.h
api/cc/peers.pb.cc
api/cc/peers.pb.h
api/cc/privacy.pb.cc
api/cc/privacy.pb.h
api/cc/sequence.pb.cc
api/cc/sequence.pb.h
api/cc/stats.pb.cc
api/cc/stats.pb.h
api/cc/types.pb.cc
api/cc/types.pb.h
api/cc/users.pb.cc
api/cc/users.pb.h
api/cc/weak.pb.cc
api/cc/weak.pb.h

api/proto/api_method_ids.proto
api/proto/auth.proto
api/proto/configs.proto
api/proto/counters.proto
api/proto/device.proto
api/proto/files.proto
api/proto/dialogs.proto
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

s2s/cc/s2s_method_ids.pb.cc
s2s/cc/s2s_method_ids.pb.h
s2s/cc/servers.pb.cc
s2s/cc/servers.pb.h
s2s/cc/presences.pb.cc
s2s/cc/presences.pb.h

s2s/proto/servers.proto
s2s/proto/presences.proto
)

add_library(proto STATIC ${PROTO_SRC_LIST})
target_link_libraries(proto protobuf)

#add_subdirectory(base/test)
