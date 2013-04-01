#ifndef NOVA_INSTANCES_DAO_IMPL_H
#define NOVA_INSTANCES_DAO_IMPL_H

#include "NovaInstancesDAO.h"

class NovaInstancesDAOImpl :public NovaInstancesDAO {
public:
	NovaInstancesDAOImpl();
	virtual ~NovaInstancesDAOImpl();

	std::string getVMStateByInstanceUUID(const char* uuid) throw(MarsException);
	int getInstanceCountByImageID(const char* imageID) throw(MarsException);
	int getInstanceCountByProjectID(const char* projectID) throw(MarsException);
	std::string getInstanceUUIDByProjectID(const char* projectID) throw(MarsException);
	std::string getInstanceUUIDByImageID(const char* imageID) throw(MarsException);
	std::string getFixedIPByInstanceUUID(const char* uuid) throw(MarsException);
	std::list<std::string> getFixedIPListByImageID(const char* imageID) throw(MarsException);
	std::string getHostNameByInstanceUUID(const char* uuid) throw(MarsException);
	std::list<std::string> getInstanceUUIDListByHostName(const char* hostName) throw(MarsException);
		
	void setVMStateByInstanceUUID(const char* uuid, const char* vmstate) throw(MarsException);
};

#endif   //NOVA_INSTANCES_DAO_IMPL_H
