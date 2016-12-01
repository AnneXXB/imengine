/**
 *  Copyright (c) 2016, https://github.com/zhatalk
 *  All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "biz_model/user_dialog_model.h"

#include <folly/Format.h>

#include "nebula/storage/conn_pool_manager.h"

//////////////////////////////////////////////////////////////////////////////////////////
bool CreateUserDialog::SerializeToQuery(std::string& query_string) const {
  folly::format(&query_string, "INSERT INTO user_dialogs(user_id,peer_id,peer_type,status,created_at,updated_at) "
                "VALUES('{}','{}',{},1,{},{})",
                dialog.user_id,
                dialog.peer_id,
                dialog.peer_type,
                dialog.created_at,
                dialog.updated_at);
  
  return !query_string.empty();
}

