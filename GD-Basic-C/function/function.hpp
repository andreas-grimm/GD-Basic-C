//
//  function.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 25/09/2023.
//

#ifndef function_hpp
#define function_hpp

#include <stdio.h>
#include <string>

#include "../statements/expression.hpp"
#include "../tokenizer/token.hpp"
#include "../variableTypes/value.hpp"
#include "../helper/logger.hpp"
#include "../helper/error_codes.hpp"
#include "../tokenizer/basic_token_type_util.hpp"

#include "../function/abs.hpp"
#include "../function/asc.hpp"
#include "../function/atn.hpp"
#include "../function/cdbl.hpp"
#include "../function/chr.hpp"
#include "../function/cint.hpp"
#include "../function/cos.hpp"
#include "../function/exp.hpp"
#include "../function/instr.hpp"
#include "../function/left.hpp"
#include "../function/len.hpp"
#include "../function/log.hpp"
#include "../function/log10.hpp"
#include "../function/mem.hpp"
#include "../function/mid.hpp"
#include "../function/right.hpp"
#include "../function/rnd.hpp"
#include "../function/sin.hpp"
#include "../function/sqr.hpp"
#include "../function/str.hpp"
#include "../function/system_func.hpp"
#include "../function/tan.hpp"
#include "../function/val.hpp"

using namespace std;

class Function: public Expression {

public:
    Function(Token oToken);
    Function(Token oToken, Expression* poExpression);
    Function(Token oToken, Expression* poFirstParam, Expression* poSecondParam);
    Function(Token oToken, Expression* poFirstParam, Expression* poSecondParam, Expression* oThirdParam);
    
    Value* evaluate();
    string content();
    
private:
    Token moToken;
    Expression* mpoFirstParam;
    Expression* mpoSecondParam;
    Expression* mpoThirdParam;
    
    Logger* mpoLogger = Logger::getInstance();
};

#endif /* function_hpp */
