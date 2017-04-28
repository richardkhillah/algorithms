//
//  PriorityQueueInterface.h
//  Emergency Room Priority Queue
//
//  Created by Richard Khillah on 5/3/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef PriorityQueueInterface_h
#define PriorityQueueInterface_h

class PriorityQueueInterface
{
public:
    /** Checks wether queue is empty.
     @return True if queue is empty; false otherwise.*/
    virtual bool isEmpty() const = 0;

    /** Adds a new item to the the queue
     @param newEntry New item to be added to the queue.
     @post newEntry has been added to the queue.
     @return True if the item has been added; false otherwise.*/
    virtual bool add(const Patient& newEntry) = 0;

    /** Removes the item at the root node.
     @return True if the root has been removed; false otherwise.*/
    virtual bool remove() = 0;

    /** Gets the highest priority item
     @pre The queue is not empty.
     @post The root node is unchanged.
     @return The data in the root node has been returned.*/
    virtual string peekTop() const throw(PrecondViolatedExcep) = 0;
};

#endif /* PriorityQueueInterface_h */
