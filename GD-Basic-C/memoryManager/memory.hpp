//
//  memory.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#ifndef memory_hpp
#define memory_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/sysctl.h>

#include "common.hpp"

using namespace std;

class Memory {
public:
    Memory();
    
    int64_t getTotalMemory();
};
 
#endif /* memory_hpp */
