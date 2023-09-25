//
//  error_codes.h
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#ifndef error_codes_h
#define error_codes_h

// Error Codes
#define ERR_NO_ERR_OK                   0

#define ERR_MISSING_PROGRAM_FILE        2
#define ERR_PROGRAM_FILE_NOT_READABLE   3

#define ERR_SYNTAX_ERROR                4
#define ERR_NUMBER_OVERFLOW             5
#define ERR_DIVISION_BY_ZERO            6
#define ERR_UNEXPECTED_TYPE             7
#define ERR_INCORRECT_OPERATOR          8
#define ERR_UNDEFINED_VALUE             9
#define ERR_UNDEFINED_EXPRESSION        10
#define ERR_UNDEFINED_STATEMENT         11
#define ERR_UNDEFINED_VARIABLE          12
#define ERR_PARENTHESIS_INCORRECT       13
#define ERR_OUT_OF_BOUNDS               14
#define ERR_UNKNOWN_OPERATOR            15
#define ERR_GOTO_UNKNOWN_TARGET         16
#define ERR_UNKNOWN_IF_STMT             17
#define ERR_EMPTY_STACK                 18
#define ERR_UNDEF_JMP_TARGET            19

// Interpreter coding error
#define ERR_UNCOVERED_MANDATORY_CLASS   40001
#define ERR_MEM_TOKEN_NOT_FOUND         40002
#define ERR_MEM_STMT_NOT_FOUND          40003
#define ERR_MEM_LINE_NOT_FOUND          40004
#define ERR_PARSE_EMPTY_PROGRAM         40005

// Warnings


#endif /* error_codes_h */
