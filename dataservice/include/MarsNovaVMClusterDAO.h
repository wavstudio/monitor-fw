#ifndef MARS_NOVA_VM_CLUSTER_DAO_H
#define MARS_NOVA_VM_CLUSTER_DAO_H

#include <string>
#include <list>
#include "MarsException.h"

class MarsNovaVMClusterDAO {
public:
	virtual std::string getFlavorByTenantID(const char* tenantID) throw(MarsException) = 0;   //project_flavor
	virtual std::list<std::string> getTenantIDList() throw(MarsException) = 0;   //project_in_cluster
	virtual int getMinnumByTenantID(const char* tenantID) throw(MarsException) = 0;
	virtual int getMaxnumByTenantID(const char* tenantID) throw(MarsException) = 0;
	virtual int getStopStatusByTenantID(const char* tenantID) throw(MarsException) = 0;
	virtual int getStatusByTenantID(const char* tenantID) throw(MarsException) = 0;
		
	virtual void getImageIDAndUserNameByTenantID(const char* tenantID, std::string& imageID,
						std::string& userName) throw(MarsException) = 0;   //image_cluster
};

#endif   //MARS_NOVA_VM_CLUSTER_DAO_H
