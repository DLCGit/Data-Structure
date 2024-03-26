// linked_list.c

#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

// Prompts the user to enter numbers to add to the list. Ends when a non-numeric
// input is entered.
void AddNodes(ListNode **head) {
  int value;
  char input[50];  // Buffer to hold the input string.

  printf("Enter a number (ending with the character 'q'): ");
#if defined(_MSC_VER) && defined(_MSVC_LANG) && (_MSVC_LANG >= 202002L)
  // C++ 14: 201402L
  // C++ 17: 201703L
  // C++20 and C++23 preview: 202002L
  #define _CRT_SECURE_NO_WARNINGS
  while (scanf_s("%49s", input, (unsigned)_countof(input)) == 1) {  // Read input as string to check for 'q'.
#else
  while (scanf("%49s", input) == 1) {  // Read input as string to check for 'q'.
#endif  // ^^^ _MSC_VER

    // Check if the first character is 'q' to end input.
    if (input[0] == 'q') {
      break;
    }

    // Attempt to convert the input to an integer and check for successful
    // conversion.
    char *endptr;
    value = strtol(input, &endptr, 10);

    // If no valid conversion could be performed, prompt the user again.
    if (endptr == input) {
      printf("Invalid input. Please enter a valid number or 'q' to quit: ");
      continue;
    }

    // Clear the input buffer.
    while (getchar() != '\n') continue;

    // Allocate memory for the new node.
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
    if (!new_node) {
      printf("Memory allocation failed.\n");
      return;
    }

    // Assign the value to the new node and insert it at the head of the list.
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;

    // Prompt for the next number.
    printf("Enter another number (ending with the character 'q'): ");
  }
}

// Checks for a duplicate value in the list. Returns true if found, false
// otherwise.
bool CheckDuplicate(const ListNode *head, int value) {
  while (head != NULL) {
    if (head->value == value) return true;
    head = head->next;
  }
  return false;
}

// Inserts a node with the given value into the sorted linked list.
bool InsertNode(ListNode **head, int new_value) {
  ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
  if (!new_node) return false;

  new_node->value = new_value;
  new_node->next = NULL;

  ListNode *current = *head;
  ListNode *previous = NULL;

  while (current != NULL && new_value > current->value) {
    previous = current;
    current = current->next;
  }

  new_node->next = current;

  if (previous == NULL) {
    *head = new_node;
  } else {
    previous->next = new_node;
  }

  return true;
}

// Deletes the first node with the specified value from the linked list.
void DeleteNode(ListNode **head, int value_to_delete) {
  ListNode *current = *head;
  ListNode *previous = NULL;

  while (current != NULL && current->value != value_to_delete) {
    previous = current;
    current = current->next;
  }

  if (current == NULL) return;

  if (previous == NULL) {
    *head = current->next;
  } else {
    previous->next = current->next;
  }

  free(current);
}

// Sorts the linked list using the bubble sort algorithm.
void SortList(ListNode *head) {
  ListNode *i, *j;
  int temp;

  for (i = head; i != NULL && i->next != NULL; i = i->next) {
    for (j = head; j->next != NULL; j = j->next) {
      if (j->value > j->next->value) {
        temp = j->value;
        j->value = j->next->value;
        j->next->value = temp;
      }
    }
  }
}

// Prints the values of all nodes in the linked list.
void PrintList(const ListNode *head) {
  if (head == NULL) {
    printf("The list is empty!\n");
    return;
  }

  while (head != NULL) {
    printf("%d ", head->value);
    head = head->next;
  }
  printf("\n");
}

// Frees all the nodes in the linked list.
void FreeList(ListNode **head) {
  ListNode *current = *head;
  ListNode *next;

  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  *head = NULL;
}

// Returns the number of elements in the linked list.
unsigned int GetListSize(const ListNode *head) {
  unsigned int size = 0;
  while (head != NULL) {
    size++;
    head = head->next;
  }
  return size;
}