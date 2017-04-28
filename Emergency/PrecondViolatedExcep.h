//
//  PrecondViolatedExcep.hpp
//  Emergency Room Priority Queue
//
//  Created by Richard Khillah on 5/3/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef PrecondViolatedExcep_h
#define PrecondViolatedExcep_h

#include <stdexcept>
#include <string>
using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
    PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcept

#endif /* PrecondViolatedExcep_h */
