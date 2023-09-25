//
//  fifo_queue.hpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/08/2023.
//

#ifndef fifo_queue_hpp
#define fifo_queue_hpp

#include <stdio.h>
#include <vector>
#include "../variableTypes/value.hpp"

using namespace std;

class FiFoQueue {

public:
    FiFoQueue();
    void push(Value* voValue);
    Value* pop();
    void reset();
    
private:
    vector<Value*> mvpoFiFo;
};

#endif /* fifo_queue_hpp */
