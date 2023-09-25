//
//  vector_util.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 21/09/2023.
//

#ifndef vector_util_hpp
#define vector_util_hpp

#include <stdio.h>
#include <vector>

#include "../statements/statement.hpp"

class VectorUtil {
public:
    static int find_first(vector<Statement*> vpoStatements, Statement* poStatement);
};

#endif /* vector_util_hpp */
