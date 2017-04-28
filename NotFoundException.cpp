/** @file NotFoundException.cpp */
#include "NotFoundException.h"

NotFoundException::NotFoundException(const string& message)
         : logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.
