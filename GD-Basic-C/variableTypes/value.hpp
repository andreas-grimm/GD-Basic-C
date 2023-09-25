//
//  value.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 24/08/2023.
//

#ifndef value_hpp
#define value_hpp

#include <stdio.h>
#include <string>
#include "../helper/error_codes.hpp"
#include "../variableTypes/variable_types.hpp"
#include "../helper/logger.hpp"

using namespace std;

class Value {

public:
    Value();
    
    virtual VariableType getType() = 0;
    virtual string getTypeToString() = 0;
    
    virtual string to_string() = 0;
    virtual float to_real() = 0;
    virtual bool to_bool() = 0;
    virtual int to_int() = 0;
    virtual double to_double() = 0;
    virtual long to_long() = 0;

    virtual Value* equals(Value* poValue) = 0;
    virtual Value* notEqual(Value* poValue) = 0;
    virtual Value* plus(Value* poValue) = 0;
    virtual Value* minus(Value* poValue) = 0;
    virtual Value* multiply(Value* poValue) = 0;
    virtual Value* divide(Value* poValue) = 0;
    virtual Value* modulo(Value* poValue) = 0;
    virtual Value* shiftLeft(Value* poValue) = 0;
    virtual Value* land(Value* poValue) = 0;
    virtual Value* lor(Value* poValue) = 0;
    virtual Value* shiftRight(Value* poValue) = 0;
    virtual Value* power(Value* poValue) = 0;
    virtual Value* smallerThan(Value* poValue) = 0;
    virtual Value* smallerEqualThan(Value* poValue) = 0;
    virtual Value* largerThan(Value* poValue) = 0;
    virtual Value* largerEqualThan(Value* poValue) = 0;

};

#endif /* value_hpp */
