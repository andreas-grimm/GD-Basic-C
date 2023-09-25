//
//  label_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/08/2023.
//

#ifndef label_statement_hpp
#define label_statement_hpp

#include <stdio.h>
#include <string>
#include <map>

#include "statement.hpp"

using namespace std;

class LabelStatement: public Statement {
    
public:
    LabelStatement();
    void putLabelStatement(string strLabel, int iStatementNumber);
    int getLabelStatement(string strLabel);
    bool containsLabelKey(string strKey);
    int getTokenNumber();
    void execute();
    string content();

    
private:
    map<string, int> mmstriLabels;

};

#endif /* label_statement_hpp */
