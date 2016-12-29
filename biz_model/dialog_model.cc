/*
 *  Copyright (c) 2016, https://github.com/nebula-im/imengine
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

#include "biz_model/dialog_model.h"

#include "nebula/base/time_util.h"
#include "proto/api/error_codes.h"
#include "dal/user_dialog_dao.h"

DialogModel& DialogModel::GetInstance() {
  static DialogModel instance;
  return instance;
}

int DialogModel::CreateIfNotExists(const std::string& uid, uint32_t peer_type, const std::string& peer_id) {
  // TODO(@benqi): 最好能有个地方能保证保证会话已经存在

  // 会话处理
  // 正向
  // 检查会话是否存在
  auto now = NowInMsecTime();
  auto& user_dialog_dao = UserDialogDAO::GetInstance();
  int r = user_dialog_dao.CheckExists(uid, peer_id, peer_type);
  // TODO(@benqi): 出错
  if (r == 0) {
    UserDialogDO user_dialog;
    user_dialog.user_id = uid;
    user_dialog.peer_id = peer_id;
    user_dialog.peer_type = peer_type;
    user_dialog.created_at = now;
    user_dialog.updated_at = now;
    
    r = user_dialog_dao.Create(user_dialog);
    if (r<0) {
      LOG(ERROR) << "SendMessage - Create error!!";
      // TODO(@benqi): 是否回滚？
      r = kErrDBError;
    }
  } else {
    // ERROR
  }

  // 反向
  // 检查会话是否存在
  r = user_dialog_dao.CheckExists(peer_id, uid, peer_type);
  if (r == 0) {
    UserDialogDO user_dialog;
    user_dialog.user_id = peer_id;
    user_dialog.peer_id = uid;
    user_dialog.peer_type = peer_type;
    user_dialog.created_at = now;
    user_dialog.updated_at = now;
    
    r = user_dialog_dao.Create(user_dialog);
    if (r<0) {
      LOG(ERROR) << "SendMessage - Create error!!";
      // TODO(@benqi): 是否回滚？
      r = kErrDBError;
      // break;
    }
  }

  return kErrOK;
}

// 创建群会话
int DialogModel::CreateIfNotExists(const std::list<std::string>& members, uint32_t peer_type, const std::string& peer_id) {
  // TODO(@benqi): 最好能有个地方能保证保证会话已经存在
  
  // 会话处理
  // 正向
  // 检查会话是否存在
  auto now = NowInMsecTime();
  auto& user_dialog_dao = UserDialogDAO::GetInstance();

  UserDialogDO user_dialog;
  user_dialog.peer_id = peer_id;
  user_dialog.peer_type = peer_type;
  user_dialog.created_at = now;
  user_dialog.updated_at = now;

  for (auto& uid : members) {
    int r = user_dialog_dao.CheckExists(uid, peer_id, peer_type);
    // TODO(@benqi): 出错
    if (r == 0) {
      user_dialog.user_id = uid;
      r = user_dialog_dao.Create(user_dialog);
      if (r<0) {
        LOG(ERROR) << "SendMessage - Create error!!";
        // TODO(@benqi): 是否回滚？
        r = kErrDBError;
      }
    } else {
      // ERROR
    }
  }
  
  return kErrOK;
}
