//
//  statement.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 24/08/2023.
//

#ifndef statement_hpp
#define statement_hpp

#include <stdio.h>
#include <string>

#include "../helper/error_codes.hpp"

using namespace std;

class Statement {

public:
    Statement();
    
    virtual int getTokenNumber() = 0;
    virtual void execute() = 0;
    virtual string content() = 0;
};

#endif /* statement_hpp */
