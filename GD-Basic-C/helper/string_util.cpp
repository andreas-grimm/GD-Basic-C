//
//  string_util.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 22/08/2023.
//

#include "string_util.hpp"

StringUtil::StringUtil() {
}

vector<string> StringUtil::split(string strInputString, string strSplitToken) {
    vector<string> vstrResult;
    
    while(strInputString.size()){
        long lIndex = strInputString.find(strSplitToken);
        
        if(lIndex != string::npos) {
            vstrResult.push_back(strInputString.substr(0,lIndex));
            strInputString = strInputString.substr(lIndex+strSplitToken.size());
            if(strInputString.size() == 0)
                vstrResult.push_back(strInputString);
        }else{
            vstrResult.push_back(strInputString);
            break;
        }
        
    }
    return vstrResult;
};

string StringUtil::from_vector(vector<string> vstrVector, string strSeperator) {
    string strReturn;
    
    for (auto strVectorContent: vstrVector) {
        strReturn += strVectorContent + strSeperator;
    }
    
    return strReturn;
};

string StringUtil::to_upper(string strString) {
    int iIndex = 0;
    char cCharacter;
    
    string strReturn;
    
    while (strString[iIndex]) {
        cCharacter = strString[iIndex];
        strReturn += toupper(cCharacter);
        iIndex++;
    }
    
    return strReturn;
}

