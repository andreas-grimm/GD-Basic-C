//
//  macro_list.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/08/2023.
//

#include "macro_list.hpp"

MacroList::MacroList(string strLogLevel) {
    mstrLogLevel = strLogLevel;
    
    mpoLogger = Logger::getInstance();
    mpoLogger->setLogLevel(mstrLogLevel);
};

MacroList::~MacroList() {
};

void MacroList::add(string strName, vector<string> vstrParameters, string strFunction) {
    mmstrstrMacroList[strName] = strFunction;
    mmstrvstrParameterList[strName] = vstrParameters;
};

string MacroList::containsMacro(string strLine) {
    for (auto strMacroListEntry: mmstrstrMacroList) {
        string strMacroName = strMacroListEntry.first;
        
        if (strLine.find(strMacroName) == true) {
            return strMacroName;
        }
    }
    return "";
}

string MacroList::getFunction(string strParameterList, string strMacroName) {
    string strWorkParameterList = strParameterList;
    vector<string> vstrParametersFromSource;
    vector<string> vstrParametersFromDEF;

    // Build the parameter list
    vstrParametersFromSource = toVector(strParameterList);

    mpoLogger->debug("MacroList", "Macros found: " + strMacroName);
    mpoLogger->debug("MacroList", "Parameters: " + StringUtil::from_vector(vstrParametersFromSource, ";"));

    for (auto oMacro : mmstrstrMacroList) {
        string strKey = oMacro.first;
        string strValue = oMacro.second;

        if (strMacroName.find(strKey)) {
            // Generate a vector with all parameters to be changed
            for (auto oParameters : mmstrvstrParameterList) {
                string strMacroKey = oParameters.first;

                if (strMacroName.find(strMacroKey)) {
                    vstrParametersFromDEF = oParameters.second;
                    mpoLogger->debug("MacroList", "Matched Parameters: " + StringUtil::from_vector(vstrParametersFromDEF, ";"));
                }
            }
/** TO-DO
            // Loop through the vectors and find the values to replace
            if (vstrParametersFromDEF.size() != vstrParametersFromSource.size()) {
                mpoLogger->error("Syntax Error: Incorrect number of parameters in macro call. Expected: " + vstrParametersFromDEF.size() + ", provided: " + vstrParametersFromSource.size());
                exit(ERR_SYNTAX_ERROR);
            }

            for (int iCounter = 0; iCounter < vstrParametersFromDEF.size(); iCounter++) {
                string strReplacement = vstrParametersFromSource.get(iCounter);
                string strOriginalValue = vstrParametersFromDEF.get(iCounter);

                mpoLogger->debug("Replace: <" + strOriginalValue + "> with <" + strReplacement + ">");

                strValue = strValue.replace(strOriginalValue, strReplacement);
            }
*/
            return strValue;
        }
    }
    return "";
}

void MacroList::print() {
    mpoLogger->debug("MacroList", "List of Macros:");
    for (auto i : mmstrstrMacroList)    // auto keyword
        mpoLogger->debug("MacroList", "Macro List: Name = [" + i.first + "] Function = [" + i.second +"]");
    for (auto j: mmstrvstrParameterList)
        mpoLogger->debug("MacroList", "Macro List: Name = [" + j.first + "] Parameter = [" + StringUtil::from_vector(j.second, ";") +"]");
}

vector<string> MacroList::toVector (string strStringCodedVector) {
    vector<string> vstrVectorFromString;
    string strValue;

    if (strStringCodedVector.find_first_of("[") >= 0) {
        strStringCodedVector = strStringCodedVector.substr(strStringCodedVector.find_first_of("[") + 1);
    }

    if (strStringCodedVector.find_first_of("]") >= 0) {
        strStringCodedVector = strStringCodedVector.substr(0, strStringCodedVector.find_first_of("]"));
    }

    UNSIGNED_LONG ulCommaFound = strStringCodedVector.find_first_of(",");
    /** TO-DO

    while (iCommaFound > 0) {
        String strFirstParameter = strStringCodedVector.substring(0, iCommaFound);
        strStringCodedVector = strStringCodedVector.substring(iCommaFound + 1).trim();
        vstrVectorFromString.add(strFirstParameter);
        iCommaFound = strStringCodedVector.indexOf(",");
    }

    vstrVectorFromString.add(strStringCodedVector);
     */

    return vstrVectorFromString;
}

