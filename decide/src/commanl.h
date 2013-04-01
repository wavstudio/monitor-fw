/*
 * commanl.h
 *
 *  Created on: Mar 11, 2013
 *      Author: root
 */

#ifndef COMMANL_H_
#define COMMANL_H_

#include <string>
#include <time.h>
#include <math.h>
#include <log4cpp/Category.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#define LOG_FORMAT			"[%d{%Y-%m-%d %H:%M:%S}][%p]%m%n"
#define COMMON_SHM_KEY			0xde11dc
#define PERM				S_IRUSR | S_IWUSR | IPC_CREAT
#define DEBUG_INFO			__FILE__, __LINE__, __PRETTY_FUNCTION__
#define dcLog(level, content)			dc_log(DEBUG_INFO, level, content)
#define strFileName  "/usr/test.log"
#define maxFileSize 50
#define maxBackIndex  10

using namespace std;

class commanl {
public:
	commanl();
	virtual ~commanl();

    typedef enum LevelENUM{
        DEBUG = 700,
        INFO = 600,
        ERROR = 300,
        ALERT = 100
    }levelEnum;

    bool init();
    /*level info*/
    void debug(const char *);
    /*level warning*/
    void info(const char *);
    /*level error*/
    void error(const char *);
    /*level alarm*/
    void alarm(const char *);
    /*custom level*/
    void dc_log(const char* file, const int line, const char* function, levelEnum, const char *);

    /* change LogLevel */
    bool changeLogLevel(std::string&);
    int checkFileSize(int newSize);
    bool checkSameFile();
    string get_prefix(const char* file, const int line, const char* function);
    inline log4cpp::CategoryStream debugStream()
    {
        refreshLogLevel();
        return m_Log->getStream(log4cpp::Priority::DEBUG);
    };

    inline log4cpp::CategoryStream infoStream()
    {
        refreshLogLevel();
        return m_Log->getStream(log4cpp::Priority::INFO);
    };

    inline log4cpp::CategoryStream errorStream()
    {
        refreshLogLevel();
        return m_Log->getStream(log4cpp::Priority::ERROR);
    };

    inline log4cpp::CategoryStream alertStream()
    {
        refreshLogLevel();
        return m_Log->getStream(log4cpp::Priority::ALERT);
    };

private:
	log4cpp::Category* m_Log;
    log4cpp::Priority::Value m_priority;
    log4cpp::Priority::Value *m_pLevel;
    int log_fd;

private:
    /* refresh LogLevel */
    void refreshLogLevel(void);
};

#endif /* COMMANL_H_ */
