//
//  rem_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 30/08/2023.
//

#ifndef rem_statement_hpp
#define rem_statement_hpp

#include <stdio.h>
#include <string>

using namespace std;

#include "statement.hpp"

class RemStatement: public Statement {
public:
    RemStatement(int iTokenNumber, string strRemText);
    
    int getTokenNumber();
    void execute();
    string content();
    
private:
    int miTokenNumber;
    string mstrRemText;

};

#endif /* rem_statement_hpp */
