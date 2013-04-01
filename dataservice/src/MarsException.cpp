#include "MarsException.h"

MarsException::MarsException(int code)
:m_Code(code) {
	m_Msg = getMarsErrorMsg(code);
}

MarsException::MarsException(const MarsException& ex) {
	m_Code = ex.m_Code;
	m_Msg = ex.m_Msg;
}

MarsException::MarsException(int code, const char* msg) 
:m_Code(code), m_Msg(msg) {
}

MarsException::~MarsException() {
}

int MarsException::getCode() {
	return m_Code;
}

const char* MarsException::getMsg() {
	return m_Msg.c_str();
}

const char* MarsException::getMarsErrorMsg(int code) {
	return "";
}
