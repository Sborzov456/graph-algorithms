#include "Graph.h"

struct vertex {
    int x;
    int y;
    int value;
    int index;//the number of vertex in list
    int color;//-1 - white, 1 - gray [FOR DFS]
    struct edge *edge;
    struct vertex *next;
    struct vertex *prev;//[FOR DFS]
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


graph *create() {
    graph *newGraph = (graph *) malloc(sizeof(graph));
    newGraph->head = NULL;
    newGraph->vertexNumber = 0;
    newGraph->edgesNumber = 0;
    return newGraph;
}

graph *addVertex(graph *graph, int x, int y, int value) {
    vertex *newVertex = (vertex *) malloc(sizeof(vertex));
    newVertex->x = x;
    newVertex->y = y;
    newVertex->value = value;
    newVertex->next = NULL;
//--------FOR DFS AND TOPOLOGICAL SORT--------
    newVertex->color = -1;
//--------FOR BELLMAN FORD ALGORITHM----------
    newVertex->index = (graph->vertexNumber) + 1;
//--------------------------------------------
    newVertex->edge = NULL;
    if (graph->head == NULL) {
        graph->head = newVertex;
    }
    else {
        newVertex->next = graph->head;
        graph->head = newVertex;
    }
    (graph->vertexNumber)++;
    return graph;
}

graph *addEdge(graph *graph, int firstVertexValue, int secondVertexValue, int weight) {
    vertex *firstVertex = findVertex(graph, firstVertexValue);
    vertex *secondVertex = findVertex(graph, secondVertexValue);
    edge *newEdge = (edge *) malloc(sizeof(edge));
    newEdge->weight = weight;
    if (firstVertex->edge == NULL) {
        firstVertex->edge = newEdge;
        firstVertex->edge->next = NULL;
        newEdge->endPoint = secondVertex;
    }
    else {
        newEdge->next = firstVertex->edge;
        firstVertex->edge = newEdge;
        newEdge->endPoint = secondVertex;
    }
    (graph->edgesNumber)++;
    return graph;
}

graph *deleteVertex(graph *graph, int value) {
    vertex *vertexToDelete = findVertex(graph, value);
    vertex *bufHead = graph->head;
    while (bufHead != NULL) {
        edge *bufEdgeListHead = bufHead->edge;
        while (bufEdgeListHead != NULL) {
            if (bufEdgeListHead->endPoint->value == vertexToDelete->value) {
                graph = deleteEdge(graph, bufHead->value, value);
            }
            bufEdgeListHead = bufEdgeListHead->next;
        }
        bufHead = bufHead->next;
    }
    graph = deleteVertexFromList(graph, value);
    free(vertexToDelete->edge);
    free(vertexToDelete);
    return graph;
}

graph *deleteVertexFromList(graph *graph, int value) {
    vertex *bufHead = graph->head;
    vertex *previousVertex = NULL;
    while ((bufHead != NULL) && (bufHead->value != value)) {
        previousVertex = bufHead;
        bufHead = bufHead->next;
    }
    if (bufHead == graph->head) {
        graph->head = graph->head->next;
        free(bufHead);
        return graph;
    }
    else {
        previousVertex->next = bufHead->next;
        free(bufHead);
        return graph;
    }
}

edge *deleteFromEdgeList(edge *edgeListHead, int secondVertexValue) {
    edge *bufEdgeListHead = edgeListHead;
    edge *previousEdge;
    while ((bufEdgeListHead != NULL) && (bufEdgeListHead->endPoint->value != secondVertexValue)) {
        previousEdge = bufEdgeListHead;
        bufEdgeListHead = bufEdgeListHead->next;
    }
    if (bufEdgeListHead == edgeListHead) {
        edgeListHead = edgeListHead->next;
        free(bufEdgeListHead);
        return edgeListHead;
    }
    else {
        previousEdge->next = bufEdgeListHead->next;
        free(bufEdgeListHead);
        return edgeListHead;
    }
}

vertex *findVertex(graph *graph, int value) {
    vertex *bufHead = graph->head;
    while ((bufHead != NULL) && (bufHead->value != value)) {
        bufHead = bufHead->next;
    }
    if (bufHead != NULL) {
        return bufHead;
    }
    else {
        return NULL;
    }
}

void printGraph(graph *graph) {
    vertex *bufHead = graph->head;
    printf("Graph: \n");
    while (bufHead != NULL) {
        printf("%d(%d) -> ", bufHead->value, bufHead->index);
        edge *bufEdgeListHead = bufHead->edge;
        if (bufEdgeListHead != NULL) {
            while (bufEdgeListHead != NULL) {
                printf("%d ", bufEdgeListHead->endPoint->value);
                bufEdgeListHead = bufEdgeListHead->next;
            }
        }
        bufHead = bufHead->next;
        printf("\n");
    }
}






