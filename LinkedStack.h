//
//  Stack.hpp
//  6 | Calculator
//
//  Created by Richard Khillah on 3/8/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef LinkedStack_h
#define LinkedStack_h

#include <stdio.h>
#include "Node.h"

class LinkedStack {
private:
    Node* topPtr;
public:
    LinkedStack();
    ~LinkedStack();
    bool isEmpty();
    bool push(const char& item);
    bool pop();
    char peek();
};

#endif /* LinkedStack_h */
