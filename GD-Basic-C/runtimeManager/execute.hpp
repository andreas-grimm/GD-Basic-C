//
//  Execute.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/09/2023.
//

#ifndef Execute_hpp
#define Execute_hpp

#include <stdio.h>
#include <vector>

#include "../helper/logger.hpp"
#include "../helper/trace.hpp"
#include "../helper/error_codes.hpp"
#include "../memoryManager/line_number_xref.hpp"
#include "../memoryManager/program_pointer.hpp"
#include "../memoryManager/program.hpp"

#include "../statements/statement.hpp"

class Execute {

public:
    Execute(Program* poProgram);
    void loadEnvironment();
    void runProgram();
    
private:
    Logger* mpoLogger = Logger::getInstance();
    LineNumberXRef* mpoLineNumbers = LineNumberXRef::getInstance();
    ProgramPointer* mpoProgramPointer = ProgramPointer::getInstance();
    
    vector<Statement*> mvpoPreRunStatements;
    vector<Statement*> mvpoStatements;
    
    Trace* mpoTrace;

};
#endif /* Execute_hpp */
