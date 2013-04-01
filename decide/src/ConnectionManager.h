#ifndef CONNECTION_MANAGER_H
#define CONNECTION_MANAGER_H

#include "ace/INET_Addr.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "ace/SOCK_Stream.h"
#include "ace/Svc_Handler.h"

class ConnectionManager : public ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> 
{
public:
	typedef ACE_Svc_Handler<ACE_SOCK_STREAM, ACE_NULL_SYNCH> super;
	
	int open(void* = 0);
	virtual int handle_input(ACE_HANDLE fd = ACE_INVALID_HANDLE);
	virtual int handle_close(ACE_HANDLE fd, ACE_Reactor_Mask mask);
};

typedef ACE_Acceptor<ConnectionManager, ACE_SOCK_ACCEPTOR> ClientAcceptor;

#endif   //CONNECTION_MANAGER_H
