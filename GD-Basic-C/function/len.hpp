//
//  len.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef len_hpp
#define len_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/string_value.hpp"
#include "../helper/logger.hpp"

class Len {

public:
    static Value* execute(Value* poValue);

private:
    Len();
};

#endif /* len_hpp */
