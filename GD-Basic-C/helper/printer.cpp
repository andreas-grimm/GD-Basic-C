//
//  printer.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#include "printer.hpp"

Printer::Printer() {
    mstrTarget = mstrDefault;
};

void Printer::println() {
    if (mstrTarget.compare(mstrDefault) == OK) {
        cout << "\n";
    };
};

void Printer::println(string strPrintLine) {
    if (mstrTarget.compare(mstrDefault) == OK) {
        cout << strPrintLine << "\n";
    }
};

void Printer::print(string strPrintLine) {
    if (mstrTarget.compare(mstrDefault) == OK) {
        cout << strPrintLine;
    }
};
