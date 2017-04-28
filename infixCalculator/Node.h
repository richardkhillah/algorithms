//  Created by Richard Khillah on 3/8/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.

/** @file Node.h
    Listing 4-1 */
#ifndef _NODE
#define _NODE
#include <string>
using std::string;
class Node
{
private:
   char     item; // A data item
   Node*    next; // Pointer to next node

public:
   Node();
   Node(const char& anItem);
   Node(const char& anItem, Node* nextNodePtr);
   void setItem(const char& anItem);
   void setNext(Node* nextNodePtr);
   char getItem() const ;
   Node* getNext() const ;
}; // end Node

//#include "Node.cpp"
#endif
