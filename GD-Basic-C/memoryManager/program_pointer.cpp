//
//  program_pointer.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 20/09/2023.
//

#include "program_pointer.hpp"

ProgramPointer* ProgramPointer::mpoProgramPointerInstance = NULL;

ProgramPointer::ProgramPointer() {
    miCurrentStatement = 0;
}

ProgramPointer* ProgramPointer::getInstance() {
    if (mpoProgramPointerInstance == NULL) {
        mpoProgramPointerInstance = new ProgramPointer();
    }
    
    return mpoProgramPointerInstance;
}


/**
 * set the current statement number.
 *
 * @param iCurrentStatement - number of the current statement
 */
void ProgramPointer::setCurrentStatement(int iCurrentStatement) {
    miCurrentStatement = iCurrentStatement;
}

/**
 * get the current statement number.
 *
 * @return - current statement number
 */
int ProgramPointer::getCurrentStatement() {
    return miCurrentStatement;
}

/**
 * calculate the next statement number.
 */
void ProgramPointer::calcNextStatement() {
    miCurrentStatement++;
}

