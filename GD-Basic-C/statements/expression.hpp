//
//  expression.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 30/08/2023.
//

#ifndef expression_hpp
#define expression_hpp

#include <stdio.h>
#include <string>
#include "../variableTypes/value.hpp"
#include "../helper/error_codes.hpp"
#include "../helper/logger.hpp"

using namespace std;

/**
 * Base interface for an expression. An expression is like a statement
 * except that it also returns a value when executed. Expressions do not
 * appear at the top level in Jasic programs, but are used in many
 * statements. For example, the value printed by a "print" statement is an
 * expression. Unlike statements, expressions can nest.
 */

class Expression {
    
public:
    virtual Value* evaluate() = 0;
    virtual string content() = 0;

private:
    Logger* mpoLogger = Logger::getInstance();

};

#endif /* expression_hpp */
