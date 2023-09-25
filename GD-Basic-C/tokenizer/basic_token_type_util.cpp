//
//  basic_token_type_util.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 22/08/2023.
//

#include "basic_token_type_util.hpp"

string BasicTokenTypeUtilities::to_string(BasicTokenType eTokenType) {
    switch (eTokenType)
    {
        case BasicTokenType::ABS:                   return "ABS";
        case BasicTokenType::AND:                   return "AND";
        case BasicTokenType::ASC:                   return "ASC";
        case BasicTokenType::ATN:                   return "ATN";
        case BasicTokenType::CALL:                  return "CALL";
        case BasicTokenType::CDBL:                  return "CDBL";
        case BasicTokenType::CHR:                   return "CHR";
        case BasicTokenType::CINT:                  return "CINT";
        case BasicTokenType::CLEAN:                 return "CLEAN";
        case BasicTokenType::CLOSE:                 return "CLOSE";
        case BasicTokenType::CLS:                   return "CLS";
        case BasicTokenType::CMD:                   return "CMD";
        case BasicTokenType::CONT:                  return "CONT";
        case BasicTokenType::COS:                   return "COS";
        case BasicTokenType::DATA:                  return "DATA";
        case BasicTokenType::DEF:                   return "DEF";
        case BasicTokenType::DIM:                   return "DIM";
        case BasicTokenType::DO:                    return "DO";
        case BasicTokenType::ELSE:                  return "ELSE";
        case BasicTokenType::END:                   return "END";
        case BasicTokenType::ENDIF:                 return "ENDIF";
        case BasicTokenType::ENDWHILE:              return "ENDWHILE";
        case BasicTokenType::ENDOFFILE:             return "ENDOFFILE";
        case BasicTokenType::EOL:                   return "EOL";
        case BasicTokenType::EOP:                   return "EOP";
        case BasicTokenType::ERL:                   return "ERL";
        case BasicTokenType::ERR:                   return "ERR";
        case BasicTokenType::EXIT:                  return "EXIT";
        case BasicTokenType::EXP:                   return "EXP";
        case BasicTokenType::FCLOSE:                return "FCLOSE";
        case BasicTokenType::FOPEN:                 return "FOPEN";
        case BasicTokenType::FOR:                   return "FOR";
        case BasicTokenType::FPRINT:                return "FPRINT";
        case BasicTokenType::FREAD:                 return "FREAD";
        case BasicTokenType::FREE:                  return "FREE";
        case BasicTokenType::GOSUB:                 return "GOSUB";
        case BasicTokenType::GOTO:                  return "GOTO";
        case BasicTokenType::IF:                    return "IF";
        case BasicTokenType::INSTR:                 return "INSTR";
        case BasicTokenType::INPUT:                 return "INPUT";
        case BasicTokenType::LEFT:                  return "LEFT";
        case BasicTokenType::LEN:                   return "LEN";
        case BasicTokenType::LENGTH:                return "LENGTH";
        case BasicTokenType::LET:                   return "LET";
        case BasicTokenType::LOG:                   return "LOG";
        case BasicTokenType::LOG10:                 return "LOG10";
        case BasicTokenType::MEM:                   return "MEM";
        case BasicTokenType::MID:                   return "MID"; // token for the MID$ function
        case BasicTokenType::MODULO:                return "MODULO"; // token for the % operation
        case BasicTokenType::NEXT:                  return "NEXT";
        case BasicTokenType::NOT:                   return "NOT";
        case BasicTokenType::ON:                    return "ON";
        case BasicTokenType::OPEN:                  return "OPEN";
        case BasicTokenType::OR:                    return "OR";
        case BasicTokenType::PRAGMA:                return "PRAGMA";
        case BasicTokenType::PRINT:                 return "PRINT";
        case BasicTokenType::RANDOM:                return "RANDOM";
        case BasicTokenType::READ:                  return "READ";
        case BasicTokenType::REM:                   return "REM";
        case BasicTokenType::RETURN:                return "RETURN";
        case BasicTokenType::RIGHT:                 return "RIGHT";
        case BasicTokenType::RND:                   return "RND";
        case BasicTokenType::SIN:                   return "SIN";
        case BasicTokenType::SQR:                   return "SQR";
        case BasicTokenType::STEP:                  return "STEP";
        case BasicTokenType::STOP:                  return "STOP";
        case BasicTokenType::TOSTRING:              return "TOSTRING"; // token for the STRING$ function
        case BasicTokenType::STR:                   return "STR"; // token for the STR$ function
        case BasicTokenType::SYSTEM:                return "SYSTEM";
        case BasicTokenType::TAB:                   return "TAB";
        case BasicTokenType::TAN:                   return "TAN";
        case BasicTokenType::THEN:                  return "THEN";
        case BasicTokenType::TIME:                  return "TIME"; // token for the TIME$ function
        case BasicTokenType::TO:                    return "TO";
        case BasicTokenType::UNTIL:                 return "UNTIL";
        case BasicTokenType::VAL:                   return "VAL";
        case BasicTokenType::WHILE:                 return "WHILE";
        case BasicTokenType::WRITE:                 return "WRITE";
        case BasicTokenType::PLUS:                  return "PLUS";
        case BasicTokenType::MINUS:                 return "MINUS";
        case BasicTokenType::MULTIPLY:              return "MULTIPLY";
        case BasicTokenType::DIVIDE:                return "DIVIDE";
        case BasicTokenType::SHIFT_LEFT:            return "SHIFT_LEFT";
        case BasicTokenType::SHIFT_RIGHT:           return "SHIFT_RIGHT";
        case BasicTokenType::COLON:                 return "COLON";
        case BasicTokenType::GREATER:               return "GREATER";
        case BasicTokenType::GREATER_EQUAL:         return "GREATER_EQUAL";
        case BasicTokenType::SMALLER:               return "SMALLER";
        case BasicTokenType::SMALLER_EQUAL:         return "SMALLER_EQUAL";
        case BasicTokenType::ASSIGN_EQUAL:          return "ASSIGN_EQUAL";
        case BasicTokenType::PASCAL_ASSIGN_EQUAL:   return "PASCAL_ASSIGN_EQUAL";
        case BasicTokenType::COMPARE_EQUAL:         return "COMPARE_EQUAL";
        case BasicTokenType::COMPARE_NOT_EQUAL:     return "COMPARE_NOT_EQUAL";
        case BasicTokenType::POWER:                 return "POWER";
        case BasicTokenType::LEFT_PAREN:            return "LEFT_PAREN";
        case BasicTokenType::RIGHT_PAREN:           return "RIGHT_PAREN";
        case BasicTokenType::COMMENT:               return "COMMENT";
        case BasicTokenType::WORD:                  return "WORD";
        case BasicTokenType::NUMBER:                return "NUMBER";
        case BasicTokenType::STRING:                return "STRING";
        case BasicTokenType::INTEGER:               return "INTEGER";
        case BasicTokenType::BOOLEAN:               return "BOOLEAN";
        case BasicTokenType::OPERATOR:              return "OPERATOR";
        case BasicTokenType::LABEL:                 return "LABEL";
        case BasicTokenType::LINE:                  return "LINE";
        case BasicTokenType::EQUALS:                return "EQUALS";
        case BasicTokenType::COMMA:                 return "COMMA";
        case BasicTokenType::SEMICOLON:             return "SEMICOLON";
        case BasicTokenType::NUL:                   return "NULL";
        default:      return "unknown";
    }
}
