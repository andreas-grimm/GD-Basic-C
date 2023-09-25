//
//  data_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 28/08/2023.
//

#include "data_statement.hpp"

/**
 * Default constructor.
 *
 * An "DATA" statement prepares and loads the FiFo Queue.
 * @param iTokenNumber - number of the command in the basic program
 * @param vpoValues - List of all Values to be pushed into the queue
 */
DataStatement::DataStatement(int iTokenNumber, vector<Value*> vpoValues) {

    miTokenNumber = iTokenNumber;
    mvpoValues = vpoValues;
}

/**
 * Get Token Number.
 *
 * @return the command line number of the statement
 */
int DataStatement::getTokenNumber() {
    return miTokenNumber;
}

/**
 * Execute.
 *
 * Push the array into the FIFO structure.
 */
//TODO: In Connection with the Java code: This makes no sense as the Queue is forgotten as soon as the execute() is done
void DataStatement::execute() {
    FiFoQueue oQueue;

    for (auto oValue: mvpoValues) {
        oQueue.push(oValue);
    }
}

/**
 * Content.
 *
 * Method for JUnit to return the content of the statement.
 *
 * @return - gives the name of the statement ("END")
 */
string DataStatement::content() {
    string strValue;

    for (auto oValue: mvpoValues) {
        strValue += " <" + oValue->to_string() + ">";
    }

    return "DATA" + strValue;
}
