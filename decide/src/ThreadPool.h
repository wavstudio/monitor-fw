#ifndef THREAD_POOL_H
#define THREAD_POOL_H

class WorkThread : public ACE_Task<ACE_MT_SYNCH> 
{
public:
	WorkThread();
	
	int svc();
};

class ThreadPool : public ACE_Task<ACE_MT_SYNCH> 
{
public:
	
	static ThreadPool* getInstance(int minPoolSize, int maxPoolSize);
	
	int svc();	
	void postMessage(ACE_Message_Block* mb);
	
private:
	static ThreadPool* m_Instance;
	int m_MinPoolSize, m_MaxPoolSize;;
	bool isShutDown;
	
	bool isDone();	
	ThreadPool(int minPoolSize, int maxPoolSize);
};



#endif   //THREAD_POOL_H