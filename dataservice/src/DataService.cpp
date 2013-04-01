#include "DataService.h"
#include "KeyStoneTenantDAOImpl.h"
#include "MarsNovaClusterInfoDAOImpl.h"
#include "MarsNovaPMStatusDAOImpl.h"
#include "MarsNovaUserDAOImpl.h"
#include "MarsNovaVMClusterDAOImpl.h"
#include "NovaImagePropDAOImpl.h"
#include "NovaInstancesDAOImpl.h"
#include "NovaVolumesDAOImpl.h"

bool DataService::m_IsInitialized = false;
DBConnectionPool* DataService::m_DBConnectionPool = NULL;
KeyStoneTenantDAO* DataService::m_KeyStoneTenantDAO = NULL;
MarsNovaClusterInfoDAO* DataService::m_MarsNovaClusterInfoDAO = NULL;
MarsNovaPMStatusDAO* DataService::m_MarsNovaPMStatusDAO = NULL;
MarsNovaUserDAO* DataService::m_MarsNovaUserDAO = NULL;
MarsNovaVMClusterDAO* DataService::m_MarsNovaVMClusterDAO = NULL;
NovaImagePropDAO* DataService::m_NovaImagePropDAO = NULL;
NovaInstancesDAO* DataService::m_NovaInstancesDAO = NULL;
NovaVolumesDAO* DataService::m_NovaVolumesDAO = NULL;

void DataService::initialize(const char* addr) throw(MarsException) {
	if (m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_INITED);
	}
	
	m_DBConnectionPool = DBConnectionPool::getInstance();
	m_DBConnectionPool->connect(addr);
	m_KeyStoneTenantDAO = new KeyStoneTenantDAOImpl();
	m_MarsNovaClusterInfoDAO = new MarsNovaClusterInfoDAOImpl();
	m_MarsNovaPMStatusDAO = new MarsNovaPMStatusDAOImpl();
	m_MarsNovaUserDAO = new MarsNovaUserDAOImpl();
	m_MarsNovaVMClusterDAO = new MarsNovaVMClusterDAOImpl();
	m_NovaImagePropDAO = new NovaImagePropDAOImpl();
	m_NovaInstancesDAO = new NovaInstancesDAOImpl();
	m_NovaVolumesDAO = new NovaVolumesDAOImpl();
	
	m_IsInitialized = true;
}

void DataService::unInitialize() throw(MarsException) {
	if (!m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_NOT_INIT);
	}
	
	m_DBConnectionPool->disconnect();
	delete m_KeyStoneTenantDAO;
	delete m_MarsNovaClusterInfoDAO;
	delete m_MarsNovaPMStatusDAO;
	delete m_MarsNovaUserDAO;
	delete m_MarsNovaVMClusterDAO;
	delete m_NovaImagePropDAO;
	delete m_NovaInstancesDAO;
	delete m_NovaVolumesDAO; 
	
	m_KeyStoneTenantDAO = NULL; 
	m_MarsNovaClusterInfoDAO = NULL;
	m_MarsNovaPMStatusDAO = NULL;
	m_MarsNovaUserDAO = NULL;
	m_MarsNovaVMClusterDAO = NULL;
	m_NovaImagePropDAO = NULL;
	m_NovaInstancesDAO = NULL;
	m_NovaVolumesDAO = NULL;
	
	m_IsInitialized = false;
}

DBConnectionPool* DataService::getDBConnectionPool() throw(MarsException) {
	if (!m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_NOT_INIT);
	}
	
	return m_DBConnectionPool;
}

KeyStoneTenantDAO* DataService::getKeyStoneTenantDAO() throw(MarsException) {
	if (!m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_NOT_INIT);
	}
	
	return m_KeyStoneTenantDAO;
}

MarsNovaClusterInfoDAO* DataService::getMarsNovaClusterInfoDAO() throw(MarsException) {
	if (!m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_NOT_INIT);
	}
	
	return m_MarsNovaClusterInfoDAO;
}

MarsNovaPMStatusDAO* DataService::getMarsNovaPMStatusDAO() throw(MarsException) {
	if (!m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_NOT_INIT);
	}
	
	return m_MarsNovaPMStatusDAO;
}

MarsNovaUserDAO* DataService::getMarsNovaUserDAO() throw(MarsException) {
	if (!m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_NOT_INIT);
	}
	
	return m_MarsNovaUserDAO;
}

MarsNovaVMClusterDAO* DataService::getMarsNovaVMClusterDAO() throw(MarsException) {
	if (!m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_NOT_INIT);
	}
	
	return m_MarsNovaVMClusterDAO;
}

NovaImagePropDAO* DataService::getNovaImagePropDAO() throw(MarsException) {
	if (!m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_NOT_INIT);
	}
	
	return m_NovaImagePropDAO;
}

NovaInstancesDAO* DataService::getNovaInstancesDAO() throw(MarsException) {
	if (!m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_NOT_INIT);
	}
	
	return m_NovaInstancesDAO;
}

NovaVolumesDAO* DataService::getNovaVolumesDAO() throw(MarsException) {
	if (!m_IsInitialized) {
		throw MarsException(MarsException::MARS_ERR_DB_SERVICE_NOT_INIT);
	}
	
	return m_NovaVolumesDAO;
}