/*
 *  Copyright (c) 2016, https://github.com/nebula-im
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

// TODO(@benqi): 使用zrpc-code-gen代码生成工具自动生成服务框架代码

#include "messenger/photos_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int PhotosServiceImpl::photos_deletePhotos(const mtproto::TL_photos_deletePhotos& request, std::shared_ptr<mtproto::TLInt64Vector>& response) {
  LOG(INFO) << "photos_deletePhotos - " << request.ToString();
  
  return kErrNotImpl;
}

int PhotosServiceImpl::photos_getUserPhotos(const mtproto::TL_photos_getUserPhotos& request, std::shared_ptr<mtproto::photos_Photos>& response) {
  LOG(INFO) << "photos_getUserPhotos - " << request.ToString();
  
  return kErrNotImpl;
}

int PhotosServiceImpl::photos_updateProfilePhoto(const mtproto::TL_photos_updateProfilePhoto& request, std::shared_ptr<mtproto::UserProfilePhoto>& response) {
  LOG(INFO) << "photos_updateProfilePhoto - " << request.ToString();
  
  return kErrNotImpl;
}

int PhotosServiceImpl::photos_uploadProfilePhoto(const mtproto::TL_photos_uploadProfilePhoto& request, std::shared_ptr<mtproto::photos_Photo>& response) {
  LOG(INFO) << "photos_uploadProfilePhoto - " << request.ToString();
  
  return kErrNotImpl;
}
