//
//  end_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 20/09/2023.
//

#ifndef end_statement_hpp
#define end_statement_hpp

#include <stdio.h>
#include <string>

#include "../helper/error_codes.hpp"
#include "../statements/statement.hpp"

using namespace std;


class EndStatement: public Statement {
public:
    EndStatement();
    EndStatement(int iTokenNumber);

    int getTokenNumber();

    void execute();

    string content();
    
private:
    int miTokenNumber;
};

#endif /* end_statement_hpp */
