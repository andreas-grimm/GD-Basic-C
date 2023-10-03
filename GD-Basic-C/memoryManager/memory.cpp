//
//  memory.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 15/08/2023.
//

#include "memory.hpp"

Memory::Memory() {
};

int64_t Memory::getTotalMemory() {
    int mib[2];
    int64_t llPhysicalMemory;
    size_t lLengthOfInt64_t;

    // Get the Physical memory size
    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    
    lLengthOfInt64_t = sizeof(int64_t);
    sysctl(mib, 2, &llPhysicalMemory, &lLengthOfInt64_t, NULL, 0);
    
    return llPhysicalMemory;
}
