#include <string.h>

#include "DBConnection.h"

DBConnection::DBConnection()
: m_Status(DB_STATUS_DISCONNECTED) ,
m_Addr(""),
m_DBName("")
{

}

DBConnection::~DBConnection() {
	disconnect();
}

void DBConnection::connect(const char* addr, const char* dbname) throw(MarsException) {
	if (NULL == addr || NULL == dbname || !strlen(addr) || !strlen(dbname)) {
		throw MarsException(MarsException::MARS_ERR_PARAM);
	}

	if (DB_STATUS_CONNECTED != m_Status) {
		mysql_init(&m_DBConnection);
		if (mysql_real_connect(&m_DBConnection, addr, dbname, dbname, dbname, 0, NULL, 0)) {
			m_Status = DB_STATUS_CONNECTED;
			m_Addr = addr;
			m_DBName = dbname;
		}
		else {
			throw MarsException(mysql_errno(&m_DBConnection), mysql_error(&m_DBConnection));
		}
	}
	else {
		throw MarsException(MarsException::MARS_ERR_DB_STATUS);
	}
}

void* DBConnection::execQuery(const char* sql) throw(MarsException) {
	MYSQL_RES* res_ptr = NULL;

	if (NULL == sql || !strlen(sql)) {
		throw MarsException(MarsException::MARS_ERR_PARAM);
	}

	if (DB_STATUS_DISCONNECTED != m_Status) {
		int res =mysql_query(&m_DBConnection, sql);
		if (res) {
			throw MarsException(mysql_errno(&m_DBConnection), mysql_error(&m_DBConnection));			
		}
		else {
			res_ptr = mysql_store_result(&m_DBConnection);
		}
	}
	else {
		throw MarsException(MarsException::MARS_ERR_DB_STATUS);
	}

	return (void *)res_ptr;
}

void DBConnection::execUpdate(const char* sql) throw(MarsException) {
	if (NULL == sql || !strlen(sql)) {
		throw MarsException(MarsException::MARS_ERR_PARAM);
	}
	
	if (DB_STATUS_DISCONNECTED != m_Status) {
		int res =mysql_query(&m_DBConnection, sql);
		if (res) {
			throw MarsException(mysql_errno(&m_DBConnection), mysql_error(&m_DBConnection));
		}
		else {
			if(mysql_errno(&m_DBConnection)){
				
			}
		}
	}
	else {
		throw MarsException(MarsException::MARS_ERR_DB_STATUS);
	}
}

void DBConnection::disconnect() throw(MarsException) {
	if (DB_STATUS_DISCONNECTED != m_Status) {
		mysql_close(&m_DBConnection);
		m_Status = DB_STATUS_DISCONNECTED;
	}
	else {
		throw MarsException(MarsException::MARS_ERR_DB_STATUS);
	}
}

