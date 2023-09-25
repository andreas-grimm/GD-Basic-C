//
//  variable_expression.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 31/08/2023.
//

#ifndef variable_expression_hpp
#define variable_expression_hpp

#include <stdio.h>
#include <string.h>

#include "../variableTypes/value.hpp"
#include "../statements/expression.hpp"
#include "../memoryManager/variable_management.hpp"
#include "../tokenizer/normalizer.hpp"
#include "../helper/string_util.hpp"
#include "../helper/logger.hpp"

class VariableExpression: public Expression {
public:
    VariableExpression(string strName);

    Value* evaluate();
    
    string getName();
    string content();
    
private:
    string mstrName;
    Logger* poLogger = Logger::getInstance();
    
};

#endif /* variable_expression_hpp */
