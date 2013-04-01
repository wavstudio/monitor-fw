/*
 * commanl.cpp
 *
 *  Created on: Mar 11, 2013
 *      Author: root
 */

#include "commanl.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <errno.h>
#include <boost/lexical_cast.hpp>

using namespace std;

commanl::commanl() {
	// TODO Auto-generated constructor stub
    m_Log = NULL;
    m_priority = log4cpp::Priority::DEBUG;
    m_pLevel = NULL;
}

commanl::~commanl() {
	// TODO Auto-generated destructor stub
	if(log_fd != -1)
		close(log_fd);
}

bool commanl::init()
{
    log4cpp::PatternLayout* pLayout = new log4cpp::PatternLayout();
    pLayout->setConversionPattern(LOG_FORMAT);

    log4cpp::RollingFileAppender* pAppender = new log4cpp::RollingFileAppender("dclog", strFileName, maxFileSize, maxBackIndex);

    if (pAppender != NULL)
    {
    	pAppender->setLayout(pLayout);
        m_Log = &log4cpp::Category::getInstance("dclog");
        m_Log->removeAllAppenders();
        m_Log->setAdditivity(false);
        m_Log->setAppender(pAppender);
        m_Log->setPriority(m_priority);

        log_fd = open(strFileName, O_WRONLY);
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Function Name: debug.
 * Description:  level debug
 * Argument(s): content - log content.
 */
void commanl::debug(const char * content)
{
    std::string temp;
    refreshLogLevel();
    temp.append(content);
    m_Log->debug(temp);
}

/**
 * Function Name: info.
 * Description:  level info
 * Argument(s): content - log content.
 */
void commanl::info(const char * content)
{
    std::string temp;
    refreshLogLevel();
    temp.append(content);
    m_Log->info(temp);
}

/**
 * Function Name: error.
 * Description:  level error
 * Argument(s): content - log content.
 */
void commanl::error(const char * content)
{
    std::string temp;
    refreshLogLevel();
    temp.append(content);
    m_Log->error(temp);
}

/**
 * Function Name: alarm.
 * Description: level alarm
 * Argument(s): content - log content.
 */
void commanl::alarm(const char * content)
{
    std::string temp;
    refreshLogLevel();
    temp.append(content);
    m_Log->alert(temp);
}
/*
 * return 0:normal write the log
 * return 1:lock;Then init the commonLog after write the log
 * return 2:lock and write
 */
int commanl::checkFileSize(int newSize)
{
//	log4cpp::RollingFileAppender* pAppender = (log4cpp::RollingFileAppender*)m_Log->getAppender("dclog");
	off_t offset = ::lseek(log_fd, 0, SEEK_END);
	if (offset >= 0) {
		if((static_cast<size_t>(offset)+newSize) < (maxFileSize - 30*1024)) {
			return 0;
		}
		else {
			if((static_cast<size_t>(offset)+newSize) >= maxFileSize){
				return 1;
			}
			else{
				//cout<<"<<< checkFileSize 2 "<<" offset: "<<offset<<"  newSize"<< newSize<<"  max:"<<maxFileSize<<endl;
				return 2;
			}
		}
	}
	return 2;
}

bool commanl::checkSameFile()
{
	struct stat f1,f2;

	stat(strFileName,&f1);
	fstat(log_fd,&f2);

	//cout<<"<<< checkSameFile  "<<strFileName<<"   log_fd = "<<log_fd<<endl;
	if((f1.st_ino == f2.st_ino) && (f1.st_dev == f2.st_dev))
		return true;
	else
		return false;
}

/**
 * Function Name: alarm.
 * Description: level alarm
 * Argument(s): level -  LevelENUM;
 *              content - log content.
 */
void commanl::dc_log(const char* file, const int line, const char* function, levelEnum level, const char* content)
{
    std::string temp;
    refreshLogLevel();
    temp = get_prefix(file, line, function);
    temp.append(content);
    if (errno) {
        char caErr[20];
        sprintf(caErr, " (errno=%d)", errno);
        temp.append(caErr);
        errno = 0;
    }
    m_Log->log(level, temp);
}

string commanl::get_prefix(const char* file, const int line, const char* function)
{
    std::string temp;
    ostringstream pidtidLog;
    pidtidLog<<"["<<file<<":"<<line<<"]";
    pidtidLog<<"["<<function<<"]";
    pidtidLog<<" ";
    temp.append(string(pidtidLog.str()));
    return temp;
}



/**
 * Function Name: changeLogLevel.
 * Description: set LogLevel to share memory.
 * Return(s): bool , init successfully return true.
 */
bool commanl::changeLogLevel(std::string& level)
{
    char buf[256];
    char oldLevel[6];
    if (m_pLevel == NULL) {
        dcLog(ALERT, "changeLogLevel fail: share memory is not exist!");
        return false;
    }
    switch (*m_pLevel) {
        case DEBUG:
            strcpy(oldLevel, "DEBUG");
            break;
        case INFO:
            strcpy(oldLevel, "INFO");
            break;
        case ERROR:
            strcpy(oldLevel, "ERROR");
            break;
        case ALERT:
            strcpy(oldLevel, "ALERT");
            break;
    }
    if (level == "DEBUG") {
        *m_pLevel = DEBUG;
    } else if (level == "INFO") {
        *m_pLevel = INFO;
    } else if (level == "ERROR") {
        *m_pLevel = ERROR;
    } else if (level == "ALERT") {
        *m_pLevel = ALERT;
    } else {
        memset(buf, 0, sizeof(buf));
        sprintf(buf, "changeLogLevel fail: unknow LogLevel=%s!", level.c_str());
        dcLog(ALERT, buf);
        return false;
    }
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "changeLogLevel from %s to %s success!", oldLevel, level.c_str());
    dcLog(ALERT, buf);
    return true;
}

/**
 * Function Name: refreshLogLevel.
 * Description: refresh LogLevel from share memory.
 */
void commanl::refreshLogLevel(void)
{
    if (m_pLevel && (m_priority != *m_pLevel))
    {
        if (*m_pLevel == DEBUG || *m_pLevel == INFO ||
            *m_pLevel == ERROR || *m_pLevel == ALERT)
	{
            m_priority = *m_pLevel;
            m_Log->setPriority(m_priority);
        }
    }
    return;
}

int write_log(const char* file, const int line, const char* function, commanl **tmp_log, commanl::levelEnum level, const char* content)
{
	int ret = 0;
	commanl *tlog=*tmp_log;

	ret = tlog->checkFileSize(strlen(content));
	if(ret)
	{
		if(ret == 1)
		{
			if(tlog->checkSameFile())
			{
				tlog->dc_log(file, line, function, level, content);
			}
			else
			{
				delete tlog;
				tlog = new commanl();
				tlog->init();
				tlog->dc_log(file, line, function, level, content);
			}
		}
		else
		{
			tlog->dc_log(file, line, function, level, content);
		}
	}
	else{
		tlog->dc_log(file, line, function, level, content);
	}
	return 1;
}
