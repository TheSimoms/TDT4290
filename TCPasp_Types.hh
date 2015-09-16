// This C++ header file was generated by the TTCN-3 compiler
// of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for user (user@user-multicom) on Wed Sep 16 15:50:39 2015

// Copyright Ericsson Telecom AB 2000-2014

// Do not edit this file unless you know what you are doing.

#ifndef TCPasp__Types_HH
#define TCPasp__Types_HH

#ifdef TITAN_RUNTIME_2
#error Generated code does not match with used runtime.\
 Code was generated without -R option but -DTITAN_RUNTIME_2 was used.
#endif

/* Header file includes */

#include <TTCN3.hh>

#if TTCN3_VERSION != 50300
#error Version mismatch detected.\
 Please check the version of the TTCN-3 compiler and the base library.
#endif

#ifndef LINUX
#error This file should be compiled on LINUX
#endif

#undef TCPasp__Types_HH
#endif

namespace TCPasp__Types {

/* Forward declarations of classes */

class ASP__TCP;
class ASP__TCP_template;
class ASP__TCP__Connect;
class ASP__TCP__Connect_template;
class ASP__TCP__Connect__result;
class ASP__TCP__Connect__result_template;
class ASP__TCP__Connected;
class ASP__TCP__Connected_template;
class ASP__TCP__Close;
class ASP__TCP__Close_template;
class ASP__TCP__Listen;
class ASP__TCP__Listen_template;
class ASP__TCP__Listen__result;
class ASP__TCP__Listen__result_template;
class ASP__TCP__Shutdown;
class ASP__TCP__Shutdown_template;
class TCP__Send__error__types;
class TCP__Send__error__types_template;
class ASP__TCP__Send__error;
class ASP__TCP__Send__error_template;

} /* end of namespace */

#ifndef TCPasp__Types_HH
#define TCPasp__Types_HH

namespace TCPasp__Types {

/* Type definitions */

typedef OCTETSTRING PDU__TCP;
typedef OCTETSTRING_template PDU__TCP_template;
typedef CHARSTRING ASP__TCP__SetAddressFamily;
typedef CHARSTRING_template ASP__TCP__SetAddressFamily_template;

/* Class definitions */

class ASP__TCP {
  OPTIONAL<INTEGER> field_client__id;
  OCTETSTRING field_data;
  boolean bound_flag;
public:
  ASP__TCP();
  ASP__TCP(const OPTIONAL<INTEGER>& par_client__id,
    const OCTETSTRING& par_data);
  ASP__TCP(const ASP__TCP& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  ASP__TCP& operator=(const ASP__TCP& other_value);
  boolean operator==(const ASP__TCP& other_value) const;
  inline boolean operator!=(const ASP__TCP& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline OPTIONAL<INTEGER>& client__id()
    {return field_client__id;}
  inline const OPTIONAL<INTEGER>& client__id() const
    {return field_client__id;}
  inline OCTETSTRING& data()
    {return field_data;}
  inline const OCTETSTRING& data() const
    {return field_data;}
  int size_of() const;
  void log() const;
  void set_param(Module_Param& param);
  void set_implicit_omit();
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
};

class ASP__TCP_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
ASP__TCP_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const ASP__TCP& other_value);
void copy_template(const ASP__TCP_template& other_value);

public:
ASP__TCP_template();
ASP__TCP_template(template_sel other_value);
ASP__TCP_template(const ASP__TCP& other_value);
ASP__TCP_template(const OPTIONAL<ASP__TCP>& other_value);
ASP__TCP_template(const ASP__TCP_template& other_value);
~ASP__TCP_template();
ASP__TCP_template& operator=(template_sel other_value);
ASP__TCP_template& operator=(const ASP__TCP& other_value);
ASP__TCP_template& operator=(const OPTIONAL<ASP__TCP>& other_value);
ASP__TCP_template& operator=(const ASP__TCP_template& other_value);
boolean match(const ASP__TCP& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
ASP__TCP valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
ASP__TCP_template& list_item(unsigned int list_index) const;
INTEGER_template& client__id();
const INTEGER_template& client__id() const;
OCTETSTRING_template& data();
const OCTETSTRING_template& data() const;
int size_of() const;
void log() const;
void log_match(const ASP__TCP& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};

class ASP__TCP__Connect {
  CHARSTRING field_hostname;
  INTEGER field_portnumber;
  OPTIONAL<CHARSTRING> field_local__hostname;
  OPTIONAL<INTEGER> field_local__portnumber;
  boolean bound_flag;
public:
  ASP__TCP__Connect();
  ASP__TCP__Connect(const CHARSTRING& par_hostname,
    const INTEGER& par_portnumber,
    const OPTIONAL<CHARSTRING>& par_local__hostname,
    const OPTIONAL<INTEGER>& par_local__portnumber);
  ASP__TCP__Connect(const ASP__TCP__Connect& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  ASP__TCP__Connect& operator=(const ASP__TCP__Connect& other_value);
  boolean operator==(const ASP__TCP__Connect& other_value) const;
  inline boolean operator!=(const ASP__TCP__Connect& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline CHARSTRING& hostname()
    {return field_hostname;}
  inline const CHARSTRING& hostname() const
    {return field_hostname;}
  inline INTEGER& portnumber()
    {return field_portnumber;}
  inline const INTEGER& portnumber() const
    {return field_portnumber;}
  inline OPTIONAL<CHARSTRING>& local__hostname()
    {return field_local__hostname;}
  inline const OPTIONAL<CHARSTRING>& local__hostname() const
    {return field_local__hostname;}
  inline OPTIONAL<INTEGER>& local__portnumber()
    {return field_local__portnumber;}
  inline const OPTIONAL<INTEGER>& local__portnumber() const
    {return field_local__portnumber;}
  int size_of() const;
  void log() const;
  void set_param(Module_Param& param);
  void set_implicit_omit();
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
};

class ASP__TCP__Connect_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
ASP__TCP__Connect_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const ASP__TCP__Connect& other_value);
void copy_template(const ASP__TCP__Connect_template& other_value);

public:
ASP__TCP__Connect_template();
ASP__TCP__Connect_template(template_sel other_value);
ASP__TCP__Connect_template(const ASP__TCP__Connect& other_value);
ASP__TCP__Connect_template(const OPTIONAL<ASP__TCP__Connect>& other_value);
ASP__TCP__Connect_template(const ASP__TCP__Connect_template& other_value);
~ASP__TCP__Connect_template();
ASP__TCP__Connect_template& operator=(template_sel other_value);
ASP__TCP__Connect_template& operator=(const ASP__TCP__Connect& other_value);
ASP__TCP__Connect_template& operator=(const OPTIONAL<ASP__TCP__Connect>& other_value);
ASP__TCP__Connect_template& operator=(const ASP__TCP__Connect_template& other_value);
boolean match(const ASP__TCP__Connect& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
ASP__TCP__Connect valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
ASP__TCP__Connect_template& list_item(unsigned int list_index) const;
CHARSTRING_template& hostname();
const CHARSTRING_template& hostname() const;
INTEGER_template& portnumber();
const INTEGER_template& portnumber() const;
CHARSTRING_template& local__hostname();
const CHARSTRING_template& local__hostname() const;
INTEGER_template& local__portnumber();
const INTEGER_template& local__portnumber() const;
int size_of() const;
void log() const;
void log_match(const ASP__TCP__Connect& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};

class ASP__TCP__Connect__result {
  INTEGER field_client__id;
  boolean bound_flag;
public:
  ASP__TCP__Connect__result();
  ASP__TCP__Connect__result(const INTEGER& par_client__id);
  ASP__TCP__Connect__result(const ASP__TCP__Connect__result& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  ASP__TCP__Connect__result& operator=(const ASP__TCP__Connect__result& other_value);
  boolean operator==(const ASP__TCP__Connect__result& other_value) const;
  inline boolean operator!=(const ASP__TCP__Connect__result& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline INTEGER& client__id()
    {return field_client__id;}
  inline const INTEGER& client__id() const
    {return field_client__id;}
  int size_of() const;
  void log() const;
  void set_param(Module_Param& param);
  void set_implicit_omit();
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
};

class ASP__TCP__Connect__result_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
ASP__TCP__Connect__result_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const ASP__TCP__Connect__result& other_value);
void copy_template(const ASP__TCP__Connect__result_template& other_value);

public:
ASP__TCP__Connect__result_template();
ASP__TCP__Connect__result_template(template_sel other_value);
ASP__TCP__Connect__result_template(const ASP__TCP__Connect__result& other_value);
ASP__TCP__Connect__result_template(const OPTIONAL<ASP__TCP__Connect__result>& other_value);
ASP__TCP__Connect__result_template(const ASP__TCP__Connect__result_template& other_value);
~ASP__TCP__Connect__result_template();
ASP__TCP__Connect__result_template& operator=(template_sel other_value);
ASP__TCP__Connect__result_template& operator=(const ASP__TCP__Connect__result& other_value);
ASP__TCP__Connect__result_template& operator=(const OPTIONAL<ASP__TCP__Connect__result>& other_value);
ASP__TCP__Connect__result_template& operator=(const ASP__TCP__Connect__result_template& other_value);
boolean match(const ASP__TCP__Connect__result& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
ASP__TCP__Connect__result valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
ASP__TCP__Connect__result_template& list_item(unsigned int list_index) const;
INTEGER_template& client__id();
const INTEGER_template& client__id() const;
int size_of() const;
void log() const;
void log_match(const ASP__TCP__Connect__result& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};

class ASP__TCP__Connected {
  CHARSTRING field_hostname;
  INTEGER field_portnumber;
  INTEGER field_client__id;
  boolean bound_flag;
public:
  ASP__TCP__Connected();
  ASP__TCP__Connected(const CHARSTRING& par_hostname,
    const INTEGER& par_portnumber,
    const INTEGER& par_client__id);
  ASP__TCP__Connected(const ASP__TCP__Connected& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  ASP__TCP__Connected& operator=(const ASP__TCP__Connected& other_value);
  boolean operator==(const ASP__TCP__Connected& other_value) const;
  inline boolean operator!=(const ASP__TCP__Connected& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline CHARSTRING& hostname()
    {return field_hostname;}
  inline const CHARSTRING& hostname() const
    {return field_hostname;}
  inline INTEGER& portnumber()
    {return field_portnumber;}
  inline const INTEGER& portnumber() const
    {return field_portnumber;}
  inline INTEGER& client__id()
    {return field_client__id;}
  inline const INTEGER& client__id() const
    {return field_client__id;}
  int size_of() const;
  void log() const;
  void set_param(Module_Param& param);
  void set_implicit_omit();
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
};

class ASP__TCP__Connected_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
ASP__TCP__Connected_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const ASP__TCP__Connected& other_value);
void copy_template(const ASP__TCP__Connected_template& other_value);

public:
ASP__TCP__Connected_template();
ASP__TCP__Connected_template(template_sel other_value);
ASP__TCP__Connected_template(const ASP__TCP__Connected& other_value);
ASP__TCP__Connected_template(const OPTIONAL<ASP__TCP__Connected>& other_value);
ASP__TCP__Connected_template(const ASP__TCP__Connected_template& other_value);
~ASP__TCP__Connected_template();
ASP__TCP__Connected_template& operator=(template_sel other_value);
ASP__TCP__Connected_template& operator=(const ASP__TCP__Connected& other_value);
ASP__TCP__Connected_template& operator=(const OPTIONAL<ASP__TCP__Connected>& other_value);
ASP__TCP__Connected_template& operator=(const ASP__TCP__Connected_template& other_value);
boolean match(const ASP__TCP__Connected& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
ASP__TCP__Connected valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
ASP__TCP__Connected_template& list_item(unsigned int list_index) const;
CHARSTRING_template& hostname();
const CHARSTRING_template& hostname() const;
INTEGER_template& portnumber();
const INTEGER_template& portnumber() const;
INTEGER_template& client__id();
const INTEGER_template& client__id() const;
int size_of() const;
void log() const;
void log_match(const ASP__TCP__Connected& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};

class ASP__TCP__Close {
  OPTIONAL<INTEGER> field_client__id;
  boolean bound_flag;
public:
  ASP__TCP__Close();
  ASP__TCP__Close(const OPTIONAL<INTEGER>& par_client__id);
  ASP__TCP__Close(const ASP__TCP__Close& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  ASP__TCP__Close& operator=(const ASP__TCP__Close& other_value);
  boolean operator==(const ASP__TCP__Close& other_value) const;
  inline boolean operator!=(const ASP__TCP__Close& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline OPTIONAL<INTEGER>& client__id()
    {return field_client__id;}
  inline const OPTIONAL<INTEGER>& client__id() const
    {return field_client__id;}
  int size_of() const;
  void log() const;
  void set_param(Module_Param& param);
  void set_implicit_omit();
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
};

class ASP__TCP__Close_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
ASP__TCP__Close_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const ASP__TCP__Close& other_value);
void copy_template(const ASP__TCP__Close_template& other_value);

public:
ASP__TCP__Close_template();
ASP__TCP__Close_template(template_sel other_value);
ASP__TCP__Close_template(const ASP__TCP__Close& other_value);
ASP__TCP__Close_template(const OPTIONAL<ASP__TCP__Close>& other_value);
ASP__TCP__Close_template(const ASP__TCP__Close_template& other_value);
~ASP__TCP__Close_template();
ASP__TCP__Close_template& operator=(template_sel other_value);
ASP__TCP__Close_template& operator=(const ASP__TCP__Close& other_value);
ASP__TCP__Close_template& operator=(const OPTIONAL<ASP__TCP__Close>& other_value);
ASP__TCP__Close_template& operator=(const ASP__TCP__Close_template& other_value);
boolean match(const ASP__TCP__Close& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
ASP__TCP__Close valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
ASP__TCP__Close_template& list_item(unsigned int list_index) const;
INTEGER_template& client__id();
const INTEGER_template& client__id() const;
int size_of() const;
void log() const;
void log_match(const ASP__TCP__Close& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};

class ASP__TCP__Listen {
  OPTIONAL<INTEGER> field_portnumber;
  OPTIONAL<CHARSTRING> field_local__hostname;
  boolean bound_flag;
public:
  ASP__TCP__Listen();
  ASP__TCP__Listen(const OPTIONAL<INTEGER>& par_portnumber,
    const OPTIONAL<CHARSTRING>& par_local__hostname);
  ASP__TCP__Listen(const ASP__TCP__Listen& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  ASP__TCP__Listen& operator=(const ASP__TCP__Listen& other_value);
  boolean operator==(const ASP__TCP__Listen& other_value) const;
  inline boolean operator!=(const ASP__TCP__Listen& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline OPTIONAL<INTEGER>& portnumber()
    {return field_portnumber;}
  inline const OPTIONAL<INTEGER>& portnumber() const
    {return field_portnumber;}
  inline OPTIONAL<CHARSTRING>& local__hostname()
    {return field_local__hostname;}
  inline const OPTIONAL<CHARSTRING>& local__hostname() const
    {return field_local__hostname;}
  int size_of() const;
  void log() const;
  void set_param(Module_Param& param);
  void set_implicit_omit();
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
};

class ASP__TCP__Listen_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
ASP__TCP__Listen_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const ASP__TCP__Listen& other_value);
void copy_template(const ASP__TCP__Listen_template& other_value);

public:
ASP__TCP__Listen_template();
ASP__TCP__Listen_template(template_sel other_value);
ASP__TCP__Listen_template(const ASP__TCP__Listen& other_value);
ASP__TCP__Listen_template(const OPTIONAL<ASP__TCP__Listen>& other_value);
ASP__TCP__Listen_template(const ASP__TCP__Listen_template& other_value);
~ASP__TCP__Listen_template();
ASP__TCP__Listen_template& operator=(template_sel other_value);
ASP__TCP__Listen_template& operator=(const ASP__TCP__Listen& other_value);
ASP__TCP__Listen_template& operator=(const OPTIONAL<ASP__TCP__Listen>& other_value);
ASP__TCP__Listen_template& operator=(const ASP__TCP__Listen_template& other_value);
boolean match(const ASP__TCP__Listen& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
ASP__TCP__Listen valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
ASP__TCP__Listen_template& list_item(unsigned int list_index) const;
INTEGER_template& portnumber();
const INTEGER_template& portnumber() const;
CHARSTRING_template& local__hostname();
const CHARSTRING_template& local__hostname() const;
int size_of() const;
void log() const;
void log_match(const ASP__TCP__Listen& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};

class ASP__TCP__Listen__result {
  INTEGER field_portnumber;
  boolean bound_flag;
public:
  ASP__TCP__Listen__result();
  ASP__TCP__Listen__result(const INTEGER& par_portnumber);
  ASP__TCP__Listen__result(const ASP__TCP__Listen__result& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  ASP__TCP__Listen__result& operator=(const ASP__TCP__Listen__result& other_value);
  boolean operator==(const ASP__TCP__Listen__result& other_value) const;
  inline boolean operator!=(const ASP__TCP__Listen__result& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline INTEGER& portnumber()
    {return field_portnumber;}
  inline const INTEGER& portnumber() const
    {return field_portnumber;}
  int size_of() const;
  void log() const;
  void set_param(Module_Param& param);
  void set_implicit_omit();
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
};

class ASP__TCP__Listen__result_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
ASP__TCP__Listen__result_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const ASP__TCP__Listen__result& other_value);
void copy_template(const ASP__TCP__Listen__result_template& other_value);

public:
ASP__TCP__Listen__result_template();
ASP__TCP__Listen__result_template(template_sel other_value);
ASP__TCP__Listen__result_template(const ASP__TCP__Listen__result& other_value);
ASP__TCP__Listen__result_template(const OPTIONAL<ASP__TCP__Listen__result>& other_value);
ASP__TCP__Listen__result_template(const ASP__TCP__Listen__result_template& other_value);
~ASP__TCP__Listen__result_template();
ASP__TCP__Listen__result_template& operator=(template_sel other_value);
ASP__TCP__Listen__result_template& operator=(const ASP__TCP__Listen__result& other_value);
ASP__TCP__Listen__result_template& operator=(const OPTIONAL<ASP__TCP__Listen__result>& other_value);
ASP__TCP__Listen__result_template& operator=(const ASP__TCP__Listen__result_template& other_value);
boolean match(const ASP__TCP__Listen__result& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
ASP__TCP__Listen__result valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
ASP__TCP__Listen__result_template& list_item(unsigned int list_index) const;
INTEGER_template& portnumber();
const INTEGER_template& portnumber() const;
int size_of() const;
void log() const;
void log_match(const ASP__TCP__Listen__result& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};

class ASP__TCP__Shutdown : public Base_Type {
boolean bound_flag;
public:
ASP__TCP__Shutdown();
ASP__TCP__Shutdown(null_type other_value);
ASP__TCP__Shutdown(const ASP__TCP__Shutdown& other_value);
ASP__TCP__Shutdown& operator=(null_type other_value);
ASP__TCP__Shutdown& operator=(const ASP__TCP__Shutdown& other_value);
boolean operator==(null_type other_value) const;
boolean operator==(const ASP__TCP__Shutdown& other_value) const;
inline boolean operator!=(null_type other_value) const { return !(*this == other_value); }
inline boolean operator!=(const ASP__TCP__Shutdown& other_value) const { return !(*this == other_value); }
inline boolean is_bound() const { return bound_flag; }
inline boolean is_present() const { return is_bound(); }
inline boolean is_value() const { return bound_flag; }
inline void clean_up() { bound_flag = FALSE; }
inline void must_bound(const char *err_msg) const { if (!bound_flag) TTCN_error("%s", err_msg); }
void log() const;
void set_param(const Module_Param& param);
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
};

class ASP__TCP__Shutdown_template : public Base_Template {
struct {
unsigned int n_values;
ASP__TCP__Shutdown_template *list_value;
} value_list;
void copy_template(const ASP__TCP__Shutdown_template& other_value);

public:
ASP__TCP__Shutdown_template();
ASP__TCP__Shutdown_template(template_sel other_value);
ASP__TCP__Shutdown_template(null_type other_value);
ASP__TCP__Shutdown_template(const ASP__TCP__Shutdown& other_value);
ASP__TCP__Shutdown_template(const OPTIONAL<ASP__TCP__Shutdown>& other_value);
ASP__TCP__Shutdown_template(const ASP__TCP__Shutdown_template& other_value);
~ASP__TCP__Shutdown_template();
void clean_up();
ASP__TCP__Shutdown_template& operator=(template_sel other_value);
ASP__TCP__Shutdown_template& operator=(null_type other_value);
ASP__TCP__Shutdown_template& operator=(const ASP__TCP__Shutdown& other_value);
ASP__TCP__Shutdown_template& operator=(const OPTIONAL<ASP__TCP__Shutdown>& other_value);
ASP__TCP__Shutdown_template& operator=(const ASP__TCP__Shutdown_template& other_value);
boolean match(null_type other_value) const;
boolean match(const ASP__TCP__Shutdown& other_value) const;
ASP__TCP__Shutdown valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
ASP__TCP__Shutdown_template& list_item(unsigned int list_index) const;
void log() const;
void log_match(const ASP__TCP__Shutdown& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(const Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};

class TCP__Send__error__types : public Base_Type { // enum
friend class TCP__Send__error__types_template;
public:
enum enum_type { TCP__SEND__INVALID__CLIENT__ID = 0, TCP__SEND__ERROR = 1, TCP__SEND__MESSAGE__NOT__COMPLETE = 2, UNKNOWN_VALUE = 3, UNBOUND_VALUE = 4 };
private:
enum_type enum_value;

public:
TCP__Send__error__types();
TCP__Send__error__types(int other_value);
TCP__Send__error__types(enum_type other_value);
TCP__Send__error__types(const TCP__Send__error__types& other_value);

TCP__Send__error__types& operator=(int other_value);
TCP__Send__error__types& operator=(enum_type other_value);
TCP__Send__error__types& operator=(const TCP__Send__error__types& other_value);

boolean operator==(enum_type other_value) const;
boolean operator==(const TCP__Send__error__types& other_value) const;
inline boolean operator!=(enum_type other_value) const { return !(*this == other_value); }
inline boolean operator!=(const TCP__Send__error__types& other_value) const { return !(*this == other_value); }
boolean operator<(enum_type other_value) const;
boolean operator<(const TCP__Send__error__types& other_value) const;
boolean operator>(enum_type other_value) const;
boolean operator>(const TCP__Send__error__types& other_value) const;
inline boolean operator<=(enum_type other_value) const { return !(*this > other_value); }
inline boolean operator<=(const TCP__Send__error__types& other_value) const { return !(*this > other_value); }
inline boolean operator>=(enum_type other_value) const { return !(*this < other_value); }
inline boolean operator>=(const TCP__Send__error__types& other_value) const { return !(*this < other_value); }

static const char *enum_to_str(enum_type enum_par);
static enum_type str_to_enum(const char *str_par);
static boolean is_valid_enum(int int_par);

static int enum2int(enum_type enum_par);
static int enum2int(const TCP__Send__error__types& enum_par);
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
};

class TCP__Send__error__types_template : public Base_Template {
union {
TCP__Send__error__types::enum_type single_value;
struct {
unsigned int n_values;
TCP__Send__error__types_template *list_value;
} value_list;
};

void copy_template(const TCP__Send__error__types_template& other_value);

public:
TCP__Send__error__types_template();
TCP__Send__error__types_template(template_sel other_value);
TCP__Send__error__types_template(int other_value);
TCP__Send__error__types_template(TCP__Send__error__types::enum_type other_value);
TCP__Send__error__types_template(const TCP__Send__error__types& other_value);
TCP__Send__error__types_template(const OPTIONAL<TCP__Send__error__types>& other_value);
TCP__Send__error__types_template(const TCP__Send__error__types_template& other_value);
~TCP__Send__error__types_template();

boolean is_bound() const;
boolean is_value() const;
void clean_up();
TCP__Send__error__types_template& operator=(template_sel other_value);
TCP__Send__error__types_template& operator=(int other_value);
TCP__Send__error__types_template& operator=(TCP__Send__error__types::enum_type other_value);
TCP__Send__error__types_template& operator=(const TCP__Send__error__types& other_value);
TCP__Send__error__types_template& operator=(const OPTIONAL<TCP__Send__error__types>& other_value);
TCP__Send__error__types_template& operator=(const TCP__Send__error__types_template& other_value);

boolean match(TCP__Send__error__types::enum_type other_value) const;
boolean match(const TCP__Send__error__types& other_value) const;
TCP__Send__error__types::enum_type valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
TCP__Send__error__types_template& list_item(unsigned int list_index);
void log() const;
void log_match(const TCP__Send__error__types& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
boolean is_present() const;
boolean match_omit() const;
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
};

class ASP__TCP__Send__error {
  OPTIONAL<INTEGER> field_client__id;
  OCTETSTRING field_data;
  INTEGER field_sent__octets;
  TCP__Send__error__types field_error__type;
  INTEGER field_os__error__code;
  CHARSTRING field_os__error__text;
  CHARSTRING field_ttcn__error__text;
  boolean bound_flag;
public:
  ASP__TCP__Send__error();
  ASP__TCP__Send__error(const OPTIONAL<INTEGER>& par_client__id,
    const OCTETSTRING& par_data,
    const INTEGER& par_sent__octets,
    const TCP__Send__error__types& par_error__type,
    const INTEGER& par_os__error__code,
    const CHARSTRING& par_os__error__text,
    const CHARSTRING& par_ttcn__error__text);
  ASP__TCP__Send__error(const ASP__TCP__Send__error& other_value);
  inline boolean is_component() { return FALSE; }
  void clean_up();
  ASP__TCP__Send__error& operator=(const ASP__TCP__Send__error& other_value);
  boolean operator==(const ASP__TCP__Send__error& other_value) const;
  inline boolean operator!=(const ASP__TCP__Send__error& other_value) const
    { return !(*this == other_value); }

  boolean is_bound() const;

inline boolean is_present() const { return is_bound(); }
  boolean is_value() const;

  inline OPTIONAL<INTEGER>& client__id()
    {return field_client__id;}
  inline const OPTIONAL<INTEGER>& client__id() const
    {return field_client__id;}
  inline OCTETSTRING& data()
    {return field_data;}
  inline const OCTETSTRING& data() const
    {return field_data;}
  inline INTEGER& sent__octets()
    {return field_sent__octets;}
  inline const INTEGER& sent__octets() const
    {return field_sent__octets;}
  inline TCP__Send__error__types& error__type()
    {return field_error__type;}
  inline const TCP__Send__error__types& error__type() const
    {return field_error__type;}
  inline INTEGER& os__error__code()
    {return field_os__error__code;}
  inline const INTEGER& os__error__code() const
    {return field_os__error__code;}
  inline CHARSTRING& os__error__text()
    {return field_os__error__text;}
  inline const CHARSTRING& os__error__text() const
    {return field_os__error__text;}
  inline CHARSTRING& ttcn__error__text()
    {return field_ttcn__error__text;}
  inline const CHARSTRING& ttcn__error__text() const
    {return field_ttcn__error__text;}
  int size_of() const;
  void log() const;
  void set_param(Module_Param& param);
  void set_implicit_omit();
  void encode_text(Text_Buf& text_buf) const;
  void decode_text(Text_Buf& text_buf);
};

class ASP__TCP__Send__error_template : public Base_Template {
struct single_value_struct;
union {
single_value_struct *single_value;
struct {
unsigned int n_values;
ASP__TCP__Send__error_template *list_value;
} value_list;
};

void set_specific();
void copy_value(const ASP__TCP__Send__error& other_value);
void copy_template(const ASP__TCP__Send__error_template& other_value);

public:
ASP__TCP__Send__error_template();
ASP__TCP__Send__error_template(template_sel other_value);
ASP__TCP__Send__error_template(const ASP__TCP__Send__error& other_value);
ASP__TCP__Send__error_template(const OPTIONAL<ASP__TCP__Send__error>& other_value);
ASP__TCP__Send__error_template(const ASP__TCP__Send__error_template& other_value);
~ASP__TCP__Send__error_template();
ASP__TCP__Send__error_template& operator=(template_sel other_value);
ASP__TCP__Send__error_template& operator=(const ASP__TCP__Send__error& other_value);
ASP__TCP__Send__error_template& operator=(const OPTIONAL<ASP__TCP__Send__error>& other_value);
ASP__TCP__Send__error_template& operator=(const ASP__TCP__Send__error_template& other_value);
boolean match(const ASP__TCP__Send__error& other_value) const;
boolean is_bound() const;
boolean is_value() const;
void clean_up();
ASP__TCP__Send__error valueof() const;
void set_type(template_sel template_type, unsigned int list_length);
ASP__TCP__Send__error_template& list_item(unsigned int list_index) const;
INTEGER_template& client__id();
const INTEGER_template& client__id() const;
OCTETSTRING_template& data();
const OCTETSTRING_template& data() const;
INTEGER_template& sent__octets();
const INTEGER_template& sent__octets() const;
TCP__Send__error__types_template& error__type();
const TCP__Send__error__types_template& error__type() const;
INTEGER_template& os__error__code();
const INTEGER_template& os__error__code() const;
CHARSTRING_template& os__error__text();
const CHARSTRING_template& os__error__text() const;
CHARSTRING_template& ttcn__error__text();
const CHARSTRING_template& ttcn__error__text() const;
int size_of() const;
void log() const;
void log_match(const ASP__TCP__Send__error& match_value) const;
void encode_text(Text_Buf& text_buf) const;
void decode_text(Text_Buf& text_buf);
void set_param(Module_Param& param);
void check_restriction(template_res t_res, const char* t_name=NULL) const;
boolean is_present() const;
boolean match_omit() const;
};


/* Function prototypes */

extern boolean operator==(null_type null_value, const ASP__TCP__Shutdown& other_value);
inline boolean operator!=(null_type null_value, const ASP__TCP__Shutdown& other_value) { return !(null_value == other_value); }

/* Global variable declarations */

extern const XERdescriptor_t PDU__TCP_xer_;
extern const TTCN_Typedescriptor_t PDU__TCP_descr_;
extern const XERdescriptor_t ASP__TCP_data_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP_data_descr_;
extern const TTCN_Typedescriptor_t ASP__TCP_descr_;
extern const XERdescriptor_t ASP__TCP_client__id_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP_client__id_descr_;
extern const XERdescriptor_t ASP__TCP__Connect_hostname_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connect_hostname_descr_;
extern const XERdescriptor_t ASP__TCP__Connect_portnumber_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connect_portnumber_descr_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connect_descr_;
extern const XERdescriptor_t ASP__TCP__Connect_local__hostname_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connect_local__hostname_descr_;
extern const XERdescriptor_t ASP__TCP__Connect_local__portnumber_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connect_local__portnumber_descr_;
extern const XERdescriptor_t ASP__TCP__Connect__result_client__id_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connect__result_client__id_descr_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connect__result_descr_;
extern const XERdescriptor_t ASP__TCP__Connected_hostname_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connected_hostname_descr_;
extern const XERdescriptor_t ASP__TCP__Connected_portnumber_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connected_portnumber_descr_;
extern const XERdescriptor_t ASP__TCP__Connected_client__id_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connected_client__id_descr_;
extern const TTCN_Typedescriptor_t ASP__TCP__Connected_descr_;
extern const TTCN_Typedescriptor_t ASP__TCP__Close_descr_;
extern const XERdescriptor_t ASP__TCP__Close_client__id_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Close_client__id_descr_;
extern const TTCN_Typedescriptor_t ASP__TCP__Listen_descr_;
extern const XERdescriptor_t ASP__TCP__Listen_portnumber_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Listen_portnumber_descr_;
extern const XERdescriptor_t ASP__TCP__Listen_local__hostname_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Listen_local__hostname_descr_;
extern const XERdescriptor_t ASP__TCP__Listen__result_portnumber_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Listen__result_portnumber_descr_;
extern const TTCN_Typedescriptor_t ASP__TCP__Listen__result_descr_;
extern const TTCN_Typedescriptor_t ASP__TCP__Shutdown_descr_;
extern const TTCN_Typedescriptor_t TCP__Send__error__types_descr_;
extern const XERdescriptor_t ASP__TCP__Send__error_data_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Send__error_data_descr_;
extern const XERdescriptor_t ASP__TCP__Send__error_sent__octets_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Send__error_sent__octets_descr_;
extern const XERdescriptor_t ASP__TCP__Send__error_os__error__code_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Send__error_os__error__code_descr_;
extern const XERdescriptor_t ASP__TCP__Send__error_os__error__text_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Send__error_os__error__text_descr_;
extern const XERdescriptor_t ASP__TCP__Send__error_ttcn__error__text_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Send__error_ttcn__error__text_descr_;
extern const TTCN_Typedescriptor_t ASP__TCP__Send__error_descr_;
extern const XERdescriptor_t ASP__TCP__Send__error_client__id_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__Send__error_client__id_descr_;
extern const CHARSTRING& c__TCP__AF__INET;
extern const CHARSTRING& c__TCP__IPv4;
extern const CHARSTRING& c__TCP__AF__INET6;
extern const CHARSTRING& c__TCP__IPv6;
extern const CHARSTRING& c__TCP__AF__UNSPEC;
extern const CHARSTRING& c__TCP__UNSPEC;
extern const XERdescriptor_t ASP__TCP__SetAddressFamily_xer_;
extern const TTCN_Typedescriptor_t ASP__TCP__SetAddressFamily_descr_;
extern TTCN_Module module_object;

} /* end of namespace */

#endif
