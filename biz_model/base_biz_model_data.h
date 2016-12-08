/**
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

#ifndef BIZ_MODEL_BASE_BIZ_MODEL_DATA_H_
#define BIZ_MODEL_BASE_BIZ_MODEL_DATA_H_

#include <string>
#include <list>

// #include "biz_model/biz_models.pb.h"

/*
enum BizResultCode {
  KBizResultCode_OK = 0,
  KBizResultCode_FLOOD_WAIT,
  KBizResultCode_ERROR,
  KBizResultCode_INTERNAL_ERROR,
};

template <typename T>
struct BizResult {
  BizResult(int _code, std::shared_ptr<T> _val)
    : code(_code), val(_val) {}

  explicit BizResult(int _code)
    : code(_code) {}

  BizResult(const BizResult& other) {
    code = other.code;
    val = other.val;
  }
  
  BizResult& operator=(const BizResult& other) {
    code = other.code;
    val = other.val;
    return *this;
  }
  
  int GetCode() const { return code; }
  
  /////////////////////////////////////////////////////////////////////////////////////////
  // 通过指针方式直接使用MESSAGE
  T& operator*() {
    CHECK(val.ger());
    return *val;
  }
  
  const T& operator*() const {
    CHECK(val.get());
    return *val;
  }
  
  std::shared_ptr<T> operator->() {
    return val;
  }
  
  const std::shared_ptr<T>& operator->() const {
    return val;
  }
  
  std::shared_ptr<T> get() {
    return val;
  }
  
  const std::shared_ptr<T>& get() const {
    return val;
  }

  
  int code;
  std::shared_ptr<T> val;
};

template<typename T>
BizResult<T> make_biz_result(int code, std::shared_ptr<T> r) {
  return BizResult<T>(code, r);
}

template<typename T>
BizResult<T> make_biz_result(std::shared_ptr<T> r) {
  return BizResult<T>(KBizResultCode_OK, r);
}

template<typename T>
BizResult<T> make_biz_result(int code) {
  return BizResult<T>(code);
}
*/

struct AppEntity {
  uint32_t app_id;
  uint32_t org_id;
  std::string app_name;
  std::string product_name;
  std::string desc;
  int status;
  uint32_t created_at;
  uint32_t updated_at;
};

struct AppKeyEntity {
  uint32_t app_id;
  std::string app_key;
  std::string app_token;
  int status;
};

struct UserEntity {
  uint32_t id;
  uint32_t app_id;
  std::string user_id;
  std::string avatar;
  std::string nick;
  int status;
  uint32_t created_at;
  uint32_t updated_at;
};

/////////////////////////////////////////////////////////////////////////////
// 会话ID
struct ConversationID {
  std::string sender_user_id;
  std::string peer_id;
  uint32_t peer_type;
};

struct MessageEntity {
  uint64_t id;
  std::string user_id;
  uint64_t message_seq;
  uint64_t message_id;
  std::string sender_user_id; // 发送方
  std::string peer_id;
  uint32_t peer_type;
  
  uint64_t client_message_id;
  uint64_t message_peer_seq;
  uint32_t message_content_type;
  std::string message_content_data;
  std::string passthrough_data;
  
  uint32_t status;
  uint64_t created_at;
  uint64_t updated_at;
};
typedef std::shared_ptr<MessageEntity> MessageEntityPtr;
typedef std::list<MessageEntityPtr> MessageEntityList;

struct UserDialogEntity {
  uint64_t id;
  std::string user_id;
  std::string peer_id;
  uint32_t peer_type;
  uint32_t status;
  uint64_t created_at;
  uint64_t updated_at;
};

typedef std::shared_ptr<UserDialogEntity> UserDialogEntityPtr;
typedef std::list<UserDialogEntityPtr> UserDialogEntityList;

/*
  struct UserID {
    uint32_t app_id;
    uint32_t user_id;
  };

  // 用户信息
  struct UserInfo {
    UserID      user_id;
    std::string nick;
    std::string avatar;
    
    // META(app_id, user_id, nick, avatar);
  };

  // 会话ID
  struct ConversationID {
    uint32_t sender_user_id;
    uint32_t peer_id;
    uint32_t peer_type;
  };
 */

//typedef std::shared_ptr<UserInfo> UserInfoPtr;
//template<class T>
//using BizResultPair = FuncFactoryManager<F, K>::RegisterTemplate;

// using template<class T> BizResultPair = std::pair<int, std::shared_ptr<T>>;

struct GroupEntity {
  uint64_t id;
  uint32_t app_id{1};
  std::string group_id;
  std::string creator_user_id;
  uint64_t client_group_id;
  std::string title;
  std::string avatar;
  std::string topic;
  std::string about;
  int status{0};
  uint64_t created_at;
  uint64_t updated_at;
  std::string title_changer_user_id;
  uint64_t title_changer_at{0};
  std::string avatar_changer_user_id;
  uint64_t avatar_changer_at{0};
};
typedef std::shared_ptr<GroupEntity> GroupEntityPtr;

struct GroupMemberEntity {
  uint64_t id;
  uint32_t app_id{1};
  std::string group_id;
  std::string user_id;
  int is_admin{0};
  int status{0};
  uint64_t invited_at;
  std::string inviter_user_id;
  uint64_t joined_at;
  uint64_t created_at;
  uint64_t updated_at;
};
typedef std::shared_ptr<GroupMemberEntity> GroupMemberEntityPtr;
typedef std::list<GroupMemberEntityPtr> GroupMemberEntityList;

#endif
