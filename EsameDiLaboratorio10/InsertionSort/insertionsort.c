//Time 25min
#include <stdlib.h>
#include <string.h>
void InsertionSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	int j = 0;
	for (int i = 1; i < (int)v_size; ++i) {
		j = i;
		int tmp = v[i];
		while (v[j-1] > v[i]) {
			--j;
		}
		if (j != i) {
			memcpy(&v[j + 1], &v[j], (i-j)*(int)sizeof(int));
			v[j] = tmp;
		}
	}
}