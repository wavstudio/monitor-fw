#include "MarsNovaUserDAOImpl.h"
#include "DBConnectionPool.h"

MarsNovaUserDAOImpl::MarsNovaUserDAOImpl() {
}

MarsNovaUserDAOImpl::~MarsNovaUserDAOImpl() {
}

std::string MarsNovaUserDAOImpl::getPasswordByUserName(const char* userName) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select password from nova_user where username='";
	std::string password = "";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += userName;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			password = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return password;
}

void MarsNovaUserDAOImpl::setPasswordByUserName(const char*userName, const char* password) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "update nova_user set password='";
	sql += password;
	sql += "' where username='";
	sql += userName;
	sql += "'";

	dbConnection->execUpdate(sql.c_str());
}
