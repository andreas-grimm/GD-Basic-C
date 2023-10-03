//
//  atn.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 27/09/2023.
//

#ifndef atn_hpp
#define atn_hpp

#include <stdio.h>
#include <math.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/long_value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../variableTypes/double_value.hpp"
#include "../helper/logger.hpp"

class Atn {

public:
    static Value* execute(Value* poValue);

private:
    Atn();
};


#endif /* atn_hpp */
