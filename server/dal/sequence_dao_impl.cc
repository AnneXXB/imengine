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

#include <folly/Conv.h>

#include "nebula/base/time_util.h"
#include "nebula/redis_client/redis_conn_pool.h"
#include "dal/seq_updates_ngen_dao.h"

// #include "nebula/base/id_util.h"

SequenceDAO& SequenceDAO::GetInstance() {
  static SequenceDAOImpl impl;
  return impl;
}

// TODO(@benqi):
//  使用数据库和REDIS获取sequence
//  redis: sequence
//  暂时不考虑DB等异常处理
uint64_t SequenceDAOImpl::GetNextID(const std::string& key) {
  std::string seq_key = "seq_updates_ngen_" + key;
  // 1. sequence
  auto pool = GetRedisConnPool("sequence");
  ScopedRedisConn conn(pool);
  auto seq = conn->incr(seq_key);
  if (seq == -1) {
    return seq;
  }

  SeqUpdatesNgenDO seq_updates_ngen_do;
  seq_updates_ngen_do.user_id = key;
  seq_updates_ngen_do.timestamp = NowInMsecTime();
  seq_updates_ngen_do.seq = seq;

  auto& seq_updates_ngen_dao = SeqUpdatesNgenDAO::GetInstance();
  
  // 使用seq==1做为哨兵减少DB和REDIS操作
  if (seq == 1) {
    // seq为1，有两种情况:
    // 1. 没有指定key的seq，第一次生成seq，DB也无纪录
    // 2. redis重新启动，DB里可能已经有值

    seq_updates_ngen_do.seq = seq_updates_ngen_dao.GetSequence(key);
    if (seq_updates_ngen_do.seq > 0) {
      // db有记录
      seq_updates_ngen_do.seq++;
      
      // 重新设置redis
      conn->set(seq_key, folly::to<std::string>(seq_updates_ngen_do.seq));
    } else {
      seq_updates_ngen_do.seq = 1;
    }
  }
  
  // 更新数据库
  seq_updates_ngen_dao.Upsert(seq_updates_ngen_do);
  return seq_updates_ngen_do.seq;
}
