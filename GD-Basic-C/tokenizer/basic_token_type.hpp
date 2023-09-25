//
//  basic_token_types.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 16/08/2023.
//

#ifndef basic_token_type_hpp
#define basic_token_type_hpp

enum BasicTokenType {
    ABS,
    AND,
    ASC,
    ATN,
    CALL,
    CDBL,
    CHR, // token for the CHR$ function
    CINT,
    CLEAN,
    CLOSE,
    CLS,
    CMD,
    CONT,
    COS,
    DATA,
    DEF,
    DIM,
    DO,
    ELSE,
    END,
    ENDIF,
    ENDWHILE,
    ENDOFFILE,
    EOL,
    EOP,
    ERL,
    ERR,
    EXIT,
    EXP,
    FCLOSE,
    FOPEN,
    FOR,
    FPRINT,
    FREAD,
    FREE,
    GOSUB,
    GOTO,
    IF,
    INSTR,
    INPUT,
    LEFT, // token for the LEFT$ function
    LEN,
    LENGTH,
    LET,
    LOG,
    LOG10,
    MEM,
    MID, // token for the MID$ function
    MODULO, // token for the % operation
    NEXT,
    NOT,
    ON,
    OPEN,
    OR,
    PRAGMA,
    PRINT,
    RANDOM,
    READ,
    REM,
    RETURN,
    RIGHT, //token for the RIGHT$ function
    RND,
    SIN,
    SQR,
    STEP,
    STOP,
    TOSTRING, // token for the STRING$ function
    STR, // token for the STR$ function
    SYSTEM,
    TAB,
    TAN,
    THEN,
    TIME, // token for the TIME$ function
    TO,
    UNTIL,
    VAL,
    WHILE,
    WRITE,
    PLUS, // token for the + operator
    MINUS, // token for the - operator
    MULTIPLY, // token for the * operator
    DIVIDE, // token for the / operator
    SHIFT_LEFT, // shift a number / bytes to the left (multiply by 2)
    SHIFT_RIGHT, // shift a number / bytes to the right (divide by 2)
    COLON, // token for the program line divider ':'
    GREATER, // token for the > operator
    GREATER_EQUAL, // token for the => operator
    SMALLER, // token for the < operator
    SMALLER_EQUAL, // token for the <= operator
    ASSIGN_EQUAL, // token for the assignment operator =
    PASCAL_ASSIGN_EQUAL, // token for the PASCAL assignment operator :=
    COMPARE_EQUAL, // token for the == operator
    COMPARE_NOT_EQUAL, // token for the != operator
    POWER, // token for the power operator
    LEFT_PAREN, // token for the ( symbol
    RIGHT_PAREN, // token for the ) symbol
    COMMENT, // to be replaced by REM
    WORD, // super-token to cover command and functions in JASIC
    NUMBER, // Token for any real values
    STRING, // Token for any strings
    INTEGER, // Token for any integer numbers
    BOOLEAN, // Token for any boolean variable
    OPERATOR, // super-token to cover all operations in JASIC
    LABEL, // JASIC GOTO label, not supported for the Dartmouth BASIC dialects
    LINE, // empty line - white space. Kept to keep the line numbering consistent
    EQUALS, // used exclusively for the JASIC version
    COMMA, // used exclusively for the print command
    SEMICOLON, // used exclusively for the print command
    NUL // empty token, not to be used
};

#endif /* basic_token_type_hpp */
