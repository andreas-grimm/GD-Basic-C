//
//  system_util.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#ifndef system_util_hpp
#define system_util_hpp

#include <string>
#include <cstring>
#include <stdio.h>

using namespace std;

class SystemUtil {
    
public:
    static string exec(string strString);
    
private:
    SystemUtil();
};

#endif /* system_util_hpp */
