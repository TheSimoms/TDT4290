// This C++ source file was generated by the TTCN-3 compiler
// of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for user (user@user-multicom) on Fri Oct  9 10:28:08 2015

// Copyright Ericsson Telecom AB 2000-2014

// Do not edit this file unless you know what you are doing.

/* Including header files */

#include "xmpp_connect.hh"

namespace xmpp__connect {

/* Prototypes of static functions */

static void pre_init_module();
static void post_init_module();
static boolean init_comp_type(const char *component_type, boolean init_base_comps);
static void module_control_part();

/* Literal string constants */

static const CHARSTRING cs_0(9, "127.0.0.1"),
cs_6(143, "<stream:error xmlns:stream=\"http://etherx.jabber.org/streams\"><xml-not-well-formed xmlns=\"urn:ietf:params:xml:ns:xmpp-streams\"/></stream:error>"),
cs_1(7, "Heisann"),
cs_5(3, "\\d*"),
cs_4(9, "localhost"),
cs_3(14, "test@localhost"),
cs_2(14, "user@localhost");
static const unsigned char module_checksum[] = { 0x33, 0xe9, 0xac, 0xe5, 0x91, 0x7d, 0xe8, 0x08, 0x04, 0xb4, 0x94, 0xc0, 0xe1, 0xbc, 0x36, 0xd5 };

/* Global variable definitions */

const TTCN_Typedescriptor_t& XMPP__TYPE_descr_ = COMPONENT_descr_;
XMPP__PortType::XMPP__PT XMPP__TYPE_component_XMPP__PORT("XMPP_PORT");
TIMER XMPP__TYPE_component_TIMER_("TIMER", 2.0e1);
static CHARSTRING const_host__name;
const CHARSTRING& host__name = const_host__name;
static INTEGER const_port__number;
const INTEGER& port__number = const_port__number;
static jabber__client::Message_template template_client__message;
const jabber__client::Message_template& client__message = template_client__message;
static http__etherx__jabber__org__streams::Stream_template template_client__stream;
const http__etherx__jabber__org__streams::Stream_template& client__stream = template_client__stream;
static http__etherx__jabber__org__streams::Stream_template template_server__stream;
const http__etherx__jabber__org__streams::Stream_template& server__stream = template_server__stream;
static const size_t num_namespaces = 21;
static const namespace_t xml_namespaces[num_namespaces+1] = {
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { NULL, NULL },
  { "", "" }
};

TTCN_Module module_object("xmpp_connect", __DATE__, __TIME__, module_checksum, pre_init_module, NULL, 0U, 4294967295U, 4294967295U, 4294967295U, NULL, 21LU, xml_namespaces, post_init_module, NULL, NULL, init_comp_type, NULL, module_control_part);

static const RuntimeVersionChecker ver_checker(  current_runtime_version.requires_major_version_5,
  current_runtime_version.requires_minor_version_3,
  current_runtime_version.requires_patch_level_0,  current_runtime_version.requires_runtime_1);

/* Bodies of functions, altsteps and testcases */

verdicttype testcase_SuccessfulConnect(boolean has_timer, double timer_value)
{
TTCN_Runtime::check_begin_testcase(has_timer, timer_value);
try {
TTCN_Runtime::begin_testcase("xmpp_connect", "SuccessfulConnect", "xmpp_connect", "XMPP_TYPE", "xmpp_connect", "XMPP_TYPE", has_timer, timer_value);
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 114 */
TTCN_Runtime::map_port(MTC_COMPREF, XMPP__TYPE_component_XMPP__PORT.get_name(), SYSTEM_COMPREF, XMPP__TYPE_component_XMPP__PORT.get_name());
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 116 */
TTCN_Logger::log_str(TTCN_USER, "HEI");
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 118 */
XMPP__TYPE_component_XMPP__PORT.send(client__stream);
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 120 */
XMPP__TYPE_component_TIMER_.start();
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 122 */
{
tmp_4:
alt_status tmp_4_alt_flag_0 = ALT_MAYBE;
alt_status tmp_4_alt_flag_1 = ALT_MAYBE;
alt_status tmp_4_alt_flag_2 = ALT_MAYBE;
alt_status tmp_4_default_flag = ALT_MAYBE;
TTCN_Snapshot::take_new(FALSE);
for ( ; ; ) {
if (tmp_4_alt_flag_0 == ALT_MAYBE) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 123 */
tmp_4_alt_flag_0 = XMPP__TYPE_component_XMPP__PORT.receive(client__stream, NULL, any_compref, NULL);
if (tmp_4_alt_flag_0 == ALT_YES) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 123 */
XMPP__TYPE_component_TIMER_.stop();
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 123 */
TTCN_Runtime::setverdict(PASS);
break;
}
}
if (tmp_4_alt_flag_1 == ALT_MAYBE) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 124 */
tmp_4_alt_flag_1 = XMPP__TYPE_component_TIMER_.timeout();
if (tmp_4_alt_flag_1 == ALT_YES) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 124 */
TTCN_Runtime::setverdict(INCONC);
break;
}
}
if (tmp_4_alt_flag_2 == ALT_MAYBE) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 125 */
tmp_4_alt_flag_2 = XMPP__TYPE_component_XMPP__PORT.receive(any_compref, NULL);
if (tmp_4_alt_flag_2 == ALT_YES) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 125 */
XMPP__TYPE_component_XMPP__PORT.stop();
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 125 */
TTCN_Runtime::setverdict(FAIL);
break;
}
}
if (tmp_4_default_flag == ALT_MAYBE) {
tmp_4_default_flag = TTCN_Default::try_altsteps();
if (tmp_4_default_flag == ALT_YES || tmp_4_default_flag == ALT_BREAK) break;
else if (tmp_4_default_flag == ALT_REPEAT) goto tmp_4;
}
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 122 */
if (tmp_4_alt_flag_0 == ALT_NO && tmp_4_alt_flag_1 == ALT_NO && tmp_4_alt_flag_2 == ALT_NO && tmp_4_default_flag == ALT_NO) TTCN_error("None of the branches can be chosen in the alt statement in file /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn between lines 122 and 126.");
TTCN_Snapshot::take_new(TRUE);
}
}
} catch (const TC_Error& tc_error) {
} catch (const TC_End& tc_end) {
TTCN_Logger::log_str(TTCN_FUNCTION, "Test case SuccessfulConnect was stopped.");
}
return TTCN_Runtime::end_testcase();
}


/* Bodies of static functions */

static void pre_init_module()
{
XMPP__PortType::module_object.pre_init_module();
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 39 */
const_host__name = cs_0;
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 40 */
const_port__number = 5222;
module_object.add_testcase_nonpard("SuccessfulConnect", testcase_SuccessfulConnect);
}

static void post_init_module()
{
XMPP__PortType::module_object.post_init_module();
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 47 */
template_client__message.from__() = OMIT_VALUE;
template_client__message.id() = OMIT_VALUE;
template_client__message.lang() = OMIT_VALUE;
template_client__message.to__() = OMIT_VALUE;
template_client__message.type__() = OMIT_VALUE;
{
jabber__client::Message_choice__list_template& tmp_0 = template_client__message.choice__list();
tmp_0.set_size(2);
{
jabber__client::Subject_template& tmp_1 = tmp_0[0].subject();
tmp_1.lang() = OMIT_VALUE;
tmp_1.base() = cs_1;
}
{
jabber__client::Body_template& tmp_2 = tmp_0[1].body();
tmp_2.lang() = OMIT_VALUE;
tmp_2.base() = cs_1;
}
}
template_client__message.elem__list() = NULL_VALUE;
template_client__message.error__() = OMIT_VALUE;
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 71 */
template_client__stream.from__() = cs_2;
template_client__stream.id() = OMIT_VALUE;
template_client__stream.lang() = OMIT_VALUE;
template_client__stream.to__() = cs_3;
template_client__stream.version() = OMIT_VALUE;
template_client__stream.attr() = NULL_VALUE;
template_client__stream.features() = OMIT_VALUE;
template_client__stream.elem() = OMIT_VALUE;
template_client__stream.elem__1() = OMIT_VALUE;
template_client__stream.elem__list() = NULL_VALUE;
{
http__etherx__jabber__org__streams::Stream_choice_choice__list__1_template& tmp_3 = template_client__stream.choice().choice__list__1();
tmp_3.set_size(1);
tmp_3[0].message__() = client__message;
}
template_client__stream.error__() = OMIT_VALUE;
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 92 */
template_server__stream.from__() = cs_4;
template_server__stream.id() = UNIVERSAL_CHARSTRING_template(STRING_PATTERN, (CHARSTRING)cs_5);
template_server__stream.lang() = OMIT_VALUE;
template_server__stream.to__() = OMIT_VALUE;
template_server__stream.version() = 1.0;
template_server__stream.attr() = NULL_VALUE;
template_server__stream.features() = OMIT_VALUE;
template_server__stream.elem() = cs_6;
template_server__stream.elem__1() = OMIT_VALUE;
template_server__stream.elem__list() = NULL_VALUE;
template_server__stream.choice() = OMIT_VALUE;
template_server__stream.error__() = OMIT_VALUE;
}

static boolean init_comp_type(const char *component_type, boolean init_base_comps)
{
(void)init_base_comps;
if (!strcmp(component_type, "XMPP_TYPE")) {
XMPP__TYPE_component_XMPP__PORT.activate_port();
return TRUE;
} else return FALSE;
}

static void module_control_part()
{
TTCN_Runtime::begin_controlpart("xmpp_connect");
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 136 */
testcase_SuccessfulConnect(FALSE, 0.0);
TTCN_Runtime::end_controlpart();
}


} /* end of namespace */
