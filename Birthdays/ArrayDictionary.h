//
//  ArrayDictionary.h
//  Birthday Dictionary
//
//  Created by Richard Khillah on 5/10/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include "Person.h"
#include "ArrayDictionaryInterface.h"

class ArrayDictionary : public ArrayDictionaryInterface
{
    static const int ROOT_INDEX = 0;
    static const int DEFAULT_CAPACITY = 21;
    Person* dictionary;
    int itemCount;
    int maxItems;

public:
    ArrayDictionary();
    ~ArrayDictionary();
    bool add(const Person& person);
    bool remove(string person);
    bool contains(string name) const;
    bool isEmpty() const;
    bool clear();

    void printDictionary() const;
    void birthMonthDisplay(string month) const;
};

#endif /* Dictionary_hpp */
