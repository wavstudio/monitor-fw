#ifndef MARS_NOVA_CLUSTER_INFO_DAO_IMPL_H
#define MARS_NOVA_CLUSTER_INFO_DAO_IMPL_H

#include "MarsNovaClusterInfoDAO.h"

class MarsNovaClusterInfoDAOImpl :public MarsNovaClusterInfoDAO {
public:
	MarsNovaClusterInfoDAOImpl();
	virtual ~MarsNovaClusterInfoDAOImpl();

	std::string getFlavorByClusterType(const char* clusterType) throw(MarsException);
	int getNumByClusterType(const char* clusterType) throw(MarsException);
	std::string getShareIPByClusterType(const char* clusterType) throw(MarsException);
};

#endif   //MARS_NOVA_CLUSTER_INFO_DAO_IMPL_H
