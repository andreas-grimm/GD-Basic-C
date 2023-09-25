//
//  line_number_xref.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 24/08/2023.
//

#ifndef line_number_xref_hpp
#define line_number_xref_hpp

#include <stdio.h>
#include <map>

#include "common.hpp"
#include "../helper/logger.hpp"
#include "../helper/error_codes.hpp"

using namespace std;

class LineNumberXRef {
public:
    static LineNumberXRef* getInstance();
    
    void setLogLevel(string strLogLevel);
    void putLineNumber(int iLineNumber, int iTokenNumber);
    void putStatementNumber(int iTokenNumber, int iStatementNumber);

    int getNextLineNumber(int iLineNumber);
    int getStatementFromToken(int iTokenNumber);
    int getStatementFromLineNumber(int iLineNumber);
    int getTokenFromStatement(int iStatement);
    int getLineNumberFromToken(int iTokenNumber);

    void list();
    bool contains(int iTokenNumber);
    
private:
    static LineNumberXRef* mpoLineNumberXRefInstance;
    LineNumberXRef();
    LineNumberXRef(const LineNumberXRef&);
    LineNumberXRef& operator=(const LineNumberXRef&);
    
    string mstrLogLevel;
    Logger* mpoLogger = Logger::getInstance();
    
    map<int, int> mmiiLineNumbers; // _aoLineNumbers
    map<int, int> mmiiStatementNumbers; // _aoStatementNumbers

};

#endif /* line_number_xref_hpp */
