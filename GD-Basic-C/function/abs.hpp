//
//  abs.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 25/09/2023.
//

#ifndef abs_hpp
#define abs_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/long_value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../variableTypes/double_value.hpp"
#include "../helper/logger.hpp"

class Abs {

public:
    static Value* execute(Value* poValue);

private:
    Abs();
};

#endif /* abs_hpp */
