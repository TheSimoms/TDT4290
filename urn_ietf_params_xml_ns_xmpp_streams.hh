// This C++ header file was generated by the TTCN-3 compiler
// of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for user (user@user-multicom) on Wed Sep 16 13:14:39 2015

// Copyright Ericsson Telecom AB 2000-2014

// Do not edit this file unless you know what you are doing.

#ifndef urn__ietf__params__xml__ns__xmpp__streams_HH
#define urn__ietf__params__xml__ns__xmpp__streams_HH

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

#undef urn__ietf__params__xml__ns__xmpp__streams_HH
#endif

namespace urn__ietf__params__xml__ns__xmpp__streams {

/* Forward declarations of classes */

class Empty;
class Empty_template;
class StreamErrorGroup;
class StreamErrorGroup_template;
class Text;
class Text_template;

} /* end of namespace */

#ifndef urn__ietf__params__xml__ns__xmpp__streams_HH
#define urn__ietf__params__xml__ns__xmpp__streams_HH

namespace urn__ietf__params__xml__ns__xmpp__streams {

/* Type definitions */

typedef Empty Bad__format;
typedef Empty_template Bad__format_template;
typedef Empty Bad__namespace__prefix;
typedef Empty_template Bad__namespace__prefix_template;
typedef Empty Conflict;
typedef Empty_template Conflict_template;
typedef Empty Connection__timeout;
typedef Empty_template Connection__timeout_template;
typedef Empty Host__gone;
typedef Empty_template Host__gone_template;
typedef Empty Host__unknown;
typedef Empty_template Host__unknown_template;
typedef Empty Improper__addressing;
typedef Empty_template Improper__addressing_template;
typedef Empty Internal__server__error;
typedef Empty_template Internal__server__error_template;
typedef Empty Invalid__from;
typedef Empty_template Invalid__from_template;
typedef Empty Invalid__id;
typedef Empty_template Invalid__id_template;
typedef Empty Invalid__namespace;
typedef Empty_template Invalid__namespace_template;
typedef Empty Invalid__xml;
typedef Empty_template Invalid__xml_template;
typedef Empty Not__authorized;
typedef Empty_template Not__authorized_template;
typedef Empty Not__well__formed;
typedef Empty_template Not__well__formed_template;
typedef Empty Policy__violation;
typedef Empty_template Policy__violation_template;
typedef Empty Remote__connection__failed;
typedef Empty_template Remote__connection__failed_template;
typedef Empty Reset;
typedef Empty_template Reset_template;
typedef Empty Resource__constraint;
typedef Empty_template Resource__constraint_template;
typedef Empty Restricted__xml;
typedef Empty_template Restricted__xml_template;
typedef UNIVERSAL_CHARSTRING See__other__host;
typedef UNIVERSAL_CHARSTRING_template See__other__host_template;
typedef Empty System__shutdown;
typedef Empty_template System__shutdown_template;
typedef Empty Undefined__condition;
typedef Empty_template Undefined__condition_template;
typedef Empty Unsupported__encoding;
typedef Empty_template Unsupported__encoding_template;
typedef Empty Unsupported__stanza__type;
typedef Empty_template Unsupported__stanza__type_template;
typedef Empty Unsupported__version;
typedef Empty_template Unsupported__version_template;

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

class StreamErrorGroup : public Base_Type {
public:
enum union_selection_type { UNBOUND_VALUE = 0, ALT_bad__format = 1, ALT_bad__namespace__prefix = 2, ALT_conflict = 3, ALT_connection__timeout = 4, ALT_host__gone = 5, ALT_host__unknown = 6, ALT_improper__addressing = 7, ALT_internal__server__error = 8, ALT_invalid__from = 9, ALT_invalid__id = 10, ALT_invalid__namespace = 11, ALT_invalid__xml = 12, ALT_not__authorized = 13, ALT_not__well__formed = 14, ALT_policy__violation = 15, ALT_remote__connection__failed = 16, ALT_reset = 17, ALT_resource__constraint = 18, ALT_restricted__xml = 19, ALT_see__other__host = 20, ALT_system__shutdown = 21, ALT_undefined__condition = 22, ALT_unsupported__encoding = 23, ALT_unsupported__stanza__type = 24, ALT_unsupported__version = 25 };
private:
union_selection_type union_selection;
union {
Empty *field_bad__format;
Empty *field_bad__namespace__prefix;
Empty *field_conflict;
Empty *field_connection__timeout;
Empty *field_host__gone;
Empty *field_host__unknown;
Empty *field_improper__addressing;
Empty *field_internal__server__error;
Empty *field_invalid__from;
Empty *field_invalid__id;
Empty *field_invalid__namespace;
Empty *field_invalid__xml;
Empty *field_not__authorized;
Empty *field_not__well__formed;
Empty *field_policy__violation;
Empty *field_remote__connection__failed;
Empty *field_reset;
Empty *field_resource__constraint;
Empty *field_restricted__xml;
UNIVERSAL_CHARSTRING *field_see__other__host;
Empty *field_system__shutdown;
Empty *field_undefined__condition;
Empty *field_unsupported__encoding;
Empty *field_unsupported__stanza__type;
Empty *field_unsupported__version;
};
void copy_value(const StreamErrorGroup& other_value);

public:
StreamErrorGroup();
StreamErrorGroup(const StreamErrorGroup& other_value);
~StreamErrorGroup();
StreamErrorGroup& operator=(const StreamErrorGroup& other_value);
boolean operator==(const StreamErrorGroup& other_value) const;
inline boolean operator!=(const StreamErrorGroup& other_value) const { return !(*this == other_value); }
Empty& bad__format();
const Empty& bad__format() const;
Empty& bad__namespace__prefix();
const Empty& bad__namespace__prefix() const;
Empty& conflict();
const Empty& conflict() const;
Empty& connection__timeout();
const Empty& connection__timeout() const;
Empty& host__gone();
const Empty& host__gone() const;
Empty& host__unknown();
const Empty& host__unknown() const;
Empty& improper__addressing();
const Empty& improper__addressing() const;
Empty& internal__server__error();
const Empty& internal__server__error() const;
Empty& invalid__from();
const Empty& invalid__from() const;
Empty& invalid__id();
const Empty& invalid__id() const;
Empty& invalid__namespace();
const Empty& invalid__namespace() const;
Empty& invalid__xml();
const Empty& invalid__xml() const;
Empty& not__authorized();
const Empty& not__authorized() const;
Empty& not__well__formed();
const Empty& not__well__formed() const;
Empty& policy__violation();
const Empty& policy__violation() const;
Empty& remote__connection__failed();
const Empty& remote__connection__failed() const;
Empty& reset();
const Empty& reset() const;
Empty& resource__constraint();
const Empty& resource__constraint() const;
Empty& restricted__xml();
const Empty& restricted__xml() const;
UNIVERSAL_CHARSTRING& see__other__host();
const UNIVERSAL_CHARSTRING& see__other__host() const;
Empty& system__shutdown();
const Empty& system__shutdown() const;
Empty& undefined__condition();
const Empty& undefined__condition() const;
Empty& unsupported__encoding();
const Empty& unsupported__encoding() const;
Empty& unsupported__stanza__type();
const Empty& unsupported__stanza__type() const;
Empty& unsupported__version();
const Empty& unsupported__version() const;
inline union_selection_type get_selection() const { return union_selection; }
boolean ischosen(union_selection_type checked_selection) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
inline boolean is_present() const { return is_bound(); }
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
char **collect_ns(const XERdescriptor_t& p_td, size_t& num, bool& def_ns) const;
};

class StreamErrorGroup_template : public Base_Template {
union {
struct {
StreamErrorGroup::union_selection_type union_selection;
union {
Empty_template *field_bad__format;
Empty_template *field_bad__namespace__prefix;
Empty_template *field_conflict;
Empty_template *field_connection__timeout;
Empty_template *field_host__gone;
Empty_template *field_host__unknown;
Empty_template *field_improper__addressing;
Empty_template *field_internal__server__error;
Empty_template *field_invalid__from;
Empty_template *field_invalid__id;
Empty_template *field_invalid__namespace;
Empty_template *field_invalid__xml;
Empty_template *field_not__authorized;
Empty_template *field_not__well__formed;
Empty_template *field_policy__violation;
Empty_template *field_remote__connection__failed;
Empty_template *field_reset;
Empty_template *field_resource__constraint;
Empty_template *field_restricted__xml;
UNIVERSAL_CHARSTRING_template *field_see__other__host;
Empty_template *field_system__shutdown;
Empty_template *field_undefined__condition;
Empty_template *field_unsupported__encoding;
Empty_template *field_unsupported__stanza__type;
Empty_template *field_unsupported__version;
};
} single_value;
struct {
unsigned int n_values;
StreamErrorGroup_template *list_value;
} value_list;
};
void copy_value(const StreamErrorGroup& other_value);

void copy_template(const StreamErrorGroup_template& other_value);

public:
StreamErrorGroup_template();
StreamErrorGroup_template(template_sel other_value);
StreamErrorGroup_template(const StreamErrorGroup& other_value);
StreamErrorGroup_template(const OPTIONAL<StreamErrorGroup>& other_value);
StreamErrorGroup_template(const StreamErrorGroup_template& other_value);
~StreamErrorGroup_template();
void clean_up();
StreamErrorGroup_template& operator=(template_sel other_value);
StreamErrorGroup_template& operator=(const StreamErrorGroup& other_value);
StreamErrorGroup_template& operator=(const OPTIONAL<StreamErrorGroup>& other_value);
StreamErrorGroup_template& operator=(const StreamErrorGroup_template& other_value);
boolean match(const StreamErrorGroup& other_value) const;
boolean is_value() const;StreamErrorGroup valueof() const;
StreamErrorGroup_template& list_item(unsigned int list_index) const;
void set_type(template_sel template_type, unsigned int list_length);
Empty_template& bad__format();
const Empty_template& bad__format() const;
Empty_template& bad__namespace__prefix();
const Empty_template& bad__namespace__prefix() const;
Empty_template& conflict();
const Empty_template& conflict() const;
Empty_template& connection__timeout();
const Empty_template& connection__timeout() const;
Empty_template& host__gone();
const Empty_template& host__gone() const;
Empty_template& host__unknown();
const Empty_template& host__unknown() const;
Empty_template& improper__addressing();
const Empty_template& improper__addressing() const;
Empty_template& internal__server__error();
const Empty_template& internal__server__error() const;
Empty_template& invalid__from();
const Empty_template& invalid__from() const;
Empty_template& invalid__id();
const Empty_template& invalid__id() const;
Empty_template& invalid__namespace();
const Empty_template& invalid__namespace() const;
Empty_template& invalid__xml();
const Empty_template& invalid__xml() const;
Empty_template& not__authorized();
const Empty_template& not__authorized() const;
Empty_template& not__well__formed();
const Empty_template& not__well__formed() const;
Empty_template& policy__violation();
const Empty_template& policy__violation() const;
Empty_template& remote__connection__failed();
const Empty_template& remote__connection__failed() const;
Empty_template& reset();
const Empty_template& reset() const;
Empty_template& resource__constraint();
const Empty_template& resource__constraint() const;
Empty_template& restricted__xml();
const Empty_template& restricted__xml() const;
UNIVERSAL_CHARSTRING_template& see__other__host();
const UNIVERSAL_CHARSTRING_template& see__other__host() const;
Empty_template& system__shutdown();
const Empty_template& system__shutdown() const;
Empty_template& undefined__condition();
const Empty_template& undefined__condition() const;
Empty_template& unsupported__encoding();
const Empty_template& unsupported__encoding() const;
Empty_template& unsupported__stanza__type();
const Empty_template& unsupported__stanza__type() const;
Empty_template& unsupported__version();
const Empty_template& unsupported__version() const;
boolean ischosen(StreamErrorGroup::union_selection_type checked_selection) const;
void log() const;
void log_match(const StreamErrorGroup& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
boolean is_present() const;
boolean match_omit() const;
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
};

class Text : public Base_Type {
  OPTIONAL<CHARSTRING> field_lang;
  UNIVERSAL_CHARSTRING field_base;
  boolean bound_flag;
public:
  Text();
  Text(const OPTIONAL<CHARSTRING>& par_lang,
    const UNIVERSAL_CHARSTRING& par_base);
  Text(const Text& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  Text& operator=(const Text& other_value);
  boolean operator==(const Text& other_value) const;
  inline boolean operator!=(const Text& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline OPTIONAL<CHARSTRING>& lang()
    {return field_lang;}
  inline const OPTIONAL<CHARSTRING>& lang() const
    {return field_lang;}
  inline UNIVERSAL_CHARSTRING& base()
    {return field_base;}
  inline const UNIVERSAL_CHARSTRING& base() const
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

class Text_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
Text_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const Text& other_value);
void copy_template(const Text_template& other_value);

public:
Text_template();
Text_template(template_sel other_value);
Text_template(const Text& other_value);
Text_template(const OPTIONAL<Text>& other_value);
Text_template(const Text_template& other_value);
~Text_template();
Text_template& operator=(template_sel other_value);
Text_template& operator=(const Text& other_value);
Text_template& operator=(const OPTIONAL<Text>& other_value);
Text_template& operator=(const Text_template& other_value);
boolean match(const Text& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
Text valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
Text_template& list_item(unsigned int list_index) const;
CHARSTRING_template& lang();
const CHARSTRING_template& lang() const;
UNIVERSAL_CHARSTRING_template& base();
const UNIVERSAL_CHARSTRING_template& base() const;
int size_of() const;
void log() const;
void log_match(const Text& match_value) const;
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
extern const XERdescriptor_t Bad__format_xer_;
extern const TTCN_Typedescriptor_t Bad__format_descr_;
extern const XERdescriptor_t Bad__namespace__prefix_xer_;
extern const TTCN_Typedescriptor_t Bad__namespace__prefix_descr_;
extern const XERdescriptor_t Conflict_xer_;
extern const TTCN_Typedescriptor_t Conflict_descr_;
extern const XERdescriptor_t Connection__timeout_xer_;
extern const TTCN_Typedescriptor_t Connection__timeout_descr_;
extern const XERdescriptor_t Host__gone_xer_;
extern const TTCN_Typedescriptor_t Host__gone_descr_;
extern const XERdescriptor_t Host__unknown_xer_;
extern const TTCN_Typedescriptor_t Host__unknown_descr_;
extern const XERdescriptor_t Improper__addressing_xer_;
extern const TTCN_Typedescriptor_t Improper__addressing_descr_;
extern const XERdescriptor_t Internal__server__error_xer_;
extern const TTCN_Typedescriptor_t Internal__server__error_descr_;
extern const XERdescriptor_t Invalid__from_xer_;
extern const TTCN_Typedescriptor_t Invalid__from_descr_;
extern const XERdescriptor_t Invalid__id_xer_;
extern const TTCN_Typedescriptor_t Invalid__id_descr_;
extern const XERdescriptor_t Invalid__namespace_xer_;
extern const TTCN_Typedescriptor_t Invalid__namespace_descr_;
extern const XERdescriptor_t Invalid__xml_xer_;
extern const TTCN_Typedescriptor_t Invalid__xml_descr_;
extern const XERdescriptor_t Not__authorized_xer_;
extern const TTCN_Typedescriptor_t Not__authorized_descr_;
extern const XERdescriptor_t Not__well__formed_xer_;
extern const TTCN_Typedescriptor_t Not__well__formed_descr_;
extern const XERdescriptor_t Policy__violation_xer_;
extern const TTCN_Typedescriptor_t Policy__violation_descr_;
extern const XERdescriptor_t Remote__connection__failed_xer_;
extern const TTCN_Typedescriptor_t Remote__connection__failed_descr_;
extern const XERdescriptor_t Reset_xer_;
extern const TTCN_Typedescriptor_t Reset_descr_;
extern const XERdescriptor_t Resource__constraint_xer_;
extern const TTCN_Typedescriptor_t Resource__constraint_descr_;
extern const XERdescriptor_t Restricted__xml_xer_;
extern const TTCN_Typedescriptor_t Restricted__xml_descr_;
extern const XERdescriptor_t See__other__host_xer_;
extern const TTCN_Typedescriptor_t See__other__host_descr_;
extern const XERdescriptor_t System__shutdown_xer_;
extern const TTCN_Typedescriptor_t System__shutdown_descr_;
extern const XERdescriptor_t Undefined__condition_xer_;
extern const TTCN_Typedescriptor_t Undefined__condition_descr_;
extern const XERdescriptor_t Unsupported__encoding_xer_;
extern const TTCN_Typedescriptor_t Unsupported__encoding_descr_;
extern const XERdescriptor_t Unsupported__stanza__type_xer_;
extern const TTCN_Typedescriptor_t Unsupported__stanza__type_descr_;
extern const XERdescriptor_t Unsupported__version_xer_;
extern const TTCN_Typedescriptor_t Unsupported__version_descr_;
extern const XERdescriptor_t StreamErrorGroup_xer_;
extern const TTCN_JSONdescriptor_t StreamErrorGroup_json_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_descr_;
extern const XERdescriptor_t StreamErrorGroup_bad__format_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_bad__format_descr_;
extern const XERdescriptor_t StreamErrorGroup_bad__namespace__prefix_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_bad__namespace__prefix_descr_;
extern const XERdescriptor_t StreamErrorGroup_conflict_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_conflict_descr_;
extern const XERdescriptor_t StreamErrorGroup_connection__timeout_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_connection__timeout_descr_;
extern const XERdescriptor_t StreamErrorGroup_host__gone_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_host__gone_descr_;
extern const XERdescriptor_t StreamErrorGroup_host__unknown_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_host__unknown_descr_;
extern const XERdescriptor_t StreamErrorGroup_improper__addressing_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_improper__addressing_descr_;
extern const XERdescriptor_t StreamErrorGroup_internal__server__error_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_internal__server__error_descr_;
extern const XERdescriptor_t StreamErrorGroup_invalid__from_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_invalid__from_descr_;
extern const XERdescriptor_t StreamErrorGroup_invalid__id_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_invalid__id_descr_;
extern const XERdescriptor_t StreamErrorGroup_invalid__namespace_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_invalid__namespace_descr_;
extern const XERdescriptor_t StreamErrorGroup_invalid__xml_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_invalid__xml_descr_;
extern const XERdescriptor_t StreamErrorGroup_not__authorized_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_not__authorized_descr_;
extern const XERdescriptor_t StreamErrorGroup_not__well__formed_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_not__well__formed_descr_;
extern const XERdescriptor_t StreamErrorGroup_policy__violation_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_policy__violation_descr_;
extern const XERdescriptor_t StreamErrorGroup_remote__connection__failed_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_remote__connection__failed_descr_;
extern const XERdescriptor_t StreamErrorGroup_reset_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_reset_descr_;
extern const XERdescriptor_t StreamErrorGroup_resource__constraint_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_resource__constraint_descr_;
extern const XERdescriptor_t StreamErrorGroup_restricted__xml_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_restricted__xml_descr_;
extern const XERdescriptor_t StreamErrorGroup_see__other__host_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_see__other__host_descr_;
extern const XERdescriptor_t StreamErrorGroup_system__shutdown_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_system__shutdown_descr_;
extern const XERdescriptor_t StreamErrorGroup_undefined__condition_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_undefined__condition_descr_;
extern const XERdescriptor_t StreamErrorGroup_unsupported__encoding_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_unsupported__encoding_descr_;
extern const XERdescriptor_t StreamErrorGroup_unsupported__stanza__type_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_unsupported__stanza__type_descr_;
extern const XERdescriptor_t StreamErrorGroup_unsupported__version_xer_;
extern const TTCN_Typedescriptor_t StreamErrorGroup_unsupported__version_descr_;
extern const XERdescriptor_t Text_base_xer_;
extern const TTCN_Typedescriptor_t Text_base_descr_;
extern const XERdescriptor_t Text_xer_;
extern const TTCN_JSONdescriptor_t Text_json_;
extern const TTCN_Typedescriptor_t Text_descr_;
extern const XERdescriptor_t Text_lang_xer_;
extern const TTCN_Typedescriptor_t Text_lang_descr_;
extern TTCN_Module module_object;

} /* end of namespace */

#endif