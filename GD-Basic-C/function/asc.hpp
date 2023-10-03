//
//  asc.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 27/09/2023.
//

#ifndef asc_hpp
#define asc_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/long_value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../variableTypes/double_value.hpp"
#include "../helper/logger.hpp"

class Asc {

public:
    static Value* execute(Value* poValue);

private:
    Asc();
};

#endif /* asc_hpp */
