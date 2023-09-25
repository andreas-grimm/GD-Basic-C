//
//  stack.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 20/09/2023.
//

#include "stack.hpp"

/**
 * Initializes the stack if it does not exist.
 */
Stack* Stack::mpoStackInstance = NULL;

Stack::Stack() {
    mpoLogger = Logger::getInstance();
}

Stack* Stack::getInstance() {
    if (mpoStackInstance == NULL) {
        mpoStackInstance = new Stack();
    }
    
    return mpoStackInstance;
}


/**
 * Pushes a Value object into the Stack.
 *
 * @param  poValue Value object to be pushed.
 */
void Stack::push(Value* poValue) {
    spoStack.push(poValue);
}


/**
 * Returns the top Value typed element from the Stack
 *
 * @return Value retrieved from the stack
 * @throws EmptyStackException the stack is empty while a pop method is called
 */
Value* Stack::pop() {
    Value* poReturn;
    
    if (!spoStack.empty()) {
        poReturn = spoStack.top();
        spoStack.pop();
        
        return poReturn;
    }


    mpoLogger->error("Stack::pop","Empty Stack");
    exit(ERR_EMPTY_STACK);
}


/**
 * Clear the Stack.
 */
void Stack::reset() {
    while (!spoStack.empty()) {
        spoStack.pop();
    }
}
