//
//  pragma_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/08/2023.
//

#include "pragma_statement.hpp"

    /**
     * add a label destination in the memory management.
     *
     * @param strParameter to be changed - name of the label
     * @param strValue - new value
     * @param iTokenNumber - number of the token in which the PRAGMA statement is added
     */
    PragmaStatement::PragmaStatement(int iTokenNumber, string strParameter, string strValue) {
        mstrParameter = strParameter;
        mstrValue = strValue;
        miTokenNumber = iTokenNumber;
    }

    void PragmaStatement::changeLogLevel(string strLogLevel) {
 //       Logger oLogger = new Logger(this.getClass().getName());

        string strLogLevelList = "trace|debug|info|warning|off";
/*
        if (strLogLevelList.contains(strLogLevel.toLowerCase(Locale.ROOT))) {
            oLogger.setLogLevel(strLogLevel);
        }
*/
//        oLogger.debug("Log Level set to: " + strLogLevel + "...");
    }

    void PragmaStatement::changeTraceLevel(string strTraceLevel) {/*
        if (strTraceLevel.toLowerCase(Locale.ROOT).contains("on")) {
            Trace oTrace = new Trace(true);
        } else {
            Trace oTrace = new Trace(false);
        }*/
    }

    int PragmaStatement::getTokenNumber() {
        return miTokenNumber;
    }

    void PragmaStatement::execute() {
//        if (_strParameter.toLowerCase(Locale.ROOT).contains("log")) {
//            changeLogLevel(_strValue);
//        }

//        if (_strParameter.toLowerCase(Locale.ROOT).contains("trace")) {
//            changeTraceLevel(_strValue);
//        }
    }

    string PragmaStatement::content() {
//        return new String("Pragma Statement: Set " + _strParameter + " to " + _strValue);
        return "";
    }
