// This C++ source file was generated by the TTCN-3 compiler
// of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for user (user@user-multicom) on Fri Sep 25 13:42:36 2015

// Copyright Ericsson Telecom AB 2000-2014

// Do not edit this file unless you know what you are doing.

/* Including header files */

#include "tcp_connect.hh"

namespace tcp__connect {

/* Prototypes of static functions */

static void pre_init_module();
static void post_init_module();
static boolean init_comp_type(const char *component_type, boolean init_base_comps);
static void module_control_part();

/* Literal string constants */

static const unsigned char os_0_octets[] = { 84, 101, 115, 116, 68, 97, 116, 97, 10 },
os_1_octets[] = { 84, 101, 115, 116, 82, 101, 115, 112, 111, 110, 115, 101, 10 };
static const OCTETSTRING os_0(9, os_0_octets),
os_1(13, os_1_octets);
static const unsigned char module_checksum[] = { 0xc9, 0x9c, 0xd4, 0xc6, 0xa7, 0xc8, 0x52, 0xdc, 0x9e, 0xbd, 0xde, 0x46, 0x8f, 0x28, 0x03, 0xbc };

/* Global variable definitions */

const TTCN_Typedescriptor_t& TCP__TYPE_descr_ = COMPONENT_descr_;
TCPasp__PortType::TCPasp__PT TCP__TYPE_component_TCP__PORT("TCP_PORT");
TIMER TCP__TYPE_component_TIMER_("TIMER", 1.0e1);
static TCPasp__Types::ASP__TCP_template template_TestData;
const TCPasp__Types::ASP__TCP_template& TestData = template_TestData;
static TCPasp__Types::ASP__TCP_template template_TestResponse;
const TCPasp__Types::ASP__TCP_template& TestResponse = template_TestResponse;
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

TTCN_Module module_object("tcp_connect", __DATE__, __TIME__, module_checksum, pre_init_module, NULL, 0U, 4294967295U, 4294967295U, 4294967295U, NULL, 21LU, xml_namespaces, post_init_module, NULL, NULL, init_comp_type, NULL, module_control_part);

static const RuntimeVersionChecker ver_checker(  current_runtime_version.requires_major_version_5,
  current_runtime_version.requires_minor_version_3,
  current_runtime_version.requires_patch_level_0,  current_runtime_version.requires_runtime_1);

/* Bodies of functions, altsteps and testcases */

verdicttype testcase_SuccessfulConnect(boolean has_timer, double timer_value)
{
TTCN_Runtime::check_begin_testcase(has_timer, timer_value);
try {
TTCN_Runtime::begin_testcase("tcp_connect", "SuccessfulConnect", "tcp_connect", "TCP_TYPE", "tcp_connect", "TCP_TYPE", has_timer, timer_value);
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 35 */
TTCN_Runtime::map_port(MTC_COMPREF, TCP__TYPE_component_TCP__PORT.get_name(), SYSTEM_COMPREF, TCP__TYPE_component_TCP__PORT.get_name());
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 36 */
TCP__TYPE_component_TCP__PORT.send(TestData);
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 38 */
{
tmp_1:
alt_status tmp_1_alt_flag_0 = ALT_MAYBE;
alt_status tmp_1_alt_flag_1 = ALT_MAYBE;
alt_status tmp_1_alt_flag_2 = ALT_MAYBE;
alt_status tmp_1_default_flag = ALT_MAYBE;
TTCN_Snapshot::take_new(FALSE);
for ( ; ; ) {
if (tmp_1_alt_flag_0 == ALT_MAYBE) {
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 39 */
tmp_1_alt_flag_0 = TCP__TYPE_component_TCP__PORT.receive(TestResponse, NULL, any_compref, NULL);
if (tmp_1_alt_flag_0 == ALT_YES) {
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 39 */
TCP__TYPE_component_TIMER_.stop();
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 39 */
TTCN_Runtime::setverdict(PASS);
break;
}
}
if (tmp_1_alt_flag_1 == ALT_MAYBE) {
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 40 */
tmp_1_alt_flag_1 = TCP__TYPE_component_TIMER_.timeout();
if (tmp_1_alt_flag_1 == ALT_YES) {
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 40 */
TTCN_Runtime::setverdict(INCONC);
break;
}
}
if (tmp_1_alt_flag_2 == ALT_MAYBE) {
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 41 */
tmp_1_alt_flag_2 = TCP__TYPE_component_TCP__PORT.receive(any_compref, NULL);
if (tmp_1_alt_flag_2 == ALT_YES) {
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 41 */
TCP__TYPE_component_TCP__PORT.stop();
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 41 */
TTCN_Runtime::setverdict(FAIL);
break;
}
}
if (tmp_1_default_flag == ALT_MAYBE) {
tmp_1_default_flag = TTCN_Default::try_altsteps();
if (tmp_1_default_flag == ALT_YES || tmp_1_default_flag == ALT_BREAK) break;
else if (tmp_1_default_flag == ALT_REPEAT) goto tmp_1;
}
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 38 */
if (tmp_1_alt_flag_0 == ALT_NO && tmp_1_alt_flag_1 == ALT_NO && tmp_1_alt_flag_2 == ALT_NO && tmp_1_default_flag == ALT_NO) TTCN_error("None of the branches can be chosen in the alt statement in file /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn between lines 38 and 42.");
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
TCPasp__PortType::module_object.pre_init_module();
module_object.add_testcase_nonpard("SuccessfulConnect", testcase_SuccessfulConnect);
}

static void post_init_module()
{
TCPasp__PortType::module_object.post_init_module();
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 22 */
template_TestData.data() = os_0;
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 27 */
{
INTEGER_template& tmp_0 = template_TestResponse.client__id();
tmp_0.set_type(VALUE_RANGE);
}
template_TestResponse.data() = os_1;
}

static boolean init_comp_type(const char *component_type, boolean init_base_comps)
{
(void)init_base_comps;
if (!strcmp(component_type, "TCP_TYPE")) {
TCP__TYPE_component_TCP__PORT.activate_port();
return TRUE;
} else return FALSE;
}

static void module_control_part()
{
TTCN_Runtime::begin_controlpart("tcp_connect");
/* /work/TDT4290/src/testcases/tcp/tcp_connect.ttcn, line 48 */
testcase_SuccessfulConnect(FALSE, 0.0);
TTCN_Runtime::end_controlpart();
}


} /* end of namespace */
