#ifndef MARS_NOVA_USER_DAO_IMPL_H
#define MARS_NOVA_USER_DAO_IMPL_H

#include "MarsNovaUserDAO.h"

class MarsNovaUserDAOImpl :public MarsNovaUserDAO {
public:
	MarsNovaUserDAOImpl();
	virtual ~MarsNovaUserDAOImpl();

	std::string getPasswordByUserName(const char* userName) throw(MarsException);
	void setPasswordByUserName(const char*userName, const char* password) throw(MarsException);
};

#endif   //MARS_NOVA_USER_DAO_IMPL_H
