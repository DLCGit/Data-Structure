// dfs.c

#include "dfs.h"

#include <stdio.h>

// Global variables - definitions
int base[MAX_SET_SIZE * 2], hash[MAX_SET_SIZE * 2];
int solution_count = 0;

// Depth-First Search implementation
void DepthFirstSearch(uint_fast32_t current_step, uint_fast32_t set_size,
                      uint_fast32_t current_state, uint_fast32_t full_set) {
  if (current_state != full_set) {
    uint_fast32_t next, single_bit;
    for (next = (~current_state) & full_set; next;) {  // Get all numbers
      // Get the position of the rightmost bit set to 1
      // single_bit = next & (-next);
      // single_bit = next & (~(next - 1) + 1);
      single_bit = next & ((uint_fast32_t)(-((int_fast32_t)next)));
      next -= single_bit;  // Remove that bit from 'next'
      base[current_step] =
          hash[single_bit %
               HASH_MODULUS];  // Save the position of the current number
      DepthFirstSearch(current_step + 1, set_size, current_state | single_bit,
                       full_set);
    }
  } else {
    for (uint_fast32_t i = 1; i <= set_size; ++i) {
      printf("%d ", base[i]);
    }
    printf("\n");
    solution_count++;
  }
}