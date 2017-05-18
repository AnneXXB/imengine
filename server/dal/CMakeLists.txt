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
  base_dal.h
  user_do.h
  user_dao.h
  user_dao_impl.h
  user_dao_impl.cc
  history_message_do.h
  history_message_dao.h
  history_message_dao_impl.h
  history_message_dao_impl.cc
  user_message_do.h
  user_message_dao.h
  user_message_dao_impl.h
  user_message_dao_impl.cc
  user_dialog_do.h
  user_dialog_dao.h
  user_dialog_dao_impl.h
  user_dialog_dao_impl.cc
  group_do.h
  group_dao.h
  group_dao_impl.h
  group_dao_impl.cc
  group_user_do.h
  group_user_dao.h
  group_user_dao_impl.h
  group_user_dao_impl.cc
  sequence_do.h
  sequence_dao.h
  sequence_dao_impl.h
  sequence_dao_impl.cc
  online_status_do.h
  online_status_dao.h
  online_status_dao_impl.h
  online_status_dao_impl.cc
  user_sequence_do.h
  user_sequence_dao.h
  user_sequence_dao_impl.h
  user_sequence_dao_impl.cc
  seq_updates_ngen_do.h
  seq_updates_ngen_dao.h
  seq_updates_ngen_dao_impl.cc
  seq_updates_ngen_dao_impl.h
  group_invite_token_do.h
  group_invite_token_dao.h
  group_invite_token_dao_impl.cc
  group_invite_token_dao_impl.h
  file_do.h
  file_dao.h
  file_dao_impl.cc
  file_dao_impl.h
  file_part_do.h
  file_part_dao.h
  file_part_dao_impl.cc
  file_part_dao_impl.h
 )

add_library(dal STATIC ${SRC_LIST})
target_link_libraries(dal mysql_client redis_client)

