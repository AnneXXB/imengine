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

#ifndef	MESSENGER_PHOTOS_SERVICE_IMPL_H_
#define	MESSENGER_PHOTOS_SERVICE_IMPL_H_

#include "messenger/zrpc_photos_service.h"

class PhotosServiceImpl : public ZRpcPhotosService {
public:
  PhotosServiceImpl() = default;
  ~PhotosServiceImpl() = default;
  
  // photos.deletePhotos#87cf7f2f id:Vector<InputPhoto> = Vector<long>;
  int photos_deletePhotos(const mtproto::TL_photos_deletePhotos& request, std::shared_ptr<mtproto::TLInt64Vector>& response) override;
  
  // photos.getUserPhotos#91cd32a8 user_id:InputUser offset:int max_id:long limit:int = photos.Photos;
  int photos_getUserPhotos(const mtproto::TL_photos_getUserPhotos& request, std::shared_ptr<mtproto::photos_Photos>& response) override;
  
  // photos.updateProfilePhoto#f0bb5152 id:InputPhoto = UserProfilePhoto;
  int photos_updateProfilePhoto(const mtproto::TL_photos_updateProfilePhoto& request, std::shared_ptr<mtproto::UserProfilePhoto>& response) override;
  
  // photos.uploadProfilePhoto#4f32c098 file:InputFile = photos.Photo;
  int photos_uploadProfilePhoto(const mtproto::TL_photos_uploadProfilePhoto& request, std::shared_ptr<mtproto::photos_Photo>& response) override;
};

#endif
