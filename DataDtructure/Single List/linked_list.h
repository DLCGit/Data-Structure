// linked_list.h

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdbool.h>

// A structure for a singly linked list node.
typedef struct ListNode {
  int value;              ///< The value of the node.
  struct ListNode *next;  ///< Pointer to the next node in the list.
} ListNode;

// Adds nodes to the linked list from user input until non-numeric input is
// provided.
void AddNodes(ListNode **head);

// Checks whether a given value exists in the linked list.
bool CheckDuplicate(const ListNode *head, int value);

// Inserts a new node with the given value into the linked list in a sorted
// position.
bool InsertNode(ListNode **head, int value);

// Deletes the first node with the given value from the linked list.
void DeleteNode(ListNode **head, int value);

// Sorts the linked list using a bubble sort algorithm.
void SortList(ListNode *head);

// Prints all the values in the linked list.
void PrintList(const ListNode *head);

// Frees all the nodes in the linked list.
void FreeList(ListNode **head);

// Returns the size of the linked list.
unsigned int GetListSize(const ListNode *head);

#endif // LINKED_LIST_H_
