#include "mergesort.h"

int* slice(int *arr, int startIndex, int endIndex){
	int *result = (int *) malloc((endIndex - startIndex) * sizeof(int));
	int i;
	for(i = startIndex; i<endIndex; i++) {
		result[i-startIndex] = arr[i];
	}
	return result;
}

void merge(int *result, int *left, int *right, int leftLen, int rightLen) {
	int i = 0, j = 0;
	while(i < leftLen && j < rightLen) {
		if (left[i] < right[i]){
			result[i+j] = left[i];
			i++;
		}
		else {
			result[i+j] = right[j];
			j++;
		}
	}
	for(; i<leftLen; i++){
		result[i+j] = left[i];
	}
	for(; j<rightLen; j++){
		result[i+j] = right[j];
	}
	free(left);
	free(right);
}

void mergesort(int len, int *arr){
	if (len <=1){
		return;
	}
	int *left = slice(arr, 0, len / 2 + 1);
	int *right = slice(arr, len / 2, len);

	printf("left: ");
	printArray(left, len / 2);
	printf("right: ");
	printArray(right, len - (len /2));

	mergesort(len / 2, left);
	mergesort(len - (len / 2), right);

	merge(arr, left, right, len / 2, len - (len / 2));
}

void printArray(int* arr, int len){
	int i = 0;
	printf("[");
	for(; i < len; i++){
		printf("%d, ", arr[i]);
	}
	printf("]\n");
}
