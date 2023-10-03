//
//  val.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef val_hpp
#define val_hpp

#include <stdio.h>
#include <math.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/long_value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../variableTypes/double_value.hpp"
#include "../helper/logger.hpp"

class Val {

public:
    static Value* execute(Value* poValue);

private:
    Val();
};

#endif /* val_hpp */
