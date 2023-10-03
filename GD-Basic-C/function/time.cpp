//
//  time.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 03/10/2023.
//

#include "time.hpp"
Time_Func::Time_Func() {
}

/**
 * Functions implemented here are similar to Statements with the difference
 * that they actually return a result to the caller of type Value. The method execute
 * triggers the function.
 *
 * @return Value the return message of the function
 */
Value* Time_Func::execute() {
    const auto now = std::chrono::system_clock::now();
    const std::time_t t_c = std::chrono::system_clock::to_time_t(now);
    StringValue* poReturn = new StringValue(t_c);

    return poReturn;
}
