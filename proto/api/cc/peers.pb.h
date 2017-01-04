// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: peers.proto

#ifndef PROTOBUF_peers_2eproto__INCLUDED
#define PROTOBUF_peers_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3001000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3001000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace zproto {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_peers_2eproto();
void protobuf_InitDefaults_peers_2eproto();
void protobuf_AssignDesc_peers_2eproto();
void protobuf_ShutdownFile_peers_2eproto();

class GroupOutPeer;
class OutPeer;
class Peer;
class UserOutPeer;

enum PeerType {
  PEER_TYPE_PRIVATE = 0,
  PEER_TYPE_GROUP = 1,
  PEER_TYPE_ENCRYPTED_PRIVATE = 2,
  PeerType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  PeerType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool PeerType_IsValid(int value);
const PeerType PeerType_MIN = PEER_TYPE_PRIVATE;
const PeerType PeerType_MAX = PEER_TYPE_ENCRYPTED_PRIVATE;
const int PeerType_ARRAYSIZE = PeerType_MAX + 1;

const ::google::protobuf::EnumDescriptor* PeerType_descriptor();
inline const ::std::string& PeerType_Name(PeerType value) {
  return ::google::protobuf::internal::NameOfEnum(
    PeerType_descriptor(), value);
}
inline bool PeerType_Parse(
    const ::std::string& name, PeerType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<PeerType>(
    PeerType_descriptor(), name, value);
}
// ===================================================================

class Peer : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.Peer) */ {
 public:
  Peer();
  virtual ~Peer();

  Peer(const Peer& from);

  inline Peer& operator=(const Peer& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Peer& default_instance();

  static const Peer* internal_default_instance();

  void Swap(Peer* other);

  // implements Message ----------------------------------------------

  inline Peer* New() const { return New(NULL); }

  Peer* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Peer* other);
  void UnsafeMergeFrom(const Peer& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .zproto.PeerType type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::zproto::PeerType type() const;
  void set_type(::zproto::PeerType value);

  // optional string id = 2;
  void clear_id();
  static const int kIdFieldNumber = 2;
  const ::std::string& id() const;
  void set_id(const ::std::string& value);
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  ::std::string* mutable_id();
  ::std::string* release_id();
  void set_allocated_id(::std::string* id);

  // @@protoc_insertion_point(class_scope:zproto.Peer)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr id_;
  int type_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_peers_2eproto_impl();
  friend void  protobuf_AddDesc_peers_2eproto_impl();
  friend void protobuf_AssignDesc_peers_2eproto();
  friend void protobuf_ShutdownFile_peers_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<Peer> Peer_default_instance_;

// -------------------------------------------------------------------

class OutPeer : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.OutPeer) */ {
 public:
  OutPeer();
  virtual ~OutPeer();

  OutPeer(const OutPeer& from);

  inline OutPeer& operator=(const OutPeer& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const OutPeer& default_instance();

  static const OutPeer* internal_default_instance();

  void Swap(OutPeer* other);

  // implements Message ----------------------------------------------

  inline OutPeer* New() const { return New(NULL); }

  OutPeer* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(OutPeer* other);
  void UnsafeMergeFrom(const OutPeer& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .zproto.PeerType type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::zproto::PeerType type() const;
  void set_type(::zproto::PeerType value);

  // optional string id = 2;
  void clear_id();
  static const int kIdFieldNumber = 2;
  const ::std::string& id() const;
  void set_id(const ::std::string& value);
  void set_id(const char* value);
  void set_id(const char* value, size_t size);
  ::std::string* mutable_id();
  ::std::string* release_id();
  void set_allocated_id(::std::string* id);

  // optional int64 access_hash = 3;
  void clear_access_hash();
  static const int kAccessHashFieldNumber = 3;
  ::google::protobuf::int64 access_hash() const;
  void set_access_hash(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:zproto.OutPeer)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr id_;
  ::google::protobuf::int64 access_hash_;
  int type_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_peers_2eproto_impl();
  friend void  protobuf_AddDesc_peers_2eproto_impl();
  friend void protobuf_AssignDesc_peers_2eproto();
  friend void protobuf_ShutdownFile_peers_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<OutPeer> OutPeer_default_instance_;

// -------------------------------------------------------------------

class UserOutPeer : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.UserOutPeer) */ {
 public:
  UserOutPeer();
  virtual ~UserOutPeer();

  UserOutPeer(const UserOutPeer& from);

  inline UserOutPeer& operator=(const UserOutPeer& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const UserOutPeer& default_instance();

  static const UserOutPeer* internal_default_instance();

  void Swap(UserOutPeer* other);

  // implements Message ----------------------------------------------

  inline UserOutPeer* New() const { return New(NULL); }

  UserOutPeer* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(UserOutPeer* other);
  void UnsafeMergeFrom(const UserOutPeer& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string uid = 1;
  void clear_uid();
  static const int kUidFieldNumber = 1;
  const ::std::string& uid() const;
  void set_uid(const ::std::string& value);
  void set_uid(const char* value);
  void set_uid(const char* value, size_t size);
  ::std::string* mutable_uid();
  ::std::string* release_uid();
  void set_allocated_uid(::std::string* uid);

  // optional int64 access_hash = 2;
  void clear_access_hash();
  static const int kAccessHashFieldNumber = 2;
  ::google::protobuf::int64 access_hash() const;
  void set_access_hash(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:zproto.UserOutPeer)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr uid_;
  ::google::protobuf::int64 access_hash_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_peers_2eproto_impl();
  friend void  protobuf_AddDesc_peers_2eproto_impl();
  friend void protobuf_AssignDesc_peers_2eproto();
  friend void protobuf_ShutdownFile_peers_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<UserOutPeer> UserOutPeer_default_instance_;

// -------------------------------------------------------------------

class GroupOutPeer : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.GroupOutPeer) */ {
 public:
  GroupOutPeer();
  virtual ~GroupOutPeer();

  GroupOutPeer(const GroupOutPeer& from);

  inline GroupOutPeer& operator=(const GroupOutPeer& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GroupOutPeer& default_instance();

  static const GroupOutPeer* internal_default_instance();

  void Swap(GroupOutPeer* other);

  // implements Message ----------------------------------------------

  inline GroupOutPeer* New() const { return New(NULL); }

  GroupOutPeer* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(GroupOutPeer* other);
  void UnsafeMergeFrom(const GroupOutPeer& from);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string group_id = 1;
  void clear_group_id();
  static const int kGroupIdFieldNumber = 1;
  const ::std::string& group_id() const;
  void set_group_id(const ::std::string& value);
  void set_group_id(const char* value);
  void set_group_id(const char* value, size_t size);
  ::std::string* mutable_group_id();
  ::std::string* release_group_id();
  void set_allocated_group_id(::std::string* group_id);

  // optional int64 access_hash = 2;
  void clear_access_hash();
  static const int kAccessHashFieldNumber = 2;
  ::google::protobuf::int64 access_hash() const;
  void set_access_hash(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:zproto.GroupOutPeer)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr group_id_;
  ::google::protobuf::int64 access_hash_;
  mutable int _cached_size_;
  friend void  protobuf_InitDefaults_peers_2eproto_impl();
  friend void  protobuf_AddDesc_peers_2eproto_impl();
  friend void protobuf_AssignDesc_peers_2eproto();
  friend void protobuf_ShutdownFile_peers_2eproto();

  void InitAsDefaultInstance();
};
extern ::google::protobuf::internal::ExplicitlyConstructed<GroupOutPeer> GroupOutPeer_default_instance_;

// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Peer

// optional .zproto.PeerType type = 1;
inline void Peer::clear_type() {
  type_ = 0;
}
inline ::zproto::PeerType Peer::type() const {
  // @@protoc_insertion_point(field_get:zproto.Peer.type)
  return static_cast< ::zproto::PeerType >(type_);
}
inline void Peer::set_type(::zproto::PeerType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:zproto.Peer.type)
}

// optional string id = 2;
inline void Peer::clear_id() {
  id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Peer::id() const {
  // @@protoc_insertion_point(field_get:zproto.Peer.id)
  return id_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Peer::set_id(const ::std::string& value) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zproto.Peer.id)
}
inline void Peer::set_id(const char* value) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zproto.Peer.id)
}
inline void Peer::set_id(const char* value, size_t size) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zproto.Peer.id)
}
inline ::std::string* Peer::mutable_id() {
  
  // @@protoc_insertion_point(field_mutable:zproto.Peer.id)
  return id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Peer::release_id() {
  // @@protoc_insertion_point(field_release:zproto.Peer.id)
  
  return id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Peer::set_allocated_id(::std::string* id) {
  if (id != NULL) {
    
  } else {
    
  }
  id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), id);
  // @@protoc_insertion_point(field_set_allocated:zproto.Peer.id)
}

inline const Peer* Peer::internal_default_instance() {
  return &Peer_default_instance_.get();
}
// -------------------------------------------------------------------

// OutPeer

// optional .zproto.PeerType type = 1;
inline void OutPeer::clear_type() {
  type_ = 0;
}
inline ::zproto::PeerType OutPeer::type() const {
  // @@protoc_insertion_point(field_get:zproto.OutPeer.type)
  return static_cast< ::zproto::PeerType >(type_);
}
inline void OutPeer::set_type(::zproto::PeerType value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:zproto.OutPeer.type)
}

// optional string id = 2;
inline void OutPeer::clear_id() {
  id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& OutPeer::id() const {
  // @@protoc_insertion_point(field_get:zproto.OutPeer.id)
  return id_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void OutPeer::set_id(const ::std::string& value) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zproto.OutPeer.id)
}
inline void OutPeer::set_id(const char* value) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zproto.OutPeer.id)
}
inline void OutPeer::set_id(const char* value, size_t size) {
  
  id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zproto.OutPeer.id)
}
inline ::std::string* OutPeer::mutable_id() {
  
  // @@protoc_insertion_point(field_mutable:zproto.OutPeer.id)
  return id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* OutPeer::release_id() {
  // @@protoc_insertion_point(field_release:zproto.OutPeer.id)
  
  return id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void OutPeer::set_allocated_id(::std::string* id) {
  if (id != NULL) {
    
  } else {
    
  }
  id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), id);
  // @@protoc_insertion_point(field_set_allocated:zproto.OutPeer.id)
}

// optional int64 access_hash = 3;
inline void OutPeer::clear_access_hash() {
  access_hash_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 OutPeer::access_hash() const {
  // @@protoc_insertion_point(field_get:zproto.OutPeer.access_hash)
  return access_hash_;
}
inline void OutPeer::set_access_hash(::google::protobuf::int64 value) {
  
  access_hash_ = value;
  // @@protoc_insertion_point(field_set:zproto.OutPeer.access_hash)
}

inline const OutPeer* OutPeer::internal_default_instance() {
  return &OutPeer_default_instance_.get();
}
// -------------------------------------------------------------------

// UserOutPeer

// optional string uid = 1;
inline void UserOutPeer::clear_uid() {
  uid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& UserOutPeer::uid() const {
  // @@protoc_insertion_point(field_get:zproto.UserOutPeer.uid)
  return uid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserOutPeer::set_uid(const ::std::string& value) {
  
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zproto.UserOutPeer.uid)
}
inline void UserOutPeer::set_uid(const char* value) {
  
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zproto.UserOutPeer.uid)
}
inline void UserOutPeer::set_uid(const char* value, size_t size) {
  
  uid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zproto.UserOutPeer.uid)
}
inline ::std::string* UserOutPeer::mutable_uid() {
  
  // @@protoc_insertion_point(field_mutable:zproto.UserOutPeer.uid)
  return uid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* UserOutPeer::release_uid() {
  // @@protoc_insertion_point(field_release:zproto.UserOutPeer.uid)
  
  return uid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void UserOutPeer::set_allocated_uid(::std::string* uid) {
  if (uid != NULL) {
    
  } else {
    
  }
  uid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), uid);
  // @@protoc_insertion_point(field_set_allocated:zproto.UserOutPeer.uid)
}

// optional int64 access_hash = 2;
inline void UserOutPeer::clear_access_hash() {
  access_hash_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 UserOutPeer::access_hash() const {
  // @@protoc_insertion_point(field_get:zproto.UserOutPeer.access_hash)
  return access_hash_;
}
inline void UserOutPeer::set_access_hash(::google::protobuf::int64 value) {
  
  access_hash_ = value;
  // @@protoc_insertion_point(field_set:zproto.UserOutPeer.access_hash)
}

inline const UserOutPeer* UserOutPeer::internal_default_instance() {
  return &UserOutPeer_default_instance_.get();
}
// -------------------------------------------------------------------

// GroupOutPeer

// optional string group_id = 1;
inline void GroupOutPeer::clear_group_id() {
  group_id_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& GroupOutPeer::group_id() const {
  // @@protoc_insertion_point(field_get:zproto.GroupOutPeer.group_id)
  return group_id_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GroupOutPeer::set_group_id(const ::std::string& value) {
  
  group_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zproto.GroupOutPeer.group_id)
}
inline void GroupOutPeer::set_group_id(const char* value) {
  
  group_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zproto.GroupOutPeer.group_id)
}
inline void GroupOutPeer::set_group_id(const char* value, size_t size) {
  
  group_id_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zproto.GroupOutPeer.group_id)
}
inline ::std::string* GroupOutPeer::mutable_group_id() {
  
  // @@protoc_insertion_point(field_mutable:zproto.GroupOutPeer.group_id)
  return group_id_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* GroupOutPeer::release_group_id() {
  // @@protoc_insertion_point(field_release:zproto.GroupOutPeer.group_id)
  
  return group_id_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void GroupOutPeer::set_allocated_group_id(::std::string* group_id) {
  if (group_id != NULL) {
    
  } else {
    
  }
  group_id_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), group_id);
  // @@protoc_insertion_point(field_set_allocated:zproto.GroupOutPeer.group_id)
}

// optional int64 access_hash = 2;
inline void GroupOutPeer::clear_access_hash() {
  access_hash_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 GroupOutPeer::access_hash() const {
  // @@protoc_insertion_point(field_get:zproto.GroupOutPeer.access_hash)
  return access_hash_;
}
inline void GroupOutPeer::set_access_hash(::google::protobuf::int64 value) {
  
  access_hash_ = value;
  // @@protoc_insertion_point(field_set:zproto.GroupOutPeer.access_hash)
}

inline const GroupOutPeer* GroupOutPeer::internal_default_instance() {
  return &GroupOutPeer_default_instance_.get();
}
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace zproto

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::zproto::PeerType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::zproto::PeerType>() {
  return ::zproto::PeerType_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_peers_2eproto__INCLUDED