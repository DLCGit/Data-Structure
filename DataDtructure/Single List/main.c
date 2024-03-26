// main.c

#include <stdio.h>

#include "linked_list.h"

/*
  Enter a number (ending with the character 'q'): 1
  Enter another number (ending with the character 'q'): 2
  Enter another number (ending with the character 'q'): 3
  Enter another number (ending with the character 'q'): 4
  Enter another number (ending with the character 'q'): 5
  Enter another number (ending with the character 'q'): 10
  Enter another number (ending with the character 'q'): 0
  Enter another number (ending with the character 'q'): -1
  Enter another number (ending with the character 'q'): q
  Value 10 is a duplicate.
  Value 5 inserted into the list.
  Sorted list: -1 0 1 2 3 4 5 5 10
  List after deleting value 3: -1 0 1 2 4 5 5 10
  Final list: -1 0 1 2 4 5 5 10
  The list contains 8 elements.
*/

int main() {
  ListNode *head = NULL;  // Start with an empty linked list.

  // Add nodes to the linked list.
  AddNodes(&head);

  // Check for duplicates.
  int value_to_check = 10;  // Example value to check.
  if (CheckDuplicate(head, value_to_check)) {
    printf("Value %d is a duplicate.\n", value_to_check);
  } else {
    printf("Value %d is not a duplicate.\n", value_to_check);
  }

  // Insert a node into the linked list.
  int value_to_insert = 5;  // Example value to insert.
  if (InsertNode(&head, value_to_insert)) {
    printf("Value %d inserted into the list.\n", value_to_insert);
  } else {
    printf("Failed to insert value %d into the list.\n", value_to_insert);
  }

  // Sort the linked list.
  SortList(head);
  printf("Sorted list: ");
  PrintList(head);

  // Delete a node from the linked list.
  int value_to_delete = 3;  // Example value to delete.
  DeleteNode(&head, value_to_delete);
  printf("List after deleting value %d: ", value_to_delete);
  PrintList(head);

  // Print the final list.
  printf("Final list: ");
  PrintList(head);

  // Get the size of the list.
  unsigned int list_size = GetListSize(head);
  printf("The list contains %u elements.\n", list_size);

  // Free the allocated memory for the list.
  FreeList(&head);

  return 0;
}