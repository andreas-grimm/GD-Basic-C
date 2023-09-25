//
//  basic_lexer.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 16/08/2023.
//

#include "basic_lexer.hpp"

BasicLexer::BasicLexer(string strLogLevel) {
    mstrLogLevel = strLogLevel;
    
    mpoLogger = Logger::getInstance();
    mpoLogger->setLogLevel(mstrLogLevel);
};

BasicLexer::~BasicLexer() {
};

vector<Token> BasicLexer::tokenize(string strSource) {
    mpoLogger->info("BasicLexer::tokenize", "started...");
    vector<Token> voTokens;
    vector<string> vstrProgramLines;
    Normalizer oNormalizer;
    StringUtil oUtil;
    
    // Convert the program into a list of lines
    mpoLogger->debug("BasicLexer::tokenize", "Split into Lines...");
    
    vstrProgramLines = oUtil.split(strSource, "\n");

    bool bIsStringRunning = false;
    int iLastLineNumber = -1;
    
    vector<string>::iterator poProgramLine = vstrProgramLines.begin();
    
    for ( ; poProgramLine < vstrProgramLines.end(); poProgramLine++) {
        Token *poToken = NULL;
        
        // split the line number from the program line... make sure that the numbers are in ascending order...
        int iLineNumber;

        if (poProgramLine->length() == 0) { // line is empty - we continue
            mpoLogger->debug("BasicLexer::tokenize", "Empty line found after line: " + to_string(iLastLineNumber));
            continue;
        } else if ((poProgramLine->find(" ", 0) < 0) ||
                   (poProgramLine->find(" ", 0) > poProgramLine->length())) { // no space found in line, so line only contains line number
            iLineNumber = stoi(*poProgramLine);
            *poProgramLine = "";
            mpoLogger->debug("BasicLexer::tokenize", "  --> only line number: " + to_string(iLineNumber) + ": `" + *poProgramLine + "`");
        } else { // isolate line number and the program line
            iLineNumber = stoi(poProgramLine->substr(0, poProgramLine->find(" ", 0)));
            *poProgramLine = poProgramLine->substr(poProgramLine->find(" ") + 1);
            mpoLogger->debug("BasicLexer::tokenize", "  --> split           : " + to_string(iLineNumber) + ": `" + *poProgramLine + "`");
        }
        
        // check whether the line number is smaller or equal to the previous number. If so - throw an syntax error
        if (iLineNumber <= iLastLineNumber) {
            mpoLogger->error("BasicLexer::tokenize", "Syntax Error: Line number sequence broken: `" + to_string(iLastLineNumber) + "` followed by `" + to_string(iLineNumber) + "`");
            exit(ERR_SYNTAX_ERROR);
        } else {
            iLastLineNumber = iLineNumber;
        }
        
        // here we handle all empty lines, e.g. lines that only contain the line number
        if (poProgramLine->length() < 1) {
            mpoLogger->info("BasicLexer::tokenize", "Ignore empty lines...");
            voTokens.push_back(Token("empty", BasicTokenType::LINE, iLineNumber));
            continue;
        } else { // normalize the line: put spaces in places where needed, or remove them
            *poProgramLine = oNormalizer.normalize(*poProgramLine);
            *poProgramLine = oNormalizer.normalizeFunction(*poProgramLine);

            // find reserved words: divide the string in an array of words
            mpoLogger->info("BasicLexer::tokenize", "Split by spaces...");
            mpoLogger->debug("BasicLexer::tokenize", "  --> to be split      : `" + *poProgramLine + "`");

            vector<string> vstrWords = split(*poProgramLine," ");
            
            // and iterate over them
            for (auto poWord = vstrWords.begin(); poWord < vstrWords.end(); poWord++) {

                // eliminate all empty strings
                if (poWord->length() <= 0) {
                    continue;
                }
                
                // this section verifies whether the next word is part of a string (as a string started but did not end yet)
                // if a string started (bIsStringRunning == true) then the word is added to the string, if the word contains
                // quotation marks ("), the string is closed.
                if (bIsStringRunning) {
                    if (poToken == NULL) {
                        mpoLogger->error("BasicLexer::tokenize", "Syntax Error: Unrecognized character sequence: `" + to_string(iLastLineNumber) + " " + *poProgramLine + "`");
                        exit(ERR_SYNTAX_ERROR);
                    }
                    mpoLogger->debug("BasicLexer::tokenize", " is string: " + *poWord);

                    // if the word ends with a ", then we stop any running string and remove the last character "
                    if (poWord->ends_with("\"")) {
                        *poWord = poWord->substr(0, poWord->length() -1);
                        bIsStringRunning = false;
                        poToken->setText(poToken->getText() + " " + *poWord);
                        voTokens.push_back(*poToken);
                    } else {
                        // add the word to the string in the token
                        poToken->setText(poToken->getText() + " " + *poWord);
                    }
                } else {        // ok - we know this is not part of a string.
                    // compare the word with the list of reserved words
                    int iIndex = oReservedWords.getIndex(*poWord);

                    if (iIndex != -1) {
                        mpoLogger->debug("BasicLexer::tokenize", "  --> found token      : '" + *poWord + "`");
                        // we found a reserved word...
                        BasicTokenType eTokenType = oReservedWords.getTokenType(iIndex);
                        
                        // this block handles all comments
                        if ((eTokenType == BasicTokenType::REM) ||
                            (eTokenType == BasicTokenType::COMMENT))  {
                            voTokens.push_back(Token(*poProgramLine, eTokenType, iLineNumber));
                            
                            break;
                        }
                        
                        poToken = new Token(*poWord, eTokenType, iLineNumber);
                        
                        // ok - this is not reserved word - so maybe it is a number?
                    }
                    else if (isNumber(*poWord) == true) {
                        mpoLogger->debug("BasicLexer::tokenize", " is number: " + *poWord);
                        poToken = new Token(*poWord, BasicTokenType::NUMBER, iLineNumber);
                        
                        // now check whether the word is marked as the beginning of a String
                    } else if (isString(*poWord)) {
                        mpoLogger->debug("BasicLexer::tokenize", " is string: " + *poWord);
                        *poWord = poWord->substr(1, poWord->length()); // remove the "
                        bIsStringRunning = true;

                        // this section handles single word strings
                        if (poWord->ends_with("\"")) {
                            *poWord = poWord->substr(0, poWord->length() - 1);
                            bIsStringRunning = false;
                            poToken = new Token(*poWord, BasicTokenType::STRING, iLineNumber);
                            voTokens.push_back(*poToken);
                        } else {
                            poToken = new Token(*poWord, BasicTokenType::STRING, iLineNumber);
                        }
                        
                        // now check whether the word is marked as a boolean
                    } else if (isBoolean(*poWord)) {
                        mpoLogger->debug("BasicLexer::tokenize", " is boolean: " + *poWord);

                        poToken = new Token(*poWord, BasicTokenType::BOOLEAN, iLineNumber);
                        
                    } else {
                        mpoLogger->debug("BasicLexer::tokenize", " is word: " + *poWord);
                        // as it is neither a number, string, or boolean - it has to be a variable / constant...
                        BasicTokenType eTokenType = BasicTokenType::WORD;
                        
                        poToken = new Token(*poWord, eTokenType, iLineNumber);
                    }
                    
                    if (poToken->getType() != BasicTokenType::STRING) { // Strings are added after they are completed.
                        voTokens.push_back(*poToken);
                    }
                };
            };
        };
    };
        
    for (auto poTokenIterator = voTokens.begin() ; poTokenIterator < voTokens.end(); poTokenIterator++) {
        BasicTokenTypeUtilities oTranslate;
        mpoLogger->debug("BasicLexer::tokenize", " [" + to_string(poTokenIterator->getLine()) + "]  ["
                              + oTranslate.to_string(poTokenIterator->getType()) + "]  ["
                              + poTokenIterator->getText() + "]");
    };

    mpoLogger->info("BasicLexer::tokenize", "completed...");

    return voTokens;
};

vector<string> BasicLexer::split(string strInputString, string strSplitToken) {
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

bool BasicLexer::isBoolean(string strString) {
    transform(strString.begin(), strString.end(), strString.begin(), ::toupper);
    
    if ((strString.compare("TRUE")) == YES) {
        return true;
    }
    
    if ((strString.compare("FALSE")) == YES) {
        return true;
    }
    
    return false;
};

bool BasicLexer::isNumber(string strString) {
    return ((!strString.empty()) &&
            (find_if(strString.begin(), strString.end(), [](unsigned char c) { return !std::isdigit(c); }) == strString.end()));
};

bool BasicLexer::isString(string strString) {
    return strString.starts_with("\"");
};
