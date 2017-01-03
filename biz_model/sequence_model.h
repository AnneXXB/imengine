/*
 *  Copyright (c) 2016, https://github.com/nebula-im/imengine
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

#ifndef BIZ_MODEL_SEQUENCE_MODEL_H_
#define BIZ_MODEL_SEQUENCE_MODEL_H_

#include <string>
#include <list>
#include <google/protobuf/message.h>

class SequenceModel {
public:
  ~SequenceModel() = default;
  
  static SequenceModel& GetInstance();

  // int Create(const std::list<std::string>& uid_list, int update_header, const std::string& update_data);
  int DeliveryUpdateDataNotMe(uint64_t my_conn_id, const std::list<std::string>& uid_list, uint32_t update_header, const std::string& update_data);
  int DeliveryUpdateDataNotMe(uint64_t my_conn_id, const std::list<std::string>& uid_list, const google::protobuf::Message& message);
  uint64_t DeliveryUpdateDataNotMe(uint64_t my_conn_id, const std::string& uid, const google::protobuf::Message& message);
};

#endif
