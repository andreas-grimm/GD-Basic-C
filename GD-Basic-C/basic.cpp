//
//  basic.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#include "basic.hpp"

Basic::Basic(string strLogLevel) {
    mstrLogLevel = strLogLevel;
    
    poLogger = Logger::getInstance();
    poLogger->setLogLevel(mstrLogLevel);
};

int Basic::interpret(string strProgramName) {
    mstrProgramName = strProgramName;
    
    mpoProgram = new Program(mstrLogLevel);

    //Read the Basic program. If the return code is not 'OK' then terminate
    poLogger->info("Basic::interpret", "Read program...");
    mpoProgram->load(strProgramName);
    
    // Find and process Macros.
    poLogger->info("Basic::interpret", "Processing macros...");
    mpoMacroProcessor = new MacroProcessor(mstrLogLevel);
    
    mpoProgram->setProgram(mpoMacroProcessor->process(mpoProgram->getProgram()));
    
    // Tokenize. At the end of the tokenization I have the program transferred into a list of tokens and parameters
    poLogger->info("Basic::interpret", "Starting tokenization...");
    mpoTokenizer = new BasicLexer(mstrLogLevel);

    mpoProgram->setTokens(mpoTokenizer->tokenize(mpoProgram->getProgram()));

    int iCounter = 0;
    for (auto oToken: mpoProgram->getTokens()) {
        if (oToken.getType()== BasicTokenType::LINE) {
            poLogger->debug("Basic::interpret", "[" + to_string(oToken.getLine()) + "] Token # <" + to_string(iCounter) + ">: [" + to_string(oToken.getType()) + "]: []");
        } else {
            poLogger->debug("Basic::interpret", "[" + to_string(oToken.getLine()) + "] Token # <" + to_string(iCounter) + ">: [" + to_string(oToken.getType()) + "]: ["
                    + oToken.getText() + "]");
        }
        iCounter++;
    }
    
    // Parse.
    poLogger->info("Basic::interpret", "Starting pre-parsing...");

    BasicParser oParser(mstrLogLevel);
    oParser.setTokens(mpoProgram->getTokens());

    mpoProgram->setPreRunStatements(oParser.parsePreRun());

    poLogger->info("Basic::interpret", "Starting parsing...");

    mpoProgram->setStatements(oParser.parse());
    
     // Run.
    poLogger->info("Basic::interpret", "Execute program...");
    
    Execute* poRun = new Execute(mpoProgram);

    // load the environment for the execution
    poRun->loadEnvironment();

    // run the program
    poRun->runProgram();

    poLogger->info("Basic::interpret", "Execution completed...");
    
    delete mpoProgram;
    delete mpoTokenizer;
    
    return miErrorCode;
};
