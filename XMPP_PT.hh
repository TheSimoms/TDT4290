// This Test Port skeleton header file was generated by the
// TTCN-3 Compiler of the TTCN-3 Test Executor version CRL 113 200/5 R3A
// for user (user@user-multicom) on Mon Sep 28 11:15:10 2015

// Copyright Ericsson Telecom AB 2000-2014

// You may modify this file. Add your attributes and prototypes of your
// member functions here.

#ifndef XMPP__PT_HH
#define XMPP__PT_HH

#include <TTCN3.hh>
#include "http_etherx_jabber_org_streams.hh"
#include "XMPP_Types.hh"
#include "Abstract_Socket.hh"

// Note: Header file XMPP_PortType.hh must not be included into this file!
// (because it includes this file)
// Please add the declarations of message types manually.

namespace XMPP__PortType {

class XMPP__PT_PROVIDER : public PORT,
#ifdef AS_USE_SSL
					 public SSL_Socket
#else
					 public Abstract_Socket
#endif
{
public:
	XMPP__PT_PROVIDER(const char *par_port_name);
	~XMPP__PT_PROVIDER();

	void set_parameter(const char *parameter_name, const char *parameter_value);

private:
	void Handle_Fd_Event(int fd, boolean is_readable, boolean is_writable, boolean is_error);
	void Handle_Timeout(double time_since_last_call);

	PacketHeaderDescr *header_descr;
	boolean is_packet_hdr_length_offset, is_packet_hdr_nr_bytes_in_length,
		is_packet_hdr_byte_order, is_packet_hdr_length_value_offset,
		is_packet_hdr_length_multiplier;
	unsigned long packet_hdr_length_offset, packet_hdr_nr_bytes_in_length, packet_hdr_length_multiplier;
	long packet_hdr_length_value_offset;
	PacketHeaderDescr::HeaderByteOrder packet_hdr_byte_order;
protected:
	void user_map(const char *system_port);
	void user_unmap(const char *system_port);

	void user_start();
	void user_stop();

	const char* local_port_name();
	const char* remote_address_name();
	const char* local_address_name();
	const char* remote_port_name();
	const char* ai_family_name();
	const char* halt_on_connection_reset_name();
	const char* server_mode_name();
	const char* socket_debugging_name();
	const char* nagling_name();
	const char* server_backlog_name();
	const char* ssl_use_ssl_name();
	const char* ssl_use_session_resumption_name();
	const char* ssl_private_key_file_name();
	const char* ssl_trustedCAlist_file_name();
	const char* ssl_certificate_file_name();
	const char* ssl_password_name();
	const char* ssl_cipher_list_name();
	const char* ssl_verifycertificate_name();

	void outgoing_send(const XMPP__Types::XMPP__Connect& send_par);
	void outgoing_send(const XMPP__Types::XMPP__Listen& send_par);
	void outgoing_send(const XMPP__Types::XMPP__Shutdown& send_par);
	void outgoing_send(const CHARSTRING& send_par);
	void outgoing_send(const http__etherx__jabber__org__streams::Stream& send_par);
	void outgoing_send(const XMPP__Types::XMPP__Close& send_par);

	virtual void incoming_message(const XMPP__Types::XMPP__Connect__result& incoming_par) = 0;
	virtual void incoming_message(const XMPP__Types::XMPP__Connected& incoming_par) = 0;
	virtual void incoming_message(const XMPP__Types::XMPP__Listen__result& incoming_par) = 0;
	virtual void incoming_message(const XMPP__Types::XMPP__Send__error& incoming_par) = 0;
	virtual void incoming_message(const http__etherx__jabber__org__streams::Stream& incoming_par) = 0;
	virtual void incoming_message(const XMPP__Types::XMPP__Close& incoming_par) = 0;

	void message_incoming(const unsigned char* msg, int length, int client_id = -1);
	void listen_port_opened(int port_number);
	void client_connection_opened(int client_id);
	void peer_connected(int client_id, const char * host, const int port);
	void peer_disconnected(int client_id);
	void Add_Fd_Read_Handler(int fd) { Handler_Add_Fd_Read(fd); }
	void Add_Fd_Write_Handler(int fd) { Handler_Add_Fd_Write(fd); }
	void Remove_Fd_Read_Handler(int fd) { Handler_Remove_Fd_Read(fd); }
	void Remove_Fd_Write_Handler(int fd) { Handler_Remove_Fd_Write(fd); }
	void Remove_Fd_All_Handlers(int fd) { Handler_Remove_Fd(fd); }
	void Handler_Uninstall() { Uninstall_Handler(); }
	void Timer_Set_Handler(double call_interval, boolean is_timeout = TRUE,
	  boolean call_anyway = TRUE, boolean is_periodic = TRUE) {
	  Handler_Set_Timer(call_interval, is_timeout, call_anyway, is_periodic);
	}
	void report_error(int client_id, int msg_length, int sent_length, const unsigned char* msg, const char* error_text);

	const PacketHeaderDescr* Get_Header_Descriptor() const;
};

} /* end of namespace */

#endif
