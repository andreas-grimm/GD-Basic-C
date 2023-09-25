//
//  logger.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#include "logger.hpp"
#include "printer.hpp"
#include "color_schema.hpp"
#include <iostream>

Logger* Logger::mpoLoggerInstance = NULL;

Logger::Logger() {
    mstrLogLevel = "error";
}

Logger* Logger::getInstance() {
    if (mpoLoggerInstance == NULL) {
        mpoLoggerInstance = new Logger();
    }
    
    return mpoLoggerInstance;
}

void Logger::setLogLevel(string strLogLevel) {
    mstrLogLevel = strLogLevel;
};

void Logger::error(string strClassName, string strErrorMessage) {
    Printer oPrinter;

    strClassName = RED + strClassName + ":" + RESET;
    oPrinter.println(assembleLogMessage(strClassName, strErrorMessage));
};

void Logger::warning(string strClassName, string strWarningMessage) {
    Printer oPrinter;

    strClassName = YELLOW + strClassName + ":" + RESET;
    oPrinter.println(assembleLogMessage(strClassName, strWarningMessage));
};

void Logger::info(string strClassName, string strInfoMessage) {
    Printer oPrinter;
    
    if ((mstrLogLevel.compare("error") == YES) ||
        (mstrLogLevel.compare("warn") == YES) ||
        (mstrLogLevel.compare("debug") == YES) ||
        (mstrLogLevel.compare("info") == YES)) {
        strClassName = RESET + strClassName + ":" ;
        oPrinter.println(assembleLogMessage(strClassName, strInfoMessage));
    }
};

void Logger::debug(string strClassName, string strDebugMessage) {
    Printer oPrinter;
    
    if (!mstrLogLevel.empty()) {
        if ((mstrLogLevel.compare("error") == YES) ||
            (mstrLogLevel.compare("warn") == YES) ||
            (mstrLogLevel.compare("debug") == YES)) {
            strClassName = BLUE + strClassName + ":" + RESET;
            oPrinter.println(assembleLogMessage(strClassName, strDebugMessage));
        }
    }
};

string Logger::assembleLogMessage(string strClassName, string strLogMessage) {
    string strReturn = strClassName + "\t\t\t\t" + strLogMessage;
    
    return strReturn;
}

