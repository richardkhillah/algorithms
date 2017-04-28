//
//  PrecondViolatedExcep.cpp
//  Emergency Room Priority Queue
//
//  Created by Richard Khillah on 5/3/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message) : logic_error("Precondition Logic Error" + message)
{} // end constructor
// end implementation file
