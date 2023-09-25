//
//  real_value.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 28/08/2023.
//

#ifndef real_value_hpp
#define real_value_hpp

#include <stdio.h>
#include <string>
#include "../helper/error_codes.hpp"
#include "../helper/common.hpp"
#include "../variableTypes/value.hpp"
#include "../variableTypes/boolean_value.hpp"

using namespace std;

class RealValue: public Value {
    
public:
    RealValue();
    
    RealValue(bool bValue);
    RealValue(float fValue);
    RealValue(double dValue);
    RealValue(long lValue);
    RealValue(int iValue);
    RealValue(string strValue);
    
    VariableType getType();
    string getTypeToString();
    
    string to_string();
    bool to_bool();
    float to_real();
    int to_int();
    double to_double();
    long to_long();
    
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
    float mfValue;
    Logger* mpoLogger = Logger::getInstance();
};

#endif /* real_value_hpp */
