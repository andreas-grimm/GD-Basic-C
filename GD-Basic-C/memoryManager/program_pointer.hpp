//
//  program_pointer.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 20/09/2023.
//

#ifndef program_pointer_hpp
#define program_pointer_hpp

#include <stdio.h>

class ProgramPointer {
public:
    static ProgramPointer* getInstance();

    void setCurrentStatement(int iCurrentStatement);
    int getCurrentStatement();
    void calcNextStatement();

private:
    static ProgramPointer* mpoProgramPointerInstance;

    ProgramPointer();
    ProgramPointer(const ProgramPointer&);
    ProgramPointer& operator=(const ProgramPointer&);

    int miCurrentStatement = 0;

};

#endif /* program_pointer_hpp */
