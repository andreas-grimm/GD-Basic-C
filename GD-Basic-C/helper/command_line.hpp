//
//  command_line.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#ifndef command_line_hpp
#define command_line_hpp

#include <stdio.h>
#include <string>
#include "common.hpp"

using namespace std;

class CommandLine {
public:
    CommandLine(int iArgc, char *astrArgV[]);
    
    int containsHelp();
    int containsInputFile();
    int containsQuiet();
    int containsLogLevel();
    
    
    string getInputFile();
    string getLogLevel();
    
private:
    int miHelp;
    int miInputFile;
    int miQuiet;
    int miLogLevel;
    string mstrInputFile;
    string mstrLogLevel;
};

#endif /* command_line_hpp */
