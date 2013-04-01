#ifndef NOVA_VOLUMES_DAO_H
#define NOVA_VOLUMES_DAO_H

#include <string>
#include "MarsException.h"

class NovaVolumesDAO {
public:
	virtual std::string getVolumeID() throw(MarsException) = 0;
	virtual std::string getVolumeUUID(const char* uuid) throw(MarsException) = 0;
};

#endif   //NOVA_VOLUMES_DAO_H
