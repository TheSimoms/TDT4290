// This C++ header file was generated by the TTCN-3 compiler
// of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for user (user@user-multicom) on Fri Oct  9 13:09:36 2015

// Copyright Ericsson Telecom AB 2000-2014

// Do not edit this file unless you know what you are doing.

#ifndef http__connect_HH
#define http__connect_HH

#ifdef TITAN_RUNTIME_2
#error Generated code does not match with used runtime.\
 Code was generated without -R option but -DTITAN_RUNTIME_2 was used.
#endif

/* Header file includes */

#include "HTTPmsg_PortType.hh"

#if TTCN3_VERSION != 50300
#error Version mismatch detected.\
 Please check the version of the TTCN-3 compiler and the base library.
#endif

#ifndef LINUX
#error This file should be compiled on LINUX
#endif

namespace http__connect {

/* Type definitions */

typedef COMPONENT HTTP__TYPE;
typedef COMPONENT_template HTTP__TYPE_template;

/* Function prototypes */

extern verdicttype testcase_SuccessfulConnect(boolean has_timer, double timer_value);

/* Global variable declarations */

extern const TTCN_Typedescriptor_t& HTTP__TYPE_descr_;
extern HTTPmsg__PortType::HTTPmsg__PT HTTP__TYPE_component_HTTP__PORT;
extern TIMER HTTP__TYPE_component_TIMER_;
extern const HTTPmsg__Types::HeaderLines_template& header__lines;
extern const HTTPmsg__Types::Connect_template& connect__;
extern const HTTPmsg__Types::Connect__result_template& connect__result;
extern const HTTPmsg__Types::HTTPRequest_template& request;
extern const HTTPmsg__Types::HTTPResponse_template& response;
extern const HTTPmsg__Types::HTTPMessage_template& request__message;
extern const HTTPmsg__Types::HTTPMessage_template& respone__message;
extern TTCN_Module module_object;

} /* end of namespace */

#endif
