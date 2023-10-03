//
//  cdbl.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/09/2023.
//

#ifndef cdbl_hpp
#define cdbl_hpp

#include <stdio.h>
#include <math.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/long_value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../variableTypes/double_value.hpp"
#include "../helper/logger.hpp"

class Cdbl {

public:
    static Value* execute(Value* poValue);

private:
    Cdbl();
};

#endif /* cdbl_hpp */
