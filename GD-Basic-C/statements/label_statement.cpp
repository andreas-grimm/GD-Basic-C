//
//  label_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/08/2023.
//

#include "label_statement.hpp"

LabelStatement::LabelStatement() {
}

/**
 * add a label destination in the memory management.
 *
 * @param strLabel - name of the label
 * @param iStatementNumber - statement number
 */
void LabelStatement::putLabelStatement(string strLabel, int iStatementNumber) {

    mmstriLabels[strLabel] = iStatementNumber;
}


/**
 * get the statement number of the label statement searched.
 *
 * @param strLabel - label name
 * @return - statement number
 */
int LabelStatement::getLabelStatement(string strLabel) {
    return mmstriLabels[strLabel];
}

/**
 * verify that the Label is stored.
 *
 * @param strKey - Label name
 * @return - true if label is in the memory management
 */
bool LabelStatement::containsLabelKey(string strKey) {

    if (mmstriLabels.size() >= 1) {
        if (mmstriLabels.count(strKey)) {
            return true;
        }
    }
    return false;
}

/**
 * Get Token Number - get the number of the corresponding token to this statement.
 *
 * @return the command line number of the statement
 */
int LabelStatement::getTokenNumber() {
    return 0;
}

/**
 * Statements implement this to actually perform whatever behavior the
 * statement causes. "print" statements will display text here, "goto"
 * statements will change the current statement, etc.
 *
 * @throws Exception as any execution error found during execution
 */
void LabelStatement::execute() {
}

/**
 * Content.
 *
 * Method for JUnit to return the content of the statement.
 *
 * @return gives the name of the statement ("INPUT") and the variable name
 * @throws Exception based on errors in the implementation classes
 */
string LabelStatement::content() {
    return "";
}
