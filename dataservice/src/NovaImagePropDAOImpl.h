#ifndef NOVA_IMAGE_PROP_DAO_IMPL_H
#define NOVA_IMAGE_PROP_DAO_IMPL_H

#include "NovaImagePropDAO.h"

class NovaImagePropDAOImpl :public NovaImagePropDAO {
public:
	NovaImagePropDAOImpl();
	virtual ~NovaImagePropDAOImpl();

	std::string getValueByImageID(const char* imageID) throw(MarsException);
}
;
#endif   //NOVA_IMAGE_PROP_DAO_IMPL_H
