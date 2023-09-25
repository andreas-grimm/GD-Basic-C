//
//  macro_processor.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#include "macro_processor.hpp"

MacroProcessor::MacroProcessor(string strLogLevel) {
    mstrLogLevel = strLogLevel;
    
    mpoLogger = Logger::getInstance();
    mpoLogger->setLogLevel(mstrLogLevel);
};

MacroProcessor::~MacroProcessor() {
    delete mpoLogger;
};

string MacroProcessor::process(string strProgram){
    mpoLogger->info("MacroProcessor::process", "Processing...");
    mpoLexer = new BasicLexer(mstrLogLevel);

    vector<string> vstrParameter;
    MacroList *poMacroList = new MacroList(mstrLogLevel);
    string strConvertedProgram = "";

    // Step 1: Tokenize the source code
    vector<Token> voTokens = tokenize(strProgram);
    

    // Step 2: Build the list of all found macros
    mpoLogger->info("MacroProcessor::process", "Identification of macros (DEF)...");

    for (auto poToken = voTokens.begin(); poToken < voTokens.end(); poToken++) {
        if (poToken->getType() == BasicTokenType::DEF) {

            string strName = poToken[1].getText();
            mpoLogger->debug("MacroProcessor::process", "[" + to_string(poToken->getLine()) + "]: [" + to_string(poToken->getType()) + "]: [DEF " + strName + "]");

            int iAdd = 3;
            while (poToken[iAdd].getType() != BasicTokenType::RIGHT_PAREN) {
                if (poToken[iAdd].getType() == BasicTokenType::WORD) {
                    vstrParameter.push_back(poToken[iAdd].getText());
                    mpoLogger->debug("MacroProcessor::process", " [" + to_string(poToken->getLine()) + "] [" + to_string(poToken->getType()) + "]: Parameter: [" + poToken[iAdd].getText() + "]");
                };
            iAdd++;
            };
            
            mpoLogger->debug("MacroProcessor::process", " [" + to_string(poToken->getLine()) + "]: [" + to_string(poToken->getType()) + "]: [DEF " + strName + "]");

            int iCounter = iAdd;
            string strFunction = "no function";
            
            while (iCounter < voTokens.size()) {
                
                if (poToken[iCounter].getType() == BasicTokenType::STRING) {
                    strFunction = poToken[iCounter].getText();
                    break;
                } else {
                    iCounter++;
                }
            }
            
            mpoLogger->debug("MacroProcessor::process", " [" + to_string(poToken->getLine()) + "]: [" + to_string(poToken->getType()) + "]: Body: [" + strFunction + "]");

            poMacroList->add(strName, vstrParameter, strFunction);
            
            vstrParameter.clear();
        }
    }

    poMacroList->print();
    
    // Step 3: Run thru the source code again and find macro usage to replace it...
    // Convert the program into a list of lines
    mpoLogger->info("MacroProcessor::process", "Adjusting source code...");
    StringUtil oStringUtil;
    vector<string> vstrProgramLines = oStringUtil.split(strProgram,"\n");

    for (auto strProgramLine: vstrProgramLines) {
        string strStatus = "";

        string strWork = strProgramLine;
        transform(strWork.begin(), strWork.end(), strWork.begin(), ::toupper);
        
        if (strWork.find(" DEF ") != string::npos) {
            strConvertedProgram += strProgramLine + '\n';
            strStatus = "ignored: [DEF] found";
        } else
        if (poMacroList->containsMacro(strProgramLine).empty() == true) {
            strConvertedProgram += strProgramLine + '\n';
            strStatus = "ignored: no macro found";
        } else {
            string strConvertedLine = convertLine(strProgramLine, poMacroList);
            strConvertedProgram += strConvertedLine + '\n';
            strStatus = "code changed: [" + strConvertedLine + "]";
        }

        mpoLogger->debug("MacroProcessor::process", " Original line: [" + strProgramLine + "] " + strStatus);
    }
    
    delete mpoLexer;
    mpoLogger->info("MacroProcessor::process", "Processing completed...");
    return strConvertedProgram;
}

vector<Token> MacroProcessor::tokenize(string strProgramText) {
    mpoLogger->info("MacroProcessor::tokenize", "started...");
    vector<Token> voReturn = mpoLexer->tokenize(strProgramText);
    mpoLogger->info("MacroProcessor::tokenize", "completed...");
    return voReturn;
};

string MacroProcessor::convertLine(string strOriginal, MacroList *poMacroList) {
    string strWork = strOriginal;
    string strChanged = strOriginal;

    string strFoundMacro = poMacroList->containsMacro(strWork);
    while (strFoundMacro.empty() != false) {
        strChanged = strWork.substr(0, strWork.find_first_of(strFoundMacro));
        string strRest = strWork.substr(strWork.find_first_of(strFoundMacro) + strFoundMacro.length(), strWork.length());
        string strGetParameters = strRest.substr(strRest.find_first_of("(") + 1, strRest.find_first_of(")"));
// TO BE DELETED       String strGetMacroName = strRest.substring(0, strRest.indexOf("("));

        strChanged += poMacroList->getFunction(strGetParameters, strFoundMacro) + strRest.substr(strRest.find_first_of(")") + 1);

        strWork = strChanged;
        strFoundMacro = poMacroList->containsMacro(strChanged);
    }
    return strChanged;
}
