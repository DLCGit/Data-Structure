// main.c

#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"

/*
  Creating hash table of size: 7
  Testing insertion...
  [0]: NULL
  [1]: 1 -> 8 -> 15 -> NULL
  [2]: 2 -> NULL
  [3]: NULL
  [4]: NULL
  [5]: NULL
  [6]: NULL
  Testing search...
  Searching for 1: FOUND
  Searching for 3: NOT FOUND
  Testing deletion...
  Deleting 1: SUCCESS
  Deleting 15: SUCCESS
  Deleting 42 (not present): FAIL
  [0]: NULL
  [1]: 8 -> NULL
  [2]: 2 -> NULL
  [3]: NULL
  [4]: NULL
  [5]: NULL
  [6]: NULL
  Destroying hash table...
  Hash table destroyed.
*/

int main() {
  int size = HASH_TABLE_SIZE;
  printf("Creating hash table of size: %d\n", size);
  HashTable hash_table = CreateHashTable(size);

  // Test insertion
  printf("Testing insertion...\n");
  InsertHashTable(hash_table, 1);
  InsertHashTable(hash_table, 2);
  InsertHashTable(hash_table, 8);  // This should go to the same bucket as 1
  InsertHashTable(hash_table,
                  15);  // This should go to the same bucket as 1 and 8

  PrintHashTable(hash_table, size);

  // Test search
  printf("Testing search...\n");
  Node *search_result;
  search_result = SearchHashTable(hash_table, 1);
  printf("Searching for 1: %s\n",
         search_result != NULL ? "FOUND" : "NOT FOUND");
  search_result = SearchHashTable(hash_table, 3);
  printf("Searching for 3: %s\n",
         search_result != NULL ? "FOUND" : "NOT FOUND");

  // Test deletion
  printf("Testing deletion...\n");
  bool delete_success;
  delete_success = DeleteHashTable(hash_table, 1);
  printf("Deleting 1: %s\n", delete_success ? "SUCCESS" : "FAIL");
  delete_success = DeleteHashTable(hash_table, 15);
  printf("Deleting 15: %s\n", delete_success ? "SUCCESS" : "FAIL");
  delete_success = DeleteHashTable(hash_table, 42);
  printf("Deleting 42 (not present): %s\n",
         delete_success ? "SUCCESS" : "FAIL");

  PrintHashTable(hash_table, size);

  // Test destruction
  printf("Destroying hash table...\n");
  DestroyHashTable(hash_table, size);
  printf("Hash table destroyed.\n");

  return EXIT_SUCCESS;
}