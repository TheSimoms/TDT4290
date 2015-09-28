// This C++ header file was generated by the TTCN-3 compiler
// of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for user (user@user-multicom) on Fri Sep 25 13:42:36 2015

// Copyright Ericsson Telecom AB 2000-2014

// Do not edit this file unless you know what you are doing.

#ifndef http__jabber__org__protocol__disco__items_HH
#define http__jabber__org__protocol__disco__items_HH

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

#undef http__jabber__org__protocol__disco__items_HH
#endif

namespace http__jabber__org__protocol__disco__items {

/* Forward declarations of classes */

class Query;
class Query_template;
class Query_sequence_item__list;
class Query_sequence_item__list_template;
class Empty;
class Empty_template;
class Item;
class Item_template;
class Query_sequence;
class Query_sequence_template;

} /* end of namespace */

#ifndef http__jabber__org__protocol__disco__items_HH
#define http__jabber__org__protocol__disco__items_HH

namespace http__jabber__org__protocol__disco__items {

/* Type definitions */

typedef UNIVERSAL_CHARSTRING FullJIDType;
typedef UNIVERSAL_CHARSTRING_template FullJIDType_template;

/* Class definitions */

class Query : public Base_Type {
  OPTIONAL<UNIVERSAL_CHARSTRING> field_node;
  OPTIONAL<Query_sequence> field_sequence;
  boolean bound_flag;
public:
  Query();
  Query(const OPTIONAL<UNIVERSAL_CHARSTRING>& par_node,
    const OPTIONAL<Query_sequence>& par_sequence);
  Query(const Query& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  Query& operator=(const Query& other_value);
  boolean operator==(const Query& other_value) const;
  inline boolean operator!=(const Query& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline OPTIONAL<UNIVERSAL_CHARSTRING>& node()
    {return field_node;}
  inline const OPTIONAL<UNIVERSAL_CHARSTRING>& node() const
    {return field_node;}
  inline OPTIONAL<Query_sequence>& sequence()
    {return field_sequence;}
  inline const OPTIONAL<Query_sequence>& sequence() const
    {return field_sequence;}
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

class Query_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
Query_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const Query& other_value);
void copy_template(const Query_template& other_value);

public:
Query_template();
Query_template(template_sel other_value);
Query_template(const Query& other_value);
Query_template(const OPTIONAL<Query>& other_value);
Query_template(const Query_template& other_value);
~Query_template();
Query_template& operator=(template_sel other_value);
Query_template& operator=(const Query& other_value);
Query_template& operator=(const OPTIONAL<Query>& other_value);
Query_template& operator=(const Query_template& other_value);
boolean match(const Query& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
Query valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
Query_template& list_item(unsigned int list_index) const;
UNIVERSAL_CHARSTRING_template& node();
const UNIVERSAL_CHARSTRING_template& node() const;
Query_sequence_template& sequence();
const Query_sequence_template& sequence() const;
int size_of() const;
void log() const;
void log_match(const Query& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};

class Query_sequence_item__list : public Base_Type {
struct recordof_setof_struct {
int ref_count;
int n_elements;
Item **value_elements;
} *val_ptr;

static const Item UNBOUND_ELEM;
private:
friend boolean operator==(null_type null_value, const Query_sequence_item__list& other_value);

public:
  typedef Item of_type;
Query_sequence_item__list();
Query_sequence_item__list(null_type other_value);
Query_sequence_item__list(const Query_sequence_item__list& other_value);
~Query_sequence_item__list();

void clean_up();
Query_sequence_item__list& operator=(null_type other_value);
Query_sequence_item__list& operator=(const Query_sequence_item__list& other_value);

boolean operator==(null_type other_value) const;
boolean operator==(const Query_sequence_item__list& other_value) const;
inline boolean operator!=(null_type other_value) const { return !(*this == other_value); }
inline boolean operator!=(const Query_sequence_item__list& other_value) const { return !(*this == other_value); }

Item& operator[](int index_value);
Item& operator[](const INTEGER& index_value);
const Item& operator[](int index_value) const;
const Item& operator[](const INTEGER& index_value) const;

Query_sequence_item__list operator<<=(int rotate_count) const;
Query_sequence_item__list operator<<=(const INTEGER& rotate_count) const;
Query_sequence_item__list operator>>=(int rotate_count) const;
Query_sequence_item__list operator>>=(const INTEGER& rotate_count) const;

Query_sequence_item__list operator+(const Query_sequence_item__list& other_value) const;

Query_sequence_item__list substr(int index, int returncount) const;

Query_sequence_item__list replace(int index, int len, const Query_sequence_item__list& repl) const;

Query_sequence_item__list replace(int index, int len, const Query_sequence_item__list_template& repl) const;

void set_size(int new_size);
inline boolean is_bound() const {return val_ptr != NULL; }
inline boolean is_present() const { return is_bound(); }
boolean is_value() const;
int size_of() const;
int n_elem() const { return size_of(); }
int lengthof() const;
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

class Query_sequence_item__list_template : public Record_Of_Template {
union {
struct {
int n_elements;
Item_template **value_elements;
} single_value;
struct {
unsigned int n_values;
Query_sequence_item__list_template *list_value;
} value_list;
};
void copy_value(const Query_sequence_item__list& other_value);
void copy_template(const Query_sequence_item__list_template& other_value);
static boolean match_function_specific(const Base_Type *value_ptr, int value_index, const Restricted_Length_Template *template_ptr, int template_index);

public:
Query_sequence_item__list_template();
Query_sequence_item__list_template(template_sel other_value);
Query_sequence_item__list_template(null_type other_value);
Query_sequence_item__list_template(const Query_sequence_item__list& other_value);
Query_sequence_item__list_template(const OPTIONAL<Query_sequence_item__list>& other_value);
Query_sequence_item__list_template(const Query_sequence_item__list_template& other_value);
~Query_sequence_item__list_template();

void clean_up();
Query_sequence_item__list_template& operator=(template_sel other_value);
Query_sequence_item__list_template& operator=(null_type other_value);
Query_sequence_item__list_template& operator=(const Query_sequence_item__list& other_value);
Query_sequence_item__list_template& operator=(const OPTIONAL<Query_sequence_item__list>& other_value);
Query_sequence_item__list_template& operator=(const Query_sequence_item__list_template& other_value);

Item_template& operator[](int index_value);
Item_template& operator[](const INTEGER& index_value);
const Item_template& operator[](int index_value) const;
const Item_template& operator[](const INTEGER& index_value) const;

void set_size(int new_size);
int n_elem() const;
int size_of(boolean is_size) const;
inline int size_of() const { return size_of(TRUE); }
inline int lengthof() const { return size_of(FALSE); }
boolean match(const Query_sequence_item__list& other_value) const;
inline boolean is_bound() const 
  {return template_selection != UNINITIALIZED_TEMPLATE; }
boolean is_value() const;
Query_sequence_item__list valueof() const;
Query_sequence_item__list substr(int index, int returncount) const;

Query_sequence_item__list replace(int index, int len, const Query_sequence_item__list_template& repl) const;

Query_sequence_item__list replace(int index, int len, const Query_sequence_item__list& repl) const;

void set_type(template_sel template_type, unsigned int list_length);
Query_sequence_item__list_template& list_item(unsigned int list_index);
void log() const;
void log_match(const Query_sequence_item__list& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
boolean is_present() const;
boolean match_omit() const;
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
};

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

class Item : public Base_Type {
  UNIVERSAL_CHARSTRING field_jid;
  OPTIONAL<UNIVERSAL_CHARSTRING> field_name;
  OPTIONAL<UNIVERSAL_CHARSTRING> field_node;
  Empty field_base;
  boolean bound_flag;
public:
  Item();
  Item(const UNIVERSAL_CHARSTRING& par_jid,
    const OPTIONAL<UNIVERSAL_CHARSTRING>& par_name,
    const OPTIONAL<UNIVERSAL_CHARSTRING>& par_node,
    const Empty& par_base);
  Item(const Item& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  Item& operator=(const Item& other_value);
  boolean operator==(const Item& other_value) const;
  inline boolean operator!=(const Item& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline UNIVERSAL_CHARSTRING& jid()
    {return field_jid;}
  inline const UNIVERSAL_CHARSTRING& jid() const
    {return field_jid;}
  inline OPTIONAL<UNIVERSAL_CHARSTRING>& name()
    {return field_name;}
  inline const OPTIONAL<UNIVERSAL_CHARSTRING>& name() const
    {return field_name;}
  inline OPTIONAL<UNIVERSAL_CHARSTRING>& node()
    {return field_node;}
  inline const OPTIONAL<UNIVERSAL_CHARSTRING>& node() const
    {return field_node;}
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

class Item_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
Item_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const Item& other_value);
void copy_template(const Item_template& other_value);

public:
Item_template();
Item_template(template_sel other_value);
Item_template(const Item& other_value);
Item_template(const OPTIONAL<Item>& other_value);
Item_template(const Item_template& other_value);
~Item_template();
Item_template& operator=(template_sel other_value);
Item_template& operator=(const Item& other_value);
Item_template& operator=(const OPTIONAL<Item>& other_value);
Item_template& operator=(const Item_template& other_value);
boolean match(const Item& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
Item valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
Item_template& list_item(unsigned int list_index) const;
UNIVERSAL_CHARSTRING_template& jid();
const UNIVERSAL_CHARSTRING_template& jid() const;
UNIVERSAL_CHARSTRING_template& name();
const UNIVERSAL_CHARSTRING_template& name() const;
UNIVERSAL_CHARSTRING_template& node();
const UNIVERSAL_CHARSTRING_template& node() const;
Empty_template& base();
const Empty_template& base() const;
int size_of() const;
void log() const;
void log_match(const Item& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};

class Query_sequence : public Base_Type {
  Query_sequence_item__list field_item__list;
  boolean bound_flag;
public:
  Query_sequence();
  Query_sequence(const Query_sequence_item__list& par_item__list);
  Query_sequence(const Query_sequence& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  Query_sequence& operator=(const Query_sequence& other_value);
  boolean operator==(const Query_sequence& other_value) const;
  inline boolean operator!=(const Query_sequence& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline Query_sequence_item__list& item__list()
    {return field_item__list;}
  inline const Query_sequence_item__list& item__list() const
    {return field_item__list;}
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

class Query_sequence_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
Query_sequence_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const Query_sequence& other_value);
void copy_template(const Query_sequence_template& other_value);

public:
Query_sequence_template();
Query_sequence_template(template_sel other_value);
Query_sequence_template(const Query_sequence& other_value);
Query_sequence_template(const OPTIONAL<Query_sequence>& other_value);
Query_sequence_template(const Query_sequence_template& other_value);
~Query_sequence_template();
Query_sequence_template& operator=(template_sel other_value);
Query_sequence_template& operator=(const Query_sequence& other_value);
Query_sequence_template& operator=(const OPTIONAL<Query_sequence>& other_value);
Query_sequence_template& operator=(const Query_sequence_template& other_value);
boolean match(const Query_sequence& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
Query_sequence valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
Query_sequence_template& list_item(unsigned int list_index) const;
Query_sequence_item__list_template& item__list();
const Query_sequence_item__list_template& item__list() const;
int size_of() const;
void log() const;
void log_match(const Query_sequence& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};


/* Function prototypes */

extern boolean operator==(null_type null_value, const Query_sequence_item__list& other_value);
inline boolean operator!=(null_type null_value, const Query_sequence_item__list& other_value) { return !(null_value == other_value); }

/* Global variable declarations */

extern const XERdescriptor_t Query_xer_;
extern const TTCN_JSONdescriptor_t Query_json_;
extern const TTCN_Typedescriptor_t Query_descr_;
extern const XERdescriptor_t Query_node_xer_;
extern const TTCN_Typedescriptor_t Query_node_descr_;
extern const XERdescriptor_t Query_sequence_item__list_xer_;
extern const TTCN_JSONdescriptor_t Query_sequence_item__list_json_;
extern const TTCN_Typedescriptor_t Query_sequence_item__list_descr_;
extern const XERdescriptor_t FullJIDType_xer_;
extern const TTCN_Typedescriptor_t FullJIDType_descr_;
extern const XERdescriptor_t Item_jid_xer_;
extern const TTCN_Typedescriptor_t Item_jid_descr_;
extern const XERdescriptor_t Empty_xer_;
extern const TTCN_JSONdescriptor_t Empty_json_;
extern const TTCN_Typedescriptor_t Empty_descr_;
extern const XERdescriptor_t Item_base_xer_;
extern const TTCN_Typedescriptor_t Item_base_descr_;
extern const XERdescriptor_t Item_xer_;
extern const TTCN_JSONdescriptor_t Item_json_;
extern const TTCN_Typedescriptor_t Item_descr_;
extern const XERdescriptor_t Item_name_xer_;
extern const TTCN_Typedescriptor_t Item_name_descr_;
extern const XERdescriptor_t Item_node_xer_;
extern const TTCN_Typedescriptor_t Item_node_descr_;
extern const XERdescriptor_t Query_sequence_item__list_0_xer_;
extern const TTCN_Typedescriptor_t Query_sequence_item__list_0_descr_;
extern const XERdescriptor_t Query_sequence_xer_;
extern const TTCN_JSONdescriptor_t Query_sequence_json_;
extern const TTCN_Typedescriptor_t Query_sequence_descr_;
extern TTCN_Module module_object;

} /* end of namespace */

#endif
