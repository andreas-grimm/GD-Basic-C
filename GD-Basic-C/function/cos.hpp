//
//  cos.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/09/2023.
//

#ifndef cos_hpp
#define cos_hpp

#include <stdio.h>
#include <math.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/long_value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../variableTypes/double_value.hpp"
#include "../helper/logger.hpp"

class Cos {

public:
    static Value* execute(Value* poValue);

private:
    Cos();
};
#endif /* cos_hpp */
