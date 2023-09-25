//
//  abs.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 25/09/2023.
//

#include "abs.hpp"

Abs::Abs() {
}

/**
 * Functions implemented here are similar to Statements with the difference
 * that they actually return a result to the caller of type Value. The method execute
 * triggers the function.
 *
 * @param poValue input value
 * @return Value the return message of the function
 */
Value* Abs::execute(Value* poValue) {
    Logger* mpoLogger = Logger::getInstance();

    if (poValue->getType() == VariableType::INT) {
        if (poValue->to_int() < 0) {
            return poValue->multiply(new IntegerValue(-1));
        } else {
            return poValue;
        }
    } else if (poValue->getType() == VariableType::LONG) {
        if (poValue->to_long() < 0) {
            return poValue->multiply(new LongValue(-1));
        } else {
            return poValue;
        }
    } else if (poValue->getType() == VariableType::REAL) {
        if (poValue->to_real() < 0) {
            return poValue->multiply(new RealValue(-1));
        } else {
            return poValue;
        }
    } else if (poValue->getType() == VariableType::DOUBLE) {
        if (poValue->to_double() < 0) {
            return poValue->multiply(new DoubleValue(-1));
        } else {
            return poValue;
        }
    }
    
    mpoLogger->error("Abs::execute", "Input value not numeric: " + poValue->to_string());
    exit(ERR_UNEXPECTED_TYPE);
}

