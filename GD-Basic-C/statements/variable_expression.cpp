//
//  variable_expression.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 31/08/2023.
//

#include "variable_expression.hpp"

/**
 * Default constructor.
 *
 * @param strName name of the variable.
 */
VariableExpression::VariableExpression(string strName) {
    mstrName = strName;
}

/**
 * Return the content of the variable in the Memory Management component.
 *
 * @return returns the value of the variable - or if the variable does not exists - returns a 0 as a numerical value
 * @throws Exception for any errors occuring in the execution of the evaluation. Currently this happens if
 * the index in an array subscription is larger than the array.
 */
Value* VariableExpression::evaluate() {
    VariableManagement* poVariableManager = VariableManagement::getInstance();
    Normalizer oNormalizer;
    
    string strKey = mstrName;

    unsigned long ulIndexStart = strKey.find_first_of("(");
    unsigned long ulIndexEnd = strKey.find_first_of(")");

    if (ulIndexStart > 0 && ulIndexEnd > 0) {
        string strInner = strKey.substr(ulIndexStart + 1, ulIndexEnd);

        if (strInner.find_last_of(",") > 0) {
            vector<string> vstrCommaSeperatedList = StringUtil::split(strInner,",");
            string strCommaSeperatedList;

            for (auto strExpression: vstrCommaSeperatedList) {
                string strValue = strExpression;
                if (poVariableManager->mapContainsKey(strExpression)) {
                    Expression* poExpression = new VariableExpression(strExpression);

                    strValue = (poExpression->evaluate())->to_string();
                }

                strCommaSeperatedList += strValue + ",";
            }
            
            string strOrigKey = strKey;
            
            strKey = strOrigKey.substr(0, ulIndexStart + 1);
            strKey += strCommaSeperatedList.substr(0, strCommaSeperatedList.length() - 1);
            if (ulIndexEnd < strKey.length()) {
                strKey += strOrigKey.substr(ulIndexEnd);
            }
        } else {
            if (poVariableManager->mapContainsKey(strInner)) {
                Expression* poExpression = new VariableExpression(strInner);

                strKey = strKey.substr(0, ulIndexStart + 1)
                        + (poExpression->evaluate())->to_string()
                        + strKey.substr(ulIndexEnd);

            }
        }

        strKey = oNormalizer.normalizeIndex(strKey);
    }

    if (poVariableManager->mapContainsKey(strKey)) {
        return poVariableManager->getMap(strKey);
    }

    poLogger->error("VariableExpression::evaluate()","Unknown variable <" + strKey + ">");
    exit(ERR_UNDEFINED_VARIABLE);
}

/**
 * Get the name of the variable.
 *
 * @return name of the vaiable as a string.
 */
string VariableExpression::getName() {
    return mstrName;
}

/**
 * This method is used in testing and debugging. It returns the set values when the constructor has been called.
 *
 * @return - readable string with the name and the value of the assignment
 */
string VariableExpression::content() {
    return getName();
}
