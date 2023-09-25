//
//  double_value.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 28/08/2023.
//

#include "double_value.hpp"

DoubleValue::DoubleValue(int iValue) {
    mdValue = iValue;
}

DoubleValue::DoubleValue(float fValue) {
    mdValue = fValue;
}

DoubleValue::DoubleValue(double dValue) {
    mdValue = dValue;
}

DoubleValue::DoubleValue(long lValue) {
    mdValue = lValue;
}

DoubleValue::DoubleValue(bool bValue) {
    if (bValue == YES) {
        mdValue = 0;
    } else {
        mdValue = -1;
    }
}

DoubleValue::DoubleValue(string strValue) {
    mdValue = stod(strValue);
}

string DoubleValue::to_string() {
    return std::to_string(mdValue);
}


float DoubleValue::to_real() {
    return mdValue;
}


int DoubleValue::to_int() {
    if ((mdValue >= INT_MAX) || (mdValue <= INT_MIN)) {
        mpoLogger->error("DoubleValue::to_int", "Overflow error: " + std::to_string(mdValue));
        exit(ERR_NUMBER_OVERFLOW);
    }
    return (int)mdValue;
}


bool DoubleValue::to_bool() {
    if (mdValue == YES)
        return true;
    return false;
}


double DoubleValue::to_double() {
    return mdValue;
};


long DoubleValue::to_long() {
    return mdValue;
};


Value* DoubleValue::evaluate() {
    return this;
}


Value* DoubleValue::equals(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mdValue == poValue->to_double()) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("DoubleValue::equals", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::notEqual(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mdValue != poValue->to_double()) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("DoubleValue::notEqual", "Syntax Error: Incompatible types: notEqual(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::plus(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        double dReturn = mdValue + poValue->to_double();
        return new DoubleValue(dReturn);
    }

    mpoLogger->error("DoubleValue::plus", "Syntax Error: Incompatible types: plus(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::minus(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        double dReturn = mdValue - poValue->to_double();
        return new DoubleValue(dReturn);
    }

    mpoLogger->error("DoubleValue::minus", "Syntax Error: Incompatible types: minus(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::multiply(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        double dReturn = mdValue * poValue->to_double();
        return new DoubleValue(dReturn);
    }

    mpoLogger->error("DoubleValue::multiply", "Syntax Error: Incompatible types: multiply(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::divide(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        
        if (poValue->to_long() == 0) {
            mpoLogger->error("DoubleValue::divide", "Division by zero error");
            exit(ERR_DIVISION_BY_ZERO);
        }
        
        double dReturn = mdValue / poValue->to_double();
        return new DoubleValue(dReturn);
    }

    mpoLogger->error("DoubleValue::divide", "Syntax Error: Incompatible types: divide(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::modulo(Value* poValue) {
    mpoLogger->error("DoubleValue::modulo", " '%' for double variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::shiftLeft(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        double dReturn = mdValue * 2 *poValue->to_double();
        return new DoubleValue(dReturn);
    }

    mpoLogger->error("DoubleValue::shiftLeft", "Syntax Error: Incompatible types: shiftLeft(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::land(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if ((mdValue == OK) && (poValue->to_double() == OK)) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("DoubleValue::and", "Syntax Error: Incompatible types: and(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::lor(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if ((mdValue == OK) || (poValue->to_double() == OK)) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("DoubleValue::or", "Syntax Error: Incompatible types: or(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::shiftRight(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        
        if (poValue->to_double() == 0) {
            mpoLogger->error("DoubleValue::shiftRight", "Division by zero error");
            exit(ERR_DIVISION_BY_ZERO);
        }
        
        double dReturn = mdValue / (2 * poValue->to_double());
        return new DoubleValue(dReturn);
    }

    mpoLogger->error("DoubleValue::shiftRight", "Syntax Error: Incompatible types: shiftRight(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::power(Value* poValue) {
    DoubleValue* poReturn;

    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        poReturn = new DoubleValue(pow(to_double(), poValue->to_double()));
        return poReturn;
    }

    mpoLogger->error("DoubleValue::power", "Syntax Error: Incompatible types: power(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::smallerThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mdValue < (poValue->to_double())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("DoubleValue::smallerThan", "Syntax Error: Incompatible types: smallerThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::smallerEqualThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mdValue <= (poValue->to_double())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("DoubleValue::smallerEqualThan", "Syntax Error: Incompatible types: smallerEqualThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::largerThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mdValue > (poValue->to_double())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("DoubleValue::largerThan", "Syntax Error: Incompatible types: largerThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* DoubleValue::largerEqualThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mdValue >= (poValue->to_double())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("DoubleValue::largerEqualThan", "Syntax Error: Incompatible types: largerEqualThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


VariableType DoubleValue::getType() {
    return VariableType::DOUBLE;
};


string DoubleValue::getTypeToString() {
    return "DoubleValue";
}
