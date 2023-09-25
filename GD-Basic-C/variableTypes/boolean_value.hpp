//
//  boolean_value.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 24/08/2023.
//

#ifndef boolean_value_hpp
#define boolean_value_hpp

#include <stdio.h>
#include <string>
#include "../helper/error_codes.hpp"
#include "../helper/common.hpp"
#include "../variableTypes/value.hpp"

using namespace std;

class BooleanValue: public Value {

public:
    BooleanValue();
    
    BooleanValue(bool bValue);
    BooleanValue(double fValue);
    BooleanValue(int iValue);
    BooleanValue(string strValue);

    VariableType getType();
    string getTypeToString();

    string to_string();
    bool to_bool();
    float to_real();
    int to_int();
    double to_double();
    long to_long();

    bool isTrue(); // replace with to_bool

    Value* evaluate();
    
    Value* equals(Value* poValue);
    Value* notEqual(Value* poValue);
    Value* plus(Value* poValue);
    Value* minus(Value* poValue);
    Value* multiply(Value* poValue);
    Value* divide(Value* poValue);
    Value* modulo(Value* poValue);
    Value* shiftLeft(Value* poValue);
    Value* land(Value* poValue);
    Value* lor(Value* poValue);
    Value* shiftRight(Value* poValue);
    Value* power(Value* poValue);
    Value* smallerThan(Value* poValue);
    Value* smallerEqualThan(Value* poValue);
    Value* largerThan(Value* poValue);
    Value* largerEqualThan(Value* poValue);
    
private:
    bool mbValue;
    Logger* mpoLogger = Logger::getInstance();

};


#endif /* boolean_value_hpp */
