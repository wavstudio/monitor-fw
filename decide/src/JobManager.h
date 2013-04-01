#ifndef JOB_MANAGER_H
#define JOB_MANAGER_H

#include <map>

class JobManager 
{
public:
	static JobManager* getInstance();
	Job* getJob(int code);
	
private:
	JobManager();
	JobManager* m_Instance;
	
	std::map(int, Job*) mJobList;
};

#endif   //JOB_MANAGER_H