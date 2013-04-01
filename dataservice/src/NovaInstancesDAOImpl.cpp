#include <stdlib.h>
#include "NovaInstancesDAOImpl.h"
#include "DBConnectionPool.h"

NovaInstancesDAOImpl::NovaInstancesDAOImpl() {
}

NovaInstancesDAOImpl::~NovaInstancesDAOImpl() {
}

std::string NovaInstancesDAOImpl::getVMStateByInstanceUUID(const char* uuid) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select vm_state from instances where uuid='";
	std::string vmstate;

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += uuid;
	sql += "'";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			vmstate = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return vmstate;
}

int NovaInstancesDAOImpl::getInstanceCountByImageID(const char* imageID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select count(*) from instances where image_ref='"; 									
	std::string instanceCount = "0";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += imageID;
	sql += "' and (vm_state='building' or vm_state='active' or vm_state='migrating') and deleted=0";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			instanceCount = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return atoi(instanceCount.c_str());
}

int NovaInstancesDAOImpl::getInstanceCountByProjectID(const char* projectID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select count(*) from instances where project_id='";
	std::string instanceCount = "0";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += projectID;
	sql	+= "' and (vm_state='building' or vm_state='active' or vm_state='migrating') and deleted=0";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			instanceCount = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return atoi(instanceCount.c_str());
}

std::string NovaInstancesDAOImpl::getInstanceUUIDByProjectID(const char* projectID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select uuid from instances where project_id='";
	std::string instanceUUID = "";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += projectID;
	sql += "' and vm_state='active' order by id desc ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			instanceUUID = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return instanceUUID;
}

std::string NovaInstancesDAOImpl::getInstanceUUIDByImageID(const char* imageID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select uuid from instances where image_ref='";
	std::string instanceUUID = "";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += imageID; 
	sql	+= "' and vm_state='active' and deleted=0 order by id desc";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			instanceUUID = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return instanceUUID;
}

std::string NovaInstancesDAOImpl::getFixedIPByInstanceUUID(const char* uuid) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select fixed_ips.address from instances,fixed_ips where fixed_ips.instance_id=instances.id and instances.uuid='";								
	std::string fixedIP = "";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += uuid;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			fixedIP = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return fixedIP;
}

std::list<std::string> NovaInstancesDAOImpl::getFixedIPListByImageID(const char* imageID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select fixed_ips.address from instances,fixed_ips where fixed_ips.instance_id=instances.id and instances.vm_state='active' and instances.deleted=0 and instances.image_ref='";									
	std::string fixedIP = "";
	std::list<std::string> fixedIPList;

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += imageID;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {			
			for (unsigned int index = 0; index < res_ptr->row_count; index++) {
				sqlrow = mysql_fetch_row(res_ptr);				
				fixedIP = sqlrow[0];
				fixedIPList.push_back(fixedIP);				
			}
		}

		mysql_free_result(res_ptr);
	}
	
	return fixedIPList;
}

std::string NovaInstancesDAOImpl::getHostNameByInstanceUUID(const char* uuid) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select host from instances where uuid='";
	std::string host = "";

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += uuid;
	sql += "' ";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			host = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return host;
}

std::list<std::string> NovaInstancesDAOImpl::getInstanceUUIDListByHostName(const char* hostName) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select uuid from instances where vm_state='active' and host='";
	std::string instanceUUID = "";
	std::list<std::string> instanceUUIDList;

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += hostName;
	sql += "'";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {			
			for (unsigned int index = 0; index < res_ptr->row_count; index++) {			
				sqlrow = mysql_fetch_row(res_ptr);	
				instanceUUID = sqlrow[0];
				instanceUUIDList.push_back(instanceUUID);				
			}
		}

		mysql_free_result(res_ptr);
	}
	
	return instanceUUIDList;
}

void NovaInstancesDAOImpl::setVMStateByInstanceUUID(const char* uuid, const char* vmstate) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "update instances set vm_state='";
	sql += vmstate;
	sql += "' where uuid='";
	sql += uuid;
	sql += "'";
		
	dbConnection->execQuery(sql.c_str());
}
