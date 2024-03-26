// hash_table.h

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <stdbool.h>

#define HASH_TABLE_SIZE 7

typedef int ElementType;

typedef struct Node {
  ElementType data;
  struct Node* next;
} Node;

typedef struct {
  Node* head;
} HashBucket;

typedef HashBucket* HashTable;

HashTable CreateHashTable(int size);
Node* SearchHashTable(HashTable hash_table, ElementType data);
bool InsertHashTable(HashTable hash_table, ElementType data);
bool DeleteHashTable(HashTable hash_table, ElementType data);
void PrintHashTable(HashTable hash_table, int size);
void DestroyHashTable(HashTable hash_table, int size);

#endif  // HASH_TABLE_H_
