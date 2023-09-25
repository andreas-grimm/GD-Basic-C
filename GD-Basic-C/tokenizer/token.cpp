//
//  token.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 16/08/2023.
//

#include "token.hpp"

Token::Token () {
};

Token::Token (string strText, BasicTokenType eType, int iLineNumber) {
    mstrText = strText;
    meType = eType;
    miLineNumber = iLineNumber;
    mbEmptyToken = false;
};

Token::Token (string strText, BasicTokenType eType, int iLineNumber, int iCommandSequenceNumber) {
    mstrText = strText;
    meType = eType;
    miLineNumber = iLineNumber;
    miCommandSequenceNumber = iCommandSequenceNumber;
    mbEmptyToken = false;
};

string Token::getText() {
    return mstrText;
};

BasicTokenType Token::getType() {
    return meType;
};

int Token::getLine() {
    return miLineNumber;
};

int Token::getCommandSequence() {
    return miCommandSequenceNumber;
};

string Token::setText(string strText) {
    mstrText = strText;
    
    return mstrText;
};

bool Token::isTokenEmpty() {
    return mbEmptyToken;
}

void Token::setTokenEmpty() {
    mbEmptyToken = true;
}
