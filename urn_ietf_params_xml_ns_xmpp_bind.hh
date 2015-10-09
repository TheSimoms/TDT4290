// This C++ header file was generated by the TTCN-3 compiler
// of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for user (user@user-multicom) on Fri Oct  9 11:34:10 2015

// Copyright Ericsson Telecom AB 2000-2014

// Do not edit this file unless you know what you are doing.

#ifndef urn__ietf__params__xml__ns__xmpp__bind_HH
#define urn__ietf__params__xml__ns__xmpp__bind_HH

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

#undef urn__ietf__params__xml__ns__xmpp__bind_HH
#endif

namespace urn__ietf__params__xml__ns__xmpp__bind {

/* Forward declarations of classes */

class Bind_choice;
class Bind_choice_template;
class Bind;
class Bind_template;

} /* end of namespace */

#ifndef urn__ietf__params__xml__ns__xmpp__bind_HH
#define urn__ietf__params__xml__ns__xmpp__bind_HH

namespace urn__ietf__params__xml__ns__xmpp__bind {

/* Type definitions */

typedef UNIVERSAL_CHARSTRING ResourceType;
typedef UNIVERSAL_CHARSTRING_template ResourceType_template;
typedef UNIVERSAL_CHARSTRING FullJIDType;
typedef UNIVERSAL_CHARSTRING_template FullJIDType_template;

/* Class definitions */

class Bind_choice : public Base_Type {
public:
enum union_selection_type { UNBOUND_VALUE = 0, ALT_resource = 1, ALT_jid = 2 };
private:
union_selection_type union_selection;
union {
UNIVERSAL_CHARSTRING *field_resource;
UNIVERSAL_CHARSTRING *field_jid;
};
void copy_value(const Bind_choice& other_value);

public:
Bind_choice();
Bind_choice(const Bind_choice& other_value);
~Bind_choice();
Bind_choice& operator=(const Bind_choice& other_value);
boolean operator==(const Bind_choice& other_value) const;
inline boolean operator!=(const Bind_choice& other_value) const { return !(*this == other_value); }
UNIVERSAL_CHARSTRING& resource();
const UNIVERSAL_CHARSTRING& resource() const;
UNIVERSAL_CHARSTRING& jid();
const UNIVERSAL_CHARSTRING& jid() const;
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

class Bind_choice_template : public Base_Template {
union {
struct {
Bind_choice::union_selection_type union_selection;
union {
UNIVERSAL_CHARSTRING_template *field_resource;
UNIVERSAL_CHARSTRING_template *field_jid;
};
} single_value;
struct {
unsigned int n_values;
Bind_choice_template *list_value;
} value_list;
};
void copy_value(const Bind_choice& other_value);

void copy_template(const Bind_choice_template& other_value);

public:
Bind_choice_template();
Bind_choice_template(template_sel other_value);
Bind_choice_template(const Bind_choice& other_value);
Bind_choice_template(const OPTIONAL<Bind_choice>& other_value);
Bind_choice_template(const Bind_choice_template& other_value);
~Bind_choice_template();
void clean_up();
Bind_choice_template& operator=(template_sel other_value);
Bind_choice_template& operator=(const Bind_choice& other_value);
Bind_choice_template& operator=(const OPTIONAL<Bind_choice>& other_value);
Bind_choice_template& operator=(const Bind_choice_template& other_value);
boolean match(const Bind_choice& other_value) const;
boolean is_value() const;Bind_choice valueof() const;
Bind_choice_template& list_item(unsigned int list_index) const;
void set_type(template_sel template_type, unsigned int list_length);
UNIVERSAL_CHARSTRING_template& resource();
const UNIVERSAL_CHARSTRING_template& resource() const;
UNIVERSAL_CHARSTRING_template& jid();
const UNIVERSAL_CHARSTRING_template& jid() const;
boolean ischosen(Bind_choice::union_selection_type checked_selection) const;
void log() const;
void log_match(const Bind_choice& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
boolean is_present() const;
boolean match_omit() const;
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
};

class Bind : public Base_Type {
  Bind_choice field_choice;
  boolean bound_flag;
public:
  Bind();
  Bind(const Bind_choice& par_choice);
  Bind(const Bind& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  Bind& operator=(const Bind& other_value);
  boolean operator==(const Bind& other_value) const;
  inline boolean operator!=(const Bind& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline Bind_choice& choice()
    {return field_choice;}
  inline const Bind_choice& choice() const
    {return field_choice;}
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

class Bind_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
Bind_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const Bind& other_value);
void copy_template(const Bind_template& other_value);

public:
Bind_template();
Bind_template(template_sel other_value);
Bind_template(const Bind& other_value);
Bind_template(const OPTIONAL<Bind>& other_value);
Bind_template(const Bind_template& other_value);
~Bind_template();
Bind_template& operator=(template_sel other_value);
Bind_template& operator=(const Bind& other_value);
Bind_template& operator=(const OPTIONAL<Bind>& other_value);
Bind_template& operator=(const Bind_template& other_value);
boolean match(const Bind& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
Bind valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
Bind_template& list_item(unsigned int list_index) const;
Bind_choice_template& choice();
const Bind_choice_template& choice() const;
int size_of() const;
void log() const;
void log_match(const Bind& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};


/* Global variable declarations */

extern const XERdescriptor_t Bind_choice_xer_;
extern const TTCN_JSONdescriptor_t Bind_choice_json_;
extern const TTCN_Typedescriptor_t Bind_choice_descr_;
extern const XERdescriptor_t ResourceType_xer_;
extern const TTCN_Typedescriptor_t ResourceType_descr_;
extern const XERdescriptor_t Bind_choice_resource_xer_;
extern const TTCN_Typedescriptor_t Bind_choice_resource_descr_;
extern const XERdescriptor_t FullJIDType_xer_;
extern const TTCN_Typedescriptor_t FullJIDType_descr_;
extern const XERdescriptor_t Bind_choice_jid_xer_;
extern const TTCN_Typedescriptor_t Bind_choice_jid_descr_;
extern const XERdescriptor_t Bind_xer_;
extern const TTCN_JSONdescriptor_t Bind_json_;
extern const TTCN_Typedescriptor_t Bind_descr_;
extern TTCN_Module module_object;

} /* end of namespace */

#endif
