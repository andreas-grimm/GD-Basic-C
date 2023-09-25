//
//  program.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#include "program.hpp"

Program::Program(string strLogLevel) {
    mstrLogLevel = strLogLevel;
    
    mpoLogger = Logger::getInstance();
    mpoLogger->setLogLevel(mstrLogLevel);
};

int Program::read(string strProgramName){
    return OK;
}

void Program::load(string strProgramName) {
    FileHandler* poFileHandler = new FileHandler();
    string* pstrProgram = new string;

    mpoLogger->info("Program::load","Loading program...");
    int iReturnCode = OK;

    iReturnCode = poFileHandler->readFile(strProgramName, pstrProgram);
    
    mpoLogger->debug("Program::load",*pstrProgram);
    
    mstrLoadedProgramSource = *pstrProgram;
    mstrCurrentProgramSource = *pstrProgram;
    
    delete poFileHandler;
    
    if (iReturnCode != OK) {
        mpoLogger->error("Program::load", "Load Error: Code: `" + to_string(iReturnCode) + "`");
        exit(ERR_PROGRAM_FILE_NOT_READABLE);

    }
}

void Program::setTokens(vector<Token> voTokens) {
    mvoTokens = voTokens;
}

vector<Token> Program::getTokens() {
    return mvoTokens;
}

string Program::getProgram() {
    return mstrCurrentProgramSource;
}

void Program::setProgram(string strProgram) {
    mstrCurrentProgramSource = strProgram;
};

void Program::setPreRunStatements(vector<Statement*> vpoPreRunStatements) {
    mvpoPreRunStatements = vpoPreRunStatements;
};

void Program::setStatements(vector<Statement*> vpoStatements) {
    mvpoStatements = vpoStatements;
};

/**
 * get PreRunStatements.
 * This method provides the list of pre-run statements inside this object.
 *
 * @return array of statements objects.
 */
vector<Statement*> Program::getPreRunStatements() {
    return mvpoPreRunStatements;
}

/**
 * get Statements.
 * This method provides the list of statements inside this object.
 *
 * @return array of statements objects.
 */
vector<Statement*> Program::getStatements() {
    return mvpoStatements;
}
