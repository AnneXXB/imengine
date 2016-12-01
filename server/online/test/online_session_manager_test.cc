/*
 * Copyright 2016 Facebook, Inc.
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

#include "onlined/online_session_manager.h"

#include <iostream>

void OnlineSessionManagerTest() {
  
  // nebula::Initializer(&argc, &argv);
  
  auto onlines = OnlineSessionManager::GetInstance();
  
  std::cout << "add..." << std::endl;
  
  onlines->AddEntry(1, 1, 11, 111, 1111);
  onlines->AddEntry(1, 2, 11, 111, 1111);
  onlines->AddEntry(2, 3, 22, 222, 2222);
  onlines->AddEntry(2, 4, 22, 222, 2222);
  onlines->AddEntry(3, 5, 33, 333, 3333);
  onlines->AddEntry(3, 6, 33, 333, 3333);
  onlines->PrintDebug();
  
  std::cout << "query by conn_id 1" << std::endl;
  SessionEntry s2;
  onlines->LookupEntryBySessionID(1, 2, &s2);
  std::cout << s2.ToString() << std::endl;
  s2.state = 1;
  
  std::cout << "query by server_id 1" << std::endl;
  SessionEntryList sessions;
  onlines->LookupEntrysByServerID(1, &sessions);
  for (auto s : sessions) {
    std::cout << s.ToString() << std::endl;
  }
  
  std::cout << "query by app_id 22" << std::endl;
  sessions.clear();
  onlines->LookupEntrysByAppID(22, &sessions);
  for (auto s : sessions) {
    std::cout << s.ToString() << std::endl;
  }
  
  std::cout << "query by user_id 333" << std::endl;
  sessions.clear();
  onlines->LookupEntrysByUserID(1, 333, &sessions);
  for (auto s : sessions) {
    std::cout << s.ToString() << std::endl;
  }
  
  std::cout << "remove by session_id 1" << std::endl;
  onlines->RemoveEntryBySessionID(1, 1);
  onlines->PrintDebug();
  
  std::cout << "remove by server_id 2" << std::endl;
  onlines->RemoveEntrysByServerID(2);
  onlines->PrintDebug();
}

// #include "nebula/base/dynamic_converter.h"

#include "nebula/base/json/json.h"

#include <folly/json.h>

using namespace nebula;

struct Person {
  Person() {}
  Person(std::string n, int a) : name(n), age(a) {}
  std::string name;
  int age;
  
  META(name, age);
};

struct Token {
  Token() {}
  
  int id;
  std::string name;
};

namespace folly {
template <> struct DynamicConverter<Person> {
  static Person convert(const dynamic& d) {
    std::string name = convertTo<std::string>(d["name"]);
    int age = convertTo<int>(d["age"]);
    return Person(name, age);  }
};

template <> struct DynamicConstructor<Person> {
  static dynamic construct(const Person& x) {
    return dynamic::object("name", x.name)("age", x.age);
  }
};

//template <> struct DynamicConstructor<Token> {
//  static dynamic construct(const Token& x) {
//    return dynamic::object(x.id, x.name)("age", x.age);
//  }
//};

}

#include "nebula/net/engine/http_client.h"
#include <folly/io/async/EventBaseManager.h>

int main(int argc, char* argv[]) {
#if 0
  Person person = {"benqi", 42};
  //auto t = person.Meta();

  auto d1 = Marshal(person);
  std::cout << folly::toJson(d1) << std::endl;

  
//  std::vector<std::pair<int, int>> v;
//  v.push_back(std::make_pair(1, 1));
//  v.push_back(std::make_pair(2, 2));
//  v.push_back(std::make_pair(3, 3));
//  v.push_back(std::make_pair(4, 4));
//  
//  auto d1 = ToJsonDynamic(v);
//  std::cout << folly::toJson(d1) << std::endl;
//
///*
//  std::map<std::string, std::string> m;
//  m["a"] = "aa";
//  m["b"] = "bb";
//  m["c"] = "cc";
// */
  
  folly::dynamic d = folly::dynamic::object(1,1)(2,2)(3,3);
  
  typedef std::map<int, int> IntIntMap;
  
  auto a222 = Unmarshal<IntIntMap>(d);
  
  for (auto v : a222) {
    std::cout << v.first << " ==> " << v.second << std::endl;
  }
//  m[1] = 1; // {"a", 1};
//  m[2] = 2; // {"b", 2};
//  m[3] = 3; // {"c", 3};
  
//
//  auto d2 = ToJsonDynamic(m);
//  
//  std::cout << folly::toJson(d2) << std::endl;
#endif
  
  folly::EventBase evb;
  
  // auto evb = folly::EventManager::get()->getEventBase();
  
  // HttpClientGet(&evb, "http://www.baidu.com/", [](HttpClientReply& reply) {
  //  std::cout << reply.ToString() << std::endl;
  // });

  auto r = HttpClientSyncGet(&evb, "http://www.baidu.com/");
  if (r) {
    std::cout << r->ToString() << std::endl;
  }
  evb.loopForever();
  
  return 0;
}

