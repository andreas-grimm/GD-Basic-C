//
//  if_then_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 20/09/2023.
//

#ifndef if_then_statement_hpp
#define if_then_statement_hpp

#include <stdio.h>
#include <string.h>

#include "../helper/logger.hpp"
#include "../helper/error_codes.hpp"

#include "../statements/statement.hpp"
#include "../statements/expression.hpp"
#include "../statements/label_statement.hpp"

#include "../memoryManager/program_pointer.hpp"
#include "../memoryManager/line_number_xref.hpp"
#include "../memoryManager/stack.hpp"

#include "../variableTypes/boolean_value.hpp"
#include "../variableTypes/integer_value.hpp"

using namespace std;


class IfThenStatement: public Statement {
    
public:
    IfThenStatement(Expression* poCondition, int iTokenNumber, int iELseStatement, int iEndIfLine, int iTargetLineNumber);

    int getTokenNumber();
    void execute();
    string content();
    
private:
    Logger* mpoLogger = Logger::getInstance();
    
    Expression* mpoCondition;
    string mstrLabel;
    int miTokenNumber = 0;
    int miTargetLineNumber = 0;
    int miElseStatement = 0;
    ProgramPointer* mpoProgramPointer = ProgramPointer::getInstance();
    LabelStatement* mpoLabelStatement;
    LineNumberXRef* mpoLineNumberObject = LineNumberXRef::getInstance();
    int miEndIfLine;

};

#endif /* if_then_statement_hpp */
