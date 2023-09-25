//
//  string_expressions.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 30/08/2023.
//

#include "string_expressions.hpp"

StringExpression::StringExpression(string strValue) {
    mstrValue = strValue;
}


string StringExpression::to_string() {
    return mstrValue;
}


VariableType StringExpression::getType() {
    return VariableType::STRG;
};


string StringExpression::getTypeToString() {
    return "StringExpression";
}

StringValue* StringExpression::getStringValue() {
    return new StringValue(mstrValue);
}

Value* StringExpression::evaluate() {
    return getStringValue();
}

/**
 * This method is used in testing and debugging. It returns the set values when the constructor has been called.
 *
 * @return - readable string with the name and the value of the assignment
 */
string StringExpression::content() {
    return to_string();
}

