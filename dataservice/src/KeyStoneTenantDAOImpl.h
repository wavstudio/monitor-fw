#ifndef KEYSTONE_TENANT_DAO_IMPL_H
#define KEYSTONE_TENANT_DAO_IMPL_H

#include "KeyStoneTenantDAO.h"

class KeyStoneTenantDAOImpl : public KeyStoneTenantDAO {
public:
	KeyStoneTenantDAOImpl();
	virtual ~KeyStoneTenantDAOImpl();

	std::string getTenantNameByID(const char* tenantID) throw(MarsException);
	std::string getTenantIDOfUser(const char* userName, const char* tenantName) throw(MarsException);
};

#endif   //KEYSTONE_TENANT_DAO_IMPL_H
