//
//  Log.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef Log_hpp
#define Log_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../helper/logger.hpp"

class Log {

public:
    static Value* execute(Value* poValue);

private:
    Log();
};

#endif /* Log_hpp */
