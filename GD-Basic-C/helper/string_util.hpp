//
//  string_util.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 22/08/2023.
//

#ifndef string_util_hpp
#define string_util_hpp

#include <string>
#include <vector>
#include <cstring>
#include <stdio.h>

using namespace std;

class StringUtil {
    
public:
    static vector<string> split(string strInputString, string strSplitToken);
    
    static string from_vector(vector<string> vstrVector, string strSeperator);
    
    static string to_upper(string strString);
    
private:
    StringUtil();
};

#endif /* string_util_hpp */
