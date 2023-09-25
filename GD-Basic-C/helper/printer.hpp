//
//  printer.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#ifndef printer_hpp
#define printer_hpp

#include <stdio.h>
#include <string>
#include <iostream>

#include "common.hpp"

using namespace std;

class Printer {
public:
    Printer();
    
    void println();
    void println(string strPrintLine);
    
    void print(string strPrintLine);
    
private:
    const string mstrDefault = "console";
    string mstrTarget;
};

#endif /* printer_hpp */
