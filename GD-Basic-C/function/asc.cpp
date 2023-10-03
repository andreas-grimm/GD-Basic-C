//
//  asc.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 27/09/2023.
//

#include "asc.hpp"

Asc::Asc() {
}

/**
 * Functions implemented here are similar to Statements with the difference
 * that they actually return a result to the caller of type Value. The method execute
 * triggers the function.
 *
 * @param poValue input value
 * @return Value the return message of the function
 * @throws Exception as any execution error found during execution
 */
Value* Asc::execute(Value* poValue) {
    Logger* mpoLogger = Logger::getInstance();
    
    if (poValue->getType() == VariableType::STRG) {
        if (poValue->to_string().length() > 0) {
            return new IntegerValue(int(poValue->to_string()[0]));
        } else {
            mpoLogger->error("Asc::execute", "Input value empty");
            exit(ERR_STRING_EMPTY);
        }
    }
    mpoLogger->error("Asc::execute", "Incorrect type");
    exit(ERR_INCORRECT_TYPE);
}
