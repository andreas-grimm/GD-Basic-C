//
//  str.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef str_hpp
#define str_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/string_value.hpp"
#include "../helper/logger.hpp"

class Str {

public:
    static Value* execute(Value* poValue);

private:
    Str();
};

#endif /* str_hpp */
