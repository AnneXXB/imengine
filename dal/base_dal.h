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

#ifndef IMENGINGE_DAL_BASE_DAL_H_
#define IMENGINGE_DAL_BASE_DAL_H_

#include <list>
#include <string>

#include <folly/Format.h>

#include "nebula/base/reflection_util.h"
#include "nebula/storage/storage_util.h"

///////////////////////////////////////////////////////////////////////
struct BaseDO {
  virtual ~BaseDO() = default;
  
  virtual std::string ToString() const {
    return "";
  }
};

///////////////////////////////////////////////////////////////////////
// typedef int64_t DAOResultCode;

struct BaseDAO {
  virtual ~BaseDAO() = default;
};

///////////////////////////////////////////////////////////////////////
// tuple's QueryAnswer访问器
template<std::size_t I = 0, typename Tuple>
typename std::enable_if<
    I == std::tuple_size<Tuple>::value
  >::type FromQueryAnswer(const Tuple& t, db::QueryAnswer& answ) {
}

template<std::size_t I = 0, typename Tuple>
typename std::enable_if<
    I < std::tuple_size<Tuple>::value
  >::type FromQueryAnswer(const Tuple& t, db::QueryAnswer& answ) {

  auto fld = std::get<I>(t);
  answ.GetColumn(fld.first, &fld.second);
  FromQueryAnswer<I + 1>(t, answ);
}

#endif
