//
//  Patient.hpp
//  Emergency Room Priority Queue
//
//  Created by Richard Khillah on 5/3/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef Patient_h
#define Patient_h
#include <string>
#include <iostream>
using namespace std;

class Patient
{
private:
    int priority;
    string name;
public:
    Patient() : priority(0),name("") {}
    Patient(int i, string n) : priority(i), name(n) {}

    int getPriority() { return priority; }
    string getName() { return name; }

    bool operator<(const Patient &p)
    { return priority < p.priority; }

    bool operator>(const Patient &p)
    { return priority > p.priority; }

    Patient& operator=(const Patient &p)
    {
        priority = p.priority;
        name = p.name;
        return *this;
    }
    void clear()
    {
        priority = NULL;
        name = "";
    }
};
#endif /* Patient_h */
