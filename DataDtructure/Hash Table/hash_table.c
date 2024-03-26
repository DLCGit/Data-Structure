// hash_table.c

#include "hash_table.h"

#include <stdio.h>
#include <stdlib.h>

HashTable CreateHashTable(int size) {
  HashTable hash_table = (HashTable)malloc(size * sizeof(HashBucket));
  if (hash_table == NULL) {
    fprintf(stderr, "Failed to allocate memory for hash table.\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < size; ++i) {
    hash_table[i].head = NULL;
  }

  return hash_table;
}

static int HashFunction(ElementType data) { return data % HASH_TABLE_SIZE; }

Node *SearchHashTable(HashTable hash_table, ElementType data) {
  if (hash_table == NULL) {
    return NULL;
  }

  Node *current = hash_table[HashFunction(data)].head;
  while (current && current->data != data) {
    current = current->next;
  }

  return current;
}

bool InsertHashTable(HashTable hash_table, ElementType data) {
  if (SearchHashTable(hash_table, data)) {
    return false;
  }

  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    fprintf(stderr, "Failed to allocate memory for node.\n");
    exit(EXIT_FAILURE);
  }
  new_node->data = data;
  new_node->next = NULL;

  int index = HashFunction(data);
  Node *current = hash_table[index].head;

  if (current == NULL) {
    hash_table[index].head = new_node;
  } else {
    while (current->next) {
      current = current->next;
    }
    current->next = new_node;
  }

  return true;
}

bool DeleteHashTable(HashTable hash_table, ElementType data) {
  int index = HashFunction(data);
  Node *current = hash_table[index].head;
  Node *previous = NULL;

  while (current && current->data != data) {
    previous = current;
    current = current->next;
  }

  if (current == NULL) {
    return false;
  }

  if (previous == NULL) {
    hash_table[index].head = current->next;
  } else {
    previous->next = current->next;
  }

  free(current);
  return true;
}

void PrintHashTable(HashTable hash_table, int size) {
  for (int i = 0; i < size; i++) {
    Node *current = hash_table[i].head;
    printf("[%d]:", i);
    while (current != NULL) {
      printf(" %d ->", current->data);
      current = current->next;
    }
    printf(" NULL\n");
  }
}

void DestroyHashTable(HashTable hash_table, int size) {
  for (int i = 0; i < size; ++i) {
    Node *current = hash_table[i].head;
    Node *temp;

    while (current) {
      temp = current;
      current = current->next;
      free(temp);
    }
  }

  free(hash_table);
}