#ifndef NOVA_IMAGE_PROP_DAO_H
#define NOVA_IMAGE_PROP_DAO_H

#include <string>
#include "MarsException.h"

class NovaImagePropDAO {
public:
	virtual std::string getValueByImageID(const char* imageID) throw(MarsException) = 0;
};

#endif   //NOVA_IMAGE_PROP_DAO_H
