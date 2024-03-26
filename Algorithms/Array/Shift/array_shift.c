// array_shift.c

#include "array_shift.h"

#include <stdio.h>

void InputElements(int *elements, int count) {
  printf("Please enter %d decimal integer elements, separated by spaces: ",
         count);
  for (int i = 0; i < count; i++) {
    // Use our custom macro that selects the correct function
#if defined(_MSC_VER) && defined(_MSVC_LANG) && (_MSVC_LANG >= 202002L)
    // C++ 14: 201402L
    // C++ 17: 201703L
    // C++20 and C++23 preview: 202002L
    #define _CRT_SECURE_NO_WARNINGS
    scanf_s("%d", &elements[i]);
#else
    scanf("%d", &elements[i]);
#endif  // ^^^ _MSC_VER
  }
}

void PrintElements(const int *elements, int count) {
  for (int i = 0; i < count; i++) {
    printf("%-3d", elements[i]);
  }
  printf("\n");
}

void LeftShiftArray(const int *source, int *destination, int count) {
  for (int i = 0; i < count; ++i) {
    int j, k;
    for (j = 0; j < (count - i); ++j) {
      destination[j] = source[i + j];
    }
    for (k = 0; k < i; ++k) {
      destination[j + k] = source[k];
    }
    printf("Array left shifted by %d positions: ", i);
    PrintElements(destination, count);
  }
}

void RightShiftArray(const int *source, int *destination, int count) {
  for (int i = 0; i < count; ++i) {
    int j, k;
    for (j = 0; j < count - i; ++j) {
      destination[i + j] = source[j];
    }
    for (k = 0; k < i; ++k) {
      destination[k] = source[count - i + k];
    }
    printf("Array right shifted by %d positions: ", i);
    PrintElements(destination, count);
  }
}