#ifndef JOB_H
#define JOB_H

#include "Protocal.h"

class Job {
public:
	virtual void run(const req& request, resp& response) = 0;
};

#endif   //JOB_H
