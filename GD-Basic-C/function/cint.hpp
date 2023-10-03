//
//  cint.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/09/2023.
//

#ifndef cint_hpp
#define cint_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/long_value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../variableTypes/double_value.hpp"
#include "../helper/logger.hpp"

class Cint {

public:
    static Value* execute(Value* poValue);

private:
    Cint();
};

#endif /* cint_hpp */
