// graph.c

#include "graph.h"

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// Array to keep track of visited vertices
static bool visited[VERTEX_MAX_SIZE] = {0};

// Helper function to create a new node
static Node *CreateNode(int vertex) {
  Node *node = (Node *)malloc(sizeof(Node));
  if (!node) {
    fprintf(stderr, "Memory allocation failed for node creation.\n");
    exit(EXIT_FAILURE);
  }
  node->vertex = vertex;
  node->next = NULL;
  return node;
}

Graph CreateGraph(int size) {
  Graph graph = (Graph)malloc(size * sizeof(GraphHead));
  if (!graph) {
    fprintf(stderr, "Memory allocation failed for graph creation.\n");
    exit(EXIT_FAILURE);
  }

  // Initialize vertices: A, B, C, D, E, F
  for (int i = 0; i < size; ++i) {  // Only 6 vertices for the grid graph
    graph[i].data = (char)('A' + i);
    graph[i].first_edge = NULL;
  }

  // Allocate and assign edges according to the grid graph
  // A: B, D
  graph[0].first_edge = CreateNode(1);
  graph[0].first_edge->next = CreateNode(3);

  // B: A, C, E
  graph[1].first_edge = CreateNode(0);
  graph[1].first_edge->next = CreateNode(2);
  graph[1].first_edge->next->next = CreateNode(4);

  // C: B, F
  graph[2].first_edge = CreateNode(1);
  graph[2].first_edge->next = CreateNode(5);

  // D: A, E
  graph[3].first_edge = CreateNode(0);
  graph[3].first_edge->next = CreateNode(4);

  // E: B, D, F
  graph[4].first_edge = CreateNode(1);
  graph[4].first_edge->next = CreateNode(3);
  graph[4].first_edge->next->next = CreateNode(5);

  // F: C, E
  graph[5].first_edge = CreateNode(2);
  graph[5].first_edge->next = CreateNode(4);

  return graph;
}

int GetFirstAdjacentVertex(Graph graph, int begin) {
  if (graph[begin].first_edge) {
    return graph[begin].first_edge->vertex;
  } else {
    return -1;
  }
}

int GetNextAdjacentVertex(Graph graph, int vertex_index, int current_vertex) {
  Node *current_node = graph[vertex_index].first_edge;
  while (current_node && current_node->vertex != current_vertex) {
    current_node = current_node->next;
  }
  if (current_node && current_node->next) {
    return current_node->next->vertex;
  } else {
    return -1;
  }
}

void DepthFirstSearch(Graph graph, int begin) {
  printf("%c ", graph[begin].data);
  visited[begin] = true;

  for (int i = GetFirstAdjacentVertex(graph, begin); i >= 0;
       i = GetNextAdjacentVertex(graph, begin, i)) {
    if (!visited[i]) {
      DepthFirstSearch(graph, i);
    }
  }
}

void DepthFirstSearchTraverse(Graph graph, int begin, int size) {
  for (int i = 0; i < size; ++i) {
    visited[i] = false;
  }

  DepthFirstSearch(graph, begin);

  for (int i = 0; i < size; ++i) {
    if (!visited[i]) {
      DepthFirstSearch(graph, i);
    }
  }
}

void BreadthFirstSearch(Graph graph, int begin) {
  Queue *queue = CreateQueue();  // Create a queue for BFS

  printf("%c ", graph[begin].data);
  visited[begin] = true;

  Enqueue(queue, begin);
  while (!IsQueueEmpty(queue)) {
    int vertex_index;
    Dequeue(queue, &vertex_index);

    for (int i = GetFirstAdjacentVertex(graph, vertex_index); i >= 0;
         i = GetNextAdjacentVertex(graph, vertex_index, i)) {
      if (!visited[i]) {
        printf("%c ", graph[i].data);
        visited[i] = true;
        Enqueue(queue, i);
      }
    }
  }

  DestroyQueue(queue);  // Destroy the queue after use
}

void BreadthFirstSearchTraverse(Graph graph, int begin, int size) {
  // Initialize all vertices as not visited
  for (int i = 0; i < size; ++i) {
    visited[i] = false;
  }

  // Start BFS from the given starting vertex
  BreadthFirstSearch(graph, begin);

  // If the graph is disconnected, this loop ensures that all components are
  // visited
  for (int i = 0; i < size; ++i) {
    if (!visited[i]) {
      BreadthFirstSearch(graph, i);
    }
  }
}