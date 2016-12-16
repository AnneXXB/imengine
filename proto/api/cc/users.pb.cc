// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: users.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "users.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace zproto {

namespace {

const ::google::protobuf::Descriptor* User_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  User_reflection_ = NULL;
const ::google::protobuf::Descriptor* User_ExtEntry_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_users_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_users_2eproto() {
  protobuf_AddDesc_users_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "users.proto");
  GOOGLE_CHECK(file != NULL);
  User_descriptor_ = file->message_type(0);
  static const int User_offsets_[6] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, uid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, access_hash_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, nick_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, avatar_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, ext_),
  };
  User_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      User_descriptor_,
      User::default_instance_,
      User_offsets_,
      -1,
      -1,
      -1,
      sizeof(User),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(User, _is_default_instance_));
  User_ExtEntry_descriptor_ = User_descriptor_->nested_type(0);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_users_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      User_descriptor_, &User::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
        User_ExtEntry_descriptor_,
        ::google::protobuf::internal::MapEntry<
            ::std::string,
            ::zproto::RawArrayValue,
            ::google::protobuf::internal::WireFormatLite::TYPE_STRING,
            ::google::protobuf::internal::WireFormatLite::TYPE_MESSAGE,
            0>::CreateDefaultInstance(
                User_ExtEntry_descriptor_));
}

}  // namespace

void protobuf_ShutdownFile_users_2eproto() {
  delete User::default_instance_;
  delete User_reflection_;
}

void protobuf_AddDesc_users_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_users_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::zproto::protobuf_AddDesc_types_2eproto();
  ::zproto::protobuf_AddDesc_files_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\013users.proto\022\006zproto\032\013types.proto\032\013file"
    "s.proto\"\313\001\n\004User\022\013\n\003uid\030\001 \001(\t\022\023\n\013access_"
    "hash\030\002 \001(\003\022\014\n\004name\030\003 \001(\t\022\014\n\004nick\030\004 \001(\t\022\036"
    "\n\006avatar\030\005 \001(\0132\016.zproto.Avatar\022\"\n\003ext\030\006 "
    "\003(\0132\025.zproto.User.ExtEntry\032A\n\010ExtEntry\022\013"
    "\n\003key\030\001 \001(\t\022$\n\005value\030\002 \001(\0132\025.zproto.RawA"
    "rrayValue:\0028\001B(\n\027com.zchat.engine.zproto"
    "B\013ZProtoUsersH\002b\006proto3", 303);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "users.proto", &protobuf_RegisterTypes);
  User::default_instance_ = new User();
  User::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_users_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_users_2eproto {
  StaticDescriptorInitializer_users_2eproto() {
    protobuf_AddDesc_users_2eproto();
  }
} static_descriptor_initializer_users_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int User::kUidFieldNumber;
const int User::kAccessHashFieldNumber;
const int User::kNameFieldNumber;
const int User::kNickFieldNumber;
const int User::kAvatarFieldNumber;
const int User::kExtFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

User::User()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:zproto.User)
}

void User::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  avatar_ = const_cast< ::zproto::Avatar*>(&::zproto::Avatar::default_instance());
}

User::User(const User& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:zproto.User)
}

void User::SharedCtor() {
    _is_default_instance_ = false;
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  uid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  access_hash_ = GOOGLE_LONGLONG(0);
  name_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  nick_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  avatar_ = NULL;
  ext_.SetAssignDescriptorCallback(
      protobuf_AssignDescriptorsOnce);
  ext_.SetEntryDescriptor(
      &::zproto::User_ExtEntry_descriptor_);
}

User::~User() {
  // @@protoc_insertion_point(destructor:zproto.User)
  SharedDtor();
}

void User::SharedDtor() {
  uid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  name_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  nick_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != default_instance_) {
    delete avatar_;
  }
}

void User::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* User::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return User_descriptor_;
}

const User& User::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_users_2eproto();
  return *default_instance_;
}

User* User::default_instance_ = NULL;

User* User::New(::google::protobuf::Arena* arena) const {
  User* n = new User;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void User::Swap(User* other) {
  if (other == this) return;
  InternalSwap(other);
}
void User::InternalSwap(User* other) {
  GetReflection()->Swap(this, other);}

::google::protobuf::Metadata User::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = User_descriptor_;
  metadata.reflection = User_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// User

// optional string uid = 1;
void User::clear_uid() {
  uid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& User::uid() const {
  // @@protoc_insertion_point(field_get:zproto.User.uid)
  return uid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void User::set_uid(const ::std::string& value) {
  
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zproto.User.uid)
}
 void User::set_uid(const char* value) {
  
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zproto.User.uid)
}
 void User::set_uid(const char* value, size_t size) {
  
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zproto.User.uid)
}
 ::std::string* User::mutable_uid() {
  
  // @@protoc_insertion_point(field_mutable:zproto.User.uid)
  return uid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* User::release_uid() {
  // @@protoc_insertion_point(field_release:zproto.User.uid)
  
  return uid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void User::set_allocated_uid(::std::string* uid) {
  if (uid != NULL) {
    
  } else {
    
  }
  uid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), uid);
  // @@protoc_insertion_point(field_set_allocated:zproto.User.uid)
}

// optional int64 access_hash = 2;
void User::clear_access_hash() {
  access_hash_ = GOOGLE_LONGLONG(0);
}
 ::google::protobuf::int64 User::access_hash() const {
  // @@protoc_insertion_point(field_get:zproto.User.access_hash)
  return access_hash_;
}
 void User::set_access_hash(::google::protobuf::int64 value) {
  
  access_hash_ = value;
  // @@protoc_insertion_point(field_set:zproto.User.access_hash)
}

// optional string name = 3;
void User::clear_name() {
  name_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& User::name() const {
  // @@protoc_insertion_point(field_get:zproto.User.name)
  return name_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void User::set_name(const ::std::string& value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zproto.User.name)
}
 void User::set_name(const char* value) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zproto.User.name)
}
 void User::set_name(const char* value, size_t size) {
  
  name_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zproto.User.name)
}
 ::std::string* User::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:zproto.User.name)
  return name_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* User::release_name() {
  // @@protoc_insertion_point(field_release:zproto.User.name)
  
  return name_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void User::set_allocated_name(::std::string* name) {
  if (name != NULL) {
    
  } else {
    
  }
  name_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), name);
  // @@protoc_insertion_point(field_set_allocated:zproto.User.name)
}

// optional string nick = 4;
void User::clear_nick() {
  nick_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 const ::std::string& User::nick() const {
  // @@protoc_insertion_point(field_get:zproto.User.nick)
  return nick_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void User::set_nick(const ::std::string& value) {
  
  nick_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zproto.User.nick)
}
 void User::set_nick(const char* value) {
  
  nick_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zproto.User.nick)
}
 void User::set_nick(const char* value, size_t size) {
  
  nick_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zproto.User.nick)
}
 ::std::string* User::mutable_nick() {
  
  // @@protoc_insertion_point(field_mutable:zproto.User.nick)
  return nick_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 ::std::string* User::release_nick() {
  // @@protoc_insertion_point(field_release:zproto.User.nick)
  
  return nick_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
 void User::set_allocated_nick(::std::string* nick) {
  if (nick != NULL) {
    
  } else {
    
  }
  nick_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), nick);
  // @@protoc_insertion_point(field_set_allocated:zproto.User.nick)
}

// optional .zproto.Avatar avatar = 5;
bool User::has_avatar() const {
  return !_is_default_instance_ && avatar_ != NULL;
}
void User::clear_avatar() {
  if (GetArenaNoVirtual() == NULL && avatar_ != NULL) delete avatar_;
  avatar_ = NULL;
}
const ::zproto::Avatar& User::avatar() const {
  // @@protoc_insertion_point(field_get:zproto.User.avatar)
  return avatar_ != NULL ? *avatar_ : *default_instance_->avatar_;
}
::zproto::Avatar* User::mutable_avatar() {
  
  if (avatar_ == NULL) {
    avatar_ = new ::zproto::Avatar;
  }
  // @@protoc_insertion_point(field_mutable:zproto.User.avatar)
  return avatar_;
}
::zproto::Avatar* User::release_avatar() {
  // @@protoc_insertion_point(field_release:zproto.User.avatar)
  
  ::zproto::Avatar* temp = avatar_;
  avatar_ = NULL;
  return temp;
}
void User::set_allocated_avatar(::zproto::Avatar* avatar) {
  delete avatar_;
  avatar_ = avatar;
  if (avatar) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:zproto.User.avatar)
}

// map<string, .zproto.RawArrayValue> ext = 6;
int User::ext_size() const {
  return ext_.size();
}
void User::clear_ext() {
  ext_.Clear();
}
 const ::google::protobuf::Map< ::std::string, ::zproto::RawArrayValue >&
User::ext() const {
  // @@protoc_insertion_point(field_map:zproto.User.ext)
  return ext_.GetMap();
}
 ::google::protobuf::Map< ::std::string, ::zproto::RawArrayValue >*
User::mutable_ext() {
  // @@protoc_insertion_point(field_mutable_map:zproto.User.ext)
  return ext_.MutableMap();
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace zproto

// @@protoc_insertion_point(global_scope)
