#ifndef MARS_NOVA_PM_STATUS_DAO_H
#define MARS_NOVA_PM_STATUS_DAO_H

#include <string>
#include "MarsException.h"

class MarsNovaPMStatusDAO {
public:
	virtual void updateIPStatusByPMIP(const char* pmip, int ipstatus) throw(MarsException) = 0;   //update_mysql
};

#endif   //MARS_NOVA_PM_STATUS_DAO_H
