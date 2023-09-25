//
//  macro_processor.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#ifndef macro_processor_hpp
#define macro_processor_hpp
#include <stdio.h>
#include <string>

#include "common.hpp"
#include "../helper/logger.hpp"
#include "../helper/string_util.hpp"
#include "../memoryManager/program.hpp"
#include "../tokenizer/basic_lexer.hpp"
#include "../tokenizer/token.hpp"
#include "macro_list.hpp"

using namespace std;

class MacroProcessor {
public:
    MacroProcessor(string strLogLevel);
    ~MacroProcessor();
    
    string process(string strProgram);

private:
    string mstrLoadedProgramSource;
    string mstrCurrentProgramSource;

    string mstrLogLevel;
    Logger* mpoLogger;
    Program *mpoProgram;
    BasicLexer *mpoLexer;
    
    vector<Token> tokenize(string strProgramText);
    string convertLine(string strOriginal, MacroList *poMacroList);
};

#endif /* macro_processor_hpp */
