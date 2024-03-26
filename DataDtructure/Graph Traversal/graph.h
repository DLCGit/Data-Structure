// graph.h

#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdbool.h>

#define VERTEX_MAX_SIZE 6

typedef struct Node {
    int vertex;
    struct Node *next;
} Node;

typedef struct GraphHead {
    char data;
    Node *first_edge;
} GraphHead;

typedef GraphHead *Graph;

Graph CreateGraph(int size);
int GetFirstAdjacentVertex(Graph graph, int begin);
int GetNextAdjacentVertex(Graph graph, int vertex_index, int current_adjacent_vertex);
void DepthFirstSearch(Graph graph, int begin);
void DepthFirstSearchTraverse(Graph graph, int begin, int size);
void BreadthFirstSearch(Graph graph, int begin);
void BreadthFirstSearchTraverse(Graph graph, int begin, int size);

#endif // GRAPH_H_
