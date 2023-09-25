//
//  fifo_queue.cpp
//  GD-Basic-C
//
//  Created by Andreas Grimm on 29/08/2023.
//

#include "fifo_queue.hpp"

FiFoQueue::FiFoQueue() {
};

void FiFoQueue::push(Value* voValue) {
    mvpoFiFo.push_back(voValue);
};

Value* FiFoQueue::pop() {
    Value* voReturn;
    
    voReturn = mvpoFiFo.front();
    mvpoFiFo.erase(mvpoFiFo.begin());
    
    return voReturn;
};

void FiFoQueue::reset() {
    mvpoFiFo.clear();
};
