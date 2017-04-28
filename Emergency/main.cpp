//
//  main.cpp
//  Emergency Room Priority Queue
//  Description: A priority queue is implemented in a fun way using an
//               emergency room as the reason for use.
//
//  Created by Richard Khillah on 5/3/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#include "Heap_PriorityQueue.h"
#include <iostream>
using namespace std;

int main() {
    PriorityQueueInterface* ER = new Heap_PriorityQueue();
    ER->add(Patient(5, "Bob"));
    ER->add(Patient(9, "Mary"));
    ER->add(Patient(1, "Max"));
    cout << ER->peekTop() << " will now see the doctor.\n"; ER->remove();
    ER->add(Patient(3, "Julio"));
    ER->add(Patient(7, "Stacy"));
    ER->add(Patient(4, "Paul"));
    ER->add(Patient(2, "Reiko"));
    ER->add(Patient(6, "Jennifer"));
    ER->add(Patient(5, "Chang"));
    cout << ER->peekTop() << " will now see the doctor.\n"; ER->remove();
    cout << ER->peekTop() << " will now see the doctor.\n"; ER->remove();
    cout << ER->peekTop() << " will now see the doctor.\n"; ER->remove();
    return 0;
}
