//Time 17m 24s
#include <stdlib.h>
//Counts the number of elements in v equal to element
int CountElements(int* v, size_t size, int element) {
	int count = 0;
	for (int i = 0; i < (int)size; i++) {
		if (v[i] == element) {
			count++;
		}
	}
	return count;
}
//Finds the index of the smallest element
int MinIndex(int* v, size_t size) {
	int min = 0;
	for (int i = 0; i < (int)size; i++) {
		if (v[i] < v[min]) {
			min = i;
		}
	}
	return min;
}
//Finds the index of the greatest element
int MaxIndex(int* v, size_t size) {
	int max = 0;
	for (int i = 0; i < (int)size; i++) {
		if (v[i] > v[max]) {
			max = i;
		}
	}
	return max;
}
void CountingSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	int max = v[MaxIndex(v, v_size)];
	int min = v[MinIndex(v, v_size)];
	//Contains the number of times an element appears from min to max
	int* tmp = calloc((size_t)(max - min + 1), sizeof(int));
	if (tmp == NULL) {
		return;
	}
	//Counts the times every element appears
	for (int i = min; i < max + 1; i++) {
		tmp[i - min] = CountElements(v, v_size, i);
	}
	int index = 0;
	//Orders the elements inserting the number of times every element appears
	for(int i=0;i<max-min+1;i++){
		for (int j = 0; j < tmp[i]; j++, index++) {
			v[index] = min + i;
		}
	}
	free(tmp);
}