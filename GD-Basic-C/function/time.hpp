//
//  time.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef time_hpp
#define time_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/string_value.hpp"
#include "../helper/logger.hpp"

class Time_Func {

public:
    static Value* execute();

private:
    Time_Func();
};

#endif /* time_hpp */
