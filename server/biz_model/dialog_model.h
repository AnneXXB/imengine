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

#ifndef BIZ_MODEL_DIALOG_MODEL_H_
#define BIZ_MODEL_DIALOG_MODEL_H_

#include <string>
#include <list>

class DialogModel {
public:
  ~DialogModel() = default;
  
  static DialogModel& GetInstance();
  
  // 创建私聊双向会话
  int CreateIfNotExists(const std::string& uid, uint32_t peer_type, const std::string& peer_id);
  
  // 创建群会话
  int CreateIfNotExists(const std::list<std::string>& members, uint32_t peer_type, const std::string& peer_id);
};

#endif
