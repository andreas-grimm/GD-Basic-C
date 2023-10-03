//
//  log10.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef log10_hpp
#define log10_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../helper/logger.hpp"

class Log10 {

public:
    static Value* execute(Value* poValue);

private:
    Log10();
};

#endif /* log10_hpp */
