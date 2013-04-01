#ifndef DATA_SERVICE_H
#define DATA_SERVICE_H

#include "MarsException.h"
#include "DBConnectionPool.h"
#include "KeyStoneTenantDAO.h"
#include "MarsNovaClusterInfoDAO.h"
#include "MarsNovaPMStatusDAO.h"
#include "MarsNovaUserDAO.h"
#include "MarsNovaVMClusterDAO.h"
#include "NovaImagePropDAO.h"
#include "NovaInstancesDAO.h"
#include "NovaVolumesDAO.h"

class DataService {
public:
	static void initialize(const char* addr) throw(MarsException);
	static void unInitialize() throw(MarsException);
	static DBConnectionPool* getDBConnectionPool() throw(MarsException);
	static KeyStoneTenantDAO* getKeyStoneTenantDAO() throw(MarsException);
	static MarsNovaClusterInfoDAO* getMarsNovaClusterInfoDAO() throw(MarsException);
	static MarsNovaPMStatusDAO* getMarsNovaPMStatusDAO() throw(MarsException);
	static MarsNovaUserDAO* getMarsNovaUserDAO() throw(MarsException);
	static MarsNovaVMClusterDAO* getMarsNovaVMClusterDAO() throw(MarsException);
	static NovaImagePropDAO* getNovaImagePropDAO() throw(MarsException);
	static NovaInstancesDAO* getNovaInstancesDAO() throw(MarsException);
	static NovaVolumesDAO* getNovaVolumesDAO() throw(MarsException);
	
private:
	static bool m_IsInitialized;
	static DBConnectionPool* m_DBConnectionPool;
	static KeyStoneTenantDAO* m_KeyStoneTenantDAO;
	static MarsNovaClusterInfoDAO* m_MarsNovaClusterInfoDAO;
	static MarsNovaPMStatusDAO* m_MarsNovaPMStatusDAO;
	static MarsNovaUserDAO* m_MarsNovaUserDAO;
	static MarsNovaVMClusterDAO* m_MarsNovaVMClusterDAO;
	static NovaImagePropDAO* m_NovaImagePropDAO;
	static NovaInstancesDAO* m_NovaInstancesDAO;
	static NovaVolumesDAO* m_NovaVolumesDAO;
};

#endif   //DATA_SERVICE_H