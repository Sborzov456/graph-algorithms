#include <stdio.h>
#include <stdlib.h>
#ifndef GRAPH_H
#define GRAPH_H

/*
    Weighted directed graph.
    The graph is defined by adjacency lists.
*/

typedef struct edge edge;
typedef struct vertex vertex;
typedef struct graph graph;

struct vertex {
    int x;
    int y;
    int value;
    int index;//the number of vertex in list
    int color;//-1 - white, 1 - gray [FOR DFS]
    struct edge *edge; // list of edges
    struct vertex *next;
    struct vertex *previous;//[FOR DFS]
};

struct edge {
    vertex *endPoint; // and the vertex from which the edge leaves (startPoint) is determined by the vertex in the list of edges of which this edge is located
    int weight;
    struct edge *next;
};

struct graph {
    int vertexNumber;
    int edgesNumber;
    vertex *head; // vertex list head
};

//Functions to work with graph
graph* create(); //create empty graph
graph* addVertex(graph* graph, int x, int y, int value);
graph* addEdge(graph* graph, int firstVertexValue, int secondVertexValue, int weight); //add edge between two vertex
graph* deleteVertex(graph* graph, int value); //delete vertex and it's edges by value
graph* deleteVertexFromList(graph* graph, int value); // delete vertex form vertex list in graph; calls in deleteVertex(...) function
graph* deleteEdge(graph* graph, int firstVertexValue, int secondVertexValue); //delete edge between two vertex
edge* deleteFromEdgeList(edge* edgeListHead, int secondVertexValue); //each vertex has a set of edges coming out of it. the function takes the value of the end point and delete edge from edges list of vertex.
vertex* findVertex(graph* graph, int value);
void printGraph(graph* graph);


#endif
