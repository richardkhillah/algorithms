//
//  Person.h
//  Birthday Dictionary
//
//  Created by Richard Khillah on 5/10/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef Person_h
#define Person_h
#include <string>
using namespace std;

#include <stdio.h>

class Person {
private:
    string name;
    string birthMonth;
    int birthDay;
    int birthYear;
public:
    Person():name(""),birthMonth(""),birthDay(0),birthYear(0000) {}; // end constructor
    Person(string n, string m, int d, int y) : name(n), birthMonth(m), birthDay(d), birthYear(y) {} // end constructor

    void setName(Person p, string newName) { p.name = newName; } // end setName

    string getName() { return name; } // end getName

    string getBirthMonth() { return birthMonth; } // end getBirthMonth

    int getBirthDay() { return birthDay; } // end getBirthDay

    int getBirthYear() { return birthYear; } // end getBirthYear

    string getBirthdate() {
        return birthMonth + " " +to_string(birthDay) + ", " + to_string(birthYear);
    } // end getBirthdate

    bool operator<(const Person &p)
    { return name < p.name; } // end operator<

    bool operator>(const Person &p)
    { return name > p.name; } // end operator>

    bool operator==(const Person &p)
    { return (name == p.name) && (birthMonth == p.birthMonth) && (birthDay == p.birthDay) && (birthYear == p.birthYear); }

    bool operator!=(const Person& p)
    {
        return (name != p.name) || (birthMonth != p.birthMonth) || (birthDay != p.birthDay) || (birthYear == p.birthYear);
    }

    Person& operator=(const Person &p)
    {
        name = p.name;
        birthMonth = p.birthMonth;
        birthDay = p.birthDay;
        birthYear = p.birthYear;
        return *this;
    }

    bool clear()
    {
        delete this;
        return true;
    }
};

#endif /* Person_h */
