//
//  ArrayDictionary.cpp
//  Birthday Dictionary
//
//  Created by Richard Khillah on 5/10/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#include "ArrayDictionary.h"
#include <iostream>

ArrayDictionary::ArrayDictionary()
{
    dictionary = new Person[DEFAULT_CAPACITY];
    itemCount = 0;
    maxItems = DEFAULT_CAPACITY;
} // end construtor

ArrayDictionary::~ArrayDictionary()
{
    dictionary->clear();
    delete [] dictionary;
    dictionary = nullptr;
} // end desctructor

bool ArrayDictionary::add(const Person& person)
{
    // If the dictionary is full, make it larger
    if (itemCount==DEFAULT_CAPACITY) {
        Person* newDictionary = new Person[2*DEFAULT_CAPACITY];

        for (int i = 0; i < itemCount; i++)
            newDictionary[i] = dictionary[i];
        delete [] dictionary;
        dictionary = newDictionary;

        // return newDictionary* to system
        delete [] newDictionary;
        newDictionary = nullptr;
    }
    if(isEmpty())
    {
        dictionary[ROOT_INDEX] = person;
        itemCount++;
    }
    else
    {
        int index = itemCount;
        // find the index to insert a newperson at.
        while (dictionary[index-1] > person && index >= ROOT_INDEX)
        {
            dictionary[index] = dictionary[index-1];
            index--;
        }
        // add the person correct index.
        dictionary[index] = person;
        // account for the added person
        itemCount++;
    }
    return true;
} // end add

bool ArrayDictionary::remove(string person)
{
    if (isEmpty() || !contains(person)) {
        return false;
    }
    else
    {
        int index = 0;
        bool found = false;
        // find the index of the person to remove
        while (!found && index < itemCount)
        {
            if (dictionary[index].getName() == person)
                found = true;
            else
                index++;
        }

        if (found) {
            if (index == itemCount) {
                itemCount--;
            }
            else {
                while(index<itemCount)
                {
                    dictionary[index] = dictionary[index+1];
                    index++;
                }
                itemCount--;
            }
        }
    }
    return true;
} // end remove

bool ArrayDictionary::contains(string name) const {
    int left = ROOT_INDEX; // left boundary index
    int right = itemCount-1; // right boundary index

    while (left <= right) {
        int midpoint = (left + right) / 2; // midpoint index
        if(dictionary[midpoint].getName() == name)
            return true;
        else if (dictionary[midpoint].getName() > name)
            right = midpoint-1;
        else
            left = midpoint+1;
    }
    return false;
} // end contains

void ArrayDictionary::printDictionary() const {
    if (!isEmpty())
    {
        int index = 0;
        while (index < itemCount) {
            cout << dictionary[index].getName() << " was born on " << dictionary[index].getBirthdate() << endl;
            index++;
        }
    }
    else
        cout << "There are no entries in your dictionary\n";
} // end printDictionary

void ArrayDictionary::birthMonthDisplay(string month) const {
    if(!isEmpty())
    {
        bool foundFirst = false;
        cout << endl;
        for (int index = 0; index < itemCount; index++) {
            if (dictionary[index].getBirthMonth() == month)
            {
                if(!foundFirst)
                {
                    cout << "The following people have birthday's in the month of " << month << ": \n";
                    foundFirst = true;
                }
                cout << dictionary[index].getName() << endl;
            }
        }
    }
} // end birthMondyDisplay

bool ArrayDictionary::isEmpty() const { return itemCount == 0; } // end isEmpty

bool ArrayDictionary::clear() {
    while (!isEmpty()) {
        dictionary[--itemCount].clear();
    }
    return true;
} // end clear
