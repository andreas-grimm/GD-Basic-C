//
//  left.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef left_hpp
#define left_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/string_value.hpp"
#include "../function/len.hpp"
#include "../helper/logger.hpp"

class Left {

public:
    static Value* execute(Value* poValue, Value* poSearch);

private:
    Left();
};

#endif /* left_hpp */
