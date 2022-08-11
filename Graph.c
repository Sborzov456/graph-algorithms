#include "Graph.h"

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
    newVertex->color = -1; // for DFS and topological sort
    newVertex->index = (graph->vertexNumber) + 1; // for Bellman-Ford algorithm
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
    if (!firstVertex->edge) {
        firstVertex->edge = newEdge;
        firstVertex->edge->next = NULL;
        newEdge->endPoint = secondVertex;
    }
    else {
        newEdge->next = firstVertex->edge;
        firstVertex->edge = newEdge;
        newEdge->endPoint = secondVertex;
    }
    graph->edgesNumber++;
    return graph;
}

graph *deleteVertex(graph *graph, int value) {
    vertex *vertexToDelete = findVertex(graph, value);
    vertex *bufHead = graph->head;
    while (bufHead) {
        edge *bufEdgeListHead = bufHead->edge;
        while (bufEdgeListHead) {
            if (bufEdgeListHead->endPoint->value == vertexToDelete->value) {
                graph = deleteEdge(graph, bufHead->value, value);
            }
            bufEdgeListHead = bufEdgeListHead->next;
        }
        bufHead = bufHead->next;
    }
    graph = deleteVertexFromList(graph, value);
    free(vertexToDelete->edge);
    return graph;
}

graph* deleteEdge(graph* graph, int firstVertexValue, int secondVertexValue)
{
    vertex* firstVertex = findVertex(graph, firstVertexValue);
    edge* bufEdgeListHead = firstVertex->edge;
    while (bufEdgeListHead)
    {
        if (bufEdgeListHead->endPoint->value == secondVertexValue)
        {
            firstVertex->edge = deleteFromEdgeList(firstVertex->edge, secondVertexValue);
            return graph;
        }
        bufEdgeListHead = bufEdgeListHead->next;
    }
    return graph;
}

graph *deleteVertexFromList(graph *graph, int value) {
    vertex *bufHead = graph->head;
    vertex *previousVertex = NULL;
    while (bufHead && bufHead->value != value) {
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
    while (bufEdgeListHead && bufEdgeListHead->endPoint->value != secondVertexValue) {
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
    while (bufHead && bufHead->value != value) {
        bufHead = bufHead->next;
    }
    if (bufHead) {
        return bufHead;
    }
    else {
        return NULL;
    }
}

void printGraph(graph *graph) {
    vertex *bufHead = graph->head;
    printf("Graph: \n");
    while (bufHead) {
        printf("%d(%d) -> ", bufHead->value, bufHead->index);
        edge *bufEdgeListHead = bufHead->edge;
        if (bufEdgeListHead) {
            while (bufEdgeListHead) {
                printf("%d ", bufEdgeListHead->endPoint->value);
                bufEdgeListHead = bufEdgeListHead->next;
            }
        }
        bufHead = bufHead->next;
        printf("\n");
    }
}

