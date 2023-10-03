//
//  rnd.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#include "rnd.hpp"
Rnd::Rnd() {
}

/**
 * Functions implemented here are similar to Statements with the difference
 * that they actually return a result to the caller of type Value. The method execute
 * triggers the function.
 *
 * @return Value the return message of the function
 * @throws Exception as any execution error found during execution
 */
Value* Rnd::execute() {
    return new RealValue((float)rand());
}
