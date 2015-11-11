// This C++ source file was generated by the TTCN-3 compiler
// of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for titanrt (titanrt@Ubuntu-14-04-64bit) on Fri May 22 16:42:32 2015

// Copyright Ericsson Telecom AB 2000-2014

// Do not edit this file unless you know what you are doing.

/* Including header files */

#include "MyExample.hh"

namespace MyExample {

/* Prototypes of static functions */

static void pre_init_module();
static boolean init_comp_type(const char *component_type, boolean init_base_comps);
static void module_control_part();

/* Literal string constants */

static const CHARSTRING cs_1(14, "Hello, TTCN-3!"),
cs_0(13, "Hello, world!");
static const unsigned char module_checksum[] = { 0x3c, 0x38, 0xc0, 0x54, 0x80, 0x8c, 0xa7, 0xc1, 0xb3, 0xd0, 0xef, 0x38, 0xcb, 0xc7, 0xd5, 0xe6 };

/* Global variable definitions */

const TTCN_Typedescriptor_t& MTCType_descr_ = COMPONENT_descr_;
PCOType MTCType_component_MyPCO("MyPCO");
static const size_t num_namespaces = 0;
TTCN_Module module_object("MyExample", __DATE__, __TIME__, module_checksum, pre_init_module, NULL, 0U, 4294967295U, 4294967295U, 4294967295U, NULL, 0LU, 0, NULL, NULL, NULL, init_comp_type, NULL, module_control_part);

static const RuntimeVersionChecker ver_checker(  current_runtime_version.requires_major_version_5,
  current_runtime_version.requires_minor_version_3,
  current_runtime_version.requires_patch_level_0,  current_runtime_version.requires_runtime_1);

/* Member functions of C++ classes */

void PCOType_BASE::remove_msg_queue_head()
{
msg_queue_item *my_head = (msg_queue_item*)msg_queue_head;
switch (my_head->item_selection) {
case MESSAGE_0:
delete (my_head)->message_0;
break;
default:
TTCN_error("Internal error: Invalid message selector in the queue of port %s.", port_name);
}
msg_queue_item_base *next_item = msg_queue_head->next_item;
delete (msg_queue_item*)msg_queue_head;
msg_queue_head = next_item;
if (next_item == NULL) msg_queue_tail = NULL;
TTCN_Logger::log_port_queue(TitanLoggerApiSimple::Port__Queue_operation::extract__msg, port_name, 0, ++msg_head_count, CHARSTRING(0,NULL), CHARSTRING(0,NULL));}

void PCOType_BASE::clear_queue()
{
while (msg_queue_head != NULL) remove_msg_queue_head();
}

PCOType_BASE::PCOType_BASE(const char *par_port_name)
 : PORT(par_port_name)
{
msg_queue_head = NULL;
msg_queue_tail = NULL;
}

PCOType_BASE::~PCOType_BASE()
{
clear_queue();
}

void PCOType_BASE::send(const CHARSTRING& send_par, const COMPONENT& destination_component)
{
if (!is_started) TTCN_error("Sending a message on port %s, which is not started.", port_name);
if (!destination_component.is_bound()) TTCN_error("Unbound component reference in the to clause of send operation.");
const TTCN_Logger::Severity log_sev = destination_component==SYSTEM_COMPREF?TTCN_Logger::PORTEVENT_MMSEND:TTCN_Logger::PORTEVENT_MCSEND;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::log_msgport_send(port_name, destination_component,
(TTCN_Logger::begin_event(log_sev, TRUE), TTCN_Logger::log_event_str(" charstring : "),
send_par.log(), TTCN_Logger::end_event_log2str()));
}
if (destination_component == SYSTEM_COMPREF) outgoing_send(send_par);
else {
Text_Buf text_buf;
prepare_message(text_buf, "charstring");
send_par.encode_text(text_buf);
send_data(text_buf, destination_component);
}
}

void PCOType_BASE::send(const CHARSTRING& send_par)
{
send(send_par, COMPONENT(get_default_destination()));
}

void PCOType_BASE::send(const CHARSTRING_template& send_par, const COMPONENT& destination_component)
{
const CHARSTRING& send_par_value = CHARSTRING(send_par.valueof());
send(send_par_value, destination_component);
}

void PCOType_BASE::send(const CHARSTRING_template& send_par)
{
const CHARSTRING& send_par_value = CHARSTRING(send_par.valueof());
send(send_par_value, COMPONENT(get_default_destination()));
}

alt_status PCOType_BASE::receive(const COMPONENT_template& sender_template, COMPONENT *sender_ptr)
{
msg_queue_item *my_head = (msg_queue_item*)msg_queue_head;
if (msg_queue_head == NULL) {
if (is_started) return ALT_MAYBE;
else {
TTCN_Logger::log(TTCN_Logger::MATCHING_PROBLEM, "Matching on port %s failed: Port is not started and the queue is empty.", port_name);
return ALT_NO;
}
} else if (!sender_template.match(my_head->sender_component)) {
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMUNSUCC:TTCN_Logger::MATCHING_MCUNSUCC;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::begin_event(log_sev);
TTCN_Logger::log_event("Matching on port %s failed: Sender of the first message in the queue does not match the from clause: ", port_name);
sender_template.log_match(my_head->sender_component);
TTCN_Logger::end_event();
}
return ALT_NO;
} else {
if (sender_ptr != NULL) *sender_ptr = my_head->sender_component;
TTCN_Logger::log(my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMSUCCESS:TTCN_Logger::MATCHING_MCSUCCESS, "Matching on port %s succeeded.", port_name);
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::PORTEVENT_MMRECV:TTCN_Logger::PORTEVENT_MCRECV;
if (TTCN_Logger::log_this_event(log_sev)) {
switch (my_head->item_selection) {
case MESSAGE_0:
TTCN_Logger::log_msgport_recv(port_name, TitanLoggerApiSimple::Msg__port__recv_operation::receive__op,
my_head->sender_component, CHARSTRING(0, NULL),
(TTCN_Logger::begin_event(log_sev,TRUE), TTCN_Logger::log_event_str(": charstring: "),
my_head->message_0->log(), TTCN_Logger::end_event_log2str()), msg_head_count+1);
break;
default:
TTCN_error("Internal error: unknown message");
}
}
remove_msg_queue_head();
return ALT_YES;
}
}

alt_status PCOType_BASE::check_receive(const COMPONENT_template& sender_template, COMPONENT *sender_ptr)
{
msg_queue_item *my_head = (msg_queue_item*)msg_queue_head;
if (msg_queue_head == NULL) {
if (is_started) return ALT_MAYBE;
else {
TTCN_Logger::log(TTCN_Logger::MATCHING_PROBLEM, "Matching on port %s failed: Port is not started and the queue is empty.", port_name);
return ALT_NO;
}
} else if (!sender_template.match(my_head->sender_component)) {
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMUNSUCC:TTCN_Logger::MATCHING_MCUNSUCC;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::begin_event(log_sev);
TTCN_Logger::log_event("Matching on port %s failed: Sender of the first message in the queue does not match the from clause: ", port_name);
sender_template.log_match(my_head->sender_component);
TTCN_Logger::end_event();
}
return ALT_NO;
} else {
if (sender_ptr != NULL) *sender_ptr = my_head->sender_component;
TTCN_Logger::log(my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMSUCCESS:TTCN_Logger::MATCHING_MCSUCCESS, "Matching on port %s succeeded.", port_name);
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::PORTEVENT_MMRECV:TTCN_Logger::PORTEVENT_MCRECV;
if (TTCN_Logger::log_this_event(log_sev)) {
switch (my_head->item_selection) {
case MESSAGE_0:
TTCN_Logger::log_msgport_recv(port_name, TitanLoggerApiSimple::Msg__port__recv_operation::check__receive__op,
my_head->sender_component, CHARSTRING(0, NULL),
(TTCN_Logger::begin_event(log_sev,TRUE), TTCN_Logger::log_event_str(": charstring: "),
my_head->message_0->log(), TTCN_Logger::end_event_log2str()), msg_head_count+1);
break;
default:
TTCN_error("Internal error: unknown message");
}
}
return ALT_YES;
}
}

alt_status PCOType_BASE::trigger(const COMPONENT_template& sender_template, COMPONENT *sender_ptr)
{
msg_queue_item *my_head = (msg_queue_item*)msg_queue_head;
if (msg_queue_head == NULL) {
if (is_started) return ALT_MAYBE;
else {
TTCN_Logger::log(TTCN_Logger::MATCHING_PROBLEM, "Matching on port %s failed: Port is not started and the queue is empty.", port_name);
return ALT_NO;
}
} else if (!sender_template.match(my_head->sender_component)) {
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMUNSUCC:TTCN_Logger::MATCHING_MCUNSUCC;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::begin_event(log_sev);
TTCN_Logger::log_event("Matching on port %s will drop a message: Sender of the first message in the queue does not match the from clause: ", port_name);
sender_template.log_match(my_head->sender_component);
TTCN_Logger::end_event();
}
remove_msg_queue_head();
return ALT_REPEAT;
} else {
if (sender_ptr != NULL) *sender_ptr = my_head->sender_component;
TTCN_Logger::log(my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMSUCCESS:TTCN_Logger::MATCHING_MCSUCCESS, "Matching on port %s succeeded.", port_name);
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::PORTEVENT_MMRECV:TTCN_Logger::PORTEVENT_MCRECV;
if (TTCN_Logger::log_this_event(log_sev)) {
switch (my_head->item_selection) {
case MESSAGE_0:
TTCN_Logger::log_msgport_recv(port_name, TitanLoggerApiSimple::Msg__port__recv_operation::trigger__op,
my_head->sender_component, CHARSTRING(0, NULL),
(TTCN_Logger::begin_event(log_sev,TRUE), TTCN_Logger::log_event_str(": charstring: "),
my_head->message_0->log(), TTCN_Logger::end_event_log2str()), msg_head_count+1);
break;
default:
TTCN_error("Internal error: unknown message");
}
}
remove_msg_queue_head();
return ALT_YES;
}
}

alt_status PCOType_BASE::receive(const CHARSTRING_template& value_template, CHARSTRING *value_ptr, const COMPONENT_template& sender_template, COMPONENT *sender_ptr)
{
msg_queue_item *my_head = (msg_queue_item*)msg_queue_head;
if (msg_queue_head == NULL) {
if (is_started) return ALT_MAYBE;
else {
TTCN_Logger::log(TTCN_Logger::MATCHING_PROBLEM, "Matching on port %s failed: Port is not started and the queue is empty.", port_name);
return ALT_NO;
}
} else if (!sender_template.match(my_head->sender_component)) {
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMUNSUCC:TTCN_Logger::MATCHING_MCUNSUCC;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::begin_event(log_sev);
TTCN_Logger::log_event("Matching on port %s failed: Sender of the first message in the queue does not match the from clause: ", port_name);
sender_template.log_match(my_head->sender_component);
TTCN_Logger::end_event();
}
return ALT_NO;
} else if (my_head->item_selection != MESSAGE_0) {
TTCN_Logger::log(my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMUNSUCC:TTCN_Logger::MATCHING_MCUNSUCC, "Matching on port %s failed: Type of the first message in the queue is not charstring.", port_name);
return ALT_NO;
} else if (!value_template.match(*my_head->message_0)) {
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF ? TTCN_Logger::MATCHING_MMUNSUCC : TTCN_Logger::MATCHING_MCUNSUCC;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::log_matching_failure(TitanLoggerApiSimple::PortType::message__,
port_name, my_head->sender_component,
TitanLoggerApiSimple::MatchingFailureType_reason::message__does__not__match__template,
(TTCN_Logger::begin_event(log_sev, TRUE), value_template.log_match(*my_head->message_0),
 TTCN_Logger::end_event_log2str()));
}
return ALT_NO;
} else {
if (value_ptr != NULL) *value_ptr = *my_head->message_0;
if (sender_ptr != NULL) *sender_ptr = my_head->sender_component;
TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMSUCCESS:TTCN_Logger::MATCHING_MCSUCCESS;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::log_matching_success(TitanLoggerApiSimple::PortType::message__,
port_name, my_head->sender_component,
(TTCN_Logger::begin_event(log_sev, TRUE), value_template.log_match(*my_head->message_0),
 TTCN_Logger::end_event_log2str()));
}
log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::PORTEVENT_MMRECV:TTCN_Logger::PORTEVENT_MCRECV;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::log_msgport_recv(port_name, TitanLoggerApiSimple::Msg__port__recv_operation::receive__op,
my_head->sender_component, CHARSTRING(0, NULL),
(TTCN_Logger::begin_event(log_sev,TRUE), TTCN_Logger::log_event_str(": charstring : "),
my_head->message_0->log(), TTCN_Logger::end_event_log2str()),
msg_head_count+1);
}
remove_msg_queue_head();
return ALT_YES;
}
}

alt_status PCOType_BASE::check_receive(const CHARSTRING_template& value_template, CHARSTRING *value_ptr, const COMPONENT_template& sender_template, COMPONENT *sender_ptr)
{
msg_queue_item *my_head = (msg_queue_item*)msg_queue_head;
if (msg_queue_head == NULL) {
if (is_started) return ALT_MAYBE;
else {
TTCN_Logger::log(TTCN_Logger::MATCHING_PROBLEM, "Matching on port %s failed: Port is not started and the queue is empty.", port_name);
return ALT_NO;
}
} else if (!sender_template.match(my_head->sender_component)) {
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMUNSUCC:TTCN_Logger::MATCHING_MCUNSUCC;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::begin_event(log_sev);
TTCN_Logger::log_event("Matching on port %s failed: Sender of the first message in the queue does not match the from clause: ", port_name);
sender_template.log_match(my_head->sender_component);
TTCN_Logger::end_event();
}
return ALT_NO;
} else if (my_head->item_selection != MESSAGE_0) {
TTCN_Logger::log(my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMUNSUCC:TTCN_Logger::MATCHING_MCUNSUCC, "Matching on port %s failed: Type of the first message in the queue is not charstring.", port_name);
return ALT_NO;
} else if (!value_template.match(*my_head->message_0)) {
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF ? TTCN_Logger::MATCHING_MMUNSUCC : TTCN_Logger::MATCHING_MCUNSUCC;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::log_matching_failure(TitanLoggerApiSimple::PortType::message__,
port_name, my_head->sender_component,
TitanLoggerApiSimple::MatchingFailureType_reason::message__does__not__match__template,
(TTCN_Logger::begin_event(log_sev, TRUE), value_template.log_match(*my_head->message_0),
 TTCN_Logger::end_event_log2str()));
}
return ALT_NO;
} else {
if (value_ptr != NULL) *value_ptr = *my_head->message_0;
if (sender_ptr != NULL) *sender_ptr = my_head->sender_component;
TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMSUCCESS:TTCN_Logger::MATCHING_MCSUCCESS;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::log_matching_success(TitanLoggerApiSimple::PortType::message__,
port_name, my_head->sender_component,
(TTCN_Logger::begin_event(log_sev, TRUE), value_template.log_match(*my_head->message_0),
 TTCN_Logger::end_event_log2str()));
}
log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::PORTEVENT_MMRECV:TTCN_Logger::PORTEVENT_MCRECV;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::log_msgport_recv(port_name, TitanLoggerApiSimple::Msg__port__recv_operation::check__receive__op,
my_head->sender_component, CHARSTRING(0, NULL),
(TTCN_Logger::begin_event(log_sev,TRUE), TTCN_Logger::log_event_str(": charstring : "),
my_head->message_0->log(), TTCN_Logger::end_event_log2str()),
msg_head_count+1);
}
return ALT_YES;
}
}

alt_status PCOType_BASE::trigger(const CHARSTRING_template& value_template, CHARSTRING *value_ptr, const COMPONENT_template& sender_template, COMPONENT *sender_ptr)
{
msg_queue_item *my_head = (msg_queue_item*)msg_queue_head;
if (msg_queue_head == NULL) {
if (is_started) return ALT_MAYBE;
else {
TTCN_Logger::log(TTCN_Logger::MATCHING_PROBLEM, "Matching on port %s failed: Port is not started and the queue is empty.", port_name);
return ALT_NO;
}
} else if (!sender_template.match(my_head->sender_component)) {
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMUNSUCC:TTCN_Logger::MATCHING_MCUNSUCC;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::begin_event(log_sev);
TTCN_Logger::log_event("Matching on port %s will drop a message: Sender of the first message in the queue does not match the from clause: ", port_name);
sender_template.log_match(my_head->sender_component);
TTCN_Logger::end_event();
}
remove_msg_queue_head();
return ALT_REPEAT;
} else if (my_head->item_selection != MESSAGE_0) {
TTCN_Logger::log(my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMUNSUCC:TTCN_Logger::MATCHING_MCUNSUCC, "Matching on port %s will drop a message: Type of the first message in the queue is not charstring.", port_name);
remove_msg_queue_head();
return ALT_REPEAT;
} else if (!value_template.match(*my_head->message_0)) {
const TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF ? TTCN_Logger::MATCHING_MMUNSUCC : TTCN_Logger::MATCHING_MCUNSUCC;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::log_matching_failure(TitanLoggerApiSimple::PortType::message__,
port_name, my_head->sender_component,
TitanLoggerApiSimple::MatchingFailureType_reason::message__does__not__match__template,
(TTCN_Logger::begin_event(log_sev, TRUE), value_template.log_match(*my_head->message_0),
 TTCN_Logger::end_event_log2str()));
}
remove_msg_queue_head();
return ALT_REPEAT;
} else {
if (value_ptr != NULL) *value_ptr = *my_head->message_0;
if (sender_ptr != NULL) *sender_ptr = my_head->sender_component;
TTCN_Logger::Severity log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::MATCHING_MMSUCCESS:TTCN_Logger::MATCHING_MCSUCCESS;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::log_matching_success(TitanLoggerApiSimple::PortType::message__,
port_name, my_head->sender_component,
(TTCN_Logger::begin_event(log_sev, TRUE), value_template.log_match(*my_head->message_0),
 TTCN_Logger::end_event_log2str()));
}
log_sev = my_head->sender_component==SYSTEM_COMPREF?TTCN_Logger::PORTEVENT_MMRECV:TTCN_Logger::PORTEVENT_MCRECV;
if (TTCN_Logger::log_this_event(log_sev)) {
TTCN_Logger::log_msgport_recv(port_name, TitanLoggerApiSimple::Msg__port__recv_operation::trigger__op,
my_head->sender_component, CHARSTRING(0, NULL),
(TTCN_Logger::begin_event(log_sev,TRUE), TTCN_Logger::log_event_str(": charstring : "),
my_head->message_0->log(), TTCN_Logger::end_event_log2str()),
msg_head_count+1);
}
remove_msg_queue_head();
return ALT_YES;
}
}

void PCOType_BASE::incoming_message(const CHARSTRING& incoming_par, component sender_component)
{
if (!is_started) TTCN_error("Port %s is not started but a message has arrived on it.", port_name);
msg_tail_count++;
if (TTCN_Logger::log_this_event(TTCN_Logger::PORTEVENT_MQUEUE)) {
TTCN_Logger::log_port_queue(TitanLoggerApiSimple::Port__Queue_operation::enqueue__msg, port_name, sender_component, msg_tail_count,
CHARSTRING(0, NULL),
(TTCN_Logger::begin_event(TTCN_Logger::PORTEVENT_MQUEUE, TRUE), TTCN_Logger::log_event_str(" charstring : "), incoming_par.log(), TTCN_Logger::end_event_log2str()));
}
msg_queue_item *new_item = new msg_queue_item;
new_item->item_selection = MESSAGE_0;
new_item->message_0 = new CHARSTRING(incoming_par);
new_item->sender_component = sender_component;
append_to_msg_queue(new_item);
}

boolean PCOType_BASE::process_message(const char *message_type, Text_Buf& incoming_buf, component sender_component, OCTETSTRING&)
{
if (!strcmp(message_type, "charstring")) {
CHARSTRING incoming_par;
incoming_par.decode_text(incoming_buf);
incoming_message(incoming_par, sender_component);
return TRUE;
} else return FALSE;
}


/* Bodies of functions, altsteps and testcases */

verdicttype testcase_HelloW(boolean has_timer, double timer_value)
{
TTCN_Runtime::check_begin_testcase(has_timer, timer_value);
TTCN_Location current_location("MyExample.ttcn", 21, TTCN_Location::LOCATION_TESTCASE, "HelloW");
try {
TTCN_Runtime::begin_testcase("MyExample", "HelloW", "MyExample", "MTCType", "MyExample", "MTCType", has_timer, timer_value);
current_location.update_lineno(23);
/* MyExample.ttcn, line 23 */
TTCN_Runtime::map_port(MTC_COMPREF, MTCType_component_MyPCO.get_name(), SYSTEM_COMPREF, MTCType_component_MyPCO.get_name());
current_location.update_lineno(24);
/* MyExample.ttcn, line 24 */
MTCType_component_MyPCO.send(cs_0);
current_location.update_lineno(25);
/* MyExample.ttcn, line 25 */
TTCN_Runtime::setverdict(PASS);
} catch (const TC_Error& tc_error) {
} catch (const TC_End& tc_end) {
TTCN_Logger::log_str(TTCN_FUNCTION, "Test case HelloW was stopped.");
}
return TTCN_Runtime::end_testcase();
}

verdicttype testcase_HelloW2(boolean has_timer, double timer_value)
{
TTCN_Runtime::check_begin_testcase(has_timer, timer_value);
TTCN_Location current_location("MyExample.ttcn", 28, TTCN_Location::LOCATION_TESTCASE, "HelloW2");
try {
TTCN_Runtime::begin_testcase("MyExample", "HelloW2", "MyExample", "MTCType", "MyExample", "MTCType", has_timer, timer_value);
current_location.update_lineno(30);
/* MyExample.ttcn, line 30 */
TIMER T("T", 1.0);
current_location.update_lineno(31);
/* MyExample.ttcn, line 31 */
TTCN_Runtime::map_port(MTC_COMPREF, MTCType_component_MyPCO.get_name(), SYSTEM_COMPREF, MTCType_component_MyPCO.get_name());
current_location.update_lineno(32);
/* MyExample.ttcn, line 32 */
MTCType_component_MyPCO.send(cs_0);
current_location.update_lineno(33);
/* MyExample.ttcn, line 33 */
T.start();
current_location.update_lineno(34);
/* MyExample.ttcn, line 34 */
{
tmp_0:
alt_status tmp_0_alt_flag_0 = ALT_MAYBE;
alt_status tmp_0_alt_flag_1 = ALT_MAYBE;
alt_status tmp_0_alt_flag_2 = ALT_MAYBE;
alt_status tmp_0_default_flag = ALT_MAYBE;
TTCN_Snapshot::take_new(FALSE);
for ( ; ; ) {
if (tmp_0_alt_flag_0 == ALT_MAYBE) {
current_location.update_lineno(35);
/* MyExample.ttcn, line 35 */
tmp_0_alt_flag_0 = MTCType_component_MyPCO.receive(CHARSTRING_template(cs_1), NULL, any_compref, NULL);
if (tmp_0_alt_flag_0 == ALT_YES) {
current_location.update_lineno(35);
/* MyExample.ttcn, line 35 */
T.stop();
current_location.update_lineno(35);
/* MyExample.ttcn, line 35 */
TTCN_Runtime::setverdict(PASS);
break;
}
}
if (tmp_0_alt_flag_1 == ALT_MAYBE) {
current_location.update_lineno(36);
/* MyExample.ttcn, line 36 */
tmp_0_alt_flag_1 = T.timeout();
if (tmp_0_alt_flag_1 == ALT_YES) {
current_location.update_lineno(36);
/* MyExample.ttcn, line 36 */
TTCN_Runtime::setverdict(INCONC);
break;
}
}
if (tmp_0_alt_flag_2 == ALT_MAYBE) {
current_location.update_lineno(37);
/* MyExample.ttcn, line 37 */
tmp_0_alt_flag_2 = MTCType_component_MyPCO.receive(any_compref, NULL);
if (tmp_0_alt_flag_2 == ALT_YES) {
current_location.update_lineno(37);
/* MyExample.ttcn, line 37 */
T.stop();
current_location.update_lineno(37);
/* MyExample.ttcn, line 37 */
TTCN_Runtime::setverdict(FAIL);
break;
}
}
if (tmp_0_default_flag == ALT_MAYBE) {
tmp_0_default_flag = TTCN_Default::try_altsteps();
if (tmp_0_default_flag == ALT_YES || tmp_0_default_flag == ALT_BREAK) break;
else if (tmp_0_default_flag == ALT_REPEAT) goto tmp_0;
}
current_location.update_lineno(34);
/* MyExample.ttcn, line 34 */
if (tmp_0_alt_flag_0 == ALT_NO && tmp_0_alt_flag_1 == ALT_NO && tmp_0_alt_flag_2 == ALT_NO && tmp_0_default_flag == ALT_NO) TTCN_error("None of the branches can be chosen in the alt statement in file MyExample.ttcn between lines 34 and 38.");
TTCN_Snapshot::take_new(TRUE);
}
}
} catch (const TC_Error& tc_error) {
} catch (const TC_End& tc_end) {
TTCN_Logger::log_str(TTCN_FUNCTION, "Test case HelloW2 was stopped.");
}
return TTCN_Runtime::end_testcase();
}


/* Bodies of static functions */

static void pre_init_module()
{
TTCN_Location current_location("MyExample.ttcn", 0, TTCN_Location::LOCATION_UNKNOWN, "MyExample");
module_object.add_testcase_nonpard("HelloW", testcase_HelloW);
module_object.add_testcase_nonpard("HelloW2", testcase_HelloW2);
}

static boolean init_comp_type(const char *component_type, boolean init_base_comps)
{
(void)init_base_comps;
if (!strcmp(component_type, "MTCType")) {
MTCType_component_MyPCO.activate_port();
return TRUE;
} else return FALSE;
}

static void module_control_part()
{
TTCN_Location current_location("MyExample.ttcn", 41, TTCN_Location::LOCATION_CONTROLPART, "MyExample");
TTCN_Runtime::begin_controlpart("MyExample");
current_location.update_lineno(43);
/* MyExample.ttcn, line 43 */
testcase_HelloW(FALSE, 0.0);
current_location.update_lineno(44);
/* MyExample.ttcn, line 44 */
testcase_HelloW2(FALSE, 0.0);
TTCN_Runtime::end_controlpart();
}


} /* end of namespace */