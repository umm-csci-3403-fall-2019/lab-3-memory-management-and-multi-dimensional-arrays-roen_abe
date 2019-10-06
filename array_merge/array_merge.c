#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "array_merge.h"
#include "../mergesort/mergesort.c"
#include "../mergesort/mergesort.h"

int removedupe(int* arr, int size){
  int* temp = (int*) malloc(size * sizeof(int));
  int j = 0;
  if (size < 2){
    return size;
  }
  for(int i=0; i<size-1; i++){
    if (arr[i] != arr[i+1]){
      temp[j++] = arr[i];
    }
  }
  temp[j++] = arr[size-1];
  int* sortedArray = (int*) malloc((j+1) * sizeof(int));
  sortedArray[0] = j;
  for (int i=0; i<j; i++){
    sortedArray[i+1]=temp[i];
  }
  for(int i=0; i<j+1; i++){
    printf("Next is %d \n", sortedArray[i]);
  }
  free(sortedArray);
  free(temp);
  return j;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
// calculate how many elements are in all arrays
  int size = 0;
  for (int i = 0; i < num_arrays; i++) {
    size += sizes[i] ;
  }
  printf("Size is %d \n", size);
//? memory for all the size arrays
int* presortedArray = (int*) malloc(size * sizeof(int));
  // combine all the elements from all the arrays
  int count = 0;
for (int i = 0; i<num_arrays; i++){
  for(int j = 0; j<sizes[i]; j++){
    presortedArray[count] = values[i][j];
    count++;
  }
}
mergesort(size, presortedArray);
for(int i=0; i<size; i++){
  printf("Next is %d \n", presortedArray[i]);
}
printf("-------------------------------------------\n");
printf("The array with unique values:\n");
removedupe(presortedArray, size);


free(presortedArray);
// should return the combined sorted num_array
return sizes;
}

int main() {
int num_arrays = 3;
int sizes[3] = {3, 3, 3};
int a0[] = {0, 2, 0};
int a1[] = {3, 5, 5};
int a2[] = {7, 7, 9};
int* values[] = {a0, a1, a2};
array_merge(num_arrays, sizes, values);
}
