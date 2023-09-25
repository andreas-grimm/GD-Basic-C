//
//  boolean_value.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 24/08/2023.
//

#include "boolean_value.hpp"

BooleanValue::BooleanValue() {
};


BooleanValue::BooleanValue(bool bValue) {
    mpoLogger->debug("BooleanValue::BooleanValue", "return: input: " + std::to_string(bValue));
    mbValue = bValue;
    mpoLogger->debug("BooleanValue::BooleanValue", "return: stored: " + std::to_string(mbValue));
};


/**
* Douple Type constructor.
*
* @param fValue Value to be stored in the container
*/
BooleanValue::BooleanValue(double fValue) {
    if (fValue == 0) {
        mbValue = false;
    } else {
        mbValue = true;
    }
}


/**
* Integer Type constructor.
*
* @param iValue Value to be stored in the container
*/
BooleanValue::BooleanValue(int iValue) {
    if (iValue == 0) {
        mbValue = false;
    } else {
        mbValue = true;
    }
}


/**
* String Type constructor.
*
* @param strValue Value to be stored in the container
*/
BooleanValue::BooleanValue(string strValue) {
    if (strcasecmp(strValue.c_str(), "TRUE") == 0) {
        mbValue = true;
    } else {
        mbValue = false;
    }
}


/**
* Override the standart toString method.
*
* @return the content of the variable as a string
*/
string BooleanValue::to_string() {
    if (mbValue == true) {
        mpoLogger->debug("BooleanValue::to_string", "return: true " + std::to_string(mbValue));
        return "True";
    }
    mpoLogger->debug("BooleanValue::to_string", "return: false " + std::to_string(mbValue));
    return "False";
}


/**
* To boolean.
*
* @return the content of the variable as a string
*/
bool BooleanValue::to_bool() {
    return mbValue;
}

/**
* Transform the content of the number value into a double.
*
* @return the content of the variable as a double
*/
float BooleanValue::to_real() {
     if (mbValue) {
         return YES;
     }
     return NO;
 }

/**
* Transform the content of the number value into an integer.
*
* @return the content of the variable as a double
*/
int BooleanValue::to_int() {
     if (mbValue) {
         return YES;
     }
     return NO;
 }

/**
* Transform the content of the number value into a double.
*
* @return the content of the variable as a double
*/
double BooleanValue::to_double() {
     if (mbValue) {
         return YES;
     }
     return NO;
 }


/**
* Transform the content of the number value into a long.
*
* @return the content of the variable as a long
*/
long BooleanValue::to_long() {
     if (mbValue) {
         return YES;
     }
     return NO;
 }

/**
* Return the value field as an object.
*
* @return the number value as an object
*/
Value* BooleanValue::evaluate() {
    return this;
}

/**
* Return the value field as an object.
*
* @return the number value as an object
*/
bool BooleanValue::isTrue() {
    mpoLogger->debug("BooleanValue::isTrue", "return: " + std::to_string(mbValue));
    return mbValue;
}


Value* BooleanValue::equals(Value* poValue) {
    mpoLogger->debug("BooleanValue::equals", "gets called ");
    if (getType() == poValue->getType()) {
        if (to_real() == poValue->to_real()) {
            return new BooleanValue(true);
        }
        return new BooleanValue(false);
    }
    
    mpoLogger->error("BooleanValue::equals", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::notEqual(Value* poValue) {
    mpoLogger->debug("BooleanValue::notEquals", "gets called ");
    if (getType() == poValue->getType()) {
        if (to_real() != poValue->to_real()) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("BooleanValue::notEqual", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::plus(Value* poValue) {
    if (getType() == poValue->getType()) {

        // A + A = A
        if (poValue->to_bool() == mbValue) {
            return new BooleanValue(true);
        }

        // A + (non A) = 1
        if (poValue->to_bool() != mbValue) {
            return new BooleanValue(true);
        }

        // A + 1 = 1
        if (poValue->to_bool() == true) {
            return new BooleanValue(true);
        } else {
        // A + 0 = A
            return new BooleanValue(mbValue);
        }
    }

    mpoLogger->error("BooleanValue::plus", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::minus(Value* poValue) {
    mpoLogger->error("BooleanValue::minus", " '-' for boolean expression is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::multiply(Value* poValue) {
    if (getType() == poValue->getType()) {
        // 0 * A = 0
        if (mbValue == false) {
            return new BooleanValue(false);
        }

        // 1 * A = A
        if (mbValue) {
            return new BooleanValue(true);
        }

        // A * A = A: covered above
        // A * (non A) = 0 : covered above
    }

    mpoLogger->error("BooleanValue::multiply", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::divide(Value* poValue) {
    mpoLogger->error("BooleanValue::divide", " '/' for boolean expression is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::modulo(Value* poValue) {
    mpoLogger->error("BooleanValue::modulo", " '%' for boolean expression is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::shiftLeft(Value* poValue) {
    mpoLogger->error("BooleanValue::shiftLeft", " '<<' for boolean expression is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::shiftRight(Value* oValue) {
    mpoLogger->error("BooleanValue::shiftRight", " '>>' for boolean expression is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::land(Value* poValue) {
    if (getType() == poValue->getType()) {

        if ((mbValue && poValue->to_bool()) == true) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("BooleanValue::and", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::lor(Value* poValue) {
    if (getType() == poValue->getType()) {

        if ((mbValue || poValue->to_bool()) == true) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("BooleanValue::or", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}

// This one implemented the XOR statement
Value* BooleanValue::power(Value* poValue) {
    if (getType() == poValue->getType()) {
        bool bWorkValue = poValue->to_bool();

        if (mbValue == bWorkValue) {
            return new BooleanValue(false);
        } else {
            return new BooleanValue(true);
        }
    }

    mpoLogger->error("BooleanValue::power", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::smallerThan(Value* poValue) {
    mpoLogger->error("BooleanValue::smallerThan", " '<' for boolean expression is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::smallerEqualThan(Value* poValue) {
    mpoLogger->error("BooleanValue::smallerEqualThan", " '=<' for boolean expression is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::largerThan(Value* poValue) {
    mpoLogger->error("BooleanValue::largerThan", " '>' for boolean expression is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* BooleanValue::largerEqualThan(Value* poValue) {
    mpoLogger->error("BooleanValue::largerEqualThan", " '>=' for boolean expression is not defined");
    exit(ERR_SYNTAX_ERROR);
 }

/**
* Structure.
*
* Method for the compiler to get the structure of the program.
*
* @return gives the name of the statement ("INPUT") and a list of the parameters
* @throws Exception based on errors in the implementation classes
*/
/*
 public String structure() throws Exception {
     String strReturn = this.toString();
     return strReturn;
 }

 */


VariableType BooleanValue::getType() {
    return VariableType::BOOL;
};


string BooleanValue::getTypeToString() {
    return "BooleanValue";
}
