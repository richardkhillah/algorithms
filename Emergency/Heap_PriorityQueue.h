//
//  Heap_PriorityQueue.hpp
//  Emergency Room Priority Queue
//
//  Created by Richard Khillah on 5/3/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef Heap_PriorityQueue_h
#define Heap_PriorityQueue_h

#include "ArrayMaxHeap.h"
#include "PriorityQueueInterface.h"


class Heap_PriorityQueue : public PriorityQueueInterface, private ArrayMaxHeap
{
public:
    Heap_PriorityQueue();
    bool isEmpty() const;
    bool add(const Patient& newPatient);
    bool remove();
    /* @pre The priority queue is not empty. */
    string peekTop() const throw(PrecondViolatedExcep);
}; // end Heap_PriorityQueue

#endif /* Heap_PriorityQueue_h */
