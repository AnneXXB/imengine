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

#ifndef DAL_SEQUENCE_DAO_H_
#define DAL_SEQUENCE_DAO_H_

#include "dal/sequence_do.h"

struct SequenceDAO : public BaseDAO {
  virtual ~SequenceDAO() = default;
  
  static SequenceDAO& GetInstance();

  virtual uint64_t GetNextID(const std::string& key) = 0;
  virtual uint64_t GetNextID2(const std::string& key) = 0;
};

#endif