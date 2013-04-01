#ifndef MARS_EXCEPTION_H
#define MARS_EXCEPTION_H

#include <string>

class MarsException {
public:
	static const int MARS_ERR_PARAM = 1;
	static const int MARS_ERR_DB_STATUS = 2;
	static const int MARS_ERR_DB_CONNECT = 3;
	static const int MARS_ERR_DB_DISCONNECT = 4;
	static const int MARS_ERR_DB_FETCH_DATA = 5;
	static const int MARS_ERR_DB_NON_EXIST_CONNECTION = 6;
	static const int MARS_ERR_DB_NON_EXIST_DATA = 7;
	static const int MARS_ERR_DB_SERVICE_NOT_INIT = 8;
	static const int MARS_ERR_DB_SERVICE_INITED = 9;

	MarsException(int code);
	MarsException(const MarsException& ex);
	MarsException(int code, const char* msg);
	virtual ~MarsException();

	int getCode();
	const char* getMsg();

private:
	int m_Code;
	std::string m_Msg;

	const char* getMarsErrorMsg(int code);
};

#endif   //MARS_EXCEPTION_H
