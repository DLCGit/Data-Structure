//main.c

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_shift.h"

/*
  Enter the number of elements in the array: 10
  Please enter 10 decimal integer elements, separated by spaces: 1
  2
  3
  4
  5
  6
  7
  8
  9
  10
  Array left shifted by 0 positions: 1  2  3  4  5  6  7  8  9  10
  Array left shifted by 1 positions: 2  3  4  5  6  7  8  9  10 1
  Array left shifted by 2 positions: 3  4  5  6  7  8  9  10 1  2
  Array left shifted by 3 positions: 4  5  6  7  8  9  10 1  2  3
  Array left shifted by 4 positions: 5  6  7  8  9  10 1  2  3  4
  Array left shifted by 5 positions: 6  7  8  9  10 1  2  3  4  5
  Array left shifted by 6 positions: 7  8  9  10 1  2  3  4  5  6
  Array left shifted by 7 positions: 8  9  10 1  2  3  4  5  6  7
  Array left shifted by 8 positions: 9  10 1  2  3  4  5  6  7  8
  Array left shifted by 9 positions: 10 1  2  3  4  5  6  7  8  9

  Array right shifted by 0 positions: 1  2  3  4  5  6  7  8  9  10
  Array right shifted by 1 positions: 10 1  2  3  4  5  6  7  8  9
  Array right shifted by 2 positions: 9  10 1  2  3  4  5  6  7  8
  Array right shifted by 3 positions: 8  9  10 1  2  3  4  5  6  7
  Array right shifted by 4 positions: 7  8  9  10 1  2  3  4  5  6
  Array right shifted by 5 positions: 6  7  8  9  10 1  2  3  4  5
  Array right shifted by 6 positions: 5  6  7  8  9  10 1  2  3  4
  Array right shifted by 7 positions: 4  5  6  7  8  9  10 1  2  3
  Array right shifted by 8 positions: 3  4  5  6  7  8  9  10 1  2
  Array right shifted by 9 positions: 2  3  4  5  6  7  8  9  10 1
*/

int main() {
  int length;
  printf("Enter the number of elements in the array: ");
#if defined(_MSC_VER) && defined(_MSVC_LANG) && (_MSVC_LANG >= 202002L)
  // C++ 14: 201402L
  // C++ 17: 201703L
  // C++20 and C++23 preview: 202002L
  #define _CRT_SECURE_NO_WARNINGS
  scanf_s("%d", &length);
#else
  scanf("%d", &length);
#endif  // ^^^ _MSC_VER

  assert(length > 0);

  int *start = (int *)malloc(sizeof(int) * length);
  int *end = (int *)malloc(sizeof(int) * length);
  assert(start && end);

  InputElements(start, length);
  LeftShiftArray(start, end, length);
  printf("\n");
  RightShiftArray(start, end, length);
  printf("\n");

  free(start);
  free(end);

  return 0;
}