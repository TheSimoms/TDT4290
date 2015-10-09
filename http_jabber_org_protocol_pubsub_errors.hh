// This C++ header file was generated by the TTCN-3 compiler
// of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for user (user@user-multicom) on Fri Oct  9 11:34:10 2015

// Copyright Ericsson Telecom AB 2000-2014

// Do not edit this file unless you know what you are doing.

#ifndef http__jabber__org__protocol__pubsub__errors_HH
#define http__jabber__org__protocol__pubsub__errors_HH

#ifdef TITAN_RUNTIME_2
#error Generated code does not match with used runtime.\
 Code was generated without -R option but -DTITAN_RUNTIME_2 was used.
#endif

/* Header file includes */

#include "XSD.hh"

#if TTCN3_VERSION != 50300
#error Version mismatch detected.\
 Please check the version of the TTCN-3 compiler and the base library.
#endif

#ifndef LINUX
#error This file should be compiled on LINUX
#endif

#undef http__jabber__org__protocol__pubsub__errors_HH
#endif

namespace http__jabber__org__protocol__pubsub__errors {

/* Forward declarations of classes */

class Empty;
class Empty_template;
class Unsupported_feature;
class Unsupported_feature_template;
class Unsupported;
class Unsupported_template;

} /* end of namespace */

#ifndef http__jabber__org__protocol__pubsub__errors_HH
#define http__jabber__org__protocol__pubsub__errors_HH

namespace http__jabber__org__protocol__pubsub__errors {

/* Type definitions */

typedef Empty Closed__node;
typedef Empty_template Closed__node_template;
typedef Empty Configuration__required;
typedef Empty_template Configuration__required_template;
typedef Empty Invalid__jid;
typedef Empty_template Invalid__jid_template;
typedef Empty Invalid__options;
typedef Empty_template Invalid__options_template;
typedef Empty Invalid__payload;
typedef Empty_template Invalid__payload_template;
typedef Empty Invalid__subid;
typedef Empty_template Invalid__subid_template;
typedef Empty Item__forbidden;
typedef Empty_template Item__forbidden_template;
typedef Empty Item__required;
typedef Empty_template Item__required_template;
typedef Empty Jid__required;
typedef Empty_template Jid__required_template;
typedef Empty Max__items__exceeded;
typedef Empty_template Max__items__exceeded_template;
typedef Empty Max__nodes__exceeded;
typedef Empty_template Max__nodes__exceeded_template;
typedef Empty Nodeid__required;
typedef Empty_template Nodeid__required_template;
typedef Empty Not__in__roster__group;
typedef Empty_template Not__in__roster__group_template;
typedef Empty Not__subscribed;
typedef Empty_template Not__subscribed_template;
typedef Empty Payload__too__big;
typedef Empty_template Payload__too__big_template;
typedef Empty Payload__required;
typedef Empty_template Payload__required_template;
typedef Empty Pending__subscription;
typedef Empty_template Pending__subscription_template;
typedef Empty Presence__subscription__required;
typedef Empty_template Presence__subscription__required_template;
typedef Empty Subid__required;
typedef Empty_template Subid__required_template;
typedef Empty Too__many__subscriptions;
typedef Empty_template Too__many__subscriptions_template;
typedef Empty Unsupported__access__model;
typedef Empty_template Unsupported__access__model_template;

/* Class definitions */

class Empty : public Base_Type { // enum
friend class Empty_template;
public:
enum enum_type { x = 0, UNKNOWN_VALUE = 1, UNBOUND_VALUE = 2 };
private:
enum_type enum_value;

public:
Empty();
Empty(int other_value);
Empty(enum_type other_value);
Empty(const Empty& other_value);

Empty& operator=(int other_value);
Empty& operator=(enum_type other_value);
Empty& operator=(const Empty& other_value);

boolean operator==(enum_type other_value) const;
boolean operator==(const Empty& other_value) const;
inline boolean operator!=(enum_type other_value) const { return !(*this == other_value); }
inline boolean operator!=(const Empty& other_value) const { return !(*this == other_value); }
boolean operator<(enum_type other_value) const;
boolean operator<(const Empty& other_value) const;
boolean operator>(enum_type other_value) const;
boolean operator>(const Empty& other_value) const;
inline boolean operator<=(enum_type other_value) const { return !(*this > other_value); }
inline boolean operator<=(const Empty& other_value) const { return !(*this > other_value); }
inline boolean operator>=(enum_type other_value) const { return !(*this < other_value); }
inline boolean operator>=(const Empty& other_value) const { return !(*this < other_value); }

static const char *enum_to_str(enum_type enum_par, boolean txt = false);
static enum_type str_to_enum(const char *str_par);
static boolean is_valid_enum(int int_par);

static int enum2int(enum_type enum_par);
static int enum2int(const Empty& enum_par);
int as_int() const { return enum2int(enum_value); }
void from_int(int p_val) { *this = p_val; }
operator enum_type() const;
inline boolean is_bound() const { return enum_value != UNBOUND_VALUE; }
inline boolean is_value() const { return enum_value != UNBOUND_VALUE; }
inline void clean_up(){ enum_value = UNBOUND_VALUE; }
inline boolean is_present() const { return is_bound(); }
void log() const;
void set_param(Module_Param& param);
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void encode(const TTCN_Typedescriptor_t&, TTCN_Buffer&, TTCN_EncDec::coding_t, ...) const;
void decode(const TTCN_Typedescriptor_t&, TTCN_Buffer&, TTCN_EncDec::coding_t, ...);
int XER_encode(const XERdescriptor_t&, TTCN_Buffer&, unsigned int, int, embed_values_enc_struct_t*) const;
int XER_decode(const XERdescriptor_t&, XmlReaderWrap&, unsigned int, embed_values_dec_struct_t*);
static boolean can_start(const char *name, const char *uri, XERdescriptor_t const& xd, unsigned int);
int JSON_encode(const TTCN_Typedescriptor_t&, JSON_Tokenizer&) const;
int JSON_decode(const TTCN_Typedescriptor_t&, JSON_Tokenizer&, boolean);
};

class Empty_template : public Base_Template {
union {
Empty::enum_type single_value;
struct {
unsigned int n_values;
Empty_template *list_value;
} value_list;
};

void copy_template(const Empty_template& other_value);

public:
Empty_template();
Empty_template(template_sel other_value);
Empty_template(int other_value);
Empty_template(Empty::enum_type other_value);
Empty_template(const Empty& other_value);
Empty_template(const OPTIONAL<Empty>& other_value);
Empty_template(const Empty_template& other_value);
~Empty_template();

boolean is_bound() const;
boolean is_value() const;
void clean_up();
Empty_template& operator=(template_sel other_value);
Empty_template& operator=(int other_value);
Empty_template& operator=(Empty::enum_type other_value);
Empty_template& operator=(const Empty& other_value);
Empty_template& operator=(const OPTIONAL<Empty>& other_value);
Empty_template& operator=(const Empty_template& other_value);

boolean match(Empty::enum_type other_value) const;
boolean match(const Empty& other_value) const;
Empty::enum_type valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
Empty_template& list_item(unsigned int list_index);
void log() const;
void log_match(const Empty& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
boolean is_present() const;
boolean match_omit() const;
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
};

class Unsupported_feature : public Base_Type { // enum
friend class Unsupported_feature_template;
public:
enum enum_type { access__authorize = 0, access__open = 1, access__presence = 2, access__roster = 3, access__whitelist = 4, auto__create = 5, auto__subscribe = 6, collections = 7, config__node = 8, create__and__configure = 9, create__nodes = 10, delete__items = 11, delete__nodes = 12, filtered__notifications = 13, get__pending = 14, instant__nodes = 15, item__ids = 16, last__published = 17, leased__subscription = 18, manage__subscriptions = 19, member__affiliation = 20, meta__data = 21, modify__affiliations = 22, multi__collection = 23, multi__subscribe = 24, outcast__affiliation = 25, persistent__items = 26, presence__notifications = 27, presence__subscribe = 28, publish = 29, publish__options = 30, publish__only__affiliation = 31, publisher__affiliation = 32, purge__nodes = 33, retract__items = 34, retrieve__affiliations = 35, retrieve__default = 36, retrieve__items = 37, retrieve__subscriptions = 38, subscribe = 39, subscription__options = 40, subscription__notifications = 41, UNKNOWN_VALUE = 42, UNBOUND_VALUE = 43 };
private:
enum_type enum_value;

public:
Unsupported_feature();
Unsupported_feature(int other_value);
Unsupported_feature(enum_type other_value);
Unsupported_feature(const Unsupported_feature& other_value);

Unsupported_feature& operator=(int other_value);
Unsupported_feature& operator=(enum_type other_value);
Unsupported_feature& operator=(const Unsupported_feature& other_value);

boolean operator==(enum_type other_value) const;
boolean operator==(const Unsupported_feature& other_value) const;
inline boolean operator!=(enum_type other_value) const { return !(*this == other_value); }
inline boolean operator!=(const Unsupported_feature& other_value) const { return !(*this == other_value); }
boolean operator<(enum_type other_value) const;
boolean operator<(const Unsupported_feature& other_value) const;
boolean operator>(enum_type other_value) const;
boolean operator>(const Unsupported_feature& other_value) const;
inline boolean operator<=(enum_type other_value) const { return !(*this > other_value); }
inline boolean operator<=(const Unsupported_feature& other_value) const { return !(*this > other_value); }
inline boolean operator>=(enum_type other_value) const { return !(*this < other_value); }
inline boolean operator>=(const Unsupported_feature& other_value) const { return !(*this < other_value); }

static const char *enum_to_str(enum_type enum_par, boolean txt = false);
static enum_type str_to_enum(const char *str_par);
static boolean is_valid_enum(int int_par);

static int enum2int(enum_type enum_par);
static int enum2int(const Unsupported_feature& enum_par);
int as_int() const { return enum2int(enum_value); }
void from_int(int p_val) { *this = p_val; }
operator enum_type() const;
inline boolean is_bound() const { return enum_value != UNBOUND_VALUE; }
inline boolean is_value() const { return enum_value != UNBOUND_VALUE; }
inline void clean_up(){ enum_value = UNBOUND_VALUE; }
inline boolean is_present() const { return is_bound(); }
void log() const;
void set_param(Module_Param& param);
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void encode(const TTCN_Typedescriptor_t&, TTCN_Buffer&, TTCN_EncDec::coding_t, ...) const;
void decode(const TTCN_Typedescriptor_t&, TTCN_Buffer&, TTCN_EncDec::coding_t, ...);
int XER_encode(const XERdescriptor_t&, TTCN_Buffer&, unsigned int, int, embed_values_enc_struct_t*) const;
int XER_decode(const XERdescriptor_t&, XmlReaderWrap&, unsigned int, embed_values_dec_struct_t*);
static boolean can_start(const char *name, const char *uri, XERdescriptor_t const& xd, unsigned int);
int JSON_encode(const TTCN_Typedescriptor_t&, JSON_Tokenizer&) const;
int JSON_decode(const TTCN_Typedescriptor_t&, JSON_Tokenizer&, boolean);
};

class Unsupported_feature_template : public Base_Template {
union {
Unsupported_feature::enum_type single_value;
struct {
unsigned int n_values;
Unsupported_feature_template *list_value;
} value_list;
};

void copy_template(const Unsupported_feature_template& other_value);

public:
Unsupported_feature_template();
Unsupported_feature_template(template_sel other_value);
Unsupported_feature_template(int other_value);
Unsupported_feature_template(Unsupported_feature::enum_type other_value);
Unsupported_feature_template(const Unsupported_feature& other_value);
Unsupported_feature_template(const OPTIONAL<Unsupported_feature>& other_value);
Unsupported_feature_template(const Unsupported_feature_template& other_value);
~Unsupported_feature_template();

boolean is_bound() const;
boolean is_value() const;
void clean_up();
Unsupported_feature_template& operator=(template_sel other_value);
Unsupported_feature_template& operator=(int other_value);
Unsupported_feature_template& operator=(Unsupported_feature::enum_type other_value);
Unsupported_feature_template& operator=(const Unsupported_feature& other_value);
Unsupported_feature_template& operator=(const OPTIONAL<Unsupported_feature>& other_value);
Unsupported_feature_template& operator=(const Unsupported_feature_template& other_value);

boolean match(Unsupported_feature::enum_type other_value) const;
boolean match(const Unsupported_feature& other_value) const;
Unsupported_feature::enum_type valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
Unsupported_feature_template& list_item(unsigned int list_index);
void log() const;
void log_match(const Unsupported_feature& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
boolean is_present() const;
boolean match_omit() const;
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
};

class Unsupported : public Base_Type {
  Unsupported_feature field_feature;
  Empty field_base;
  boolean bound_flag;
public:
  Unsupported();
  Unsupported(const Unsupported_feature& par_feature,
    const Empty& par_base);
  Unsupported(const Unsupported& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  Unsupported& operator=(const Unsupported& other_value);
  boolean operator==(const Unsupported& other_value) const;
  inline boolean operator!=(const Unsupported& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline Unsupported_feature& feature()
    {return field_feature;}
  inline const Unsupported_feature& feature() const
    {return field_feature;}
  inline Empty& base()
    {return field_base;}
  inline const Empty& base() const
    {return field_base;}
  int size_of() const;
  void log() const;
  void set_param(Module_Param& param);
  void set_implicit_omit();
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
void encode(const TTCN_Typedescriptor_t&, TTCN_Buffer&, TTCN_EncDec::coding_t, ...) const;
void decode(const TTCN_Typedescriptor_t&, TTCN_Buffer&, TTCN_EncDec::coding_t, ...);
int XER_encode(const XERdescriptor_t&, TTCN_Buffer&, unsigned int, int, embed_values_enc_struct_t*) const;
int XER_decode(const XERdescriptor_t&, XmlReaderWrap&, unsigned int, embed_values_dec_struct_t*);
static boolean can_start(const char *name, const char *uri, XERdescriptor_t const& xd, unsigned int);
int JSON_encode(const TTCN_Typedescriptor_t&, JSON_Tokenizer&) const;
int JSON_decode(const TTCN_Typedescriptor_t&, JSON_Tokenizer&, boolean);
char **collect_ns(const XERdescriptor_t& p_td, size_t& num_ns, bool& def_ns) const;
};

class Unsupported_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
Unsupported_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const Unsupported& other_value);
void copy_template(const Unsupported_template& other_value);

public:
Unsupported_template();
Unsupported_template(template_sel other_value);
Unsupported_template(const Unsupported& other_value);
Unsupported_template(const OPTIONAL<Unsupported>& other_value);
Unsupported_template(const Unsupported_template& other_value);
~Unsupported_template();
Unsupported_template& operator=(template_sel other_value);
Unsupported_template& operator=(const Unsupported& other_value);
Unsupported_template& operator=(const OPTIONAL<Unsupported>& other_value);
Unsupported_template& operator=(const Unsupported_template& other_value);
boolean match(const Unsupported& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
Unsupported valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
Unsupported_template& list_item(unsigned int list_index) const;
Unsupported_feature_template& feature();
const Unsupported_feature_template& feature() const;
Empty_template& base();
const Empty_template& base() const;
int size_of() const;
void log() const;
void log_match(const Unsupported& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};


/* Global variable declarations */

extern const XERdescriptor_t Empty_xer_;
extern const TTCN_JSONdescriptor_t Empty_json_;
extern const TTCN_Typedescriptor_t Empty_descr_;
extern const XERdescriptor_t Closed__node_xer_;
extern const TTCN_Typedescriptor_t Closed__node_descr_;
extern const XERdescriptor_t Configuration__required_xer_;
extern const TTCN_Typedescriptor_t Configuration__required_descr_;
extern const XERdescriptor_t Invalid__jid_xer_;
extern const TTCN_Typedescriptor_t Invalid__jid_descr_;
extern const XERdescriptor_t Invalid__options_xer_;
extern const TTCN_Typedescriptor_t Invalid__options_descr_;
extern const XERdescriptor_t Invalid__payload_xer_;
extern const TTCN_Typedescriptor_t Invalid__payload_descr_;
extern const XERdescriptor_t Invalid__subid_xer_;
extern const TTCN_Typedescriptor_t Invalid__subid_descr_;
extern const XERdescriptor_t Item__forbidden_xer_;
extern const TTCN_Typedescriptor_t Item__forbidden_descr_;
extern const XERdescriptor_t Item__required_xer_;
extern const TTCN_Typedescriptor_t Item__required_descr_;
extern const XERdescriptor_t Jid__required_xer_;
extern const TTCN_Typedescriptor_t Jid__required_descr_;
extern const XERdescriptor_t Max__items__exceeded_xer_;
extern const TTCN_Typedescriptor_t Max__items__exceeded_descr_;
extern const XERdescriptor_t Max__nodes__exceeded_xer_;
extern const TTCN_Typedescriptor_t Max__nodes__exceeded_descr_;
extern const XERdescriptor_t Nodeid__required_xer_;
extern const TTCN_Typedescriptor_t Nodeid__required_descr_;
extern const XERdescriptor_t Not__in__roster__group_xer_;
extern const TTCN_Typedescriptor_t Not__in__roster__group_descr_;
extern const XERdescriptor_t Not__subscribed_xer_;
extern const TTCN_Typedescriptor_t Not__subscribed_descr_;
extern const XERdescriptor_t Payload__too__big_xer_;
extern const TTCN_Typedescriptor_t Payload__too__big_descr_;
extern const XERdescriptor_t Payload__required_xer_;
extern const TTCN_Typedescriptor_t Payload__required_descr_;
extern const XERdescriptor_t Pending__subscription_xer_;
extern const TTCN_Typedescriptor_t Pending__subscription_descr_;
extern const XERdescriptor_t Presence__subscription__required_xer_;
extern const TTCN_Typedescriptor_t Presence__subscription__required_descr_;
extern const XERdescriptor_t Subid__required_xer_;
extern const TTCN_Typedescriptor_t Subid__required_descr_;
extern const XERdescriptor_t Too__many__subscriptions_xer_;
extern const TTCN_Typedescriptor_t Too__many__subscriptions_descr_;
extern const XERdescriptor_t Unsupported_feature_xer_;
extern const TTCN_JSONdescriptor_t Unsupported_feature_json_;
extern const TTCN_Typedescriptor_t Unsupported_feature_descr_;
extern const XERdescriptor_t Unsupported_base_xer_;
extern const TTCN_Typedescriptor_t Unsupported_base_descr_;
extern const XERdescriptor_t Unsupported_xer_;
extern const TTCN_JSONdescriptor_t Unsupported_json_;
extern const TTCN_Typedescriptor_t Unsupported_descr_;
extern const XERdescriptor_t Unsupported__access__model_xer_;
extern const TTCN_Typedescriptor_t Unsupported__access__model_descr_;
extern TTCN_Module module_object;

} /* end of namespace */

#endif
