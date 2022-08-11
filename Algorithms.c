#include "Algorithms.h"

//DFS

//return 0: way don't exist
//return 1: way exist
int DFS(vertex *startVertex, vertex *previousVertex, int finishVertexValue)
{
    if (startVertex->value == finishVertexValue) {
        return 1;
    }
    if (startVertex->color == 1) {
        return 0;
    }
    startVertex->color = 1;
    previousVertex = startVertex;
    edge *bufEdgeListHead = previousVertex->edge;
    while (bufEdgeListHead) {
        vertex *neighbourVertex = bufEdgeListHead->endPoint;
        neighbourVertex->previous = previousVertex;
        if (DFS(neighbourVertex, previousVertex, finishVertexValue)) {
            return 1;
        }
        else {
            bufEdgeListHead = bufEdgeListHead->next;
        }
    }
    return 0;
}

void getDFSResult(graph* graph, int startVertexValue, int finishVertexValue)
{
    vertex *bufHead = graph->head;
    while (bufHead) {
        bufHead->color = -1;
        bufHead->previous = NULL;
        bufHead = bufHead->next;
    }
    vertex *startVertex = findVertex(graph, startVertexValue);
    if (DFS(startVertex, NULL, finishVertexValue)) {
        printf("The vertex is reachable\n");
        vertex *finishVertex = findVertex(graph, finishVertexValue);
        printf("Way: \n");
        while (finishVertex) {
            printf("%d ", finishVertex->value);
            finishVertex = finishVertex->previous;
        }
    }
    else {
        printf("The vertex is NOT reachable\n");
    }
}

//Bellman-Ford
int bellmanFord(graph* graph, int startVertexValue, int finishVertexValue)
{
    int *distanceArray = (int *) malloc((graph->vertexNumber + 1) * sizeof(int));
    vertex **res = (vertex **) malloc((graph->vertexNumber + 1) * sizeof(vertex *));
    vertex *startVertex = findVertex(graph, startVertexValue);
    vertex *finishVertex = findVertex(graph, finishVertexValue);
    for (int i = 0; i < graph->vertexNumber + 1; i++) {
        res[i] = NULL;
    }
    for (int i = 0; i < graph->vertexNumber + 1; i++) {
        distanceArray[i] = -1;
    }
    distanceArray[startVertex->index] = 0;
    for (int i = 0; i < graph->vertexNumber; i++) {
        vertex *bufHead = graph->head;
        for (int j = 0; j < graph->vertexNumber + 1; j++) {
            edge *bufEdgeHeadList = bufHead->edge;
            while (bufEdgeHeadList) {
                if ((distanceArray[bufEdgeHeadList->endPoint->index] == -1) && (distanceArray[bufHead->index] != -1)) {
                    distanceArray[bufEdgeHeadList->endPoint->index] = distanceArray[bufHead->index] + bufEdgeHeadList->weight;
                    res[bufEdgeHeadList->endPoint->index] = bufHead;
                }
                else if (distanceArray[bufEdgeHeadList->endPoint->index] != -1 && distanceArray[bufHead->index] != -1 &&
                distanceArray[bufEdgeHeadList->endPoint->index] > distanceArray[bufHead->index] + bufEdgeHeadList->weight) {
                    distanceArray[bufEdgeHeadList->endPoint->index] = distanceArray[bufHead->index] + bufEdgeHeadList->weight;
                    res[bufEdgeHeadList->endPoint->index] = bufHead;
                }
                bufEdgeHeadList = bufEdgeHeadList->next;
            }
            bufHead = bufHead->next;
            if (!bufHead) {
                break;
            }
        }
    }
    printf("Distance: %d\n", distanceArray[finishVertex->index]);
    vertex *bufFinishVertex = finishVertex;
    if (distanceArray[finishVertex->index] != -1) {
        printf("Way: ");
        do {
            printf("%d ", finishVertex->value);
            finishVertex = res[finishVertex->index];
        } while ((res[finishVertex->index] != NULL) && (res[finishVertex->index]->value != bufFinishVertex->value));
        printf("%d\n", startVertex->value);
    }
    else {
        printf("There is no way");
        return 0;
    }
    return 0;
}

//Topological Sort
void topologicalSort(graph* graph)
{
    vertex *bufHead = graph->head;
    int *sortedArray = (int *) malloc(graph->vertexNumber * sizeof(int));
    for (int i = 0; i < graph->vertexNumber; i++) {
        while (bufHead) {
            if (headspring(graph, bufHead) && bufHead->color != 1) {
                bufHead->color = 1;
                sortedArray[i] = bufHead->index;
                break;
            }
            bufHead = bufHead->next;
        }
    }
    bufHead = graph->head;
    for (int i = graph->vertexNumber; i >= 1; i--) {
        bufHead->index = sortedArray[i];
        bufHead = bufHead->next;
    }
}

int headspring(graph* graph, vertex* checkingVertex)
{
    vertex *bufHead = graph->head;
    if (checkingVertex->color != 1) {
        while (bufHead) {
            edge *bufEdgeListHead = bufHead->edge;
            while (bufEdgeListHead) {
                if (bufEdgeListHead->endPoint->value == checkingVertex->value && bufHead->color != 1) {
                    return 0; //not the headspring
                }
                bufEdgeListHead = bufEdgeListHead->next;
            }
            bufHead = bufHead->next;
        }
        return 1;//the headspring
    }
}
