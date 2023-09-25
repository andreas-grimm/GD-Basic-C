//
//  trace.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/09/2023.
//

#ifndef trace_hpp
#define trace_hpp

#include <stdio.h>
#include <string>
#include "../helper/printer.hpp"
#include "../helper/color_schema.hpp"

using namespace std;

class Trace {

public:
    static Trace* getInstance();
    
    void trace(int iSourceLine);
    
private:
    static Trace* mpoTraceInstance;
    
    Trace();
    Trace(const Trace&);
    Trace& operator=(const Trace&);

    bool mbTraceLevel = false;
    int miLastLine = -1;
};

#endif /* trace_hpp */
