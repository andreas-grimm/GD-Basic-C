//
//  basic_lexer.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 16/08/2023.
//

#ifndef basic_lexer_hpp
#define basic_lexer_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>

#include "common.hpp"
#include "../helper/logger.hpp"
#include "../memoryManager/program.hpp"
#include "../tokenizer/token.hpp"
#include "basic_token_type.hpp"
#include "basic_token_type_util.hpp"
#include "normalizer.hpp"
#include "../helper/string_util.hpp"

using namespace std;

class BasicLexer {
public:
    BasicLexer(string strLogLevel);
    ~BasicLexer();

    vector<Token> tokenize(string strProgramText);
private:
    string mstrLogLevel;
    Logger* mpoLogger;
    
    ReservedWords oReservedWords;
    
    vector<string> split(string strInputString, string strSplitToken);
    
    bool isNumber(string strString);
    bool isString(string strString);
    bool isBoolean(string strString);
};

#endif /* basic_lexer_hpp */
