#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "array_merge.h"
#include "../mergesort/mergesort.c"
#include "../mergesort/mergesort.h"

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

int removedupe(int* array, int size){
  int* temp = (int*) malloc(size * sizeof(int));
  int j;
  if (size < 2){
    return size
  }
  for(int i=0; i<size-1; i++){
    if (array[i] != array[i+1]){
      temp[j++] = array[i];
    }
  }
  temp[j++] = arr[size-1];
  for (int i=0; i<j; i++){
    arr[i]=temp[i];
  }  
  free(temp);
  return j;
}

free(presortedArray);

// should return the combined sorted num_array
return sizes;

}


int main() {
int num_arrays = 3;
int sizes[3] = {3, 3, 3};
int a0[] = {0, 2, 1};
int a1[] = {3, 5, 5};
int a2[] = {6, 7, 7};
int* values[] = {a0, a1, a2};

array_merge(num_arrays, sizes, values);

}
