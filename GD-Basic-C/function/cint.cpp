//
//  cint.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/09/2023.
//

#include "cint.hpp"
/**
 * Private Constructor.
 */
Cint::Cint() {
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
Value* Cint::execute(Value* poValue) {
    Logger* mpoLogger = Logger::getInstance();
    
    if (poValue->getType() == VariableType::INT) {
        return poValue;
    } else
        if (poValue->getType() == VariableType::LONG) {
            return new IntegerValue(poValue->to_int());
        } else
            if (poValue->getType() == VariableType::REAL) {
                return new IntegerValue(poValue->to_int());
            }

    mpoLogger->error("Cint::execute", "Incorrect type");
    exit(ERR_INCORRECT_TYPE);
}
