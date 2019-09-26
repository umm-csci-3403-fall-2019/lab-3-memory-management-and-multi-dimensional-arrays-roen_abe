#ifndef MERGESORT_H_GUARD
#define MERGESORT_H_GUARD

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define UNIT_TESTING
int* slice(int *arr, int start, int end);
void merge(int *result, int *left, int *right, int leftLen, int rightLen);
void mergesort(int *arr, int len);
void printArray(int* arr, int len);
#endif
