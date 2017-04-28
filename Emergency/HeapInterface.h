//
//  HeapInterface.h
//  Emergency Room Priority Queue
//
//  Created by Richard Khillah on 5/3/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef HeapInterface_h
#define HeapInterface_h
#include "Patient.h"
#include <string>
using namespace std;

class HeapInterface
{
public:
    /** Sees whether this heap is empty.
     @return True if the heap is empty; false if not. */
    virtual bool isEmpty() const = 0;

    /** Gets the number of nodes in this heap.
     @return The number of nodes in the heap. */
    virtual int getNumberOfNodes() const = 0;

    /** Gets the height of this heap.
     @retrun The height of the heap. */
    virtual int getHeight() const = 0;

    /** Gets the data that is in the root of the heap.
     @pre The heap is not empty.
     @post The root's data has been returned and the heap is unchanged.
     @return The data in the root of the heap. */
    virtual string peekTop() const = 0;

    /** Adds a new node containing the given data to this heap.
     @param newNata The data for the new node.
     @post The heap contains a new node.
     @return True if the addition is successful, false otherwise. */
    virtual bool add(const Patient& newPatient) = 0;

    /** Removes the root node from this heap.
     @return True if removal is successful; false otherwise. */
    virtual bool remove() = 0;

    /** Removes all nodes from this heap. */
    virtual void clear() = 0;
}; // end HeapInterface

#endif /* HeapInterface_h */
