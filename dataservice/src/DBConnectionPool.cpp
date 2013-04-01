#include <string.h>
#include "DBConnectionPool.h"

DBConnectionPool* DBConnectionPool::m_Instance = NULL;

DBConnectionPool::DBConnectionPool() {

}

DBConnectionPool::~DBConnectionPool() {
	disconnect();
}

DBConnectionPool* DBConnectionPool::getInstance() {
	if (NULL != m_Instance) {
		m_Instance = new DBConnectionPool();
	}

	return m_Instance;
}

DBConnection* DBConnectionPool::getDBConnection(const char* dbname) throw(MarsException) {
	DBConnection* dbConnection = NULL;

	if (dbname != NULL && !strlen(dbname)) {
		std::map<std::string, DBConnection* >::iterator it = m_DBConnectionMap.find(dbname);
		if (it != m_DBConnectionMap.end()) {
			dbConnection = m_DBConnectionMap.find(dbname)->second;
			if (NULL == dbConnection) {
				throw MarsException(MarsException::MARS_ERR_DB_NON_EXIST_CONNECTION);
			}
		}
		else {
			throw MarsException(MarsException::MARS_ERR_DB_NON_EXIST_CONNECTION);
		}
		
	}
	else {
		throw MarsException(MarsException::MARS_ERR_PARAM);
	}

	return dbConnection;
}

void DBConnectionPool::connect(const char*addr) throw(MarsException) {
	const char* dbNameList[] = {"nova", "glance", "keystone", "mars"};

	if (NULL == addr || !strlen(addr)) {
		throw MarsException(MarsException::MARS_ERR_PARAM);
	}
	
	try {
		for (unsigned int index = 0; index < sizeof(dbNameList); index++) {
			DBConnection* dbConnection = new DBConnection;
			try {
				dbConnection->connect(addr, dbNameList[index]);			
				m_DBConnectionMap.insert(std::pair<std::string, DBConnection* >(dbNameList[index], dbConnection));	
			}
			catch (MarsException& ex) {
				delete dbConnection;
				dbConnection = NULL;
				throw ex;
			}			
		}
	}
	catch (MarsException& ex) {
		disconnect();
		throw ex;
	}
}

void DBConnectionPool::disconnect() throw(MarsException) {
	std::map<std::string, DBConnection* >::iterator it;
		
	for (it = m_DBConnectionMap.begin();it != m_DBConnectionMap.end(); ++it) {
		DBConnection*dbConnection = it->second;		
		try {
			dbConnection->disconnect();
		}
		catch (MarsException& ex) {

		}
		delete dbConnection;
	}
	
	m_DBConnectionMap.clear();
}
