//
//  instr.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/09/2023.
//

#ifndef instr_hpp
#define instr_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/string_value.hpp"
#include "../helper/logger.hpp"

class Instr {

public:
    static Value* execute(Value* poValue, Value* poSearch);

private:
    Instr();
};

#endif /* instr_hpp */
