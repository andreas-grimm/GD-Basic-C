//
//  mem.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#include "mem.hpp"
Mem::Mem() {
}

/**
 * Functions implemented here are similar to Statements with the difference
 * that they actually return a result to the caller of type Value. The method execute
 * triggers the function.
 *
 * @return Value the return message of the function
 */
Value* Mem::execute() {
    int64_t llMemory = Memory::getTotalMemory() / 1024000;

    return new RealValue((float)llMemory);
}
