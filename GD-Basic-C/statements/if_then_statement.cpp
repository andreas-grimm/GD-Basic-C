//
//  if_then_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 20/09/2023.
//

#include "if_then_statement.hpp"

/**
 * BASIC constructor.
 *
 * @param poCondition - condition to be tested.
 * @param iTokenNumber - the number of this token related to this statement
 * @param iELseStatement location of the next command to be processed after the else command
 * @param iEndIfLine - destination for the jump after unsuccessful completion of the condition.
 * @param iTargetLineNumber - alternative syntax: if the coder wants to use a jump target if the condition is
 *                          true, the jump target is added here.
 */
IfThenStatement::IfThenStatement(Expression* poCondition, int iTokenNumber, int iELseStatement, int iEndIfLine, int iTargetLineNumber) {
    miTokenNumber = iTokenNumber;
    mpoCondition = poCondition;
    mstrLabel = "";
    miElseStatement = iELseStatement;
    miEndIfLine = iEndIfLine;
    miTargetLineNumber = iTargetLineNumber;
}

/**
 * Get Token Number.
 *
 * @return the command line number of the statement
 */
int IfThenStatement::getTokenNumber() {
    return miTokenNumber;
}

/**
 * Execute the If statement.
 *
 * @throws Exception - exposes any exception coming from the memory management
 */
void IfThenStatement::execute() {
    Stack* poStack = Stack::getInstance();
    
    // This part of the method is executed if the BASIC interpreter uses labels (e.g. we are using JASIC)
    if (mpoLabelStatement != NULL) {
        if (mpoLabelStatement->containsLabelKey(mstrLabel)) {
            BooleanValue bValue = mpoCondition->evaluate();
            if (bValue.isTrue()) {
                mpoProgramPointer->setCurrentStatement(mpoLabelStatement->getLabelStatement(mstrLabel));
            }
            
            return;
        }
    }

    // here we are using line numbers to jump to the destination. This is only done for BASIC programs.
    mpoLogger->debug("IfThenStatement::execute", "mpoCondition = " + mpoCondition->content());
    bool bValue = mpoCondition->evaluate()->to_bool();
    mpoLogger->debug("IfThenStatement::execute", "Evaluated condition = " + std::to_string(bValue));

    // different to the code above: when the result of the condition is false, then ignore the next block and
    // jump to the END-IF statement.
    if (!bValue) {
        int iStatementNo = 0;
        
        if (miElseStatement != 0) { // ok - we found an ELSE statement - so we jump there rather than to the END-IF
            iStatementNo = mpoLineNumberObject->getStatementFromLineNumber(mpoLineNumberObject->getNextLineNumber(miElseStatement));
        } else {
            // no ELSE - check for an END-IF
            if (miEndIfLine != 0) {
                iStatementNo = mpoLineNumberObject->getStatementFromLineNumber(mpoLineNumberObject->getNextLineNumber(miEndIfLine));
            }
        }
        
        if (iStatementNo != 0) {
            mpoProgramPointer->setCurrentStatement(iStatementNo);
            return;
        }
        
        
        // only if the _iElseStatement, _iEndIfLine number and the _iTargetLineNumber are 0 then we have a
        // problem
        if (miTargetLineNumber == 0) {
            mpoLogger->error("IfThenStatement::execute", "IF [unknown]: Target: [" + to_string(miEndIfLine) + "]");
            exit(ERR_UNKNOWN_IF_STMT);
        }
        
        return;
    }

    // if the condition is true, check whether we have a jump target. The jump target needs to be valid otherwise
    // an exception is thrown
    if (miTargetLineNumber != 0) {
        int iStatementNo = mpoLineNumberObject->getStatementFromLineNumber(miTargetLineNumber);

        if (iStatementNo != 0) {
            mpoProgramPointer->setCurrentStatement(iStatementNo);
            return;
        }
        mpoLogger->error("IfThenStatement::execute", "IF [unknown]: Target: [" + to_string(miTargetLineNumber) + "]");
        exit(ERR_UNKNOWN_IF_STMT);
    }

    if (miElseStatement != 0) { // ok - we found an ELSE statement - and we will run into it. So put the
        // necessary info on the stack, then ELSE can use it to jump over the ELSE block.
        int iStatementNo = mpoLineNumberObject->getStatementFromLineNumber(mpoLineNumberObject->getNextLineNumber(miEndIfLine));
        poStack->push(new IntegerValue(iStatementNo));
    }
}

/**
 * This method is used in testing and debugging. It returns the set values when the constructor has been called.
 *
 * @return - readable string with the name and the value of the assignment
 */
string IfThenStatement::content() {
    return "IF (" + mpoCondition->content() + ") THEN " + to_string(miTargetLineNumber);
}
