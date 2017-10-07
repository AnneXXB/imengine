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

// TODO(@benqi): 使用zrpc-code-gen代码生成工具自动生成

#include "messenger/zrpc_photos_service.h"

#include "nebula/base/logger/glog_util.h"
#include "proto/api/error_codes.h"


int ZRpcPhotosService::photos_deletePhotos(const mtproto::TL_photos_deletePhotos& request, std::shared_ptr<mtproto::TLInt64Vector>& response) {
  LOG(ERROR) << "photos_deletePhotos not impl";
  return kErrNotImpl;
}

int ZRpcPhotosService::photos_getUserPhotos(const mtproto::TL_photos_getUserPhotos& request, std::shared_ptr<mtproto::photos_Photos>& response) {
  LOG(ERROR) << "photos_getUserPhotos not impl";
  return kErrNotImpl;
}

int ZRpcPhotosService::photos_updateProfilePhoto(const mtproto::TL_photos_updateProfilePhoto& request, std::shared_ptr<mtproto::UserProfilePhoto>& response) {
  LOG(ERROR) << "photos_updateProfilePhoto not impl";
  return kErrNotImpl;
}

int ZRpcPhotosService::photos_uploadProfilePhoto(const mtproto::TL_photos_uploadProfilePhoto& request, std::shared_ptr<mtproto::photos_Photo>& response) {
  LOG(ERROR) << "photos_uploadProfilePhoto not impl";
  return kErrNotImpl;
}
