#include "JobManager.h"

JobManager* JobManager::m_Instance = NULL;

JobManager::JobManager() {
}

Job* JobManager::getJob(int code) {
	Job* job = NULL;
	
	std::map<int,JobManager*>::iterator it = mJobList.find(code);
	if (it != mJobList.end()) {
		job = mJobList->second;
	}
	
	return job;
}

JobManager* JobManager::getInstance() {
	if (NULL == m_Instance) {
		m_Instance = new JobManager;
		m_Instance.init();
	}
	
	return m_Instance;
}

void JobManager::init() {
	//Create all jobs and put them into mJobList
	//m_Instance.insert(std::pair<int, JobManager*>(code, new Job()));
}