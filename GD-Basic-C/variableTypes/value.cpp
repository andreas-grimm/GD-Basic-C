//
//  value.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 24/08/2023.
//

#include "value.hpp"

Value::Value() {
}

VariableType Value::getType() {
    return VariableType::UNDEFINED;
};

/**
 * Value types override this to convert themselves to a string representation.
 *
 * @return the value as a string
 */
string Value::to_string() {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Value types override this to convert themselves to a numeric representation.
 *
 * @return the value as a float
 */
float Value::to_real() {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Value types override this to convert themselves to a numeric representation.
 *
 * @return the value as a bool
 */
bool Value::to_bool() {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Value types override this to convert themselves to a numeric representation.
 *
 * @return the value as a double
 */
int Value::to_int() {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Value types override this to convert themselves to a numeric representation.
 *
 * @return the value as a double
 */
double Value::to_double() {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Value types override this to convert themselves to a numeric representation.
 *
 * @return the value as a long
 */
long Value::to_long(){
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Compares of one value object with another one. Returns true if equal.
 *
 * @param poValue second value for the comparison
 * @return BooleanValue(true) if the objects are equal (not identical), BooleanValue(false) otherwise
 */
Value* Value::equals(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
}

/**
 * Compares of one value object with another one. Returns true if not equal.
 *
 * @param poValue second value for the comparison
 * @return BooleanValue(true) if the objects are equal (not identical), BooleanValue(false) otherwise
 */
Value* Value::notEqual(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Addition of one value object with another one.
 *
 * @param poValue second value for the calculation
 * @return the result of the addition
 */
Value* Value::plus(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Substraction of one value object with another one.
 *
 * @param poValue subtractor for the calculation
 * @return the result of the substraction
 */
Value* Value::minus(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Multiplication of one value object with another one.
 *
 * @param poValue second factor for the calculation
 * @return the result of the multiplication
 */
Value* Value::multiply(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Division of one value object with another one.
 *
 * @param poValue divisor for the calculation
 * @return the result of the division
 * @throws DivideByZeroException thrown for a division by zero
 */
Value* Value::divide(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Remainder of an integer division.
 *
 * @param poValue divisor for the calculation
 * @return the result of the division
 */
Value* Value::modulo(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Multiplication of one value object by 2, parameter times.
 *
 * @param poValue second factor for the calculation
 * @return the result of the multiplication
 */
Value* Value::shiftLeft(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Execution of the logical AND function.
 *
 * @param poValue second statement to compare
 * @return the result of the function
 */
Value* Value::land(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Execution of the logical OR function.
 *
 * @param poValue second statement to compare
 * @return the result of the function
 */
Value* Value::lor(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Division of one value object by 2, parameter times.
 *
 * @param poValue divisor for the calculation
 * @return the result of the division
 */
Value* Value::shiftRight(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * Calcualte the power of one value object with another one.
 *
 * @param poValue divisor for the calculation
 * @return the result of the divition
 */
Value* Value::power(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * smallerThan compares one value object with another one.
 *
 * @param poValue comparison value for function
 * @return BooleanValue(true) if this object is smaller (not equal), BooleanValue(false) otherwise
 */
Value* Value::smallerThan(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * smallerEqualThan compares one value object with another one.
 *
 * @param poValue comparison value for function
 * @return BooleanValue(true) if this object is smaller (not equal), BooleanValue(false) otherwise
 */
Value* Value::smallerEqualThan(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * largerThan of one value object with another one.
 *
 * @param poValue comparison value for function
 * @return BooleanValue(true) if this object is larger (not equal), BooleanValue(false) otherwise
 */
Value* Value::largerThan(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * largerEqualThan of one value object with another one.
 *
 * @param poValue comparison value for function
 * @return BooleanValue(true) if this object is larger (not equal), BooleanValue(false) otherwise
 */
Value* Value::largerEqualThan(Value* poValue) {
    exit(ERR_UNDEFINED_VALUE);
};

/**
 * getType returns the type of the instantiated object of the class family value.
 *
 * @return "unknown" to block use of a function against the superclass
 */
string Value::getTypeToString() {
    return "unknown";
}
