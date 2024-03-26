// queue.c

#include "queue.h"

#include <stdio.h>
#include <stdlib.h>

Queue *CreateQueue() {
  Queue *queue = (Queue *)malloc(sizeof(Queue));
  if (!queue) {
    fprintf(stderr, "Failed to allocate memory for queue!\n");
    exit(EXIT_FAILURE);
  }

  queue->front = queue->rear = (QueueNode *)malloc(sizeof(QueueNode));
  if (!queue->front) {
    fprintf(stderr, "Failed to allocate memory for queue node!\n");
    free(queue);
    exit(EXIT_FAILURE);
  }

  queue->front->next = NULL;
  return queue;
}

bool IsQueueEmpty(Queue *queue) { return queue->front == queue->rear; }

void Enqueue(Queue *queue, int element) {
  QueueNode *new_node = (QueueNode *)malloc(sizeof(QueueNode));
  if (!new_node) {
    fprintf(stderr, "Failed to allocate memory for queue node!\n");
    exit(EXIT_FAILURE);
  }

  new_node->data = element;
  new_node->next = NULL;

  queue->rear->next = new_node;
  queue->rear = new_node;
}

bool Dequeue(Queue *queue, int *data) {
  if (IsQueueEmpty(queue)) {
    return false;
  }

  QueueNode *temp_node = queue->front->next;
  *data = temp_node->data;
  queue->front->next = temp_node->next;

  if (queue->rear == temp_node) {
    queue->rear = queue->front;
  }

  free(temp_node);
  return true;
}

void DestroyQueue(Queue *queue) {
  while (!IsQueueEmpty(queue)) {
    int data;
    Dequeue(queue, &data);  // Using Dequeue to free nodes
  }
  free(queue->front);  // Free the sentinel node
  free(queue);         // Free the queue structure
}

void TraverseQueue(Queue *queue) {
  if (IsQueueEmpty(queue)) {
    puts("The queue is empty!");
  } else {
    QueueNode *current = queue->front->next;
    printf("Queue elements: ");
    while (current) {
      printf("%d ", current->data);
      current = current->next;
    }
    putchar('\n');
  }
}