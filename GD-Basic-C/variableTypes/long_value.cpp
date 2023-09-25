//
//  long_value.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 27/08/2023.
//

#include "long_value.hpp"

LongValue::LongValue() {
    mpoLogger = Logger::getInstance();
}

LongValue::LongValue(int iValue) {
    mlValue = iValue;
}

LongValue::LongValue(float fValue) {
    if ((fValue >= LONG_MAX) || (fValue <= LONG_MIN)) {
        mpoLogger->error("LongValue", "Overflow error: " + std::to_string(fValue));
        exit(ERR_NUMBER_OVERFLOW);
    }
    
    mlValue = fValue;
}

LongValue::LongValue(double dValue) {
    if ((dValue >= LONG_MAX) || (dValue <= LONG_MIN)) {
        mpoLogger->error("LongValue", "Overflow error: " + std::to_string(dValue));
        exit(ERR_NUMBER_OVERFLOW);
    }
    
    mlValue = dValue;
}

LongValue::LongValue(long lValue) {
    mlValue = lValue;
}

LongValue::LongValue(bool bValue) {
    if (bValue == YES) {
        mlValue = 0;
    } else {
        mlValue = -1;
    }
}

LongValue::LongValue(string strValue) {
    mlValue = stol(strValue);
}

string LongValue::to_string() {
    return std::to_string(mlValue);
}


float LongValue::to_real() {
    return mlValue;
}


int LongValue::to_int() {
    if ((mlValue >= INT_MAX) || (mlValue <= INT_MIN)) {
        mpoLogger->error("LongValue::to_int", "Overflow error: " + std::to_string(mlValue));
        exit(ERR_NUMBER_OVERFLOW);
    }
    return (int)mlValue;
}


bool LongValue::to_bool() {
    if (mlValue == YES)
        return true;
    return false;
}


double LongValue::to_double() {
    return mlValue;
};


long LongValue::to_long() {
    return mlValue;
};


Value* LongValue::evaluate() {
    return this;
}


Value* LongValue::equals(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mlValue == poValue->to_long()) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("LongValue::equals", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::notEqual(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mlValue != poValue->to_long()) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("LongValue::notEquals", "Syntax Error: Incompatible types: notEquals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::plus(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        long lReturn = mlValue + poValue->to_long();
        return new LongValue(lReturn);
    }

    mpoLogger->error("LongValue::plus", "Syntax Error: Incompatible types: plus(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::minus(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        long lReturn = mlValue - poValue->to_long();
        return new LongValue(lReturn);
    }

    mpoLogger->error("LongValue::minus", "Syntax Error: Incompatible types: minus(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::multiply(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        long lReturn = mlValue * poValue->to_long();
        return new LongValue(lReturn);
    }

    mpoLogger->error("LongValue::multiply", "Syntax Error: Incompatible types: multiply(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::divide(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        
        if (poValue->to_long() == 0) {
            mpoLogger->error("LongValue::divide", "Division by zero error");
            exit(ERR_DIVISION_BY_ZERO);
        }
        
        long lReturn = mlValue / poValue->to_long();
        return new LongValue(lReturn);
    }

    mpoLogger->error("LongValue::divide", "Syntax Error: Incompatible types: divide(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::modulo(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        
        if (poValue->to_long() == 0) {
            mpoLogger->error("LongValue::modulo", "Division by zero error");
            exit(ERR_DIVISION_BY_ZERO);
        }
        
        long lReturn = mlValue % poValue->to_long();
        return new LongValue(lReturn);
    }

    mpoLogger->error("LongValue::modulo", "Syntax Error: Incompatible types: modulo(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::shiftLeft(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        long lReturn = mlValue * 2 *poValue->to_long();
        return new LongValue(lReturn);
    }

    mpoLogger->error("LongValue::shiftLeft", "Syntax Error: Incompatible types: shiftLeft(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::land(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if ((mlValue == OK) && (poValue->to_long() == OK)) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("LongValue::and", "Syntax Error: Incompatible types: and(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::lor(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if ((mlValue == OK) || (poValue->to_long() == OK)) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("LongValue::or", "Syntax Error: Incompatible types: or(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::shiftRight(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        
        if (poValue->to_long() == 0) {
            mpoLogger->error("LongValue::shiftRight", "Division by zero error");
            exit(ERR_DIVISION_BY_ZERO);
        }
        
        long lReturn = mlValue / (2 * poValue->to_long());
        return new LongValue(lReturn);
    }

    mpoLogger->error("LongValue::shiftRight", "Syntax Error: Incompatible types: shiftRight(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::power(Value* poValue) {
    LongValue* poReturn;

    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        poReturn = new LongValue(pow(to_long(), poValue->to_long()));
        return poReturn;
    }

    mpoLogger->error("LongValue::power", "Syntax Error: Incompatible types: power(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::smallerThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mlValue < (poValue->to_long())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("LongValue::smallerThan", "Syntax Error: Incompatible types: smallerThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::smallerEqualThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mlValue <= (poValue->to_long())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("LongValue::smallerEqualThan", "Syntax Error: Incompatible types: smallerEqualThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::largerThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mlValue > (poValue->to_long())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("LongValue::largerThan", "Syntax Error: Incompatible types: largerThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* LongValue::largerEqualThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mlValue >= (poValue->to_long())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("LongValue::largerEqualThan", "Syntax Error: Incompatible types: largerEqualThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


VariableType LongValue::getType() {
    return VariableType::LONG;
};


string LongValue::getTypeToString() {
    return "LongValue";
}
