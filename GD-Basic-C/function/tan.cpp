//
//  tan.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#include "tan.hpp"

Tan::Tan() {
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
Value* Tan::execute(Value* poValue) {
    Logger* mpoLogger = Logger::getInstance();
    
    if (poValue->getType() == VariableType::REAL) {
        return new RealValue(tan(poValue->to_real()));
    }

    mpoLogger->error("Tan::execute", "Incorrect type");
    exit(ERR_INCORRECT_TYPE);
}
