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

#include "dal/sequence_dao_impl.h"

#include "nebula/base/id_util.h"

SequenceDAO& SequenceDAO::GetInstance() {
  static SequenceDAOImpl impl;
  return impl;
}

// TODO(@benqi):
//  先用snowflake算法跑通流程
uint64_t SequenceDAOImpl::GetNextID(const std::string& key) {
  return GetNextIDBySnowflake();
}
