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

#ifndef CORE_CORE_SHORTLINK_PACKER_H_
#define CORE_CORE_SHORTLINK_PACKER_H_

#include "mars/comm/http.h"

class AutoBuffer;
void shortlink_pack(const std::string& _url, const std::map<std::string, std::string>& _headers, const AutoBuffer& _body, AutoBuffer& _out_buff);

#endif //CORE_CORE_SHORTLINK_PACKER_H_
