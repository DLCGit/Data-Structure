// dfs.h

#ifndef DFS_H_
#define DFS_H_

#include <stdint.h>

#define MAX_SET_SIZE 31
#define HASH_MODULUS 37

// Global variables
extern int base[MAX_SET_SIZE * 2];
extern int hash[MAX_SET_SIZE * 2];
extern int solution_count;

// Function prototype
void DepthFirstSearch(uint_fast32_t current_step, uint_fast32_t set_size,
                      uint_fast32_t current_state, uint_fast32_t full_set);

#endif  // DFS_H_
