# Weighted Directed Graph :arrow_right:
## :pushpin: Short Description 
   This project implements a _weighted directed graph_ data structure that is defined by _adjacency lists_.
## :pushpin: Adjacency Lists
   Adjacency lists are a way of representing a graph in memory. 

   The peculiarity of this method is that the _structure of each vertex stores a list of edges emerging from it_, and the _edge structure stores the vertex that            this edge enters_.
   
   _The graph itself is a list of vertices_. Therefore, in the vertex structure there is a pointer to the next one.
   
   ```C
   struct vertex {
     struct edge *edge; // list of edges
     struct vertex *next;
   }
   ```
   
   ```C
   struct edge {
    vertex *endPoint;
    struct edge *next;
  }
   ```
## :pushpin: Algorithms
### :exclamation: [DFS](https://en.wikipedia.org/wiki/Depth-first_search)(_Depth-First Search_)
   The DFS algorithm is used to _find a path between two given vertices_. If one vertex is not reachable from another, an error code is returned.

   In the project, this algorithm can be called by a `getDFSResult()` function.
   
### :exclamation: [Bellman-Ford Algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)
   The Bellman-Ford algorithm is used to find the shortest path between given vertices.

   In the project, this algorithm can be called by a `BellmanFord()` function.
  
