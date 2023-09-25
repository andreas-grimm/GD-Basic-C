//
//  string_expressions.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 30/08/2023.
//

#ifndef string_expressions_hpp
#define string_expressions_hpp

#include <stdio.h>
#include <string>

#include "../statements/expression.hpp"
#include "../variableTypes/string_value.hpp"

using namespace std;

class StringExpression: public Expression {
    
public:
    StringExpression(string strValue);
    
    string to_string();

    VariableType getType();
    string getTypeToString();
    
    StringValue* getStringValue();
    
    string content();
    Value* evaluate();

private:
    string mstrValue;
};

#endif /* string_expressions_hpp */
