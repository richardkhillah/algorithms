//
//  Stack.cpp
//  6 | Calculator
//
//  Created by Richard Khillah on 3/8/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#include "LinkedStack.h"
#include <cassert>
#include <iostream>
using namespace std;

LinkedStack::LinkedStack() : topPtr(nullptr) {
} // end constructor

LinkedStack::~LinkedStack() {
    while (!isEmpty()) {
        pop();
    }
} // end destructor


bool LinkedStack::isEmpty() {
    bool result = (topPtr == nullptr) ? true:false;
    return result;//return topPtr == nullptr;
} // end isEmpty()


bool LinkedStack::push(const char& item) {
    Node *newNode = new Node(item, topPtr);
    topPtr = newNode;
    newNode = nullptr;
    return true;
} // end push


bool LinkedStack::pop() {
    if (!isEmpty()) {
        Node* currPtr = topPtr;
        topPtr = (topPtr->getNext());
        
        // return node to system
        currPtr->setNext(nullptr);
        currPtr = nullptr;
        return true;
    } // end if
    return false;
} // end pop


char LinkedStack::peek() {
    return topPtr->getItem();
} // end peek