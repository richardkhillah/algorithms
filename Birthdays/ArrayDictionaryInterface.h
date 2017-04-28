//
//  DictionaryInterface.h
//  Birthday Dictionary
//
//  Created by Richard Khillah on 5/10/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef DictionaryInterface_h
#define DictionaryInterface_h
#include <string>
#include "Person.h"
using namespace std;

class ArrayDictionaryInterface {
public:
    /** Adds new person to the dictionary and sorts by first name.
     @param person The data for the new dictionary entry.
     @post The dictionary contains the new Person.
     @return True if the addition is successful, false otherwise.
     */
    virtual bool add(const Person& person) = 0;

    /** Removes a person from the dictionary.
     @param person The person to remove from the dictionary.
     @return True if the person is removed, false otherwise.
     */
    virtual bool remove(string person) = 0;

    /** Sees whether the dictionary contains an entry.
     @param name Name of the person to search for.
     @return True if the person is in the dictionary, false otherwise.
     */
    virtual bool contains(string name) const = 0;

    /** Sees whether this dictionary is empty.
     @return True if the heap is empty, false otherwise.
     */
    virtual bool isEmpty() const= 0;

    /** Removes all entries from dictionary.
     */
    virtual bool clear() = 0;

    /** Displays all people in the dictionary.
     */
    virtual void printDictionary() const = 0;

    /** Displays all people in the dictionary who were born in the month passed in.
     @param The month you wish to search for.
     */
    virtual void birthMonthDisplay(string month) const = 0;
};

#endif /* DictionaryInterface_h */
