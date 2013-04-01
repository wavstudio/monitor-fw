#include "ConnectionManager.h"

int ConnectionManager::open(void* p) {
	if (super::open(p) == -1) {
		return -1;
	}
	
	//set keepavlive of peer();
	
	return 0;
}

int ConnectionManager::handle_input(ACE_HANDLE fd) {
	const size_t INPUT_SIZE = 256;
	char buffer[INPUT_SIZE] = {0};
	ssize_t recvBytes = 0;
	
	recvBytes = this->peer().recv(buffer, sizeof(buffer));
	if (recvBytes <= 0) {
		//Connection closed
		return -1;
	}
	
	//put received message into thread pool
	ACE_Message_Block* mb = new ACE_Message_Block(recvBytes);
	mb->copy(buffer, recvBytes);
	ThreadPool::getInstance()->postMessage(mb);
	
	return 0;
}

int ConnectionManager::handle_close(ACE_HANDLE fd, ACE_Reactor_Mask mask) {
	if (mask == ACE_Event_Handler::WRITE_MASK) {
		return 0;
	}
	
	return super::handle_close(fd, mask);
}

