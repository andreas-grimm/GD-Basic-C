//
//  goto_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 20/09/2023.
//

#include "goto_statement.hpp"

/**
 * Default constructor.
 *
 * @param strTarget - target of the jump - defined by a label
 */
GotoStatement::GotoStatement(string strTarget) {
    mpoLogger = Logger::getInstance();

    miTokenNumber = 0;
    mstrTarget = strTarget;
}

/**
 * Default constructor.
 * @param iTokenNumber - number of the line of the command
 * @param strTarget - target of the jump - defined by a label
 */
GotoStatement::GotoStatement(int iTokenNumber, string strTarget) {
    mpoLogger = Logger::getInstance();

    miTokenNumber = iTokenNumber;
    mstrTarget = strTarget;
}

/**
 * Get Token Number.
 *
 * @return the command line number of the statement
 */
int GotoStatement::getTokenNumber() {
    return miTokenNumber;
}

/**
 * Execute the transaction.
 *
 * @throws SyntaxErrorException for unknown or incorrect formatted targets
 */
void GotoStatement::execute() {
    // This part of the method is executed if the BASIC interpreter uses labels (e.g. we are using JASIC)
    if (mpoLabelStatement->containsLabelKey(mstrTarget)) {
        
        mpoLogger->debug("GotoStatement::execute","jump to [" + mstrTarget + "]");
        mpoProgramPointer->setCurrentStatement(mpoLabelStatement->getLabelStatement(mstrTarget));
        mpoLogger->debug("GotoStatement::execute","jump to [" + to_string(mpoLabelStatement->getLabelStatement(mstrTarget)) + "]");
        return;
    }

    // here we are using line numbers to jump to the destination. This is only done for BASIC programs.
    int iTokenNo = mpoLineNumberObject->getStatementFromLineNumber(stoi(mstrTarget));

    if (iTokenNo != 0) {
        mpoProgramPointer->setCurrentStatement(iTokenNo);
        return;
    }

    mpoLogger->error("GotoStatement::execute","GOTO [unknown]: Target: " + mstrTarget);
    exit(ERR_GOTO_UNKNOWN_TARGET);
}

/**
 * This method is used in testing and debugging. It returns the set values when the constructor has been called.
 *
 * @return - readable string with the name and the value of the assignment
 */
string GotoStatement::content() {
    if (mpoLabelStatement->containsLabelKey(mstrTarget)) {
        return "GOTO [" + mstrTarget + "]: Destination: " + to_string(mpoLabelStatement->getLabelStatement(mstrTarget));
    }

    return "GOTO [" + mstrTarget + "]: Destination: " + to_string(mpoLineNumberObject->getStatementFromLineNumber(stoi(mstrTarget)));
}
