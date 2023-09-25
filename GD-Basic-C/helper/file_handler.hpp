//
//  file_handler.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#ifndef file_handler_hpp
#define file_handler_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

#include "common.hpp"
#include "error_codes.hpp"


using namespace std;

class FileHandler {
public:
    FileHandler();
    
    int readFile(string strFileName, string* pstrFileContent);
    int writeFile(string strFileName, string strFileType, string* pstrFileContent);
};

#endif /* file_handler_hpp */
