//
//  vector_util.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/09/2023.
//

#include "vector_util.hpp"

int VectorUtil::find_first(vector<Statement*> vpoStatements, Statement* poStatement) {
    int iIndex = 0;
    
    for (auto oIterStatement: vpoStatements) {
        if (oIterStatement->getTokenNumber() == poStatement->getTokenNumber()) {
            return iIndex;
        }
        
        iIndex++;
    }
    
    return -1;
};
