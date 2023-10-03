//
//  system_func.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef system_func_hpp
#define system_func_hpp

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/string_value.hpp"
#include "../function/len.hpp"
#include "../helper/logger.hpp"
#include "../helper/string_util.hpp"
#include "../helper/system_util.hpp"

class System {

public:
    static Value* execute(Value* poValue, Value* poSearch);

private:
    System();
};

#endif /* system_func_hpp */
