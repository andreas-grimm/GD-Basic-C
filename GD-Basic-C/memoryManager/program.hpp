//
//  program.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#ifndef program_hpp
#define program_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include "common.hpp"
#include "../helper/logger.hpp"
#include "../helper/file_handler.hpp"
#include "../tokenizer/token.hpp"
#include "../statements/statement.hpp"

using namespace std;

class Program {
public:
    Program(string strLogLevel);
    
    int read(string strProgramName);
    void load(string strProgramName);
    
    string getProgram();
    void setProgram(string strProgram);
    
    void setTokens(vector<Token> voTokens);
    vector<Token> getTokens();
    
    void setPreRunStatements(vector<Statement*> vpoPreRunStatements);
    void setStatements(vector<Statement*> vpoStatements);
    
    vector<Statement*> getPreRunStatements();
    vector<Statement*> getStatements();


    
private:
    string mstrLoadedProgramSource;
    string mstrCurrentProgramSource;
    
    string mstrLogLevel;
    Logger* mpoLogger;
    
    vector<Token> mvoTokens;
    vector<Statement*> mvpoPreRunStatements;
    vector<Statement*> mvpoStatements;
};

#endif /* program_hpp */
