#ifndef MARS_NOVA_USER_DAO_H
#define MARS_NOVA_USER_DAO_H

#include <string>
#include "MarsException.h"

class MarsNovaUserDAO {
public:
	virtual std::string getPasswordByUserName(const char* userName) throw(MarsException) = 0;	
	virtual void setPasswordByUserName(const char*userName, const char* password) throw(MarsException) = 0;   ////update_mysql
};

#endif   //MARS_NOVA_USER_DAO_H
