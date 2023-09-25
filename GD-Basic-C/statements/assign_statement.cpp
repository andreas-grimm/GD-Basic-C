//
//  assign_statement.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 31/08/2023.
//

#include "assign_statement.hpp"

/**
 * Default constructor.
 *
 * @param iTokenNumber - number of the basic command line
 * @param strName - target of the assign statement
 * @param poExpression - value of the assignment statement
 */
AssignStatement::AssignStatement(int iTokenNumber, string strName, Expression* poExpression) {
    mstrKey = strName;
    mpoExpression = poExpression;
    miTokenNumber = iTokenNumber;
}

/**
 * Default constructor.
 *
 * @param strName - target of the assign statement
 * @param poExpression - value of the assignment statement
 */
AssignStatement::AssignStatement(string strName, Expression* poExpression) {
    mstrKey = strName;
    mpoExpression = poExpression;
    miTokenNumber = 0;
}

/**
 * Get Token Number.
 *
 * @return the command line number of the statement
 */
int AssignStatement::getTokenNumber() {
    return miTokenNumber;
}

/**
 * The assignment is defined as part of the default constructor. But only here the transaction is actually
 * executed. After the execution, the variable is assigned.
 *
 * @throws Exception - any excpetion coming from the memory management
 */
void AssignStatement::execute() {
    StringUtil oUtil;
    Normalizer oNormalizer;
    string strKey = mstrKey;

    // here the found word could be an array or a function... first determine the being and the end position of
    // the bracketed part...
    unsigned long ulIndexStart = strKey.find_first_of("(");
    unsigned long ulIndexEnd = strKey.find_first_of(")");

    if (ulIndexStart > 0 && ulIndexEnd > 0) {
        string strInner = strKey.substr(ulIndexStart + 1, ulIndexEnd);

        if (strInner.find_first_of(",")) {
            vector<string> vstrCommaSeperatedList = oUtil.split(strInner, ",");
            string strCommaSeperatedList;

            for (auto pstrExpression: vstrCommaSeperatedList) {
                string strValue = pstrExpression;
                if (mpoVariableManagement->mapContainsKey(strValue)) {
                    Expression* poExpression = new VariableExpression(strValue);
                    strValue = (poExpression->evaluate())->to_string();
                }

                strCommaSeperatedList += strValue + ",";
            }

            strKey = strKey.substr(0, ulIndexStart + 1)
            + strCommaSeperatedList.substr(0, strCommaSeperatedList.length() - 1);
                  //  + strKey.substr(ulIndexEnd - 1);

        } else {
            if (mpoVariableManagement->mapContainsKey(strInner)) {
                Expression* poExpression = new VariableExpression(strInner);

                strKey = strKey.substr(0, ulIndexStart + 1)
                        + (poExpression->evaluate())->to_string()
                        + strKey.substr(ulIndexEnd);

            }
        }

        strKey = oNormalizer.normalizeIndex(strKey);
    }

    mpoVariableManagement->putMap(strKey, mpoExpression->evaluate());
}

/**
 * This method is used in testing and debugging. It returns the set values when the constructor has been called.
 *
 * @return - readable string with the name and the value of the assignment
 */
string AssignStatement::content() {
    return "ASSIGN [" + mstrKey + ":= " + mpoExpression->content() + "]";
}
