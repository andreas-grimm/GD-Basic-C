//
//  basic_parser.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 24/08/2023.
//

#ifndef basic_parser_hpp
#define basic_parser_hpp

#include <stdio.h>
#include <vector>
#include "common.hpp"
#include "../helper/logger.hpp"
#include "../helper/string_util.hpp"
#include "../helper/vector_util.hpp"
#include "../tokenizer/token.hpp"
#include "../tokenizer/basic_token_type_util.hpp"
#include "../statements/statement.hpp"
#include "../memoryManager/line_number_xref.hpp"
#include "../variableTypes/value.hpp"
#include "../variableTypes/string_value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../variableTypes/double_value.hpp"

#include "../statements/data_statement.hpp"
#include "../statements/label_statement.hpp"
#include "../statements/pragma_statement.hpp"
#include "../statements/rem_statement.hpp"

#include "../statements/expression.hpp"
#include "../statements/string_expressions.hpp"
#include "../statements/real_expression.hpp"
#include "../statements/operator_expression.hpp"
#include "../statements/print_statement.hpp"
#include "../statements/assign_statement.hpp"
#include "../statements/goto_statement.hpp"
#include "../statements/if_then_statement.hpp"
#include "../statements/end_statement.hpp"
#include "../statements/else_statement.hpp"
#include "../statements/colon_statement.hpp"

#include "../function/function.hpp"

using namespace std;

class BasicParser {
    
public:
    BasicParser(string strLogLevel);
    ~BasicParser();
    
    void setTokens(vector<Token> voToken);
    
    vector<Statement*> parsePreRun();
    vector<Statement*> parse();
    
private:
    Logger *mpoLogger;
    string mstrLogLevel;
    
    vector<Token> mvoTokens;
    LineNumberXRef* mpoLineNumber;
    
    Token getToken(int iPosition, int iOffset);
    Token findToken(int iPosition, BasicTokenType eType);
    Token consumeToken(int iPosition, BasicTokenType eType);
    
    Expression* expression(int* iPosition);
    Expression* operate(int* iPosition);
    Expression* atomic(int* iPosition);
};
    
#endif /* basic_parser_hpp */
