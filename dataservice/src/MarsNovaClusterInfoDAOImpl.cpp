#include <stdlib.h>

#include "MarsNovaClusterInfoDAOImpl.h"
#include "DBConnectionPool.h"

MarsNovaClusterInfoDAOImpl::MarsNovaClusterInfoDAOImpl() {
}

MarsNovaClusterInfoDAOImpl::~MarsNovaClusterInfoDAOImpl() {
}

std::string MarsNovaClusterInfoDAOImpl::getFlavorByClusterType(const char* clusterType) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select flavor from nova_cluster_info where clustertype='";
	std::string flavor = "";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += clusterType;
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

int MarsNovaClusterInfoDAOImpl::getNumByClusterType(const char* clusterType) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select num from nova_cluster_info where clustertype='";
	std::string num = "0";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += clusterType;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			num = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return atoi(num.c_str());
}

std::string MarsNovaClusterInfoDAOImpl::getShareIPByClusterType(const char* clusterType) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "select shareip from nova_cluster_info where clustertype='";
	std::string shareip = "";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += clusterType;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			shareip = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return shareip;
}

