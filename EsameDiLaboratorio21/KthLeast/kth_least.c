//Time 16min
#include "minheap.h"

void Swap(ElemType* a, ElemType* b) {
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}
extern int KthLeast(const int* v, size_t n, int k) {
	Heap* h = HeapCreateEmpty();
	//Create heap
	for (int i = 0; i < (int)n; i++) {
		HeapMinInsertNode(h, &v[i]);
	}
	int original_size = (int)h->size;
	while ((int)h->size > 1) {
		Swap(&h->data[0], &h->data[h->size - 1]);
		h->size--;
		HeapMinMoveDown(h, 0);
	}
	int res = h->data[original_size - k];
	h->size = original_size;
	HeapDelete(h);
	return res;
}
