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

#ifndef BIZ_MODEL_MODEL_MAIN_MANAGER_H_
#define BIZ_MODEL_MODEL_MAIN_MANAGER_H_

// #include "base/memory/singleton.h"
#include <folly/Singleton.h>

#include "biz_model/model_module.h"

// 数据存储有可能不仅仅直接访问mysql，比如有人提出来使用Atlas(360)，甚至可以采用其它的数据库(MongoDB等)，
// 故model提供一些接口，
// 能以插件方式实现不同的数据访问
class ModelMainManager {
public:
  ~ModelMainManager() {
    Destroy();
  }

  static std::shared_ptr<ModelMainManager> GetInstance();

  bool Initialize(const std::string model_type);
  void Destroy();

  LoginManager* GetLoginManager();
//  DepartmentManager* GetDepartmentManager();
  UserManager* GetUserManager();
//  GroupManager* GetGroupManager();
//  RelationshipManager* GetRelationshipManager();
  MessageManager* GetMessageManager();
//  FileManager* GetFileManager();
//  CounterManager* GetCounterManager();
//  AudioManager* GetAudioManager();
  SequenceManager* GetSequenceManager();
  UserDialogManager* GetUserDialogManager();

private:
  friend class folly::Singleton<ModelMainManager>;

  ModelMainManager() = default;

protected:
  ModelModule* module_{nullptr};
};

#endif

