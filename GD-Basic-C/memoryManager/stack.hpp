//
//  stack.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 20/09/2023.
//

#ifndef stack_hpp
#define stack_hpp

#include <stdio.h>
#include <stack>

#include "../helper/logger.hpp"
#include "../variableTypes/value.hpp"

using namespace std;


class Stack {

public:    
    static Stack* getInstance();

    void push(Value* poValue);
    Value* pop();
    void reset();
    
private:
    static Stack* mpoStackInstance;
    
    Stack();
    Stack(const Stack&);
    Stack& operator=(const Stack&);

    Logger* mpoLogger;

    stack<Value*> spoStack;
};

#endif /* stack_hpp */
