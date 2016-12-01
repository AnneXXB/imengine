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

#include "biz_model/model_main_manager.h"

#include "nebula/base/glog_util.h"

#include "biz_model/zares/zares_model_module.h"

static folly::Singleton<ModelMainManager> g_model_main_manager;

std::shared_ptr<ModelMainManager> ModelMainManager::GetInstance() {
  return g_model_main_manager.try_get();
}

bool ModelMainManager::Initialize(const std::string model_type) {
  if (model_type == "zares") {
    module_ = new ZAresModelModule();
    module_->Initialize(model_type);
  } else {
    // NOTREACHED() << "Invalid model_type " << model_type;
  }
  return true;
}

void ModelMainManager::Destroy() {
  if (module_) {
    delete module_;
    module_ = NULL;
  }
}

LoginManager* ModelMainManager::GetLoginManager() {
  DCHECK(module_);
  return module_->GetLoginManager();
}
//DepartmentManager* ModelMainManager::GetDepartmentManager() {
//  DCHECK(module_);
//  return module_->GetDepartmentManager();
//}

UserManager* ModelMainManager::GetUserManager() {
  DCHECK(module_);
  return module_->GetUserManager();
}

//GroupManager* ModelMainManager::GetGroupManager() {
//  DCHECK(module_);
//  return module_->GetGroupManager();
//}
//RelationshipManager* ModelMainManager::GetRelationshipManager() {
//  DCHECK(module_);
//  return module_->GetRelationshipManager();
//}
MessageManager* ModelMainManager::GetMessageManager() {
  DCHECK(module_);
  return module_->GetMessageManager();
}
//FileManager* ModelMainManager::GetFileManager() {
//  DCHECK(module_);
//  return module_->GetFileManager();
//}
//CounterManager* ModelMainManager::GetCounterManager() {
//  DCHECK(module_);
//  return module_->GetCounterManager();
//}
//AudioManager* ModelMainManager::GetAudioManager() {
//  DCHECK(module_);
//  return module_->GetAudioManager();
//}

SequenceManager* ModelMainManager::GetSequenceManager() {
  DCHECK(module_);
  return module_->GetSequenceManager();
}

