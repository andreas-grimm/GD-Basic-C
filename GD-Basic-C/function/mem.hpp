//
//  mem.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef mem_hpp
#define mem_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../helper/logger.hpp"
#include "../memoryManager/memory.hpp"


class Mem {

public:
    static Value* execute();

private:
    Mem();
};
#endif /* mem_hpp */
