#ifndef DB_CONNECTION_POOL_H
#define DB_CONNECTION_POOL_H

#include <map>
#include "DBConnection.h"

class DBConnectionPool {
public:
	static DBConnectionPool* getInstance();
	virtual ~DBConnectionPool();

	DBConnection* getDBConnection(const char* dbname) throw(MarsException);
	void connect(const char*addr) throw(MarsException);
	void disconnect() throw(MarsException);

private:
	DBConnectionPool();
	
	static DBConnectionPool* m_Instance;
	std::map<std::string, DBConnection* > m_DBConnectionMap;
};

#endif   //DB_CONNECTION_POOL_H 
