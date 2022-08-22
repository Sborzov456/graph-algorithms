# Weighted Directed Graph :arrow_right:
## :pushpin: Short Description 
   This project implements a _weighted directed graph_ data structure that is defined by _adjacency lists_.
## :pushpin: Adjacency Lists
   Adjacency lists are a way of representing a graph in memory. 

   The peculiarity of this method is that the _structure of each vertex stores a list of edges emerging from it_, and the _edge structure stores the vertex that            this edge enters_.
   
   _The graph itself is a list of vertices_. Therefore, in the vertex structure there is a pointer to the next one.
   
   ```C++
   struct vertex {
     struct edge *edge; // list of edges
     struct vertex *next;
   }
   ```
   
   ```C++
   struct edge {
    vertex *endPoint;
    struct edge *next;
  }
   ```
## :pushpin: Algorithms
