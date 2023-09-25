//
//  string_value.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 28/08/2023.
//

#include "string_value.hpp"

StringValue::StringValue(int iValue) {
    mstrValue = std::to_string(iValue);
}

StringValue::StringValue(float fValue) {
    mstrValue = std::to_string(fValue);
}

StringValue::StringValue(double dValue) {
    mstrValue = std::to_string(dValue);
}

StringValue::StringValue(long lValue) {
    mstrValue = std::to_string(lValue);
}

StringValue::StringValue(bool bValue) {
    if (bValue == YES) {
        mstrValue = "TRUE";
    } else {
        mstrValue = "FALSE";
    }
}

StringValue::StringValue(string strValue) {
    mstrValue = strValue;
}

string StringValue::to_string() {
    return mstrValue;
}


float StringValue::to_real() {
    return stof(mstrValue);
}


int StringValue::to_int() {
    return stoi(mstrValue);
}


bool StringValue::to_bool() {
    if (mstrValue == "TRUE")
        return true;
    return false;
}


double StringValue::to_double() {
    return stod(mstrValue);
};


long StringValue::to_long() {
    return stol(mstrValue);
};


Value* StringValue::evaluate() {
    return this;
}


Value* StringValue::equals(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mstrValue == poValue->to_string()) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("StringValue::equals", "Syntax Error: Incompatible types: equals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::notEqual(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mstrValue != poValue->to_string()) {
            return new BooleanValue(true);
        }

        return new BooleanValue(false);
    }

    mpoLogger->error("StringValue::notEquals", "Syntax Error: Incompatible types: notEquals(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::plus(Value* poValue) {
    if (getType() == poValue->getType()) {
        string strReturn = mstrValue + poValue->to_string();
        return new StringValue(strReturn);
    }

    mpoLogger->error("StringValue::plus", "Syntax Error: Incompatible types: plus(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::minus(Value* poValue) {
    mpoLogger->error("StringValue::minus", " '-' for string variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::multiply(Value* poValue) {
    mpoLogger->error("StringValue::multiply", " '*' for string variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::divide(Value* poValue) {
    mpoLogger->error("StringValue::divide", " '/' for string variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::modulo(Value* poValue) {
    mpoLogger->error("StringValue::modulo", " '%' for string variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::shiftLeft(Value* poValue) {
    mpoLogger->error("StringValue::shiftLeft", " '<<' for string variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::land(Value* poValue) {
    mpoLogger->error("StringValue::and", " '&&' for string variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::lor(Value* poValue) {
    mpoLogger->error("StringValue::or", " '||' for double variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::shiftRight(Value* poValue) {
    mpoLogger->error("StringValue::shiftRight", " '>>' for string variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::power(Value* poValue) {
    mpoLogger->error("StringValue::power", " '^' for double variables is not defined");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::smallerThan(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mstrValue < (poValue->to_string())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("StringValue::smallerThan", "Syntax Error: Incompatible types: smallerThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::smallerEqualThan(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mstrValue <= (poValue->to_string())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("StringValue::smallerEqualThan", "Syntax Error: Incompatible types: smallerEqualThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::largerThan(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mstrValue > (poValue->to_string())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("StringValue::largerThan", "Syntax Error: Incompatible types: largerThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


Value* StringValue::largerEqualThan(Value* poValue) {
    if (getType() == poValue->getType()) {
        if (mstrValue >= (poValue->to_string())) {
            return new BooleanValue(true);
        }
        
        return new BooleanValue(false);
    }

    mpoLogger->error("StringValue::largerEqualThan", "Syntax Error: Incompatible types: largerEqualThan(`" + getTypeToString() + "`, `" + poValue->getTypeToString() + "`)");
    exit(ERR_SYNTAX_ERROR);
}


VariableType StringValue::getType() {
    return VariableType::STRG;
};


string StringValue::getTypeToString() {
    return "StringValue";
}

/**
 * The keys extentions (squared ('[]') or round ('()') brackets are ignored in previous steps of the value
 * retrieval. During this step they are now processed.
 *
 * @param strKey the original requesting key.
 * @return processed string, either using round or squared brackets: substring or string being part of an array.
 * @throws RuntimeException for any errors occuring in the execution of the evaluation. Currently this happens if
 * the index in an array subscription is larger than the array.
 */
Value* StringValue::process(string strKey) {
    if (strKey.find("[") != string::npos) {
        return new StringValue(squareBrackets(strKey));
    }

    return this;
}

string StringValue::squareBrackets(string strKey) {
    // lets check whether between the brackets is a comma
    unsigned long ulComma = strKey.find_first_of(",");
    unsigned long ulStart = strKey.find_first_of("[");
    unsigned long ulEnd = strKey.find_first_of("]");

    if (ulComma > ulStart && ulComma < ulEnd) {
        int ulFirstNo = stoi(strKey.substr(ulStart + 1, ulComma));
        int ulSecondNo = stoi(strKey.substr(ulComma + 1, ulEnd));

        if (ulSecondNo >= mstrValue.length()) {
            mpoLogger->error("StringValue::squareBrackets", "Index value " + std::to_string(ulSecondNo) + " out of bounds");
            exit(ERR_OUT_OF_BOUNDS);
        }

        return mstrValue.substr(ulFirstNo, ulSecondNo + 1);
    }

    // no - no comma, we return the pointed character
    int iPosition = stoi(strKey.substr(ulStart + 1, ulEnd - 1));

    if (iPosition >= mstrValue.length()) {
        mpoLogger->error("StringValue::squareBrackets", "Index value " + std::to_string(iPosition) + " out of bounds");
        exit(ERR_OUT_OF_BOUNDS);
    }
    string strReturn = std::string(1, mstrValue.at(iPosition));
    return strReturn;
}
