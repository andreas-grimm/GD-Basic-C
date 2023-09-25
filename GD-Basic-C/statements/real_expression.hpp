//
//  real_expression.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 05/09/2023.
//

#ifndef real_expression_hpp
#define real_expression_hpp

#include <stdio.h>
#include <string>

#include "../statements/expression.hpp"
#include "../variableTypes/real_value.hpp"

using namespace std;

class RealExpression: public Expression {
    
public:
    RealExpression(string strValue);
    
    string to_string();

    VariableType getType();
    string getTypeToString();
    
    RealValue* getRealValue();
    
    string content();
    Value* evaluate();
    
private:
    float mfValue;
};

#endif /* real_expression_hpp */
