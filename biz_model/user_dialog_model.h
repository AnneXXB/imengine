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

#ifndef BIZ_MODEL_USER_DIALOG_MODEL_H_
#define BIZ_MODEL_USER_DIALOG_MODEL_H_

#include "nebula/storage/storage_util.h"
#include "biz_model/base_biz_model_data.h"

//////////////////////////////////////////////////////////////////////////////////////////
struct CreateUserDialog : public BaseSqlQuery {
  CreateUserDialog(UserDialogEntity& _dialog)
    : dialog(_dialog) {}
  
  bool SerializeToQuery(std::string& query_string) const override;
  
  UserDialogEntity& dialog;
};

//////////////////////////////////////////////////////////////////////////////////////////
struct LoadUserDialogs : public QueryWithResult {
  LoadUserDialogs(UserDialogEntity& _dialog)
    : dialog(_dialog) {}
  
  bool SerializeToQuery(std::string& query_string) const override;
  
  UserDialogEntity& dialog;
};

#endif // BIZ_MODEL_USER_DIALOG_MODEL_H_
