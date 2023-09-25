//
//  reserved_words.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 17/08/2023.
//

#ifndef reserved_words_hpp
#define reserved_words_hpp

#include <string>
#include "../helper/common.hpp"
#include "basic_token_type.hpp"

using namespace std;

class ReservedWords {

public:
    ReservedWords();
    
    int getIndex(string strTokenType);
    BasicTokenType getTokenType(int iIndex);

private:
    string mastrReservedWords[101] = {
        "@PRAGMA", "ABS", "AND", "ASC", "ATN",
        "CALL", "CDBL", "CHR", "CINT", "CLEAN", "CLOSE", "CLS", "CMD", "CONT", "COS",
        "DATA", "DEF", "DIM", "DO",
        "ELSE", "END", "END-IF", "END-WHILE", "EOF", "EOL", "ERL", "ERR", "EXIT", "EXP",
        "FCLOSE", "FOPEN", "FOR", "FPRINT", "FREAD", "FREE",
        "GOSUB", "GOTO",
        "IF", "INSTR", "INPUT",
        "LEFT", "LEN", "LENGTH", "LET", "LOG", "LOG10",
        "MEM", "MID", "%",
        "NEXT", "NOT",
        "ON", "OPEN", "OR",
        "PRINT",
        "RANDOM", "READ", "REM", "RETURN", "RIGHT$", "RND",
        "SIN", "SQR", "STEP", "STOP", "STRING", "STR", "SYSTEM",
        "TAB", "TAN", "THEN", "TIME", "TO",
        "UNTIL",
        "VAL",
        "WHILE", "WRITE",
        "&&", "+", "-", "*", "/", ":",
        ">", ">=", "<", "<=", "=", ":=", "==", "!=", "^",
        "(", ")", "'", ";", ",", "||", "?",
//        "\\(", "\\)", "\\'", "\\;", "\\,", "||", "\\?",
        ">>", "<<",
};

    BasicTokenType maeTokenTypes[101] = {
        BasicTokenType::PRAGMA,
        BasicTokenType::ABS, BasicTokenType::AND, BasicTokenType::ASC, BasicTokenType::ATN,
        BasicTokenType::CALL, BasicTokenType::CDBL, BasicTokenType::CHR, BasicTokenType::CINT, BasicTokenType::CLEAN,
            BasicTokenType::CLOSE, BasicTokenType::CLS, BasicTokenType::CMD, BasicTokenType::CONT, BasicTokenType::COS,
        BasicTokenType::DATA, BasicTokenType::DEF, BasicTokenType::DIM, BasicTokenType::DO,
        BasicTokenType::ELSE, BasicTokenType::END, BasicTokenType::ENDIF, BasicTokenType::ENDWHILE, BasicTokenType::ENDOFFILE, BasicTokenType::EOL,
            BasicTokenType::ERL, BasicTokenType::ERR, BasicTokenType::EXIT, BasicTokenType::EXP,
        BasicTokenType::FCLOSE, BasicTokenType::FOPEN, BasicTokenType::FOR, BasicTokenType::FPRINT, BasicTokenType::FREAD,
            BasicTokenType::FREE,
        BasicTokenType::GOSUB, BasicTokenType::GOTO,
        BasicTokenType::IF, BasicTokenType::INSTR, BasicTokenType::INPUT,
        BasicTokenType::LEFT, BasicTokenType::LEN, BasicTokenType::LENGTH, BasicTokenType::LET, BasicTokenType::LOG, BasicTokenType::LOG10,
        BasicTokenType::MEM, BasicTokenType::MID, BasicTokenType::MODULO,
            BasicTokenType::NEXT, BasicTokenType::NOT,
        BasicTokenType::ON, BasicTokenType::OPEN, BasicTokenType::OR,
        BasicTokenType::PRINT,
        BasicTokenType::RANDOM, BasicTokenType::READ, BasicTokenType::REM, BasicTokenType::RETURN,
            BasicTokenType::RIGHT, BasicTokenType::RND,
        BasicTokenType::SIN, BasicTokenType::SQR, BasicTokenType::STEP, BasicTokenType::STOP, BasicTokenType::TOSTRING, BasicTokenType::STR,
            BasicTokenType::SYSTEM,
        BasicTokenType::TAB, BasicTokenType::TAN, BasicTokenType::THEN, BasicTokenType::TIME, BasicTokenType::TO,
        BasicTokenType::UNTIL,
        BasicTokenType::VAL,
        BasicTokenType::WHILE, BasicTokenType::WRITE,
        BasicTokenType::AND, BasicTokenType::PLUS, BasicTokenType::MINUS, BasicTokenType::MULTIPLY, BasicTokenType::DIVIDE,
            BasicTokenType::COLON,
        BasicTokenType::GREATER, BasicTokenType::GREATER_EQUAL, BasicTokenType::SMALLER, BasicTokenType::SMALLER_EQUAL, BasicTokenType::ASSIGN_EQUAL,
            BasicTokenType::PASCAL_ASSIGN_EQUAL, BasicTokenType::COMPARE_EQUAL, BasicTokenType::COMPARE_NOT_EQUAL, BasicTokenType::POWER,
        BasicTokenType::LEFT_PAREN, BasicTokenType::RIGHT_PAREN, BasicTokenType::COMMENT, BasicTokenType::SEMICOLON,
            BasicTokenType::COMMA, BasicTokenType::OR, BasicTokenType::PRINT,
        BasicTokenType::SHIFT_RIGHT, BasicTokenType::SHIFT_LEFT,};
};

#endif /* reserved_words_hpp */
