//
//  macro_list.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/08/2023.
//

#ifndef macro_list_hpp
#define macro_list_hpp

#include <stdio.h>
#include <string>
#include <map>

#include "common.hpp"
#include "../helper/logger.hpp"
#include "../helper/string_util.hpp"
#include "../memoryManager/program.hpp"

using namespace std;

class MacroList {
    
public:

    MacroList(string strLogLevel);
    ~MacroList();

    void add(string strName, vector<string> vstrParameters, string strFunction);
    string containsMacro(string strLine);
    string getFunction(string strParameterList, string strMacroName);

    void print();
    
private:
    Logger *mpoLogger;
    string mstrLogLevel;

    map<string, string> mmstrstrMacroList;
    map<string, vector<string>> mmstrvstrParameterList;
    vector<string> toVector (string strStringCodedVector);

};

#endif /* macro_list_hpp */
