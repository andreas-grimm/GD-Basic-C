//
//  colon_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/09/2023.
//

#include "colon_statement.hpp"

/**
 * Default constructor.
 *
 * An "DIM" statement initializes an array of any type.
 * @param iTokenNumber - number of the command in the basic program
 */
ColonStatement::ColonStatement(int iTokenNumber) {
    miTokenNumber = iTokenNumber;
}

/**
 * Get Token Number.
 *
 * @return the command line number of the statement
 */
int ColonStatement::getTokenNumber() {
    return miTokenNumber;
}

/**
 * Execute.
 *
 * Terminate the running program.
 */
void ColonStatement::execute() {
}

/**
 * Content.
 *
 * Method for JUnit to return the content of the statement.
 *
 * @return - gives the name of the statement ("END")
 */
string ColonStatement::content() {
    return "COLON";
}

