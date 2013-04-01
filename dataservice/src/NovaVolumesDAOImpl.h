#ifndef NOVA_VOLUMES_DAO_IMPL_H
#define NOVA_VOLUMES_DAO_IMPL_H

#include "NovaVolumesDAO.h"

class NovaVolumesDAOImpl :public NovaVolumesDAO {
public:
	NovaVolumesDAOImpl();
	virtual ~NovaVolumesDAOImpl();

	std::string getVolumeID() throw(MarsException);
	std::string getVolumeUUID(const char* uuid) throw(MarsException);
};

#endif   //NOVA_VOLUMES_DAO_IMPL_H
