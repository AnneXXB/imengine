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

#ifndef BIZ_MODEL_SEQUENCE_MODEL_H_
#define BIZ_MODEL_SEQUENCE_MODEL_H_

#include <stdint.h>
#include <string>
#include <map>

class SequenceModel {
public:
  SequenceModel() = default;

  // uint32_t GetNextID(const uint64_t key);
  // uint32_t AsyGetNextID(const uint64_t key);
  uint64_t GetNextID(const std::string& key);

private:
  std::map<std::string, uint32_t> seqs_;
};


#endif
