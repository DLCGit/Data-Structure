// queue.h

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>

typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;

Queue *CreateQueue();
bool IsQueueEmpty(Queue *queue);
void Enqueue(Queue *queue, int element);
bool Dequeue(Queue *queue, int *data);
void DestroyQueue(Queue *queue);
void TraverseQueue(Queue *queue);

#endif // QUEUE_H_
