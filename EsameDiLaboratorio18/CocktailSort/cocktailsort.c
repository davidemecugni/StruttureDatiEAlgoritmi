//Time 10m 30s
#include <stdlib.h>
#include <stdbool.h>

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void CocktailSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	int start = 0;
	int end = (int)v_size - 1;
	bool scambi = true;
	while (start < end && scambi) {
		scambi = false;
		for (int i = start; i < end; i++) {
			if (v[i] > v[i + 1]) {
				Swap(&v[i], &v[i + 1]);
				scambi = true;
			}
		}
		--end;
		for (int i = end; i > start; i--) {
			if (v[i - 1] > v[i]) {
				Swap(&v[i - 1], &v[i]);
				scambi = true;
			}
		}
		++start;
	}
}