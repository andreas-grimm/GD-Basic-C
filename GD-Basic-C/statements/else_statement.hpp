//
//  else_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/09/2023.
//

#ifndef else_statement_hpp
#define else_statement_hpp

#include <stdio.h>
#include <string>

#include "../memoryManager/program_pointer.hpp"
#include "../memoryManager/stack.hpp"
#include "../statements/statement.hpp"

#include "../variableTypes/integer_value.hpp"

#include "../helper/logger.hpp"
#include "../helper/error_codes.hpp"

using namespace std;

class ElseStatement: public Statement {

public:
    ElseStatement(int iTokenNumber);
    int getTokenNumber();
    void execute();
    string content();

private:
    Logger* mpoLogger;
    ProgramPointer* mpoProgramPointer;
    int miTokenNumber;
};

#endif /* else_statement_hpp */
