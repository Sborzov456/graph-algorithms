#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#ifndef ALGORITHMSONGRAPHS_ALGORITHMS_H
#define ALGORITHMSONGRAPHS_ALGORITHMS_H

/*
    1) Search for some given vertex from another given vertex using the depth-first search method.
    2) Finding the shortest path between two given graph vertices using the Bellman-Ford algorithm.
    3) Checking the graph for acyclicity; topological sorting of a graph
*/

//DFS
int DFS(vertex* startVertex, vertex* previousVertex, int finishVertexValue); //the process of finding a way
void getDFSResult(graph* graph, int startVertexValue, int finishVertexValue); // prepares values to DFS(...) outputs the resulting way
//need two functions since the DFS(...) is recursive function

//Bellman-Ford Algorithm
int bellmanFord(graph* graph, int startVertexValue, int finishVertexValue);

//Topological Sort
void topologicalSort(graph* graph);
int headspring(graph* graph, vertex* checkingVertex); // returns 1 if vertex is headspring and 0 if not

#endif
