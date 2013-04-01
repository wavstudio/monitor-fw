#ifndef MARS_NOVA_CLUSTER_INFO_DAO_H
#define MARS_NOVA_CLUSTER_INFO_DAO_H

#include <string>
#include "MarsException.h"

class MarsNovaClusterInfoDAO {
public:
	virtual std::string getFlavorByClusterType(const char* clusterType) throw(MarsException) = 0;   //image_flavor
	virtual int getNumByClusterType(const char* clusterType) throw(MarsException) = 0;
	virtual std::string getShareIPByClusterType(const char* clusterType) throw(MarsException) = 0;
};

#endif   //MARS_NOVA_CLUSTER_INFO_DAO_H
