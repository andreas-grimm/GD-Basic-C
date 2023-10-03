//
//  mid.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef mid_hpp
#define mid_hpp

#include <stdio.h>

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/string_value.hpp"
#include "../function/len.hpp"
#include "../helper/logger.hpp"

class Mid {

public:
    static Value* execute(Value* poValue, Value* poStartPosition, Value* poEndPosition);

private:
    Mid();
};

#endif /* mid_hpp */
