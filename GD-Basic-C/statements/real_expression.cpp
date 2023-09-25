//
//  real_expression.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 05/09/2023.
//

#include "real_expression.hpp"

RealExpression::RealExpression(string strValue) {
    RealValue* poRealValue = new RealValue(strValue);
    mfValue = poRealValue->to_real();
}


string RealExpression::to_string() {
    RealValue* poRealValue = new RealValue(mfValue);
    return poRealValue->to_string();
}


VariableType RealExpression::getType() {
    return VariableType::REAL;
};


string RealExpression::getTypeToString() {
    return "RealExpression";
}

RealValue* RealExpression::getRealValue() {
    return new RealValue(mfValue);
}

Value* RealExpression::evaluate() {
    return getRealValue();
}
/**
 * This method is used in testing and debugging. It returns the set values when the constructor has been called.
 *
 * @return - readable string with the name and the value of the assignment
 */
string RealExpression::content() {
    return to_string();
}
