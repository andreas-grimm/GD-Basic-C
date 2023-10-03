//
//  str.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#include "str.hpp"
/**
 * Private Constructor.
 */
Str::Str() {
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
Value* Str::execute(Value* poValue) {
    Logger* mpoLogger = Logger::getInstance();
    
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::DOUBLE) ||
        (poValue->getType() == VariableType::LONG)) {
        return new StringValue(poValue->to_string());
    }

    mpoLogger->error("Str::execute", "Incorrect type");
    exit(ERR_INCORRECT_TYPE);
}
