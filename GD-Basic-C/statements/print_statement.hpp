//
//  print_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 30/08/2023.
//

#ifndef print_statement_hpp
#define print_statement_hpp

#include <stdio.h>
#include <iostream>
#include <string>

#include "../statements/statement.hpp"
#include "../statements/expression.hpp"

using namespace std;

class PrintStatement: public Statement {

public:
    PrintStatement(Expression* oExpression);
    PrintStatement(int iTokenNumber, vector<Expression*> aoExpression, bool bCRLF);
    
    int getTokenNumber();
    void execute();
    string content();
    
private:
    Expression* mpoExpression;
    int miTokenNumber;
    vector<Expression*> mvpoExpression;
    bool mbCRLF;
};

#endif /* print_statement_hpp */
