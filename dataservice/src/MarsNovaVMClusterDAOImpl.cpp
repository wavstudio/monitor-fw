#include <stdlib.h>
#include "MarsNovaVMClusterDAOImpl.h"
#include "DBConnectionPool.h"

MarsNovaVMClusterDAOImpl::MarsNovaVMClusterDAOImpl() {
}

MarsNovaVMClusterDAOImpl::~MarsNovaVMClusterDAOImpl() {
}

std::string MarsNovaVMClusterDAOImpl::getFlavorByTenantID(const char* tenantID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select flavor from nova_vmcluster where tenant_id='";
	std::string flavor = "";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += tenantID;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			flavor = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return flavor;
}

std::list<std::string> MarsNovaVMClusterDAOImpl::getTenantIDList() throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select tenant_id from nova_vmcluster";
	std::string tenantID = "";
	std::list<std::string> tenantIDList;

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {						
			for (unsigned int index = 0; index < res_ptr->row_count; index++) {
				sqlrow = mysql_fetch_row(res_ptr);
				tenantID = sqlrow[0];
				tenantIDList.push_back(tenantID);
			}
		}

		mysql_free_result(res_ptr);
	}
	
	return tenantIDList;
}

void MarsNovaVMClusterDAOImpl::getImageIDAndUserNameByTenantID(const char* tenantID, std::string& imageID,
						std::string& userName) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select image_id, username from nova_vmcluster where tenant_id='";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += tenantID;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			imageID = sqlrow[0];
			userName = sqlrow[1];
		}

		mysql_free_result(res_ptr);
	}
}

int MarsNovaVMClusterDAOImpl::getMinnumByTenantID(const char* tenantID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select minnum from nova_vmcluster where tenant_id='";
	std::string minnum = "0";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += tenantID;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			minnum = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return atoi(minnum.c_str());
}

int MarsNovaVMClusterDAOImpl::getMaxnumByTenantID(const char* tenantID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select maxnum from nova_vmcluster where tenant_id='";
	std::string maxnum = "0";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += tenantID;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			maxnum = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return atoi(maxnum.c_str());
}

int MarsNovaVMClusterDAOImpl::getStopStatusByTenantID(const char* tenantID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select stop_status from nova_vmcluster where tenant_id='";
	std::string stopStatus = "0";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += tenantID;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			stopStatus = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return atoi(stopStatus.c_str());
}

int MarsNovaVMClusterDAOImpl::getStatusByTenantID(const char* tenantID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select status from nova_vmcluster where tenant_id='";
	std::string status = "0";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += tenantID;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			status = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return atoi(status.c_str());
}
