//
//  data_statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 28/08/2023.
//

#ifndef data_statement_hpp
#define data_statement_hpp

#include <stdio.h>
#include <vector>
#include "statement.hpp"
#include "../variableTypes/value.hpp"
#include "../memoryManager/fifo_queue.hpp"

using namespace std;

class DataStatement: public Statement {

public:
    DataStatement(int iTokenNumber, vector<Value*> voValues);
    
    int getTokenNumber();
    void execute();
    string content();

private:
    int miTokenNumber;
    vector<Value*> mvpoValues;
};

#endif /* data_statement_hpp */
