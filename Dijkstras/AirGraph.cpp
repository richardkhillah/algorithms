//
//  AirGraph.cpp
//  Dijkstra's Algorithm implemented using using an Airport as example medium.
//
//  Created by Richard Khillah on 5/17/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//

#include "SFAirGraph.h"
#include <iostream>
using namespace std;


AirGraph::AirGraph()
{} // end constructor


int AirGraph::getEdgeWeight(int start, int end)
{
    return graphMatrix[start][end];
} // end getEdgeWeight

void AirGraph::dijkstrasAlg()
{
    int vertexSetIndex = 0;
    int vertexSet[MAX_ARRAY_SIZE] = {-1,-1,-1,-1,-1,-1};
    int weights[MAX_ARRAY_SIZE] = {0,0,0,0,0,0};
    int n = MAX_ARRAY_SIZE; // number of verticies in graph

    for(int step = 1; step < n; step++)
    {
        if(step == 1)
        {

            vertexSet[vertexSetIndex] = 0;
            vertexSetIndex++;

            for (int v = 0; v < n; v++)
                weights[v] = graphMatrix[0][v];
        }
        else // Steps 2 through n
        {
            // Find the smallest weight[v] such that v is not in the vertexSet
            int min = 0;
            int v = 0; // vertex to be added to vertex set.

            for(int sVertex = 0; sVertex < n; sVertex++) // sVertex = search Vertex
            {
                if (!contains(sVertex, vertexSet) && min == 0 && weights[sVertex] != INFINITY)
                {
                    min = weights[sVertex];
                    v = sVertex;
                }
                else if (!contains(sVertex, vertexSet) && min != 0 && weights[sVertex] < min && weights[sVertex] != INFINITY ) {
                    min = weights[sVertex];
                    v = sVertex;
                }
            }

            // Add v to vertexSet
            vertexSet[vertexSetIndex] = v;
            vertexSetIndex++;

            // Check weight[u] for all u not in vertexSet
            for(int u = 0; u < MAX_ARRAY_SIZE; u++)
            {
                if (!contains(u, vertexSet))
                    if((weights[u] > weights[v] + graphMatrix[v][u]))
                        weights[u] = weights[v] + graphMatrix[v][u];
            }
        }
    }

    // display shortest paths
    printArray(destinationMatrix);
    printArray(weights);
}

bool AirGraph::contains(int vertex, int vSet[])
{
    for(int i = 0; i < MAX_ARRAY_SIZE; i++)
        if (vSet[i] == vertex)
            return true;
    return false;
}

template<class ItemType>
void AirGraph::printArray(ItemType arr[])
{
    for(int i = 0; i < MAX_ARRAY_SIZE; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
