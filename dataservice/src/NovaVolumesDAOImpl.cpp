#include "NovaVolumesDAOImpl.h"
#include "DBConnectionPool.h"

NovaVolumesDAOImpl::NovaVolumesDAOImpl() {
}

NovaVolumesDAOImpl::~NovaVolumesDAOImpl() {
}

std::string NovaVolumesDAOImpl::getVolumeID() throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select id from volumes where deleted=0 and status='available' limit 1";
	std::string volumeID = "";
	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			volumeID = sqlrow[0];
			mysql_free_result(res_ptr);
		}
		else {
			mysql_free_result(res_ptr);
			throw MarsException(MarsException::MARS_ERR_DB_NON_EXIST_DATA);
		}
	}
	else {
		throw MarsException(MarsException::MARS_ERR_DB_FETCH_DATA);
	}
	
	return volumeID;
}

std::string NovaVolumesDAOImpl::getVolumeUUID(const char* uuid) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select volumes.id from volumes, instances where volumes.instance_id=instances.id and uuid='";
	std::string volumeUUID = "";
	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += uuid;
	sql += "'";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			volumeUUID = sqlrow[0];
			mysql_free_result(res_ptr);
		}
		else {
			throw MarsException(MarsException::MARS_ERR_DB_NON_EXIST_DATA);
		}		
	}
	else {
		throw MarsException(MarsException::MARS_ERR_DB_FETCH_DATA);
	}
	
	return volumeUUID;
}
