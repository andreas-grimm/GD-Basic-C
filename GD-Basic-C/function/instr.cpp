//
//  instr.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/09/2023.
//

#include "instr.hpp"
/**
 * Private Constructor.
 */
Instr::Instr() {
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
Value* Instr::execute(Value* poValue, Value* poSearch) {
    Logger* mpoLogger = Logger::getInstance();
    
    if ((poValue->getType() == VariableType::STRG) &&
        (poSearch->getType() == VariableType::STRG)){
        if ((poValue->to_string().length() < 1) || (poSearch->to_string().length() < 1)) {
            mpoLogger->error("Instr::execute", "Input string or search string is empty");
            exit(ERR_STRING_EMPTY);
        } else {
            IntegerValue* poReturn = new IntegerValue((int)(poValue->to_string().find(poSearch->to_string())));
            return poReturn;
        }
    }

    mpoLogger->error("Instr::execute", "Incorrect type");
    exit(ERR_INCORRECT_TYPE);
}