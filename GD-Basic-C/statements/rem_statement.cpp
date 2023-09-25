//
//  rem_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 30/08/2023.
//

#include "rem_statement.hpp"

/**
 * Default constructor.
 *
 * An "REM" statement performs the hard termination of the interpreter.
 * @param iTokenNumber - number of the command in the basic program
 * @param strRemText - text of the rem statement
 */
RemStatement::RemStatement(int iTokenNumber, string strRemText) {

    miTokenNumber = iTokenNumber;
    mstrRemText = strRemText;
}

/**
 * Get Line Number.
 *
 * @return iLineNumber - the command line number of the statement
 */
int RemStatement::getTokenNumber() {
    return miTokenNumber;
}

/**
 * Execute.
 *
 * Terminate the running program.
 */
void RemStatement::execute() {
}

/**
 * Content.
 *
 * Method for JUnit to return the content of the statement.
 *
 * @return - gives the name of the statement ("REM")
 */
string RemStatement::content() {
    return "REM [" + mstrRemText + "]";
}
