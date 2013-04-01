#include "KeyStoneTenantDAOImpl.h"
#include "DBConnectionPool.h"

KeyStoneTenantDAOImpl::KeyStoneTenantDAOImpl() {
}

KeyStoneTenantDAOImpl::~KeyStoneTenantDAOImpl() {
}

std::string KeyStoneTenantDAOImpl::getTenantNameByID(const char* tenantID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("keystone");
	std::string sql = "select name from tenant where id='";	
	std::string tenantName;

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += tenantID;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());;
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			tenantName = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return tenantName;
}

std::string KeyStoneTenantDAOImpl::getTenantIDOfUser(const char* userName, const char* tenantName) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("keystone");
		
	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;
	std::string tenantID = "";
	std::string sql = "select tenant.id from tenant,user,user_tenant_membership where user_tenant_membership.user_id=user.id and user_tenant_membership.tenant_id = tenant.id and tenant.name='";			
			
	sql += tenantName;
	sql += "' and user.name='";
	sql += userName;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			tenantID = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return tenantID;
}
