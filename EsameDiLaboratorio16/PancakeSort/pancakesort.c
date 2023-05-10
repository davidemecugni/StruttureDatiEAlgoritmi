//Time 23m 46s
#include <stdlib.h>
//Finds the index of an array up to elements <= of dim
int FindMax(int* v, int dim) {
	if (v == NULL) {
		return -1;
	}
	int max = v[0];
	int index_max = 0;
	for (int i = 1; i <= dim; i++) {
		if (v[i] > max) {
			max = v[i];
			index_max = i;
		}
	}
	return index_max;
}
//Swap for int
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//Inverts the elements of an array up to to_flip
//Ex [1,2,3,4,5,6] to_flip = 2 -> [3,2,1,4,5,6]
void Flip(int* v, int to_flip) {
	int left = 0, right = to_flip;
	while (left < right) {
		Swap(&v[left], &v[right]);
		left++;
		right--;
	}
}
void PancakeSort(int* v, size_t v_size) {
	if (v == NULL || v_size <= 1) {
		return;
	}
	int curr_size = (int)v_size;
	;
	int m;
	//For every element, finds the max, puts it in v[0]
	//Flips the entire v(putting the max at the end
	while (curr_size != 1) {
		m = FindMax(v, curr_size - 1);
		Flip(v, m);
		Flip(v, curr_size - 1);
		--curr_size;
	}
	return;
}