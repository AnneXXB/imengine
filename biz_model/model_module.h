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

#ifndef BIZ_MODEL_MODEL_MODULE_H_
#define BIZ_MODEL_MODEL_MODULE_H_

#include "biz_model/login_manager.h"
//#include "zaresd/model/department_manager.h"
#include "biz_model/user_manager.h"
//#include "zaresd/model/group_manager.h"
//#include "zaresd/model/relationship_manager.h"
#include "biz_model/message_manager.h"
//#include "zaresd/model/file_manager.h"
//#include "zaresd/model/counter_manager.h"
//#include "zaresd/model/audio_manager.h"
#include "biz_model/user_dialog_manager.h"
#include "biz_model/sequence_manager.h"

class ModelModule {
public:
  virtual ~ModelModule() {}

  virtual bool Initialize(const std::string& model_type) { return true; }
  virtual void Destroy() {}

//  //////////////////////////////////////////////////////////////////////////
  LoginManager* GetLoginManager() {
    return login_manager_;
  }
//  DepartmentManager* GetDepartmentManager() {
//    return department_manager_;
//  }
  UserManager* GetUserManager() {
    return user_manager_;
  }
//  GroupManager* GetGroupManager() {
//    return group_manager_;
//  }
//  RelationshipManager* GetRelationshipManager() {
//    return relationship_manager_;
//  }
  MessageManager* GetMessageManager() {
    return message_manager_;
  }
//  FileManager* GetFileManager() {
//    return file_manager_;
//  }
//  CounterManager* GetCounterManager() {
//    return counter_manager_;
//  }
//  AudioManager* GetAudioManager() {
//    return audio_manager_;
//  }

  SequenceManager* GetSequenceManager() {
    return sequence_manager_;
  }

  UserDialogManager* GetUserDialogManager() {
    return user_dialog_manager_;
  }
  

protected:
  ModelModule() = default;

  LoginManager* login_manager_{nullptr};
//  DepartmentManager* department_manager_;
  UserManager* user_manager_{nullptr};
//  GroupManager* group_manager_;
//  RelationshipManager* relationship_manager_;
  MessageManager* message_manager_{nullptr};
//  FileManager* file_manager_;
//  CounterManager* counter_manager_;
//  AudioManager* audio_manager_;
  SequenceManager* sequence_manager_{nullptr};
  
  UserDialogManager* user_dialog_manager_{nullptr};
};

#endif
