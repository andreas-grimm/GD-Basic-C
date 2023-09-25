//
//  integer_value.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 27/08/2023.
//

#include "integer_value.hpp"

IntegerValue::IntegerValue() {
    mpoLogger = Logger::getInstance();
}


IntegerValue::IntegerValue(int iValue) {
    miValue = iValue;
}

IntegerValue::IntegerValue(float fValue) {
    if ((fValue >= INT_MAX) || (fValue <= INT_MIN)) {
        mpoLogger->error("IntegerValue", "Overflow error: " + std::to_string(fValue));
        exit(ERR_NUMBER_OVERFLOW);
    }
    
    miValue = fValue;
}

IntegerValue::IntegerValue(double dValue) {
    if ((dValue >= INT_MAX) || (dValue <= INT_MIN)) {
        mpoLogger->error("IntegerValue", "Overflow error: " + std::to_string(dValue));
        exit(ERR_NUMBER_OVERFLOW);
    }
    
    miValue = dValue;
}

IntegerValue::IntegerValue(long lValue) {
    if ((lValue >= INT_MAX) || (lValue <= INT_MIN)) {
        mpoLogger->error("IntegerValue", "Overflow error: " + std::to_string(lValue));
        exit(ERR_NUMBER_OVERFLOW);
    }
    
    miValue = (int)lValue;
}

IntegerValue::IntegerValue(bool bValue) {
    if (bValue == YES) {
        miValue = 0;
    } else {
        miValue = -1;
    }
}

IntegerValue::IntegerValue(string strValue) {
    miValue = stoi(strValue);
}

string IntegerValue::to_string() {
    return std::to_string(miValue);
}


float IntegerValue::to_real() {
    return miValue;
}


int IntegerValue::to_int() {
    return miValue;
}


bool IntegerValue::to_bool() {
    if (miValue == YES)
        return true;
    return false;
}


double IntegerValue::to_double() {
    return miValue;
};


long IntegerValue::to_long() {
    return (long)miValue;
};


Value* IntegerValue::evaluate() {
    return this;
}


Value* IntegerValue::equals(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (miValue == poValue->to_int()) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("IntegerValue::equals", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::notEqual(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (miValue != poValue->to_int()) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("IntegerValue::notEquals", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::plus(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        int iReturn = miValue + poValue->to_int();
        return new IntegerValue(iReturn);
    }

    mpoLogger->error("IntegerValue::plus", "Syntax Error: Incompatible types: plus(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::minus(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        int iReturn = miValue - poValue->to_int();
        return new IntegerValue(iReturn);
    }

    mpoLogger->error("IntegerValue::minus", "Syntax Error: Incompatible types: minus(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::multiply(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        int iReturn = miValue * poValue->to_int();
        return new IntegerValue(iReturn);
    }

    mpoLogger->error("IntegerValue::multiply", "Syntax Error: Incompatible types: multiply(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::divide(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        
        if (poValue->to_int() == 0) {
            mpoLogger->error("IntegerValue::divide", "Division by zero error");
            exit(ERR_DIVISION_BY_ZERO);
        }
        
        int iReturn = miValue / poValue->to_int();
        return new IntegerValue(iReturn);
    }

    mpoLogger->error("IntegerValue::divide", "Syntax Error: Incompatible types: divide(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::modulo(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        
        if (poValue->to_int() == 0) {
            mpoLogger->error("IntegerValue::modulo", "Division by zero error");
            exit(ERR_DIVISION_BY_ZERO);
        }
        
        int iReturn = miValue % poValue->to_int();
        return new IntegerValue(iReturn);
    }

    mpoLogger->error("IntegerValue::modulo", "Syntax Error: Incompatible types: modulo(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::shiftLeft(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        int iReturn = miValue * 2 *poValue->to_int();
        return new IntegerValue(iReturn);
    }

    mpoLogger->error("IntegerValue::shiftLeft", "Syntax Error: Incompatible types: shiftLeft(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::land(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if ((miValue == OK) && (poValue->to_int() == OK)) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("IntegerValue::and", "Syntax Error: Incompatible types: and(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::lor(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if ((miValue == OK) || (poValue->to_int() == OK)) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("IntegerValue::or", "Syntax Error: Incompatible types: or(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::shiftRight(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        
        if (poValue->to_int() == 0) {
            mpoLogger->error("IntegerValue::shiftRight", "Division by zero error");
            exit(ERR_DIVISION_BY_ZERO);
        }
        
        int iReturn = miValue / (2 * poValue->to_int());
        return new IntegerValue(iReturn);
    }

    mpoLogger->error("IntegerValue::shiftRight", "Syntax Error: Incompatible types: shiftRight(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::power(Value* poValue) {
    IntegerValue* poReturn;

    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        poReturn = new IntegerValue(pow(to_real(), poValue->to_real()));
        return poReturn;
    }

    mpoLogger->error("IntegerValue::power", "Syntax Error: Incompatible types: power(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::smallerThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (miValue < (poValue->to_int())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("IntegerValue::smallerThan", "Syntax Error: Incompatible types: smallerThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::smallerEqualThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (miValue <= (poValue->to_int())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("IntegerValue::smallerEqualThan", "Syntax Error: Incompatible types: smallerEqualThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::largerThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (miValue > (poValue->to_int())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("IntegerValue::largerThan", "Syntax Error: Incompatible types: largerThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* IntegerValue::largerEqualThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (miValue >= (poValue->to_int())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("IntegerValue::largerEqualThan", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


VariableType IntegerValue::getType() {
    return VariableType::INT;
};


string IntegerValue::getTypeToString() {
    return "IntegerValue";
}
