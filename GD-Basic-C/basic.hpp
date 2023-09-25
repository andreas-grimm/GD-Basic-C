//
//  basic.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#ifndef basic_hpp
#define basic_hpp

#include <stdio.h>
#include <string>

#include "helper/logger.hpp"
#include "memoryManager/program.hpp"
#include "macroManager/macro_processor.hpp"
#include "parser/basic_parser.hpp"
#include "runtimeManager/execute.hpp"

using namespace std;

class Basic {
public:
    Basic(string strLogLevel);
    
    int interpret(string strProgramName);
    
private:
    string mstrProgramName;
    string mstrLogLevel;
    int miErrorCode;
    
    Logger* poLogger;
    Program *mpoProgram;
    MacroProcessor *mpoMacroProcessor;
    BasicLexer *mpoTokenizer;
};

#endif /* basic_hpp */
