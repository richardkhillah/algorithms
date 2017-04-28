//
//  main.cpp
//  Birthday Dictionary
//
//  Created by Richard Khillah on 5/10/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#include <iostream>
#include "ArrayDictionary.h"

int main()
{
    ArrayDictionaryInterface* dictionary = new ArrayDictionary();
    dictionary->add(Person("billy", "june", 1, 1990));
    dictionary->add(Person("zeke", "july", 1, 1998));
    dictionary->add(Person("allie", "july", 10, 1988));
    dictionary->add(Person("richard", "september", 15, 1988));
    dictionary->add(Person("joe", "november", 21, 1974));
    dictionary->add(Person("alex", "July", 9, 1987));

    dictionary->printDictionary();

    dictionary->birthMonthDisplay("july");

    cout << "\nLooking for \"richard\" now.\n...\n";
    if (dictionary->contains("richard")) {
        cout << "Richard was found.\n";
    } else { cout << "Richard was not found...\n"; }

    cout << "Looking for \"turnip\" now.\n...\n";
    if (dictionary->contains("turnip")) {
        cout << "turnip was found.\n";
    } else { cout << "turnip was not found...\n"; }

    cout << "\nAfter removing richard, the list now looks like:\n";
    dictionary->remove("richard");
    dictionary->printDictionary();

    return 0;
}

/*
 Script started on Tue May 10 23:44:33 2016
 [?1034hbash-3.2$ ./a.out
 alex was born on July 9, 1987
 allie was born on july 10, 1988
 billy was born on june 1, 1990
 joe was born on november 21, 1974
 richard was born on september 15, 1988
 zeke was born on july 1, 1998

 The following people have birthday's in the month of july:
 allie
 zeke

 Looking for "richard" now.
 ...
 Richard was found.
 Looking for "turnip" now.
 ...
 turnip was not found...

 After removing richard, the list now looks like:
 alex was born on July 9, 1987
 allie was born on july 10, 1988
 billy was born on june 1, 1990
 joe was born on november 21, 1974
 zeke was born on july 1, 1998
 bash-3.2$ exit
 exit

 Script done on Tue May 10 23:44:43 2016
 */
