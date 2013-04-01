#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#include "ace/INET_Addr.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Stream.h"
#include "ace/Svc_Handler.h"

typedef ACE_Acceptor<ClientService, ACE_SOCK_ACCEPTOR> ClientAccepor;

class ConnectionManager : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> 
{
public:
	typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> super;
	
	int open(void* = 0);
	virtual int handler_input(ACE_HANDLE fd = ACE_INVALID_HANDLER);
	virtual int handle_close(ACE_HANDLE fd, ACE_Reactor_Mask mask);
};

#endif   //CONNECTION_MANAGER_H