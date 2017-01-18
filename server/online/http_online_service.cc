/*
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

#include "online/http_online_service.h"

#include <folly/dynamic.h>
#include <folly/json.h>

#include "nebula/net/handler/http/http_request_handler.h"

#include "online/online_session_manager.h"

REGISTER_HTTP_HANDLER(StatusHttpHandler, "/query", Query);

/*
 查询用户状态
 get请求：
 http://status.nebulaim.com:15001/query?uid=xxx
 返回数据结构：
 {
  [
    {
      "server_id": xxx, // gate_server编号
      "app_id": xxx,		// app_id
      "user_id": xxx,   // 用户id
      "conn_id": xxx,   // 连接id
      "status": xxx     // 状态
    }
	]
 }
 */

void Query(const proxygen::HTTPMessage& headers, folly::IOBufQueue* body, proxygen::ResponseBuilder* r) {
  std::string uids = headers.getDecodedQueryParam("uids");
  std::string app_id = headers.getDecodedQueryParam("app_id");
  
  std::vector<folly::StringPiece> v;
  folly::split(",", uids, v);

  std::list<std::string> app_user_id_list;
  
  for (auto& uid : v) {
    std::string app_user_id = uid.str() + "@" + app_id;
    app_user_id_list.push_back(app_user_id);
  }
  
  SessionEntryList sessions;
  auto online_manager = OnlineSessionManager::GetInstance();
  online_manager->LookupEntrysByUserIDList(app_user_id_list, &sessions);
  
  folly::dynamic d = folly::dynamic::array;
  // object();

  for (auto& v : sessions) {
    folly::dynamic d2 = folly::dynamic::object();
    d2["app_id"] = v.app_id;
    d2["user_id"] = v.user_id;
    d2["server_id"] = v.server_id;
    d2["conn_id"] = v.session_id;
    d2["status"] = 1;

    d.push_back(d2);
  }
  auto json = folly::toJson(d);
  json.push_back('\n');
  std::unique_ptr<folly::IOBuf> json_string = folly::IOBuf::copyBuffer(json.c_str(), json.length());
  
  LOG(INFO) << "Query - query result: " << json;
  
  r->header("Content-Type", "application/json;charset=utf-8").body(std::move(json_string));
}

