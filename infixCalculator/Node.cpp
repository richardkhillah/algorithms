//  Created by Richard Khillah on 3/8/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.

/** @file Node.cpp */
#include "Node.h"
#include <cstddef>

Node::Node() : next(nullptr)
{
} // end default constructor


Node::Node(const char& anItem) : item(anItem), next(nullptr)
{
} // end constructor


Node::Node(const char& anItem, Node* nextNodePtr) :
                item(anItem), next(nextNodePtr)
{
} // end constructor


void Node::setItem(const char& anItem)
{
   item = anItem;
} // end setItem


void Node::setNext(Node* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext


char Node::getItem() const
{
   return item;
} // end getItem


Node* Node::getNext() const
{
   return next;
} // end getNext
