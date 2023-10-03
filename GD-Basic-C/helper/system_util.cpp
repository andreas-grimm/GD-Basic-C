//
//  system_util.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#include "system_util.hpp"

SystemUtil::SystemUtil() {
}

string SystemUtil::exec(string strCommand) {
    const char* cCommand = strCommand.c_str();
    char acBuffer[2048];
    string strResult = "";
    
    FILE* fPipe = popen(cCommand, "r");
    
    if (!fPipe) throw std::runtime_error("popen() failed!");
    
    try {
        while (fgets(acBuffer, sizeof acBuffer, fPipe) != NULL) {
            strResult += acBuffer;
        }
    } catch (...) {
        pclose(fPipe);
        throw;
    }
    
    pclose(fPipe);
    return strResult;
}
