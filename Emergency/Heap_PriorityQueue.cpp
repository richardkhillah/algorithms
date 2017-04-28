//
//  Heap_PriorityQueue.cpp
//  Emergency Room Priority Queue
//
//  Created by Richard Khillah on 5/3/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#include "Heap_PriorityQueue.h"


Heap_PriorityQueue::Heap_PriorityQueue()
{
    ArrayMaxHeap();
} // end constructor


bool Heap_PriorityQueue::isEmpty() const
{
    return ArrayMaxHeap::isEmpty();
} // end isEmpty


bool Heap_PriorityQueue::add(const Patient& newPatient)
{
    return ArrayMaxHeap::add(newPatient);
} // end add;


bool Heap_PriorityQueue::remove()
{
    return ArrayMaxHeap::remove();
} // end remove

/** @pre The priority queue is not empty.*/

string Heap_PriorityQueue::peekTop() const throw(PrecondViolatedExcep)
{
    try {
        return ArrayMaxHeap::peekTop();
    } catch(PrecondViolatedExcep exception) {
        throw PrecondViolatedExcep("Attempted peek into an empty priority queue.");
    } // end try/catch
}
