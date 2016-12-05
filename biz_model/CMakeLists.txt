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
  base_biz_model_data.h
  history_message_model.cc
  history_message_model.h
  user_message_model.cc
  user_message_model.h
  app_model.cc
  app_model.h
  user_model.cc
  user_model.h
  sequence_model.cc
  sequence_model.h
  user_dialog_model.cc
  user_dialog_model.h
  online_status_model.cc
  online_status_model.h
  group_model.cc
  group_model.h
 )

add_library(biz_model STATIC ${SRC_LIST})
target_link_libraries(biz_model nebula-storage)

