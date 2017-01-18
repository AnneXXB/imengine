/*
 * Copyright 2017 Facebook, Inc.
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

#include "core/checksum.h"

#include <algorithm>
#include <stdexcept>
#include "core/crc.hpp"

// 移除硬件实现部分

namespace {
  
uint32_t crc32c_sw(const uint8_t *data, size_t nbytes,
                   uint32_t startingChecksum) {
  
  // Reverse the bits in the starting checksum so they'll be in the
  // right internal format for Boost's CRC engine.
  //     O(1)-time, branchless bit reversal algorithm from
  //     http://graphics.stanford.edu/~seander/bithacks.html
  startingChecksum = ((startingChecksum >> 1) & 0x55555555) |
  ((startingChecksum & 0x55555555) << 1);
  startingChecksum = ((startingChecksum >> 2) & 0x33333333) |
  ((startingChecksum & 0x33333333) << 2);
  startingChecksum = ((startingChecksum >> 4) & 0x0f0f0f0f) |
  ((startingChecksum & 0x0f0f0f0f) << 4);
  startingChecksum = ((startingChecksum >> 8) & 0x00ff00ff) |
  ((startingChecksum & 0x00ff00ff) << 8);
  startingChecksum = (startingChecksum >> 16) |
  (startingChecksum << 16);
  
  static const uint32_t CRC32C_POLYNOMIAL = 0x1EDC6F41;
  boost::crc_optimal<32, CRC32C_POLYNOMIAL, ~0U, 0, true, true> sum(
                                                                    startingChecksum);
  sum.process_bytes(data, nbytes);
  return sum.checksum();
}
  
} // folly::detail
  
uint32_t crc32c(const uint8_t *data, size_t nbytes,
                uint32_t startingChecksum) {
  return crc32c_sw(data, nbytes, startingChecksum);
}

