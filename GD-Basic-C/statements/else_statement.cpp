//
//  else_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/09/2023.
//

#include "else_statement.hpp"

/**
 * Default constructor.
 *
 * An "ELSE" statement jumps to the command past the "END-IF" command.
 *
 * @param iTokenNumber the line number of this command
 */
ElseStatement::ElseStatement(int iTokenNumber) {
    mpoProgramPointer = ProgramPointer::getInstance();
    miTokenNumber = iTokenNumber;
    mpoLogger = Logger::getInstance();
}

int ElseStatement::getTokenNumber() {
    return miTokenNumber;
}

void ElseStatement::execute() {
    Stack* poStack = Stack::getInstance();

    int iTargetLineNumber = ((IntegerValue) poStack->pop()).to_int();

    if (iTargetLineNumber == 0) {
        mpoLogger->error("ElseStatement::execute", "Undefined Jump Target");
        exit(ERR_UNDEF_JMP_TARGET);
    } else {
        mpoProgramPointer->setCurrentStatement(iTargetLineNumber);
    }

}

string ElseStatement::content() {
    return "ELSE";
}
