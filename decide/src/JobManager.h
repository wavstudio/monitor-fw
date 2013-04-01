#ifndef JOB_MANAGER_H
#define JOB_MANAGER_H

#include <map>
#include "Job.h"

class JobManager 
{
public:
	static JobManager* getInstance();
	Job* getJob(int code);
	
private:
	JobManager();
	static JobManager* m_Instance;
	
	std::map<int, Job* > m_JobList;
	void init();
};

#endif   //JOB_MANAGER_H

