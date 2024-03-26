// main.c

#include <stdio.h>

#include "graph.h"
#include "queue.h"

/*
  // A---B---C
  // |   |   |
  // D---E---F

  Creating graph of size: 6
  Depth-First Search Traversal from vertex A:
  A B C F E D
  Depth-First Search Traversal from vertex C:
  C B A D E F
  Breadth-First Search Traversal from vertex A:
  A B D C E F
  Breadth-First Search Traversal from vertex C:
  C B F A E D
*/

int main() {
  int size = VERTEX_MAX_SIZE;
  printf("Creating graph of size: %d\n", size);

  // Create a graph with predefined edges and vertices
  Graph graph = CreateGraph(size);

  // Test the depth-first search traversal from different starting points
  printf("Depth-First Search Traversal from vertex A:\n");
  DepthFirstSearchTraverse(graph, 0,
                           size);  // Assuming vertex 'A' is at index 0
  printf("\n");

  printf("Depth-First Search Traversal from vertex C:\n");
  DepthFirstSearchTraverse(graph, 2,
                           size);  // Assuming vertex 'C' is at index 2
  printf("\n");

  // Test the breadth-first search traversal from different starting points
  printf("Breadth-First Search Traversal from vertex A:\n");
  BreadthFirstSearchTraverse(graph, 0,
                             size);  // Assuming vertex 'A' is at index 0
  printf("\n");

  printf("Breadth-First Search Traversal from vertex C:\n");
  BreadthFirstSearchTraverse(graph, 2,
                             size);  // Assuming vertex 'C' is at index 2
  printf("\n");

  // Free the memory used by the graph
  // Will be implemented based on your specific memory management strategy
  // DestroyGraph(graph);

  return 0;
}