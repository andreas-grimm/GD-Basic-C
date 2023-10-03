//
//  left.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#include "left.hpp"
/**
 * Private Constructor.
 */
Left::Left() {
}

/**
 * Functions implemented here are similar to Statements with the difference
 * that they actually return a result to the caller of type Value. The method execute
 * triggers the function.
 *
 * @param poValue input string value
 * @param poLength length of the expected substring
 * @return Value the return message of the function
 */
Value* Left::execute(Value* poValue, Value* poLength) {
    Logger* mpoLogger = Logger::getInstance();
    
    if ((poValue->getType() == VariableType::STRG) &&
        ((poLength->getType() == VariableType::REAL) ||
         (poLength->getType() == VariableType::INT))) {
        
        int iLength = (int) poLength->to_int();

        if (iLength >= (Len::execute(poValue))->to_int()) {
            mpoLogger->error("Left::execute", "Length exceeds size of String");
            exit(ERR_STRING_TOO_SHORT);
        }

        return new StringValue(poValue->to_string().substr(0, iLength));
    }

    mpoLogger->error("Left::execute", "First Input value not String: " + poValue->to_string() + " or second value is not integer: " + poLength->to_string());
    exit(ERR_INCORRECT_TYPE);
}
