//
//  val.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#include "val.hpp"

/**
 * Private Constructor.
 */
Val::Val() {
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
Value* Val::execute(Value* poValue) {
    Logger* mpoLogger = Logger::getInstance();
    
    if (poValue->getType() == VariableType::STRG) {
        return new RealValue(stof(poValue->to_string()));
    }

    mpoLogger->error("Val::execute", "Incorrect type");
    exit(ERR_INCORRECT_TYPE);
}
