//
//  token.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 16/08/2023.
//

#ifndef token_hpp
#define token_hpp

#include <stdio.h>

#include "../helper/common.hpp"
#include "../helper/logger.hpp"
#include "basic_token_type.hpp"

using namespace std;

class Token {
public:
    Token ();
    Token (string strText, BasicTokenType eType, int iLineNumber);
    Token (string strText, BasicTokenType eType, int iLineNumber, int miCommandSequenceNumber);

    string getText();
    BasicTokenType getType();
    int getLine();
    int getCommandSequence();
    
    string setText(string strText);
    
    bool isTokenEmpty();
    void setTokenEmpty();
    
private:
    string mstrText;
    BasicTokenType meType;
    int miLineNumber;
    int miCommandSequenceNumber;
    bool mbEmptyToken;
};

#endif /* token_hpp */
