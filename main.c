#include "Graph.h"
#include "Algorithms.h"
#include "SecondaryFunctions.h"

int main()
{
    int option = -1;
    char *msgs[] = {
            "0. Quit",
            "1. Add vertex",
            "2. Add edge",
            "3. Delete vertex",
            "4. Delete edge",
            "5. Print graph",
            "6. DFS",
            "7. Bellman-Ford algorithm",
            "8. Topological sort"};
    graph* graph = create();
    while (option)
    {
        option = dialog(msgs);
        if (option == 1)
        {
            int x, y, value;
            printf("Enter x: ");
            scanf("%d", &x);
            printf("Enter y: ");
            scanf("%d", &y);
            printf("Enter value: ");
            scanf("%d", &value);
            graph = addVertex(graph, x, y, value);
        }
        if (option == 2)
        {
            int firstVertexValue, secondVertexValue, weight;
            printf("Enter first vertex value: ");
            scanf("%d", &firstVertexValue);
            printf("Enter second vertex value: ");
            scanf("%d", &secondVertexValue);
            printf("Enter weight of edge: ");
            scanf("%d", &weight);
            graph = addEdge(graph, firstVertexValue, secondVertexValue, weight);
        }
        if (option == 3)
        {
            int value;
            printf("Enter value of vertex you want to remove: ");
            scanf("%d", &value);
            graph = deleteVertex(graph, value);
        }
        if (option == 4)
        {
            int firstVertexValue, secondVertexValue;
            printf("Enter first vertex value: ");
            scanf("%d", &firstVertexValue);
            printf("Enter second vertex value: ");
            scanf("%d", &secondVertexValue);
            graph = deleteEdge(graph, firstVertexValue, secondVertexValue);
        }
        if (option == 5)
        {
            printGraph(graph);
        }
        if (option == 6)
        {
            int startVertexValue, finishVertexValue;
            printf("Enter from which vertex you want to find way: ");
            scanf("%d", &startVertexValue);
            printf("Enter the end point of the way: ");
            scanf("%d", &finishVertexValue);
            getDFSResult(graph, startVertexValue, finishVertexValue);
        }
        if (option == 7)
        {
            int startVertexValue, finishVertexValue;
            printf("Enter from which vertex you want to find way: ");
            scanf("%d", &startVertexValue);
            printf("Enter the end point of the way: ");
            scanf("%d", &finishVertexValue);
            bellmanFord(graph, startVertexValue, finishVertexValue);
        }
        if (option == 8)
        {
            topologicalSort(graph);
        }
    }
    return(0);
}









