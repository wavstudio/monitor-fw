#ifndef MARS_NOVA_PM_STATUS_DAO_IMPL_H
#define MARS_NOVA_PM_STATUS_DAO_IMPL_H

#include "MarsNovaPMStatusDAO.h"

class MarsNovaPMStatusDAOImpl :public MarsNovaPMStatusDAO {
public:
	MarsNovaPMStatusDAOImpl();
	virtual ~MarsNovaPMStatusDAOImpl();

	void updateIPStatusByPMIP(const char* pmip, int ipstatus) throw(MarsException);
};

#endif   //MARS_NOVA_PM_STATUS_DAO_IMPL_H
