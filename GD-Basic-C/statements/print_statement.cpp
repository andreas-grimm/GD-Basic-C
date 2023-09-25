//
//  print_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 30/08/2023.
//

#include "print_statement.hpp"

/**
 * Default constructor.
 *
 * Receive the statement that is targeted to be printed.
 *
 * @param poExpression - input to the print statement
 */
PrintStatement::PrintStatement(Expression* poExpression) {
    miTokenNumber = 0;
    mpoExpression = poExpression;
    mvpoExpression.clear();
    mbCRLF = true;
}


/**
 * Default constructor.
 *
 * Receive the statement that is targeted to be printed.
 *
 * @param iTokenNumber  - number of the token in the BASIC program
 * @param vpoExpression - list of inputs to the print statement
 * @param bCRLF - if true, the line to be printed ends with a CR
 */
PrintStatement::PrintStatement(int iTokenNumber, vector<Expression*> vpoExpression, bool bCRLF) {
    miTokenNumber = iTokenNumber;
    mpoExpression = NULL;
    mvpoExpression = vpoExpression;
    mbCRLF = bCRLF;
}


/**
 * Get Line Number.
 *
 * @return iLineNumber - the command line number of the statement
 */
int PrintStatement::getTokenNumber() {
    return miTokenNumber;
}

/**
 * Execute the transaction.
 *
 * @throws Exception any execution error found throws an exception
 */
void PrintStatement::execute() {
    // the simple output of the expression is only used for the JASIC version
    if (mpoExpression != NULL) {
        cout << (mpoExpression->evaluate())->to_string();
    }

    // this more complex version is used by the BASIC version
    if (!mvpoExpression.empty()) {
        for (auto poExpression : mvpoExpression) {
            string strOutput = (poExpression->evaluate()->to_string());
            cout << strOutput;
        }

        if (mbCRLF) {
            cout << "\n";
        }
    }
}


/**
 * This method is used in testing and debugging. It returns the set values when the constructor has been called.
 *
 * @return - readable string with the name and the value of the assignment
 */
string PrintStatement::content() {
    if (!mvpoExpression.empty()) {
        string strContent;

        for (auto poExpression : mvpoExpression) {
            strContent += "<" + poExpression->content() + ">";
        }

        return "PRINT (" + strContent + ")";
    }

    if (mpoExpression != NULL) {
        return "PRINT (" + mpoExpression->content() + ")";
    }

    return "PRINT ()";
}
