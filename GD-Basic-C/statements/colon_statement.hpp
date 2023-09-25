//
//  colon_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/09/2023.
//

#ifndef colon_statement_hpp
#define colon_statement_hpp

#include <stdio.h>
#include <string>

#include "../statements/statement.hpp"

class ColonStatement: public Statement {
public:
    ColonStatement(int iTokenNumber);

    int getTokenNumber();
    void execute();
    string content();

private:
    int miTokenNumber;

};

#endif /* colon_statement_hpp */
