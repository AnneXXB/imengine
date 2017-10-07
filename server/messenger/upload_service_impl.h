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

#ifndef	MESSENGER_UPLOAD_SERVICE_IMPL_H_
#define	MESSENGER_UPLOAD_SERVICE_IMPL_H_

#include "messenger/zrpc_upload_service.h"

class UploadServiceImpl : public ZRpcUploadService {
public:
  UploadServiceImpl() = default;
  ~UploadServiceImpl() = default;
  
  // upload.getCdnFile#2000bcc3 file_token:bytes offset:int limit:int = upload.CdnFile;
  int upload_getCdnFile(const mtproto::TL_upload_getCdnFile& request, std::shared_ptr<mtproto::upload_CdnFile>& response) override;
  
  // upload.getFile#e3a6cfb5 location:InputFileLocation offset:int limit:int = upload.File;
  int upload_getFile(const mtproto::TL_upload_getFile& request, std::shared_ptr<mtproto::upload_File>& response) override;
  
  // upload.getWebFile#24e6818d location:InputWebFileLocation offset:int limit:int = upload.WebFile;
  int upload_getWebFile(const mtproto::TL_upload_getWebFile& request, std::shared_ptr<mtproto::upload_WebFile>& response) override;
  
  // upload.reuploadCdnFile#2e7a2020 file_token:bytes request_token:bytes = Bool;
  int upload_reuploadCdnFile(const mtproto::TL_upload_reuploadCdnFile& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // upload.saveBigFilePart#de7b673d file_id:long file_part:int file_total_parts:int bytes:bytes = Bool;
  int upload_saveBigFilePart(const mtproto::TL_upload_saveBigFilePart& request, std::shared_ptr<mtproto::Bool>& response) override;
  
  // upload.saveFilePart#b304a621 file_id:long file_part:int bytes:bytes = Bool;
  int upload_saveFilePart(const mtproto::TL_upload_saveFilePart& request, std::shared_ptr<mtproto::Bool>& response) override;
};

#endif
