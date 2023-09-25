//
//  normalizer.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 16/08/2023.
//

#ifndef normalizer_hpp
#define normalizer_hpp

#include <stdio.h>
#include <algorithm>
#include <string>
#include <regex>

#include "../helper/common.hpp"
#include "../helper/logger.hpp"
#include "../helper/error_codes.hpp"

#include "reserved_words.hpp"

using namespace std;

class Normalizer {
public:
    Normalizer ();
    
    string normalize(string strProgramLine);
    string normalizeFunction(string strProgramLine);
    string normalizeIndex(string strProgramLine);

private:
    string mstrLogLevel;
    Logger* mpoLogger;
    ReservedWords oReservedWords;
};

#endif /* normalizer_hpp */
