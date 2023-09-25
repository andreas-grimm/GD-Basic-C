//
//  line_number_xref.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 24/08/2023.
//

#include "line_number_xref.hpp"

LineNumberXRef* LineNumberXRef::mpoLineNumberXRefInstance = NULL;

LineNumberXRef::LineNumberXRef() {
}

LineNumberXRef* LineNumberXRef::getInstance() {
    if (mpoLineNumberXRefInstance == NULL) {
        mpoLineNumberXRefInstance = new LineNumberXRef();
    }

    return mpoLineNumberXRefInstance;
}

void LineNumberXRef::setLogLevel(string strLogLevel) {
    mstrLogLevel = strLogLevel;
    
    Logger* poLogger = Logger::getInstance();
    poLogger->setLogLevel(mstrLogLevel);
};

/**
 * add a line number destination in the memory management.
 *
 * @param iLineNumber - name of the label
 * @param iTokenNumber - statement number
 */
void LineNumberXRef::putLineNumber(int iLineNumber, int iTokenNumber) {
    mmiiLineNumbers[iTokenNumber] = iLineNumber;
}

/**
 * add a line number destination in the memory management.
 *
 * @param iTokenNumber - name of the label
 * @param iStatementNumber - statement number
 */
void LineNumberXRef::putStatementNumber(int iTokenNumber, int iStatementNumber) {
    mpoLogger->debug("LineNumberXRef::putStatementNumber","iTokenNumber [" + to_string(iTokenNumber) + "] iStatementNumber ["
            + to_string(iStatementNumber) + "]");
    mmiiStatementNumbers[iTokenNumber] = iStatementNumber;
}

/**
 * get the statement number of the line number searched.
 *
 * @param iTokenNumber token number
 * @return BASIC source code line number
 * @throws RuntimeException a requested token number was not found
 */
int LineNumberXRef::getLineNumberFromToken(int iTokenNumber) {
  
    if (mmiiLineNumbers.contains(iTokenNumber)) {
        mpoLogger->debug("LineNumberXRef::getLineNumberFromToken","Token No. [" + to_string(iTokenNumber) + "] ---> Line No. [" + to_string(mmiiLineNumbers[iTokenNumber]) + "]");

        return mmiiLineNumbers[iTokenNumber];
    }

    mpoLogger->error("LineNumberXRef::getLineNumberFromToken","Token No. [" + to_string(iTokenNumber) + "] not found");
    exit(ERR_MEM_TOKEN_NOT_FOUND);
}


/**
 * get the statement number of the line number searched.
 *
 * @param iStatement statement number
 * @return token number
 * @throws RuntimeException a requested token number was not found
 */
int LineNumberXRef::getTokenFromStatement(int iStatement) {
    for (auto oTokenStatementPair : mmiiStatementNumbers) {
        if (oTokenStatementPair.second == iStatement) {
            mpoLogger->debug("LineNumberXRef::getTokenFromStatement","Statement No. [" + to_string(iStatement) + "] ---> Token No. [" + to_string(oTokenStatementPair.first) + "]");
            return oTokenStatementPair.first;
        }
    }

    mpoLogger->error("LineNumberXRef::getTokenFromStatement","Statement No. [" + to_string(iStatement) + "] not found");
    exit(ERR_MEM_STMT_NOT_FOUND);
}

/**
 * get the statement number of the line number searched.
 *
 * @param iLineNumber BASIC source code line number
 * @return statement number
 * @throws RuntimeException a requested statement number was not found
 */
int LineNumberXRef::getStatementFromLineNumber(int iLineNumber) {
    for (auto oTokenLineNumbersPair : mmiiLineNumbers) {
        if (oTokenLineNumbersPair.second == iLineNumber) {
            int iTokenNumber = oTokenLineNumbersPair.first;

            if (mmiiStatementNumbers.contains(iTokenNumber)) {
                mpoLogger->debug("LineNumberXRef::getStatementFromLineNumber","Line No. [" + to_string(iLineNumber) + "] ---> Statement [" + to_string(mmiiStatementNumbers[iTokenNumber]) + "]");
                return mmiiStatementNumbers[iTokenNumber];
            }
        }
    }

    mpoLogger->error("LineNumberXRef::getStatementFromLineNumber","Line No. [" + to_string(iLineNumber) + "] not found");
    exit(ERR_MEM_LINE_NOT_FOUND);
}

/**
 * get the statement number of the token number searched.
 *
 * @param iTokenNumber token number
 * @return statement number
 * @throws RuntimeException a requested statement number was not found
 */
int LineNumberXRef::getStatementFromToken(int iTokenNumber) {

    if (mmiiStatementNumbers.contains(iTokenNumber)) {
        mpoLogger->debug("LineNumberXRef::getStatementFromToken","Token No. [" + to_string(iTokenNumber) + "] ---> Statement ["
                + to_string(mmiiStatementNumbers[iTokenNumber]) + "]");
        return mmiiStatementNumbers[iTokenNumber];
    }

    mpoLogger->error("LineNumberXRef::getStatementFromToken","Token No. [" + to_string(iTokenNumber) + "] not found");
    exit(ERR_MEM_TOKEN_NOT_FOUND);
}

/**
 * get the statement number of the line number searched.
 *
 * @param iLineNumber BASIC source code line number
 * @return next following BASIC source code number
 */
int LineNumberXRef::getNextLineNumber(int iLineNumber) {
    int iNextHigherStatement = 0;

    for (auto oLine : mmiiLineNumbers) {

        if (oLine.second > iLineNumber) {
            int iNewNextHigher = oLine.second;

            if (iNextHigherStatement == 0) {
                iNextHigherStatement = iNewNextHigher;
            }

            if (iNewNextHigher < iNextHigherStatement) {
                iNextHigherStatement = iNewNextHigher;
            }
        }
    }
    mpoLogger->debug("LineNumberXRef::getNextLineNumber","Line No. [" + to_string(iLineNumber) + "] ---> next Line No. ["
                     + to_string(iNextHigherStatement) + "]");

    return iNextHigherStatement;
}

/**
 * verify that a requested statement number is in the XRef table.
 *
 * @param iTokenNumber statement number
 * @return true if the statement is in the memory management
 */
bool LineNumberXRef::contains(int iTokenNumber) {

    return mmiiLineNumbers.contains(iTokenNumber);
}

/**
 * verify that a requested statement number is in the XRef table.
 */
void LineNumberXRef::list() {
    for (auto oLine : mmiiLineNumbers) {
        mpoLogger->debug("LineNumberXRef::list","Token No. [" + to_string(oLine.first) + "] ---> Line No. ["
                                   + to_string(oLine.second) + "]");
    }
}
