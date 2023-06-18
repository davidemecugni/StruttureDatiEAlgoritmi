//Time 11min
#include <stdlib.h>
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
size_t TwoThirds(size_t n) {
	if (n % 3 == 0) {
		return (2 * n) / 3;
	}
	return (2 * n) / 3 + 1;
}
void Stooge(int* vector, size_t vector_size) {
	if (vector == NULL || vector_size < 2) {
		return;
	}
	if (vector[0] > vector[vector_size - 1]) {
		Swap(&vector[0], &vector[vector_size - 1]);
	}
	if (vector_size >= 3) {
		Stooge(vector, TwoThirds(vector_size));
		Stooge(vector + (vector_size/3 ), TwoThirds(vector_size));
		Stooge(vector, TwoThirds(vector_size));
	}
}