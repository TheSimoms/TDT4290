// This C++ source file was generated by the TTCN-3 compiler
// of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for user (user@user-multicom) on Mon Sep 28 11:06:25 2015

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

static const unsigned char os_0_octets[] = { 84, 101, 115, 116, 68, 97, 116, 97, 10 };
static const OCTETSTRING os_0(9, os_0_octets);
static const CHARSTRING cs_0(9, "127.0.0.1");
static const unsigned char module_checksum[] = { 0x12, 0xbe, 0x91, 0x3f, 0x36, 0xa5, 0x67, 0x49, 0xe0, 0x84, 0x57, 0xe4, 0x45, 0xf5, 0x9e, 0x4d };

/* Global variable definitions */

const TTCN_Typedescriptor_t& XMPP__TYPE_descr_ = COMPONENT_descr_;
XMPP__PortType::XMPP__PT XMPP__TYPE_component_XMPP__PORT("XMPP_PORT");
TIMER XMPP__TYPE_component_TIMER_("TIMER", 1.0e1);
static CHARSTRING const_host__name;
const CHARSTRING& host__name = const_host__name;
static INTEGER const_port__number;
const INTEGER& port__number = const_port__number;
static XMPP__Types::XMPP__Connect_template template_xmpp__connect;
const XMPP__Types::XMPP__Connect_template& xmpp__connect = template_xmpp__connect;
static http__etherx__jabber__org__streams::Stream_template template_xmpp__stream;
const http__etherx__jabber__org__streams::Stream_template& xmpp__stream = template_xmpp__stream;
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
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 61 */
TTCN_Runtime::map_port(MTC_COMPREF, XMPP__TYPE_component_XMPP__PORT.get_name(), SYSTEM_COMPREF, XMPP__TYPE_component_XMPP__PORT.get_name());
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 63 */
XMPP__TYPE_component_XMPP__PORT.send(xmpp__connect);
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 64 */
XMPP__TYPE_component_XMPP__PORT.send(xmpp__stream);
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 66 */
XMPP__TYPE_component_TIMER_.start();
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 68 */
{
tmp_0:
alt_status tmp_0_alt_flag_0 = ALT_MAYBE;
alt_status tmp_0_alt_flag_1 = ALT_MAYBE;
alt_status tmp_0_alt_flag_2 = ALT_MAYBE;
alt_status tmp_0_default_flag = ALT_MAYBE;
TTCN_Snapshot::take_new(FALSE);
for ( ; ; ) {
if (tmp_0_alt_flag_0 == ALT_MAYBE) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 69 */
tmp_0_alt_flag_0 = XMPP__TYPE_component_XMPP__PORT.receive(xmpp__stream, NULL, any_compref, NULL);
if (tmp_0_alt_flag_0 == ALT_YES) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 69 */
XMPP__TYPE_component_TIMER_.stop();
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 69 */
TTCN_Runtime::setverdict(PASS);
break;
}
}
if (tmp_0_alt_flag_1 == ALT_MAYBE) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 70 */
tmp_0_alt_flag_1 = XMPP__TYPE_component_TIMER_.timeout();
if (tmp_0_alt_flag_1 == ALT_YES) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 70 */
TTCN_Runtime::setverdict(INCONC);
break;
}
}
if (tmp_0_alt_flag_2 == ALT_MAYBE) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 71 */
tmp_0_alt_flag_2 = XMPP__TYPE_component_XMPP__PORT.receive(any_compref, NULL);
if (tmp_0_alt_flag_2 == ALT_YES) {
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 71 */
XMPP__TYPE_component_XMPP__PORT.stop();
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 71 */
TTCN_Runtime::setverdict(FAIL);
break;
}
}
if (tmp_0_default_flag == ALT_MAYBE) {
tmp_0_default_flag = TTCN_Default::try_altsteps();
if (tmp_0_default_flag == ALT_YES || tmp_0_default_flag == ALT_BREAK) break;
else if (tmp_0_default_flag == ALT_REPEAT) goto tmp_0;
}
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 68 */
if (tmp_0_alt_flag_0 == ALT_NO && tmp_0_alt_flag_1 == ALT_NO && tmp_0_alt_flag_2 == ALT_NO && tmp_0_default_flag == ALT_NO) TTCN_error("None of the branches can be chosen in the alt statement in file /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn between lines 68 and 72.");
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
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 36 */
const_host__name = cs_0;
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 37 */
const_port__number = 5222;
module_object.add_testcase_nonpard("SuccessfulConnect", testcase_SuccessfulConnect);
}

static void post_init_module()
{
XMPP__PortType::module_object.post_init_module();
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 44 */
template_xmpp__connect.hostname() = cs_0;
template_xmpp__connect.portnumber() = 5222;
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 49 */
template_xmpp__stream.data() = os_0;
template_xmpp__stream.client__id() = 1235;
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
/* /work/TDT4290/src/testcases/xmpp/xmpp_connect.ttcn, line 82 */
testcase_SuccessfulConnect(FALSE, 0.0);
TTCN_Runtime::end_controlpart();
}


} /* end of namespace */
