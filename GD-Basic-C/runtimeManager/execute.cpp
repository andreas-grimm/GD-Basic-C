//
//  Execute.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/09/2023.
//

#include "Execute.hpp"
Execute::Execute(Program* poProgram) {
    mvpoPreRunStatements = poProgram->getPreRunStatements();
    mvpoStatements = poProgram->getStatements();
    
    mpoTrace = Trace::getInstance();
}

void Execute::loadEnvironment() {
    mpoLogger->info("Execute::loadEnvironment","Pre-load environment...");
    if (mvpoPreRunStatements.size() > 0) {
        /*
        _oProgramPointer.setCurrentStatement(0);
        while (_oProgramPointer.getCurrentStatement() < _aoPreRunStatements.size()) {
            // as long as we have not reached the end of the code
            int iThisStatement = _oProgramPointer.getCurrentStatement();

            _oProgramPointer.calcNextStatement();
            _oLogger.debug("PreRun Statement # <" + iThisStatement + ">: [" + _aoPreRunStatements.get(
                    iThisStatement).content() + "]");

            _aoPreRunStatements.get(iThisStatement).execute();
        }
         */
    } else {
        mpoLogger->debug("Execute::loadEnvironment","No pre-parsing run...");
    }
}

void Execute::runProgram() {

    mpoLogger->info("Execute::loadEnvironment","Starting execution...");
    if (mvpoStatements.size() > 0) {
        int iSourceCodeLineNumber = -1;
        mpoProgramPointer->setCurrentStatement(0);

        while (mpoProgramPointer->getCurrentStatement() < mvpoStatements.size()) {
            // as long as we have not reached the end of the code
            int iThisStatement = mpoProgramPointer->getCurrentStatement();

            iSourceCodeLineNumber = mpoLineNumbers->getLineNumberFromToken(mvpoStatements[iThisStatement]->getTokenNumber());

            mpoProgramPointer->calcNextStatement();

            mpoLogger->debug(
                    "Execute::runProgram",
                    "Basic Source Code Line [" + to_string(iSourceCodeLineNumber) + "] Statement [ "
                            + to_string(mvpoStatements[iThisStatement]->getTokenNumber()) + "]: "
                            + mvpoStatements[iThisStatement]->content());

            mpoTrace->trace(iSourceCodeLineNumber);

            mvpoStatements[iThisStatement]->execute();
        }
    } else {
        mpoLogger->error("Execute::runProgram","Parsing delivered empty program");
        exit(ERR_PARSE_EMPTY_PROGRAM);
    }
}

