//Time 10min
#include <stdlib.h>
#include <stdbool.h>
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
extern void BrickSort(int* v, size_t v_size) {
	if(v == NULL || v_size < 2) {
		return;
	}
	bool ordered = false;
	while (!ordered) {
		ordered = true;
		for (int i = 0; i < (int)v_size; i += 2) {
			if (i + 1 < (int)v_size) {
				if (v[i] > v[i + 1]) {
					ordered = false;
					Swap(&v[i], &v[i + 1]);
				}
			}
		}
		for (int i = 1; i < (int)v_size; i += 2) {
			if (i + 1 < (int)v_size) {
				if (v[i] > v[i + 1]) {
					ordered = false;
					Swap(&v[i], &v[i + 1]);
				}
			}
		}
	}
}