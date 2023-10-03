//
//  chr.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/09/2023.
//

#ifndef chr_hpp
#define chr_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/integer_value.hpp"
#include "../variableTypes/string_value.hpp"
#include "../helper/logger.hpp"

class Chr {

public:
    static Value* execute(Value* poValue);

private:
    Chr();
};

#endif /* chr_hpp */
