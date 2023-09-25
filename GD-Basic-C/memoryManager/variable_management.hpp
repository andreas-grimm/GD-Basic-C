//
//  variable_management.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 31/08/2023.
//

#ifndef variable_management_hpp
#define variable_management_hpp

#include <stdio.h>
#include <string>
#include <map>

#include "../helper/logger.hpp"
#include "../variableTypes/value.hpp"
#include "../variableTypes/boolean_value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/long_value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../variableTypes/double_value.hpp"
#include "../variableTypes/string_value.hpp"
#include "../tokenizer/normalizer.hpp"

class VariableManagement {

public:
    static VariableManagement* getInstance();
    
    void putMap(string strKey, Value* oValue);
    void putMap(string strKey, float fValue);
    void putMap(string strKey, double dValue);
    void putMap(string strKey, long lValue);
    void putMap(string strKey, string strValue);
    void putMap(string strKey, int iValue);
    
    Value* getMap(string strKey);

    bool mapContainsKey(string strKey);
    
private:
    Logger* mpoLogger = Logger::getInstance();
    
    static VariableManagement* mpoVariableManagementInstance;
    
    VariableManagement();
    VariableManagement(const VariableManagement&);
    VariableManagement& operator=(const VariableManagement&);

    map<string, Value*> mmstroUntyped;
    map<string, BooleanValue*> mmstroBooleans;
    map<string, IntegerValue*> mmstroIntegers;
    map<string, LongValue*> mmstroLongs;
    map<string, RealValue*> mmstroReals;
    map<string, DoubleValue*> mmstroDoubles;
    map<string, StringValue*> mmstroStrings;
};

#endif /* variable_management_hpp */
