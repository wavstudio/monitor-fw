#include "NovaImagePropDAOImpl.h"
#include "DBConnectionPool.h"

NovaImagePropDAOImpl::NovaImagePropDAOImpl() {
}

NovaImagePropDAOImpl::~NovaImagePropDAOImpl() {
}

std::string NovaImagePropDAOImpl::getValueByImageID(const char* imageID) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("nova");
	std::string sql = "select value from image_properties where deleted=0 and image_id='";
	std::string value;

	MYSQL_RES* res_ptr = NULL;
	MYSQL_ROW sqlrow;

	sql += imageID;
	sql += "'";
	res_ptr = (MYSQL_RES*)dbConnection->execQuery(sql.c_str());
	if (res_ptr) {
		if (res_ptr->row_count) {
			sqlrow = mysql_fetch_row(res_ptr);
			value = sqlrow[0];
		}

		mysql_free_result(res_ptr);
	}
	
	return value;
}