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

#include "messenger/upload_service_impl.h"

#include "nebula/net/rpc/zrpc_service_util.h"
#include "nebula/base/time_util.h"
#include "nebula/base/id_util.h"

#include "proto/api/error_codes.h"

int UploadServiceImpl::upload_getCdnFile(const mtproto::TL_upload_getCdnFile& request, std::shared_ptr<mtproto::upload_CdnFile>& response) {
  LOG(INFO) << "upload_getCdnFile - " << request.ToString();
  
  return kErrNotImpl;
}

int UploadServiceImpl::upload_getFile(const mtproto::TL_upload_getFile& request, std::shared_ptr<mtproto::upload_File>& response) {
  LOG(INFO) << "upload_getFile - " << request.ToString();
  
  return kErrNotImpl;
}

int UploadServiceImpl::upload_getWebFile(const mtproto::TL_upload_getWebFile& request, std::shared_ptr<mtproto::upload_WebFile>& response) {
  LOG(INFO) << "upload_getWebFile - " << request.ToString();
  
  return kErrNotImpl;
}

int UploadServiceImpl::upload_reuploadCdnFile(const mtproto::TL_upload_reuploadCdnFile& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "upload_reuploadCdnFile - " << request.ToString();
  
  return kErrNotImpl;
}

int UploadServiceImpl::upload_saveBigFilePart(const mtproto::TL_upload_saveBigFilePart& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "upload_saveBigFilePart - " << request.ToString();
  
  return kErrNotImpl;
}

int UploadServiceImpl::upload_saveFilePart(const mtproto::TL_upload_saveFilePart& request, std::shared_ptr<mtproto::Bool>& response) {
  LOG(INFO) << "upload_saveFilePart - " << request.ToString();
  
  return kErrNotImpl;
}
