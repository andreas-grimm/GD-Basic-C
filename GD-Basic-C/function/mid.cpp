//
//  mid.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#include "mid.hpp"
Mid::Mid() {
}

/**
 * Functions implemented here are similar to Statements with the difference
 * that they actually return a result to the caller of type Value. The method execute
 * triggers the function.
 *
 * @param poValue input value
 * @param poStartPosition Starting position of the substring
 * @param poEndPosition Ending position of the substring
 * @return Value the return message of the function
 */
Value* Mid::execute(Value* poValue, Value* poStartPosition, Value* poEndPosition) {
    Logger* mpoLogger = Logger::getInstance();
    
    if ((poValue->getType() == VariableType::STRG) &&
        ((poStartPosition->getType() == VariableType::REAL) || (poStartPosition->getType() == VariableType::INT)) &&
        ((poEndPosition->getType() == VariableType::REAL) || (poEndPosition->getType() == VariableType::INT))) {
        
        int iStart = (int) poStartPosition->to_int();
        int iEnd = (int) poEndPosition->to_int();

        if ((iStart < 0) || (iEnd < 0) || (iStart > iEnd) || (iEnd > (poValue->to_string()).length())) {
            mpoLogger->error("Mid::execute", "Requested parameter does not fit the String");
            exit(ERR_STRING_TOO_SHORT);
        }

        return new StringValue(poValue->to_string().substr(poStartPosition->to_int(), poEndPosition->to_int()));
    }

    mpoLogger->error("Left::execute", "Input values do not match requirements: " + poValue->to_string() + " or second value is not integer: " + poStartPosition->to_string() + ", " + poEndPosition->to_string());
    exit(ERR_INCORRECT_TYPE);
}
