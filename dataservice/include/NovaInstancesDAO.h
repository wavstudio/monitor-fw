#ifndef NOVA_INSTANCES_DAO_H
#define NOVA_INSTANCES_DAO_H

#include <string>
#include <list>
#include "MarsException.h"

class NovaInstancesDAO {
public:
	virtual std::string getVMStateByInstanceUUID(const char* uuid) throw(MarsException) = 0;   //check_vm_state
	virtual int getInstanceCountByImageID(const char* imageID) throw(MarsException) = 0;   //instance_image
	virtual int getInstanceCountByProjectID(const char* projectID) throw(MarsException) = 0;   //instance_project
	virtual std::string getInstanceUUIDByProjectID(const char* projectID) throw(MarsException) = 0;  //uuid_project
	virtual std::string getInstanceUUIDByImageID(const char* imageID) throw(MarsException) = 0;  //uuid_image
	virtual std::string getFixedIPByInstanceUUID(const char* uuid) throw(MarsException) = 0;  //ip_uuid
	virtual std::list<std::string> getFixedIPListByImageID(const char* imageID) throw(MarsException) = 0;   //ip_image
	virtual std::string getHostNameByInstanceUUID(const char* uuid) throw(MarsException) = 0;   //select_host
	virtual std::list<std::string> getInstanceUUIDListByHostName(const char* hostName) throw(MarsException) = 0;   //vm_in_host
		
	virtual void setVMStateByInstanceUUID(const char* uuid, const char* vmstate) throw(MarsException) = 0 ;  //update_nova
};

#endif   //NOVA_INSTANCES_DAO_H
