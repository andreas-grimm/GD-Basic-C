//
//  operator_expression.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 12/09/2023.
//

#include "operator_expression.hpp"

OperatorExpression::OperatorExpression(Expression* poLeft, string strOperator, Expression* poRight) {
    mpoLogger = Logger::getInstance();

    mpoLogger->debug("OperatorExpression::OperatorExpression","");
    mpoLeft = poLeft;
    mstrOperator = strOperator;
    meOperator = BasicTokenType::NUL;
    mpoRight = poRight;
}

/**
 * Default constructor.
 *
 * @param poLeft left part of the operation
 * @param eOperator the actual operator - defined as a BasicTokenType
 * @param poRight right side of the operation
 */
OperatorExpression::OperatorExpression(Expression* poLeft, BasicTokenType eOperator, Expression* poRight) {
    mpoLogger = Logger::getInstance();
    
    mpoLogger->debug("OperatorExpression::OperatorExpression"," created:" + poLeft->content());
    mpoLeft = poLeft;
    mstrOperator = STRG_NULL;
    meOperator = eOperator;
    mpoRight = poRight;
}

/**
 * Return the content of the result of the operation as a value variable.
 *
 * @throws Exception syntax error is the operator cannot be executed
 * @return returns the result of the operation.
 */
Value* OperatorExpression::evaluate() {
    Value* poLeftValue = mpoLeft->evaluate();
    Value* poRightValue = mpoRight->evaluate();
    mpoLogger->debug("OperatorExpression::evaluate"," LeftValue:" + poLeftValue->to_string() + ", RightValue: " + poRightValue->to_string());

    switch (meOperator) {
        case BasicTokenType::PLUS: {
            return poLeftValue->plus(poRightValue);
        }
        case MINUS: {
            return poLeftValue->minus(poRightValue);
        }
        case MULTIPLY: {
            return poLeftValue->multiply(poRightValue);
        }
        case DIVIDE: {
            return poLeftValue->divide(poRightValue);
        }
        case POWER: {
            return poLeftValue->power(poRightValue);
        }
        case AND: {
            return poLeftValue->land(poRightValue);
        }
        case OR: {
            return poLeftValue->lor(poRightValue);
        }
        case COMPARE_EQUAL: {
            return poLeftValue->equals(poRightValue);
        }
        case COMPARE_NOT_EQUAL: {
            return poLeftValue->notEqual(poRightValue);
        }
        case SMALLER: {
            return poLeftValue->smallerThan(poRightValue);
        }
        case SMALLER_EQUAL: {
            return poLeftValue->smallerEqualThan(poRightValue);
        }
        case GREATER: {
            return poLeftValue->largerThan(poRightValue);
        }
        case GREATER_EQUAL: {
            return poLeftValue->largerEqualThan(poRightValue);
        }
        case MODULO: {
            return poLeftValue->modulo(poRightValue);
        }
        case SHIFT_RIGHT: {
            return poLeftValue->shiftRight(poRightValue);
        }
        case SHIFT_LEFT: {
            return poLeftValue->shiftLeft(poRightValue);
        }
        default: {
            mpoLogger->error("OperatorExpression::evaluate", "Unknown operator: " + mstrOperator);
            exit(ERR_UNKNOWN_OPERATOR);
        };
    }
}

/**
 * get the left side of the operation.
 *
 * @return the left side of the operation as an expression
 */
Expression* OperatorExpression::getLeft() {
    return mpoLeft;
}

/**
 * get the operator of the operation.
 *
 * @return - the operator as a string
 */
string OperatorExpression::getOperator() {
    return mstrOperator;
}

/**
 * get the right side of the operation.
 *
 * @return the right side of the operation as an expression
 */
Expression* OperatorExpression::getRight() {
    return mpoRight;
}

/**
 * This method is used in testing and debugging. It returns the set values when the constructor has been called.
 *
 * @return - readable string with the name and the value of the assignment
 */
string OperatorExpression::content() {
    return mpoLeft->content() + " " + BasicTokenTypeUtilities::to_string(meOperator) + " " +mpoRight->content();
}

