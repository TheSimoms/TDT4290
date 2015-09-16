/******************************************************************************
* Copyright (c) 2004, 2014  Ericsson AB
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*  Zoltan Bibo - initial implementation and initial documentation
*  Akos Cserveni
*  Attila Balasko
*  Csaba Bela Koppany
*  Csaba Feher
*  Eduard Czimbalmos
*  Endre Szalai
*  Gabor Szalai
*  Janos Kovesdi
*  Jozsef Gyurusi
*  Tibor Csondes
*  Zoltan Jasz
******************************************************************************/
//
//  File:               TCPasp_PT.cc
//  Description:        TCP test port source
//  Rev:                R9A
//  Prodnr:             CNL 113 347
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#include "TCPasp_PT.hh"
#include "TCPasp_PortType.hh"

namespace TCPasp__PortType {

TCPasp__PT_PROVIDER::TCPasp__PT_PROVIDER(const char *par_port_name)
  : PORT(par_port_name),
#ifdef AS_USE_SSL
			 SSL_Socket("TCP", par_port_name)
#else
			 Abstract_Socket("TCP", par_port_name)
#endif
{
  header_descr = NULL;
  is_packet_hdr_length_offset = FALSE;
  is_packet_hdr_nr_bytes_in_length = FALSE;
  is_packet_hdr_byte_order = FALSE;
  is_packet_hdr_length_value_offset = FALSE;
  is_packet_hdr_length_multiplier = FALSE;
  packet_hdr_length_offset = 0;
  packet_hdr_nr_bytes_in_length = 0;
  packet_hdr_length_value_offset = 0;
  packet_hdr_length_multiplier = 1;
  packet_hdr_byte_order = PacketHeaderDescr::Header_MSB;
}

TCPasp__PT_PROVIDER::~TCPasp__PT_PROVIDER()
{
  delete header_descr;
}

void TCPasp__PT_PROVIDER::set_parameter(const char *parameter_name,
                               const char *parameter_value)
{
  log_debug("entering TCPasp__PT_PROVIDER::set_parameter(%s, %s)", parameter_name,
    parameter_value);
  if(strcmp(parameter_name, "packet_hdr_length_offset") == 0) {
    is_packet_hdr_length_offset = TRUE;
    long int_value;
    if (sscanf(parameter_value, "%ld", &int_value) != 1 || int_value < 0)
      log_error("The value of parameter 'packet_hdr_length_offset' "
	"must be a non-negative integer");
    packet_hdr_length_offset = int_value;
  }
  else if(strcmp(parameter_name, "packet_hdr_nr_bytes_in_length") == 0) {
    is_packet_hdr_nr_bytes_in_length = TRUE;
    long int_value;
    if(sscanf(parameter_value, "%ld", &int_value) != 1 || int_value < 0)
      log_error("The value of parameter 'packet_hdr_nr_bytes_in_length' "
        "must be a non-negative integer");
    packet_hdr_nr_bytes_in_length = int_value;
  }
  else if(strcmp(parameter_name, "packet_hdr_byte_order") == 0) {
    is_packet_hdr_byte_order = TRUE;
    if(strcmp(parameter_value, "MSB") == 0) {
      packet_hdr_byte_order = PacketHeaderDescr::Header_MSB;
    }
    else if (strcmp(parameter_value, "LSB") == 0){
      packet_hdr_byte_order = PacketHeaderDescr::Header_LSB;}
    else log_error("Parameter value '%s' not recognized for parameter "
      "'packet_hdr_byte_order' Possible values: \"MSB\" or \"LSB\"",
      parameter_value);
  }
  else if(strcmp(parameter_name, "packet_hdr_length_value_offset") == 0) {
    is_packet_hdr_length_value_offset = TRUE;
    long int_value;
    if(sscanf(parameter_value, "%ld", &int_value) != 1)
      log_error("The value of parameter 'packet_hdr_length_value_offset' "
        "must be a number");
    packet_hdr_length_value_offset = int_value;
  }
  else if(strcmp(parameter_name, "packet_hdr_length_multiplier") == 0) {
    is_packet_hdr_length_multiplier = TRUE;
    long int_value;
    if(sscanf(parameter_value, "%ld", &int_value) != 1 || int_value <= 0)
      log_error("The value of parameter 'packet_hdr_length_multiplier' "
        "must be a positive integer");
    packet_hdr_length_multiplier = int_value;
  }
  else {
    if(!parameter_set(parameter_name ,parameter_value))
      TTCN_warning("TCPasp__PT_PROVIDER::set_parameter(): Unsupported Test Port parameter: %s", parameter_name);
  }
  log_debug("leaving TCPasp__PT_PROVIDER::set_parameter(%s, %s)", parameter_name, parameter_value);
}

void TCPasp__PT_PROVIDER::Handle_Fd_Event(int fd,
  boolean is_readable, boolean is_writable, boolean is_error)
{
  log_debug("entering TCPasp__PT_PROVIDER::Handle_Fd_Event()");
  Handle_Socket_Event(fd, is_readable, is_writable, is_error);
  log_debug("leaving TCPasp__PT_PROVIDER::Handle_Fd_Event()");
}

void TCPasp__PT_PROVIDER::Handle_Timeout(double time_since_last_call)
{
  log_debug("entering TCPasp__PT_PROVIDER::Handle_Timeout()");
  Handle_Timeout_Event(time_since_last_call);
  log_debug("leaving TCPasp__PT_PROVIDER::Handle_Timeout()");
}

void TCPasp__PT_PROVIDER::message_incoming(const unsigned char* msg, int messageLength, int client_id) {
  log_debug("entering TCPasp__PT_PROVIDER::message_incoming()");
  TCPasp__Types::ASP__TCP parameters;
  parameters.data() = OCTETSTRING(messageLength, msg);
  if(client_id != -1) {
    parameters.client__id() = client_id;
  } else {
    parameters.client__id() = OMIT_VALUE;
  }

  incoming_message(parameters);
  log_debug("leaving TCPasp__PT_PROVIDER::message_incoming()");
}

void TCPasp__PT_PROVIDER::peer_disconnected(int client_id) {
  log_debug("entering TCPasp__PT_PROVIDER::peer_disconnected()");
  if(get_use_connection_ASPs())
  {
    TCPasp__Types::ASP__TCP__Close asp;
    asp.client__id() = client_id;
    incoming_message(asp);
  }
  else Abstract_Socket::peer_disconnected(client_id);
  log_debug("leaving TCPasp__PT_PROVIDER::peer_disconnected()");
}

void TCPasp__PT_PROVIDER::user_map(const char */*system_port*/)
{
  log_debug("entering TCPasp__PT_PROVIDER::user_map()");
  if (is_packet_hdr_nr_bytes_in_length) {
    header_descr = new PacketHeaderDescr(packet_hdr_length_offset,
      packet_hdr_nr_bytes_in_length, packet_hdr_byte_order,
      packet_hdr_length_value_offset, packet_hdr_length_multiplier);
  } else {
    if (is_packet_hdr_length_offset)
      log_error("Parameter 'packet_hdr_length_offset' cannot be used without "
	"'packet_hdr_nr_bytes_in_length'");
    if (is_packet_hdr_byte_order)
      log_error("Parameter 'packet_hdr_byte_order' cannot be used without "
	"'packet_hdr_nr_bytes_in_length'");
    if (is_packet_hdr_length_value_offset)
      log_error("Parameter 'packet_hdr_length_value_offset' cannot be used "
	"without 'packet_hdr_nr_bytes_in_length'");
    if (is_packet_hdr_length_multiplier)
      log_error("Parameter 'packet_hdr_length_multiplier' cannot be used "
	"without 'packet_hdr_nr_bytes_in_length'");
  }
  if(!get_use_connection_ASPs())
    map_user();
  log_debug("leaving TCPasp__PT_PROVIDER::user_map()");
}

void TCPasp__PT_PROVIDER::user_unmap(const char */*system_port*/)
{
  log_debug("entering TCPasp__PT_PROVIDER::user_unmap()");
  unmap_user();
  delete header_descr;
  header_descr = NULL;
  log_debug("leaving TCPasp__PT_PROVIDER::user_unmap()");
}

void TCPasp__PT_PROVIDER::user_start()
{
  log_debug("entering TCPasp__PT_PROVIDER::user_start()");
  log_debug("leaving TCPasp__PT_PROVIDER::user_start()");
}

void TCPasp__PT_PROVIDER::user_stop()
{
  log_debug("entering TCPasp__PT_PROVIDER::user_stop()");
  log_debug("leaving TCPasp__PT_PROVIDER::user_stop()");
}

void TCPasp__PT_PROVIDER::outgoing_send(const TCPasp__Types::ASP__TCP& send_par)
{
  log_debug("entering TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP)");

  if(send_par.client__id().is_bound() && send_par.client__id().ispresent()) {
    send_outgoing((const unsigned char*)send_par.data(),
                  send_par.data().lengthof(), send_par.client__id()());
  } else {
    send_outgoing((const unsigned char*)send_par.data(),
                  send_par.data().lengthof());
  }
  log_debug("leaving TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP)");
}

void TCPasp__PT_PROVIDER::outgoing_send(const TCPasp__Types::ASP__TCP__Connect& send_par)
{
  log_debug("entering TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP__Connect)");

  char remotePort[6];
  char localPort[6];
  const char* localHostname = NULL;
  char* localServicename = NULL;

  sprintf(remotePort, "%d", (int)send_par.portnumber());
  
  if(send_par.local__hostname().is_bound() && send_par.local__hostname().ispresent()) {
    localHostname = send_par.local__hostname()();
  } else {
    localHostname = get_local_host_name();
    if (localHostname) log_debug("using local host name configured in %s: %s", local_address_name(), localHostname);
    else log_debug("using 'localhost' as local host name");
  }
  
  if(send_par.local__portnumber().is_bound() && send_par.local__portnumber().ispresent())
  {
    sprintf(localPort, "%d", (int)send_par.local__portnumber()());
    localServicename = localPort;
  } else if (get_local_port_number()>0) {
    log_debug("using local port number configured in %s: %d", local_port_name(), get_local_port_number());
    sprintf(localPort, "%d", get_local_port_number());
    localServicename = localPort;
  } else {
    log_debug("using ephemeral local port number");
  }

  open_client_connection(send_par.hostname(), remotePort, localHostname, localServicename);
  
  log_debug("leaving TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP__Connect)");
}

void TCPasp__PT_PROVIDER::report_error(int client_id, int msg_length, int sent_length, const unsigned char* msg, const char* error_text)
{
  log_debug("entering TCPasp__PT_PROVIDER::report_error");
  if(get_use_connection_ASPs()){
    TCPasp__Types::ASP__TCP__Send__error asp;
    if(client_id!=-1) asp.client__id() = client_id;
    else asp.client__id() = OMIT_VALUE;
    asp.data()=OCTETSTRING(msg_length,msg);
    asp.os__error__code()=errno;
    if(sent_length==-2){
      asp.sent__octets()=0;
      asp.error__type()=0; //TCP__SEND__INVALID__CLIENT__ID;
    }
    else if(sent_length==-1) {
      asp.sent__octets()=0;
      asp.error__type()=1; //TCP__SEND__ERROR;
    }
    else {
      asp.sent__octets()=sent_length;
      asp.error__type()=2; //TCP__SEND__MESSAGE__NOT__COMPLETE;
    }
    char *emsg=strerror(errno);
    if(emsg) asp.os__error__text()=emsg;
    else asp.os__error__text()="";
    asp.ttcn__error__text()=error_text;
    incoming_message(asp);
    errno=0;
  } else log_error("%s",error_text);
  log_debug("leaving TCPasp__PT_PROVIDER::report_error");
}

const PacketHeaderDescr *TCPasp__PT_PROVIDER::Get_Header_Descriptor() const
{
  return header_descr;
}

void TCPasp__PT_PROVIDER::client_connection_opened(int client_id)
{
  log_debug("entering TCPasp__PT_PROVIDER::client_connection_opened(%d)", client_id);

  if(get_use_connection_ASPs())
  {
    TCPasp__Types::ASP__TCP__Connect__result asp;

    asp.client__id() = client_id;

    incoming_message(asp);
  }
  else Abstract_Socket::client_connection_opened(client_id);

  log_debug("leaving TCPasp__PT_PROVIDER::client_connection_opened()");
}

void TCPasp__PT_PROVIDER::peer_connected(int client_id, const char * host, const int port)
{
  log_debug("entering TCPasp__PT_PROVIDER::peer_connected(%d, %s, %d)", client_id, host, port);

  if(get_use_connection_ASPs())
  {
    TCPasp__Types::ASP__TCP__Connected asp;

    asp.hostname() = host;
    asp.portnumber() = port;
    asp.client__id() = client_id;

    incoming_message(asp);
  }

  log_debug("leaving TCPasp__PT_PROVIDER::peer_connected()");
}

void TCPasp__PT_PROVIDER::outgoing_send(const TCPasp__Types::ASP__TCP__Close& send_par)
{
  log_debug("entering TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP__Close)");

  if(send_par.client__id().is_bound() && send_par.client__id().ispresent())
    remove_client((int)send_par.client__id()());
  else
    remove_all_clients();

  log_debug("leaving TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP__Close)");
}

void TCPasp__PT_PROVIDER::outgoing_send(const TCPasp__Types::ASP__TCP__Listen& send_par)
{
  log_debug("entering TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP__Listen)");

  char localPort[7];
  const char* localServicename = NULL;
  const char* localHostname = NULL;
  
  if(send_par.local__hostname().is_bound() && send_par.local__hostname().ispresent()) {
    localHostname = send_par.local__hostname()();
  } else {
    localHostname = get_local_host_name();
    if (localHostname) { log_debug("using local host name configured in %s: %s", local_address_name(), get_local_host_name()); }
    else { log_debug("using 'localhost' as local host name"); }

  }
  
  if(send_par.portnumber().is_bound() && send_par.portnumber().ispresent())
  {
    sprintf(localPort, "%d", (int)send_par.portnumber()());
    localServicename = (const char*)&localPort;
  } else if (get_local_port_number()>0) {
    log_debug("using local port number configured in %s: %d", local_port_name(), get_local_port_number());
    sprintf(localPort, "%d", get_local_port_number());
    localServicename = localPort;
  } else {
    log_debug("using ephemeral local port number");
  }
  open_listen_port(localHostname, localServicename);
  

  log_debug("leaving TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP__Listen)");
}

void TCPasp__PT_PROVIDER::listen_port_opened(int port_number)
{
  log_debug("entering TCPasp__PT_PROVIDER::listen_port_opened(%d)", port_number);

  if(get_use_connection_ASPs())
  {
    TCPasp__Types::ASP__TCP__Listen__result asp;
    asp.portnumber() = port_number;
    incoming_message(asp);
  }
  else Abstract_Socket::listen_port_opened(port_number);

  log_debug("leaving TCPasp__PT_PROVIDER::listen_port_opened()");
}

void TCPasp__PT_PROVIDER::outgoing_send(const TCPasp__Types::ASP__TCP__Shutdown& /*send_par*/)
{
  log_debug("entering TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP__Shutdown)");

  close_listen_port();

  log_debug("leaving TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP__Shutdown)");
}

void TCPasp__PT_PROVIDER::outgoing_send(const TCPasp__Types::ASP__TCP__SetAddressFamily& send_par)
{
  log_debug("entering TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP__SetAddressFamily)");

  if (send_par == TCPasp__Types::c__TCP__AF__INET || send_par == TCPasp__Types::c__TCP__IPv4) {
    set_ai_family(AF_INET);
    log_debug("Address family set to %s", (const char*)send_par);
  } else if (send_par == TCPasp__Types::c__TCP__AF__INET6 || send_par == TCPasp__Types::c__TCP__IPv6) {
    set_ai_family(AF_INET6);
    log_debug("Address family set to %s", (const char*)send_par);
  } else if(send_par == TCPasp__Types::c__TCP__AF__UNSPEC || send_par == TCPasp__Types::c__TCP__UNSPEC) {
    set_ai_family(AF_UNSPEC);
    log_debug("Address family set to %s", (const char*)send_par);
  } else {
    log_warning("Address family %s is not allowed. Ignored.", (const char*)send_par);
  }

  log_debug("leaving TCPasp__PT_PROVIDER::outgoing_send(ASP__TCP__SetAddressFamily)");
}

const char* TCPasp__PT_PROVIDER::local_port_name()              { return "serverPort";}
const char* TCPasp__PT_PROVIDER::remote_address_name()          { return "destIPAddr";}
const char* TCPasp__PT_PROVIDER::local_address_name()           { return "serverIPAddr";}
const char* TCPasp__PT_PROVIDER::remote_port_name()             { return "destPort";}
const char* TCPasp__PT_PROVIDER::ai_family_name()               { return "addressFamily";}
const char* TCPasp__PT_PROVIDER::halt_on_connection_reset_name(){ return "halt_on_connection_reset";}
const char* TCPasp__PT_PROVIDER::server_mode_name()             { return "server_mode";}
const char* TCPasp__PT_PROVIDER::socket_debugging_name()        { return "socket_debugging";}
const char* TCPasp__PT_PROVIDER::nagling_name()                 { return "nagling";}
const char* TCPasp__PT_PROVIDER::server_backlog_name()          { return "server_backlog";}
const char* TCPasp__PT_PROVIDER::ssl_use_ssl_name()                { return "ssl_use_ssl";}
const char* TCPasp__PT_PROVIDER::ssl_use_session_resumption_name() { return "ssl_use_session_resumption";}
const char* TCPasp__PT_PROVIDER::ssl_private_key_file_name()       { return "ssl_private_key_file";}
const char* TCPasp__PT_PROVIDER::ssl_trustedCAlist_file_name()     { return "ssl_trustedCAlist_file";}
const char* TCPasp__PT_PROVIDER::ssl_certificate_file_name()       { return "ssl_certificate_chain_file";}
const char* TCPasp__PT_PROVIDER::ssl_password_name()               { return "ssl_private_key_password";}
const char* TCPasp__PT_PROVIDER::ssl_cipher_list_name()            { return "ssl_allowed_ciphers_list";}
const char* TCPasp__PT_PROVIDER::ssl_verifycertificate_name()      { return "ssl_verify_certificate";}

}//namespace
