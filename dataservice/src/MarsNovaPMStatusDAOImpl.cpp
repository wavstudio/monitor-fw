#include "MarsNovaPMStatusDAOImpl.h"
#include "DBConnectionPool.h"

MarsNovaPMStatusDAOImpl::MarsNovaPMStatusDAOImpl() {
}

MarsNovaPMStatusDAOImpl::~MarsNovaPMStatusDAOImpl() {
}

void MarsNovaPMStatusDAOImpl::updateIPStatusByPMIP(const char* pmip, int ipstatus) throw(MarsException) {
	DBConnection* dbConnection = DBConnectionPool::getInstance()->getDBConnection("mars");
	std::string sql = "update nova_pm_status set ipstatus=";
	sql += ipstatus;
	sql += " where pmip='";
	sql += pmip;
	sql += "'";

	dbConnection->execQuery(sql.c_str());
}

