//
//  atn.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 27/09/2023.
//

#include "atn.hpp"

Atn::Atn() {
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
Value* Atn::execute(Value* poValue) {
    Logger* mpoLogger = Logger::getInstance();
    
    if (poValue->getType() == VariableType::REAL) {
        return new RealValue(atan(poValue->to_real()));
    }

    mpoLogger->error("Atn::execute", "Incorrect type");
    exit(ERR_INCORRECT_TYPE);
}
