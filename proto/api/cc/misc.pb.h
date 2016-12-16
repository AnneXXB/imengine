// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: misc.proto

#ifndef PROTOBUF_misc_2eproto__INCLUDED
#define PROTOBUF_misc_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace zproto {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_misc_2eproto();
void protobuf_AssignDesc_misc_2eproto();
void protobuf_ShutdownFile_misc_2eproto();

class BoolRsp;
class Config;
class ConfigNotify;
class Extension;
class SeqDateRsp;
class SeqRsp;
class VoidRsp;

// ===================================================================

class VoidRsp : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.VoidRsp) */ {
 public:
  VoidRsp();
  virtual ~VoidRsp();

  VoidRsp(const VoidRsp& from);

  inline VoidRsp& operator=(const VoidRsp& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const VoidRsp& default_instance();

  void Swap(VoidRsp* other);

  // implements Message ----------------------------------------------

  inline VoidRsp* New() const { return New(NULL); }

  VoidRsp* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(VoidRsp* other);
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

  // @@protoc_insertion_point(class_scope:zproto.VoidRsp)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_misc_2eproto();
  friend void protobuf_AssignDesc_misc_2eproto();
  friend void protobuf_ShutdownFile_misc_2eproto();

  void InitAsDefaultInstance();
  static VoidRsp* default_instance_;
};
// -------------------------------------------------------------------

class SeqRsp : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.SeqRsp) */ {
 public:
  SeqRsp();
  virtual ~SeqRsp();

  SeqRsp(const SeqRsp& from);

  inline SeqRsp& operator=(const SeqRsp& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SeqRsp& default_instance();

  void Swap(SeqRsp* other);

  // implements Message ----------------------------------------------

  inline SeqRsp* New() const { return New(NULL); }

  SeqRsp* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SeqRsp* other);
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

  // optional int32 seq = 1;
  void clear_seq();
  static const int kSeqFieldNumber = 1;
  ::google::protobuf::int32 seq() const;
  void set_seq(::google::protobuf::int32 value);

  // optional bytes state = 2;
  void clear_state();
  static const int kStateFieldNumber = 2;
  const ::std::string& state() const;
  void set_state(const ::std::string& value);
  void set_state(const char* value);
  void set_state(const void* value, size_t size);
  ::std::string* mutable_state();
  ::std::string* release_state();
  void set_allocated_state(::std::string* state);

  // @@protoc_insertion_point(class_scope:zproto.SeqRsp)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr state_;
  ::google::protobuf::int32 seq_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_misc_2eproto();
  friend void protobuf_AssignDesc_misc_2eproto();
  friend void protobuf_ShutdownFile_misc_2eproto();

  void InitAsDefaultInstance();
  static SeqRsp* default_instance_;
};
// -------------------------------------------------------------------

class SeqDateRsp : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.SeqDateRsp) */ {
 public:
  SeqDateRsp();
  virtual ~SeqDateRsp();

  SeqDateRsp(const SeqDateRsp& from);

  inline SeqDateRsp& operator=(const SeqDateRsp& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SeqDateRsp& default_instance();

  void Swap(SeqDateRsp* other);

  // implements Message ----------------------------------------------

  inline SeqDateRsp* New() const { return New(NULL); }

  SeqDateRsp* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SeqDateRsp* other);
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

  // optional int32 seq = 1;
  void clear_seq();
  static const int kSeqFieldNumber = 1;
  ::google::protobuf::int32 seq() const;
  void set_seq(::google::protobuf::int32 value);

  // optional bytes state = 2;
  void clear_state();
  static const int kStateFieldNumber = 2;
  const ::std::string& state() const;
  void set_state(const ::std::string& value);
  void set_state(const char* value);
  void set_state(const void* value, size_t size);
  ::std::string* mutable_state();
  ::std::string* release_state();
  void set_allocated_state(::std::string* state);

  // optional int64 date = 3;
  void clear_date();
  static const int kDateFieldNumber = 3;
  ::google::protobuf::int64 date() const;
  void set_date(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:zproto.SeqDateRsp)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr state_;
  ::google::protobuf::int64 date_;
  ::google::protobuf::int32 seq_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_misc_2eproto();
  friend void protobuf_AssignDesc_misc_2eproto();
  friend void protobuf_ShutdownFile_misc_2eproto();

  void InitAsDefaultInstance();
  static SeqDateRsp* default_instance_;
};
// -------------------------------------------------------------------

class BoolRsp : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.BoolRsp) */ {
 public:
  BoolRsp();
  virtual ~BoolRsp();

  BoolRsp(const BoolRsp& from);

  inline BoolRsp& operator=(const BoolRsp& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const BoolRsp& default_instance();

  void Swap(BoolRsp* other);

  // implements Message ----------------------------------------------

  inline BoolRsp* New() const { return New(NULL); }

  BoolRsp* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(BoolRsp* other);
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

  // optional bool value = 1;
  void clear_value();
  static const int kValueFieldNumber = 1;
  bool value() const;
  void set_value(bool value);

  // @@protoc_insertion_point(class_scope:zproto.BoolRsp)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  bool value_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_misc_2eproto();
  friend void protobuf_AssignDesc_misc_2eproto();
  friend void protobuf_ShutdownFile_misc_2eproto();

  void InitAsDefaultInstance();
  static BoolRsp* default_instance_;
};
// -------------------------------------------------------------------

class Config : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.Config) */ {
 public:
  Config();
  virtual ~Config();

  Config(const Config& from);

  inline Config& operator=(const Config& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Config& default_instance();

  void Swap(Config* other);

  // implements Message ----------------------------------------------

  inline Config* New() const { return New(NULL); }

  Config* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Config* other);
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

  // optional int32 max_group_size = 1;
  void clear_max_group_size();
  static const int kMaxGroupSizeFieldNumber = 1;
  ::google::protobuf::int32 max_group_size() const;
  void set_max_group_size(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:zproto.Config)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::int32 max_group_size_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_misc_2eproto();
  friend void protobuf_AssignDesc_misc_2eproto();
  friend void protobuf_ShutdownFile_misc_2eproto();

  void InitAsDefaultInstance();
  static Config* default_instance_;
};
// -------------------------------------------------------------------

class Extension : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.Extension) */ {
 public:
  Extension();
  virtual ~Extension();

  Extension(const Extension& from);

  inline Extension& operator=(const Extension& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const Extension& default_instance();

  void Swap(Extension* other);

  // implements Message ----------------------------------------------

  inline Extension* New() const { return New(NULL); }

  Extension* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(Extension* other);
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

  // optional int32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // optional bytes data = 2;
  void clear_data();
  static const int kDataFieldNumber = 2;
  const ::std::string& data() const;
  void set_data(const ::std::string& value);
  void set_data(const char* value);
  void set_data(const void* value, size_t size);
  ::std::string* mutable_data();
  ::std::string* release_data();
  void set_allocated_data(::std::string* data);

  // @@protoc_insertion_point(class_scope:zproto.Extension)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::internal::ArenaStringPtr data_;
  ::google::protobuf::int32 id_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_misc_2eproto();
  friend void protobuf_AssignDesc_misc_2eproto();
  friend void protobuf_ShutdownFile_misc_2eproto();

  void InitAsDefaultInstance();
  static Extension* default_instance_;
};
// -------------------------------------------------------------------

class ConfigNotify : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:zproto.ConfigNotify) */ {
 public:
  ConfigNotify();
  virtual ~ConfigNotify();

  ConfigNotify(const ConfigNotify& from);

  inline ConfigNotify& operator=(const ConfigNotify& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const ConfigNotify& default_instance();

  void Swap(ConfigNotify* other);

  // implements Message ----------------------------------------------

  inline ConfigNotify* New() const { return New(NULL); }

  ConfigNotify* New(::google::protobuf::Arena* arena) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(ConfigNotify* other);
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

  // optional .zproto.Config config = 1;
  bool has_config() const;
  void clear_config();
  static const int kConfigFieldNumber = 1;
  const ::zproto::Config& config() const;
  ::zproto::Config* mutable_config();
  ::zproto::Config* release_config();
  void set_allocated_config(::zproto::Config* config);

  // @@protoc_insertion_point(class_scope:zproto.ConfigNotify)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::zproto::Config* config_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_misc_2eproto();
  friend void protobuf_AssignDesc_misc_2eproto();
  friend void protobuf_ShutdownFile_misc_2eproto();

  void InitAsDefaultInstance();
  static ConfigNotify* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// VoidRsp

// -------------------------------------------------------------------

// SeqRsp

// optional int32 seq = 1;
inline void SeqRsp::clear_seq() {
  seq_ = 0;
}
inline ::google::protobuf::int32 SeqRsp::seq() const {
  // @@protoc_insertion_point(field_get:zproto.SeqRsp.seq)
  return seq_;
}
inline void SeqRsp::set_seq(::google::protobuf::int32 value) {
  
  seq_ = value;
  // @@protoc_insertion_point(field_set:zproto.SeqRsp.seq)
}

// optional bytes state = 2;
inline void SeqRsp::clear_state() {
  state_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SeqRsp::state() const {
  // @@protoc_insertion_point(field_get:zproto.SeqRsp.state)
  return state_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SeqRsp::set_state(const ::std::string& value) {
  
  state_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zproto.SeqRsp.state)
}
inline void SeqRsp::set_state(const char* value) {
  
  state_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zproto.SeqRsp.state)
}
inline void SeqRsp::set_state(const void* value, size_t size) {
  
  state_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zproto.SeqRsp.state)
}
inline ::std::string* SeqRsp::mutable_state() {
  
  // @@protoc_insertion_point(field_mutable:zproto.SeqRsp.state)
  return state_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SeqRsp::release_state() {
  // @@protoc_insertion_point(field_release:zproto.SeqRsp.state)
  
  return state_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SeqRsp::set_allocated_state(::std::string* state) {
  if (state != NULL) {
    
  } else {
    
  }
  state_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), state);
  // @@protoc_insertion_point(field_set_allocated:zproto.SeqRsp.state)
}

// -------------------------------------------------------------------

// SeqDateRsp

// optional int32 seq = 1;
inline void SeqDateRsp::clear_seq() {
  seq_ = 0;
}
inline ::google::protobuf::int32 SeqDateRsp::seq() const {
  // @@protoc_insertion_point(field_get:zproto.SeqDateRsp.seq)
  return seq_;
}
inline void SeqDateRsp::set_seq(::google::protobuf::int32 value) {
  
  seq_ = value;
  // @@protoc_insertion_point(field_set:zproto.SeqDateRsp.seq)
}

// optional bytes state = 2;
inline void SeqDateRsp::clear_state() {
  state_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SeqDateRsp::state() const {
  // @@protoc_insertion_point(field_get:zproto.SeqDateRsp.state)
  return state_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SeqDateRsp::set_state(const ::std::string& value) {
  
  state_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zproto.SeqDateRsp.state)
}
inline void SeqDateRsp::set_state(const char* value) {
  
  state_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zproto.SeqDateRsp.state)
}
inline void SeqDateRsp::set_state(const void* value, size_t size) {
  
  state_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zproto.SeqDateRsp.state)
}
inline ::std::string* SeqDateRsp::mutable_state() {
  
  // @@protoc_insertion_point(field_mutable:zproto.SeqDateRsp.state)
  return state_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SeqDateRsp::release_state() {
  // @@protoc_insertion_point(field_release:zproto.SeqDateRsp.state)
  
  return state_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SeqDateRsp::set_allocated_state(::std::string* state) {
  if (state != NULL) {
    
  } else {
    
  }
  state_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), state);
  // @@protoc_insertion_point(field_set_allocated:zproto.SeqDateRsp.state)
}

// optional int64 date = 3;
inline void SeqDateRsp::clear_date() {
  date_ = GOOGLE_LONGLONG(0);
}
inline ::google::protobuf::int64 SeqDateRsp::date() const {
  // @@protoc_insertion_point(field_get:zproto.SeqDateRsp.date)
  return date_;
}
inline void SeqDateRsp::set_date(::google::protobuf::int64 value) {
  
  date_ = value;
  // @@protoc_insertion_point(field_set:zproto.SeqDateRsp.date)
}

// -------------------------------------------------------------------

// BoolRsp

// optional bool value = 1;
inline void BoolRsp::clear_value() {
  value_ = false;
}
inline bool BoolRsp::value() const {
  // @@protoc_insertion_point(field_get:zproto.BoolRsp.value)
  return value_;
}
inline void BoolRsp::set_value(bool value) {
  
  value_ = value;
  // @@protoc_insertion_point(field_set:zproto.BoolRsp.value)
}

// -------------------------------------------------------------------

// Config

// optional int32 max_group_size = 1;
inline void Config::clear_max_group_size() {
  max_group_size_ = 0;
}
inline ::google::protobuf::int32 Config::max_group_size() const {
  // @@protoc_insertion_point(field_get:zproto.Config.max_group_size)
  return max_group_size_;
}
inline void Config::set_max_group_size(::google::protobuf::int32 value) {
  
  max_group_size_ = value;
  // @@protoc_insertion_point(field_set:zproto.Config.max_group_size)
}

// -------------------------------------------------------------------

// Extension

// optional int32 id = 1;
inline void Extension::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 Extension::id() const {
  // @@protoc_insertion_point(field_get:zproto.Extension.id)
  return id_;
}
inline void Extension::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:zproto.Extension.id)
}

// optional bytes data = 2;
inline void Extension::clear_data() {
  data_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Extension::data() const {
  // @@protoc_insertion_point(field_get:zproto.Extension.data)
  return data_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Extension::set_data(const ::std::string& value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:zproto.Extension.data)
}
inline void Extension::set_data(const char* value) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:zproto.Extension.data)
}
inline void Extension::set_data(const void* value, size_t size) {
  
  data_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:zproto.Extension.data)
}
inline ::std::string* Extension::mutable_data() {
  
  // @@protoc_insertion_point(field_mutable:zproto.Extension.data)
  return data_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Extension::release_data() {
  // @@protoc_insertion_point(field_release:zproto.Extension.data)
  
  return data_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Extension::set_allocated_data(::std::string* data) {
  if (data != NULL) {
    
  } else {
    
  }
  data_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), data);
  // @@protoc_insertion_point(field_set_allocated:zproto.Extension.data)
}

// -------------------------------------------------------------------

// ConfigNotify

// optional .zproto.Config config = 1;
inline bool ConfigNotify::has_config() const {
  return !_is_default_instance_ && config_ != NULL;
}
inline void ConfigNotify::clear_config() {
  if (GetArenaNoVirtual() == NULL && config_ != NULL) delete config_;
  config_ = NULL;
}
inline const ::zproto::Config& ConfigNotify::config() const {
  // @@protoc_insertion_point(field_get:zproto.ConfigNotify.config)
  return config_ != NULL ? *config_ : *default_instance_->config_;
}
inline ::zproto::Config* ConfigNotify::mutable_config() {
  
  if (config_ == NULL) {
    config_ = new ::zproto::Config;
  }
  // @@protoc_insertion_point(field_mutable:zproto.ConfigNotify.config)
  return config_;
}
inline ::zproto::Config* ConfigNotify::release_config() {
  // @@protoc_insertion_point(field_release:zproto.ConfigNotify.config)
  
  ::zproto::Config* temp = config_;
  config_ = NULL;
  return temp;
}
inline void ConfigNotify::set_allocated_config(::zproto::Config* config) {
  delete config_;
  config_ = config;
  if (config) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:zproto.ConfigNotify.config)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace zproto

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_misc_2eproto__INCLUDED
