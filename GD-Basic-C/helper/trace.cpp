//
//  trace.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/09/2023.
//

#include "trace.hpp"

Trace* Trace::mpoTraceInstance = NULL;

/**
 * Constructor of the Logger class.
 */
Trace::Trace() {
}


Trace* Trace::getInstance() {
    if (mpoTraceInstance == NULL) {
        mpoTraceInstance = new Trace();
    }
    
    return mpoTraceInstance;
}


/**
* Prints the line number of the BASIC command.
*
* @param iSourceLine - BASIC line number to be printed
*/
void Trace::trace(int iSourceLine) {
    Printer oPrinter;

    if (mbTraceLevel && iSourceLine != miLastLine) {
        string strOutput;
        
        strOutput = YELLOW + to_string(iSourceLine) + " " + RESET;
        oPrinter.println(strOutput);
        miLastLine = iSourceLine;
    }
}

