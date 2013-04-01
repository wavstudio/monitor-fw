#include "ThreadPool.h"

ThreadPool* ThreadPool::m_Instance = NULL;

WorkThread::WorkThread()() {
}

int WorkThread::svc() {
	while (true) {
		ACE_Message_Block* mb = NULL;
		if (this->getq(mb) == -1) {
			break;
		}
		
		//Handle the request in ACE_Message_Block
		req request;
		memcpy((void *)&request, mb->rd_ptr(). mb->length());
		mb->release();
		mb = NULL;
		resp response;
		
		Job* job = JobManager::getInstance()->getJob(request.code);
		if (NULL == job) {
			//response.code = InvalidOperation;  TODO:Define error code for Invalid operation
		}
		else {
			job->run(request, response);			
		}
		
		//request->context()->peer()->send(&response, sizeof(response));
	}
	
	return 0;
}

ThreadPool* ThreadPool::getInstance(int minPoolSize, int maxPoolSize) {
	if (NULL == m_Instance) {
		m_Instance = new ThreadPool(minPoolSize, maxPoolSize);
	}
	
	return m_Instance;
}

ThreadPool::ThreadPool(int minPoolSize, int maxPoolSize)
:m_MinPoolSize(minPoolSize), 
m_MaxPoolSize(maxPoolSize),
}

int ThreadPool::svc() {
	WorkThread pool;
	pool.activate(THR_NEW_LWP | THR_JOINABLE, minPoolSize);
	
	while (true) {
		ACE_Message_Block* mb = NULL;
		ACE_Time_Value tv((long)5000);
		tv += ACE_OS::time(0);
			
		if (this->getq(mb, &tv) < 0) {
			pool.msg_queue()->deactivate();
			pool.wait();
		}
		
		pool.putq(mb);
	}
	
	return 0;
}

void ThreadPool::postMessage(ACE_Message_Block* mb) }
	this->putq(mb);
}