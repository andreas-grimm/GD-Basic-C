//
//  exp.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/09/2023.
//

#ifndef exp_hpp
#define exp_hpp

#include <stdio.h>
#include <math.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/long_value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../variableTypes/double_value.hpp"
#include "../helper/logger.hpp"

class Exp {

public:
    static Value* execute(Value* poValue);

private:
    Exp();
};

#endif /* exp_hpp */
