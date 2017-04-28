//
//  ArrayMaxHeap.cpp
//  Emergency Room Priority Queue
//
//  Created by Richard Khillah on 5/3/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#include "ArrayMaxHeap.h"
#include <cmath>


int ArrayMaxHeap::getLeftChildIndex(const int nodeIndex) const
{
    if(isEmpty())
        throw PrecondViolatedExcep("The heap is empty.");
    return 2*nodeIndex+1;
} // end getLeftChildIndex


int ArrayMaxHeap::getRightChildIndex(const int nodeIndex) const
{
    if(isEmpty())
        throw PrecondViolatedExcep("The heap is empty.");
    return 2*nodeIndex+2;
} // end getRightChildIndex


int ArrayMaxHeap::getParentIndex(const int nodeIndex) const
{
    if (isEmpty() || nodeIndex == ROOT_INDEX)
    {
        if (isEmpty()) {
            throw PrecondViolatedExcep("The heap is empty.");
        }
        else
            throw PrecondViolatedExcep("Root node has not parent node.");
    }
    return (nodeIndex-1) / 2;
} // end getParentIndex


bool ArrayMaxHeap::isLeaf(int nodeIndex) const
{
    return (getLeftChildIndex(nodeIndex) > itemCount) && (getRightChildIndex(nodeIndex) > itemCount);
} // end isLeaf


void ArrayMaxHeap::heapRebuild(int subTreeRootIndex)
{
    if (!isLeaf(subTreeRootIndex)) {
        // The root must have a left child; assume it is the larger child
        int largerChildIndex = getLeftChildIndex(ROOT_INDEX);   // Left child index

        if (getRightChildIndex(ROOT_INDEX) < itemCount) {
            int rightChildIndex = largerChildIndex+1;           // Right child index
            if(patients[rightChildIndex] > patients[largerChildIndex])
                largerChildIndex = rightChildIndex;             // Larger child index
        }

        // If the item in the root is smaller than the item in the larger child, swap patients
        if (patients[ROOT_INDEX] < patients[largerChildIndex]) {
            Patient temp = patients[ROOT_INDEX];
            patients[ROOT_INDEX] = patients[largerChildIndex];
            patients[largerChildIndex] = temp;
            // Transform the semiheap rooted at largerChildIndex into a heap
            heapRebuild(largerChildIndex);
        }
    }
    // Else root is a leaf, so you are done.
} // end heapRebuild


void ArrayMaxHeap::heapCreate()
{
    for(int index = itemCount/2 -1; index >=0; index--)
        heapRebuild(index);
} // end heapCreate


ArrayMaxHeap::ArrayMaxHeap():itemCount(0), maxItems(DEFAULT_CAPACITY)
{
    patients = new Patient[DEFAULT_CAPACITY];
} // end constructor


ArrayMaxHeap::ArrayMaxHeap(const Patient someArray[], const int arraySize)
{
    // Allocate the heap array
    patients = new Patient[2*arraySize];

    // Copy given values into array
    for (int index = 0; index < arraySize; index++)
        patients[index] = someArray[index];
    // Reorganize the array into a heap
    heapCreate();
} // end constructor


ArrayMaxHeap::~ArrayMaxHeap()
{
    patients->clear();
    delete [] patients;
    patients = nullptr;
} // end destructor


bool ArrayMaxHeap::isEmpty() const
{
    return itemCount == 0;
} // end isEmpty


int ArrayMaxHeap::getNumberOfNodes() const
{
    return itemCount;
} //end getNumberOfNodes


int ArrayMaxHeap::getHeight() const
{
    return (log(itemCount+1)/log(2));
} // end getHeight


string ArrayMaxHeap::peekTop() const
{
    return patients[ROOT_INDEX].getName();
} // end peekTop


bool ArrayMaxHeap::add(const Patient& newPatient)
{
    // Insert newData into the bottom of the tree
    patients[itemCount] = newPatient;

    // Trickle new item up to the appropiate spot in the tree
    int newPatientIndex = itemCount;
    bool inPlace = false;
    while ((newPatientIndex > 0) && !inPlace) {
        int parentIndex = getParentIndex(newPatientIndex);
        if (patients[newPatientIndex].getPriority() <= patients[parentIndex].getPriority())
            inPlace = true;
        else {
            Patient temp = patients[newPatientIndex];
            patients[newPatientIndex] = patients[parentIndex];
            patients[parentIndex] = temp;
            newPatientIndex = parentIndex;
        }
    }
    itemCount++;
    return true;
} // end add


bool ArrayMaxHeap::remove()
{
    // Copy the item from the last node and place it into the root
    patients[ROOT_INDEX] = patients[itemCount-1];

    // Remove the last node
    itemCount--;

    heapRebuild(ROOT_INDEX);
    return true;
} // end remove


void ArrayMaxHeap::clear()
{
    for(int i = 0; i < maxItems; i++)
        patients[i].clear();
}
