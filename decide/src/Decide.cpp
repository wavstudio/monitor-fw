#include <stdio.h>

#include "ace/INET_Addr.h"
#include "ace/SOCK_Acceptor.h"
#include "ace/Reactor.h"
#include "ace/Acceptor.h"
#include "ConnectionManager.h"

int main(int argc, char** args) {
    
	ACE_INET_Addr listenPort(5000);
	ConnectionManager cm;
	if (cm.open(listenPort) == -1) {
		return 1;
	}
	
	ACE_Reactor::instance£¨£©->run_reactor_event_loop();
	
  return 0;
}
