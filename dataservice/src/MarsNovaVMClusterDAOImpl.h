#ifndef MARS_NOVA_VM_CLUSTER_DAO_IMPL_H
#define MARS_NOVA_VM_CLUSTER_DAO_IMPL_H

#include "MarsNovaVMClusterDAO.h"

class MarsNovaVMClusterDAOImpl :public MarsNovaVMClusterDAO {
public:
	MarsNovaVMClusterDAOImpl();
	virtual ~MarsNovaVMClusterDAOImpl();

	std::string getFlavorByTenantID(const char* tenantID) throw(MarsException);
	std::list<std::string> getTenantIDList() throw(MarsException);
	void getImageIDAndUserNameByTenantID(const char* tenantID, std::string& imageID,
						std::string& userName) throw(MarsException);
							
	int getMinnumByTenantID(const char* tenantID) throw(MarsException);
	int getMaxnumByTenantID(const char* tenantID) throw(MarsException);
	int getStopStatusByTenantID(const char* tenantID) throw(MarsException);
	int getStatusByTenantID(const char* tenantID) throw(MarsException);
};

#endif   //MARS_NOVA_VM_CLUSTER_DAO_IMPL_H
