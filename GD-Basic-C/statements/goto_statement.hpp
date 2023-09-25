//
//  goto_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 20/09/2023.
//

#ifndef goto_statement_hpp
#define goto_statement_hpp

#include <stdio.h>
#include <string>

#include "../statements/statement.hpp"
#include "../helper/logger.hpp"
#include "../memoryManager/program_pointer.hpp"
#include "../memoryManager/line_number_xref.hpp"
#include "../statements/label_statement.hpp"

using namespace std;

class GotoStatement: public Statement {

public:
    GotoStatement(string strTarget);
    GotoStatement(int iTokenNumber, string strTarget);
    
    int getTokenNumber();
    void execute();

    string content();

private:
    Logger *mpoLogger;

    string mstrTarget;
    int miTokenNumber;
    ProgramPointer* mpoProgramPointer = ProgramPointer::getInstance();
    LabelStatement* mpoLabelStatement = new LabelStatement();
    LineNumberXRef* mpoLineNumberObject = LineNumberXRef::getInstance();
};

#endif /* goto_statement_hpp */
