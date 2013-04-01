#ifndef KEYSTONE_TENANT_DAO_H
#define KEYSTONE_TENANT_DAO_H

#include <string>
#include "MarsException.h"

class KeyStoneTenantDAO {
public:
	virtual std::string getTenantNameByID(const char* tenantID) throw(MarsException) = 0;   //cluster_tenant
	virtual std::string getTenantIDOfUser(const char* userName, const char* tenantName) throw(MarsException) = 0;   //tenant_cluster
};

#endif   //KEYSTONE_TENANT_DAO_H
