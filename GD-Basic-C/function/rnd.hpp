//
//  rnd.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef rnd_hpp
#define rnd_hpp

#include <stdio.h>
#include <math.h>
#include "../variableTypes/value.hpp"
#include "../variableTypes/real_value.hpp"
#include "../helper/logger.hpp"

class Rnd {

public:
    static Value* execute();

private:
    Rnd();
};

#endif /* rnd_hpp */
