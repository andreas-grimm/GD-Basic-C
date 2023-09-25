//
//  operator_expression.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 12/09/2023.
//

#ifndef operator_expression_hpp
#define operator_expression_hpp

#include <stdio.h>
#include <string>
#include <typeinfo>

#include "../helper/logger.hpp"
#include "../statements/expression.hpp"
#include "../variableTypes/value.hpp"
#include "../tokenizer/basic_token_type.hpp"
#include "../tokenizer/basic_token_type_util.hpp"

class OperatorExpression: public Expression {

public:
    OperatorExpression(Expression* poLeft, string strOperator, Expression* poRight);
    OperatorExpression(Expression* poLeft, BasicTokenType eOperator, Expression* poRight);
    
    Value* evaluate();
    Expression* getLeft();
    string getOperator();
    Expression* getRight();
    string content();
    
private:
    Logger* mpoLogger;
    Expression* mpoLeft;
    string mstrOperator;
    BasicTokenType meOperator;
    Expression* mpoRight;
};


#endif /* operator_expression_hpp */
