//
//  exp.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/09/2023.
//

#include "exp.hpp"
Exp::Exp() {
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
Value* Exp::execute(Value* poValue) {
    Logger* mpoLogger = Logger::getInstance();
    
    if (poValue->getType() == VariableType::REAL) {
        return new RealValue(exp(poValue->to_real()));
    }

    mpoLogger->error("Exp::execute", "Incorrect type");
    exit(ERR_INCORRECT_TYPE);
}
