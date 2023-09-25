//
//  file_handler.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#include "file_handler.hpp"

FileHandler::FileHandler(){
    
};

int FileHandler::readFile(string strFileName, string* pstrFileContent) {
    int iReturn = OK;
    string strLine;
    ifstream oFileIn; // here the oFileIn is an input stream

    oFileIn.open (strFileName) ; // connecting oFileIn to file Input File
    if ( oFileIn.is_open () ) {
        while ( getline ( oFileIn , strLine ) ) {
            *pstrFileContent = pstrFileContent->append(strLine + '\n');
        }
        oFileIn.close () ;   // closing the file stream
    } else {
        iReturn = ERR_PROGRAM_FILE_NOT_READABLE;
    }
    
    return iReturn;
};

int FileHandler::writeFile(string strFileName, string strFileType, string* pstrFileContent) {
    return OK;
};
