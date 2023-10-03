//
//  sqr.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef sqr_hpp
#define sqr_hpp

#include <stdio.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../helper/logger.hpp"

class Sqr {

public:
    static Value* execute(Value* poValue);

private:
    Sqr();
};
#endif /* sqr_hpp */
