//
//  logger.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#ifndef logger_hpp
#define logger_hpp

#include <stdio.h>
#include <string>

#include "common.hpp"

using namespace std;

class Logger {
public:
    static Logger* getInstance();
    
    void setLogLevel(string strLogLevel);
    
    void error(string strClassName, string strErrorMessage);
    void warning(string strClassName, string strWarningMessage);
    void info(string strClassName, string strInfoMessage);
    void debug(string strClassName,string strDebugMessage);

private:
    static Logger* mpoLoggerInstance;
    
    Logger();
    Logger(const Logger&);
    Logger& operator=(const Logger&);
    
    string mstrClassName;
    string mstrLogLevel = "error";
    
    string assembleLogMessage(string strClassName, string strLogMessage);
};

#endif /* logger_hpp */
