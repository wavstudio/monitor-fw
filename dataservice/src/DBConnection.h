#ifndef DB_CONNECTION_H
#define DB_CONNECTION_H

#include <string>
#include <mysql/mysql.h>
#include "MarsException.h"

class DBConnection {
public:
	typedef enum {
		DB_STATUS_CONNECTED = 0, 
		DB_STATUS_DISCONNECTED = 1
	} db_status_t;

	DBConnection();
	virtual ~DBConnection();

	void connect(const char* addr, const char* dbname) throw(MarsException);
	void* execQuery(const char* sql) throw(MarsException);
	void execUpdate(const char* sql) throw(MarsException);
	void disconnect() throw(MarsException);

private:
	MYSQL m_DBConnection;	
	db_status_t m_Status;
	std::string m_Addr;
	std::string m_DBName;
};

#endif   //DB_CONNECTION_H
