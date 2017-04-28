//
//  ArrayMaxHeap.hpp
//  Emergency Room Priority Heap
//
//  Created by Richard Khillah on 5/3/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef ArrayMaxHeap_h
#define ArrayMaxHeap_h

#include "HeapInterface.h"
#include "Patient.h"
#include "PrecondViolatedExcep.h"


class ArrayMaxHeap : public HeapInterface
{
private:
    static const int ROOT_INDEX = 0;
    static const int DEFAULT_CAPACITY = 21;
    Patient* patients;
    int itemCount;
    int maxItems;

protected:
    // Returns the array index of the left child (if it exists).
    int getLeftChildIndex(const int nodeIndex) const;

    // Returns the array index of the right child (if it exists).
    int getRightChildIndex(const int nodeIndex) const;

    // Returns the array index of the parent node.
    int getParentIndex(const int nodeIndex) const;

    // Tests whether this node is a leaf
    bool isLeaf(int nodeIndex) const;

    // Converts a semiheap to a heap.
    void heapRebuild(int subTreeRootIndex);

    // Creates a heap from an unsorted array.
    void heapCreate();

public:
    ArrayMaxHeap();
    ArrayMaxHeap(const Patient someArray[], const int arraySize);
    virtual ~ArrayMaxHeap();

    // HeapInterface Public Methods:
    bool isEmpty() const;
    int getNumberOfNodes() const;
    int getHeight() const;
    string peekTop() const;
    bool add(const Patient& newPatient);
    bool remove();
    void clear();
}; // end ArrayMaxHeap

#endif /* ArrayMaxHeap_h */
