//
//  AirGraph.h
//  12 | CSAir
//
//  Created by Richard Khillah on 5/17/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#ifndef AirGraph_h
#define AirGraph_h

#include <string>
const int INFINITY = 99999;
const int MAX_ARRAY_SIZE = 6;

class AirGraph
{
private:
    int graphMatrix[MAX_ARRAY_SIZE][MAX_ARRAY_SIZE] =
    {
        {0, 120, 150, INFINITY, INFINITY, 500},
        {120,0, INFINITY, 75, INFINITY, 350},
        {150, INFINITY, 0, INFINITY, 250, INFINITY},
        {INFINITY, 75, INFINITY, 0, 150, INFINITY},
        {INFINITY, INFINITY, 250, 150, 0, INFINITY},
        {500, 350, INFINITY, INFINITY, INFINITY, 0}
    };
    std::string destinationMatrix[MAX_ARRAY_SIZE] =
    {
        "SFO", "LAX", "LAS", "PHX", "DEN", "JFK"
    };

protected:
    bool contains(int vertex, int vSet[]);
    template<class ItemType>
    void printArray(ItemType arr[]);
public:
    AirGraph();
    int getEdgeWeight(int start, int end);
    void dijkstrasAlg();
};

#endif /* AirGraph_h */
