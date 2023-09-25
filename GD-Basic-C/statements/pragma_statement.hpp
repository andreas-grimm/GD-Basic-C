//
//  pragma_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/08/2023.
//

#ifndef pragma_statement_hpp
#define pragma_statement_hpp

#include <stdio.h>
#include <string>

#include "../statements/statement.hpp"

using namespace std;

class PragmaStatement: public Statement {
    
public:
    PragmaStatement(int iPragmaLineNumber, string strSetting, string strValue);
    void changeLogLevel(string strLogLevel);
    void changeTraceLevel(string strTraceLevel);
    
    int getTokenNumber();
    void execute();
    string content();
    
private:
    string mstrParameter;
    string mstrValue;
    int miTokenNumber;

};

#endif /* pragma_statement_hpp */
