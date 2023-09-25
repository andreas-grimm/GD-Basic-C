//
//  assign_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 31/08/2023.
//

#ifndef assign_statement_hpp
#define assign_statement_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>

#include "../statements/statement.hpp"
#include "../statements/expression.hpp"
#include "../statements/variable_expression.hpp"

#include "../memoryManager/variable_management.hpp"
#include "../tokenizer/normalizer.hpp"
#include "../helper/string_util.hpp"

using namespace std;

class AssignStatement: public Statement {
    
public:
    AssignStatement(int iTokenNumber, string strName, Expression* poExpressin);
    AssignStatement(string strName, Expression* poExpression);
    
    int getTokenNumber();
    void execute();
    string content();
    
private:
    string mstrKey;
    Expression* mpoExpression;
    int miTokenNumber;
    VariableManagement* mpoVariableManagement = VariableManagement::getInstance();
};

#endif /* assign_statement_hpp */
