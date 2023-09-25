//
//  real_value.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 28/08/2023.
//

#include "real_value.hpp"

RealValue::RealValue(int iValue) {
    mfValue = (float)iValue;
}

RealValue::RealValue(float fValue) {
    mfValue = fValue;
}

RealValue::RealValue(double dValue) {
    mfValue = (float)dValue;
}

RealValue::RealValue(long lValue) {
    mfValue = (float)lValue;
}

RealValue::RealValue(bool bValue) {
    if (bValue == YES) {
        mfValue = 0;
    } else {
        mfValue = -1;
    }
}

RealValue::RealValue(string strValue) {
    mfValue = stof(strValue);
}

string RealValue::to_string() {
    return std::to_string(mfValue);
}


float RealValue::to_real() {
    return mfValue;
}


int RealValue::to_int() {
    if ((mfValue >= INT_MAX) || (mfValue <= INT_MIN)) {
        mpoLogger->error("RealValue::to_int", "Overflow error: " + std::to_string(mfValue));
        exit(ERR_NUMBER_OVERFLOW);
    }
    return (int)mfValue;
}


bool RealValue::to_bool() {
    if (mfValue == YES)
        return true;
    return false;
}


double RealValue::to_double() {
    return mfValue;
};


long RealValue::to_long() {
    return mfValue;
};


Value* RealValue::evaluate() {
    return this;
}


Value* RealValue::equals(Value* poValue) {
    bool bReturn = false;
    
    if (getType() == poValue->getType()) {
        if (mfValue == poValue->to_real()) {
            bReturn = true;
        }
    } else {
        mpoLogger->error("RealValue::equals", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
        exit(ERR_SYNTAX_ERROR);
    }
    
    return new BooleanValue(bReturn);
}


Value* RealValue::notEqual(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mfValue != poValue->to_real()) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("RealValue::notEqual", "Syntax Error: Incompatible types: notEqual(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::plus(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        float fReturn = mfValue + poValue->to_real();
        return new RealValue(fReturn);
    }

    mpoLogger->error("RealValue::plus", "Syntax Error: Incompatible types: plus(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::minus(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        float fReturn = mfValue - poValue->to_real();
        return new RealValue(fReturn);
    }

    mpoLogger->error("RealValue::minus", "Syntax Error: Incompatible types: minus(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::multiply(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        float fReturn = mfValue * poValue->to_real();
        return new RealValue(fReturn);
    }

    mpoLogger->error("RealValue::multiply", "Syntax Error: Incompatible types: multiply(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::divide(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        
        if (poValue->to_real() == 0) {
            mpoLogger->error("RealValue::divide", "Division by zero error");
            exit(ERR_DIVISION_BY_ZERO);
        }
        
        float fReturn = mfValue / poValue->to_real();
        return new RealValue(fReturn);
    }

    mpoLogger->error("RealValue::divide", "Syntax Error: Incompatible types: divide(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::modulo(Value* poValue) {
    mpoLogger->error("RealValue::modulo", " '%' for real variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::shiftLeft(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        float fReturn = mfValue * 2 *poValue->to_real();
        return new RealValue(fReturn);
    }

    mpoLogger->error("RealValue::shiftLeft", "Syntax Error: Incompatible types: shiftLeft(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::land(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if ((mfValue == OK) && (poValue->to_long() == OK)) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("RealValue::and", "Syntax Error: Incompatible types: and(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::lor(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if ((mfValue == OK) || (poValue->to_long() == OK)) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("RealValue::or", "Syntax Error: Incompatible types: or(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::shiftRight(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        
        if (poValue->to_real() == 0) {
            mpoLogger->error("RealValue::shiftRight", "Division by zero error");
            exit(ERR_DIVISION_BY_ZERO);
        }
        
        float fReturn = mfValue / (2 * poValue->to_real());
        return new RealValue(fReturn);
    }

    mpoLogger->error("RealValue::shiftRight", "Syntax Error: Incompatible types: shiftRight(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::power(Value* poValue) {
    RealValue* poReturn;

    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        poReturn = new RealValue(pow(to_real(), poValue->to_real()));
        return poReturn;
    }

    mpoLogger->error("RealValue::power", "Syntax Error: Incompatible types: power(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::smallerThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mfValue < (poValue->to_real())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("RealValue::smallerThan", "Syntax Error: Incompatible types: smallerThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::smallerEqualThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mfValue <= (poValue->to_real())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("RealValue::smallerEqualThan", "Syntax Error: Incompatible types: smallerEqualThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::largerThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mfValue > (poValue->to_real())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("RealValue::largerThan", "Syntax Error: Incompatible types: largerThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* RealValue::largerEqualThan(Value* poValue) {
    if ((poValue->getType() == VariableType::INT) ||
        (poValue->getType() == VariableType::REAL) ||
        (poValue->getType() == VariableType::LONG) ||
        (poValue->getType() == VariableType::DOUBLE)) {
        if (mfValue >= (poValue->to_real())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("RealValue::largerEqualThan", "Syntax Error: Incompatible types: largerEqualThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


VariableType RealValue::getType() {
    return VariableType::REAL;
};


string RealValue::getTypeToString() {
    return "RealValue";
}
