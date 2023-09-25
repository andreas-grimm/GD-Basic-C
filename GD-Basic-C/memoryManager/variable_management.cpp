//
//  variable_management.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 31/08/2023.
//

#include "variable_management.hpp"

VariableManagement* VariableManagement::mpoVariableManagementInstance = NULL;

VariableManagement::VariableManagement() {
}

VariableManagement* VariableManagement::getInstance() {
    if (mpoVariableManagementInstance == NULL) {
        mpoVariableManagementInstance = new VariableManagement();
    }
    
    return mpoVariableManagementInstance;
}

// section managing internal variables...
/**
 * Put a key - value pair into the variable map structure.
 *
 * @param strKey key part of the pair
 * @param poValue value part of the pair, here as an Value object
 * @throws SyntaxErrorException if the parenthesis are not set correctly
 */
void VariableManagement::putMap(string strKey, Value* poValue) {
    VariableType eVariableType = VariableType::UNDEFINED;
    Normalizer oNormalizer;

    if (strKey.find_first_of("$")) {
        eVariableType = VariableType::STRG;
    } else if (strKey.find_first_of("%")) {
        eVariableType = VariableType::INT;
    } else if (strKey.find_first_of("&")) {
        eVariableType = VariableType::LONG;
    } else if (strKey.find_first_of("#")) {
        eVariableType = VariableType::REAL;
    } else if (strKey.find_first_of("!")) {
        eVariableType = VariableType::DOUBLE;
    } else if (strKey.find_first_of("@")) {
        eVariableType = VariableType::BOOL;
    }

    switch (eVariableType) {
        case VariableType::STRG: {
            mmstroStrings[oNormalizer.normalizeIndex(strKey)] = (StringValue*)poValue;
            break;
        }
        case VariableType::INT: {
            mmstroIntegers[oNormalizer.normalizeIndex(strKey)] = (IntegerValue*)poValue;
            break;
        }
        case VariableType::LONG: {
            mmstroLongs[oNormalizer.normalizeIndex(strKey)] = (LongValue*)poValue;
            break;
        }
        case VariableType::REAL: {
            mmstroReals[oNormalizer.normalizeIndex(strKey)] = (RealValue*)poValue;
            break;
        }
        case VariableType::DOUBLE: {
            mmstroDoubles[oNormalizer.normalizeIndex(strKey)] = (DoubleValue*)poValue;
            break;
        }
        case VariableType::BOOL: {
            mmstroBooleans[oNormalizer.normalizeIndex(strKey)] = (BooleanValue*)poValue;
            break;
        }
        default: {
            mmstroUntyped[oNormalizer.normalizeIndex(strKey)] = poValue;
        }
    }
}

/**
 * Put a key - value pair into the variable map structure.
 *
 * @param strKey - key part of the pair
 * @param fValue - value part of the pair, here as an double
 * @throws SyntaxErrorException variable is not marked as real
 * @throws RuntimeException incorrect format of the parenthesis
 */
void VariableManagement::putMap(string strKey, float fValue) {
    Normalizer oNormalizer;

    if (strKey.find_first_of("!")) {
        RealValue* poValue = new RealValue(fValue);
        mmstroReals[oNormalizer.normalizeIndex(strKey)] = poValue;
        return;
    }

    mpoLogger->error("VariableManagement::putMap:", "Syntax Error: Variable name [" + strKey + "] does not end as a Real: '!'");
    exit(ERR_UNEXPECTED_TYPE);
}

/**
 * Put a key - value pair into the variable map structure.
 *
 * @param strKey - key part of the pair
 * @param dValue - value part of the pair, here as an double
 * @throws SyntaxErrorException variable is not marked as real
 * @throws RuntimeException incorrect format of the parenthesis
 */
void VariableManagement::putMap(string strKey, double dValue) {
    Normalizer oNormalizer;

    if (strKey.find_first_of("#")) {
        DoubleValue* poValue = new DoubleValue(dValue);
        mmstroDoubles[oNormalizer.normalizeIndex(strKey)] = poValue;
        return;
    }

    mpoLogger->error("VariableManagement::putMap:", "Syntax Error: Variable name [" + strKey + "] does not end as a Double: '#'");
    exit(ERR_UNEXPECTED_TYPE);
}

/**
 * Put a key - value pair into the variable map structure.
 *
 * @param strKey key part of the pair
 * @param strValue value part of the pair, here as a string
 * @throws SyntaxErrorException variable is not marked as string
 * @throws RuntimeException incorrect format of the parenthesis
 */
void VariableManagement::putMap(string strKey, string strValue) {
    Normalizer oNormalizer;

    if (strKey.find_first_of("$")) {
        StringValue* poValue = new StringValue(strValue);
        mmstroStrings[oNormalizer.normalizeIndex(strKey)] = poValue;
        return;
    }

    mpoLogger->error("VariableManagement::putMap:", "Syntax Error: Variable name [" + strKey + "] does not end as a String: '$'");
    exit(ERR_UNEXPECTED_TYPE);
}

/**
 * Put a key - value pair into the variable map structure.
 *
 * @param strKey - key part of the pair
 * @param iValue - value part of the pair, here as an integer
 * @throws SyntaxErrorException variable is not marked as integer
 * @throws RuntimeException incorrect format of the parenthesis
 */
void VariableManagement::putMap(string strKey, int iValue) {
    Normalizer oNormalizer;

    if (strKey.find_first_of("%")) {
        IntegerValue* poValue = new IntegerValue(iValue);
        mmstroIntegers[oNormalizer.normalizeIndex(strKey)] = poValue;
        return;
    }

    mpoLogger->error("VariableManagement::putMap:", "Syntax Error: Variable name [" + strKey + "] does not end as a Integer: '%'");
    exit(ERR_UNEXPECTED_TYPE);
}

/**
 * Put a key - value pair into the variable map structure.
 *
 * @param strKey - key part of the pair
 * @param lValue - value part of the pair, here as an integer
 * @throws SyntaxErrorException variable is not marked as integer
 * @throws RuntimeException incorrect format of the parenthesis
 */
void VariableManagement::putMap(string strKey, long lValue) {
    Normalizer oNormalizer;

    if (strKey.find_first_of("&")) {
        LongValue* poValue = new LongValue(lValue);
        mmstroLongs[oNormalizer.normalizeIndex(strKey)] = poValue;
        return;
    }

    mpoLogger->error("VariableManagement::putMap:", "Syntax Error: Variable name [" + strKey + "] does not end as a Long: '&'");
    exit(ERR_UNEXPECTED_TYPE);
}


/**
 * Get variable defined by a given key value.
 *
 * @param strKey - Key used for retrieval
 * @return Value object to be returned
 * @throws SyntaxErrorException if the parenthesis are not set correctly
 * @throws RuntimeException escalated exception
 */
Value* VariableManagement::getMap(string strKey) {
    Normalizer oNormalizer;
    bool bProcess = false;
    
    string strWork = strKey;
    
    unsigned long ulIndex = strKey.find_first_of("[");
    if (ulIndex > 0) {
        bProcess = true;
        strWork = strKey.substr(0, ulIndex);
    }
    
    strWork = oNormalizer.normalizeIndex(strWork);
    
    if (mmstroUntyped.contains(strWork)) {
        mpoLogger->debug("VariableManagement::getMap","retrieving key: <" + strWork + "> [untyped] ");
        return mmstroUntyped[strWork];
    }
    
    if (mmstroStrings.contains(strWork)) {
        mpoLogger->debug("VariableManagement::getMap","retrieving key: <" + strWork + "> [string] " + mmstroStrings[strWork]->to_string());
        StringValue* poString = (StringValue*)mmstroStrings[strWork];
        
        if (bProcess) {
            return  poString->process(strKey);
        }
        
        return mmstroStrings[strWork];
    }

    if (mmstroIntegers.contains(strWork)) {
        mpoLogger->debug("VariableManagement::getMap","retrieving key: <" + strWork + "> [integer] ");
        return mmstroIntegers[strWork];
    }

    if (mmstroDoubles.contains(strWork)) {
        mpoLogger->debug("VariableManagement::getMap","retrieving key: <" + strWork + "> [double] ");
        return mmstroDoubles[strWork];
    }

    if (mmstroLongs.contains(strWork)) {
        mpoLogger->debug("VariableManagement::getMap","retrieving key: <" + strWork + "> [long] ");
        return mmstroLongs[strWork];
    }

    if (mmstroReals.contains(strWork)) {
        mpoLogger->debug("VariableManagement::getMap","retrieving key: <" + strWork + "> [real] ");
        return mmstroReals[strWork];
    }

    if (mmstroBooleans.contains(strWork)) {
        mpoLogger->debug("VariableManagement::getMap","retrieving key: <" + strWork + "> [boolean] ");
        return mmstroBooleans[strWork];
    }

    return NULL;
}


/**
 * Verifies that the variables structure contains a given key.
 *
 * @param strKey Key to be verified
 * @return true, if key is in the data structure
 * @throws SyntaxErrorException if the parenthesis are not set correctly
 */
bool VariableManagement::mapContainsKey(string strKey) {
    string strWork = strKey;
    Normalizer oNormalizer;

    unsigned long ulIndex = strKey.find_first_of("[");
    if (ulIndex > 0) {
        strWork = strKey.substr(0, ulIndex);
    }

    strWork = oNormalizer.normalizeIndex(strWork);

    if (mmstroUntyped.contains(strWork) ||
        mmstroBooleans.contains(strWork) ||
        mmstroIntegers.contains(strWork) ||
        mmstroReals.contains(strWork) ||
        mmstroStrings.contains(strWork)) {
        return true;
    }

    return false;
}
