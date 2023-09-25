//
//  basic_token_type_util.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 22/08/2023.
//

#ifndef basic_token_type_util_hpp
#define basic_token_type_util_hpp

#include <stdio.h>
#include <string>

#include "basic_token_type.hpp"

using namespace std;

class BasicTokenTypeUtilities {
public:
    static string to_string(BasicTokenType eTokenType);
};

#endif /* basic_token_type_util_hpp */
