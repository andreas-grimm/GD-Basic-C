//
//  command_line.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#include "command_line.hpp"
#include <getopt.h>

CommandLine::CommandLine(int iArgc, char *astrArgV[]) {
    miInputFile = NO;
    miQuiet = NO;
    miLogLevel = NO;
    miHelp = NO;
    
    for(;;) {
        switch(getopt(iArgc, astrArgV, "i:ql:h")) // note the colon (:) to indicate that 'i' and 'l' has a parameter and is not a switch
        {
            case 'i':
                miInputFile = YES;
                mstrInputFile = optarg;
                continue;
                
            case 'q':
                miQuiet = YES;
                continue;
                
            case 'l':
                miLogLevel = YES;
                mstrLogLevel = optarg;
                continue;

            case '?':
                miHelp = YES;
                continue;
                
            case 'h':
            default :
                miHelp = YES;
                break;
        };
        
        break;
    };
};

int CommandLine::containsHelp() {
    return miHelp;
};

int CommandLine::containsInputFile() {
    return miInputFile;
};

int CommandLine::containsQuiet() {
    return miQuiet;
};

int CommandLine::containsLogLevel() {
    return miLogLevel;
};

string CommandLine::getInputFile() {
    return mstrInputFile;
}

string CommandLine::getLogLevel() {
    return mstrLogLevel;
}
