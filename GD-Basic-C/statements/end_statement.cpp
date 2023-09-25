//
//  end_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 20/09/2023.
//

#include "end_statement.hpp"

/**
 * Default constructor.
 *
 * An "END" statement performs the hard termination of the interpreter.
 */
EndStatement::EndStatement() {
    miTokenNumber = 0;
}

/**
 * Default constructor.
 *
 * An "END" statement performs the hard termination of the interpreter.
 * @param iTokenNumber - number of the command in the basic program
 */
EndStatement::EndStatement(int iTokenNumber) {
    miTokenNumber = iTokenNumber;
}

/**
 * Get Line Number.
 *
 * @return iLineNumber - the command line number of the statement
 */
int EndStatement::getTokenNumber() {
    return miTokenNumber;
}

/**
 * Execute.
 *
 * Terminate the running program.
 */
void EndStatement::execute() {
    exit(ERR_NO_ERR_OK);
}

/**
 * Content.
 *
 * Method for JUnit to return the content of the statement.
 *
 * @return - gives the name of the statement ("END")
 */
string EndStatement::content() {

    return "END";
}

