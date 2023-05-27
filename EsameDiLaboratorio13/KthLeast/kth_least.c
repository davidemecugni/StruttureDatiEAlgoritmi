//Time 16min
#define _CRT_SECURE_NO_WARNINGS
#include "minheap.h"
#include <string.h>
#include <stdlib.h>
void Swap(ElemType* a, ElemType* b) {
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}
extern int KthLeast(const Heap* h, int k) {
	Heap* h_copy = HeapCreateEmpty();
	h_copy->size = h->size;
	h_copy->data = calloc(h->size, sizeof(ElemType));
	memcpy(h_copy->data, h->data, sizeof(ElemType) * h->size);
	int original_size = (int)h_copy->size;
	while ((int)h_copy->size > 1) {
		Swap(&h_copy->data[0], &h_copy->data[h_copy->size - 1]);
		h_copy->size--;
		HeapMinMoveDown(h_copy, 0);
	}
	int res = h_copy->data[original_size - k];
	h_copy->size = original_size;
	HeapDelete(h_copy);
	return res;
}
