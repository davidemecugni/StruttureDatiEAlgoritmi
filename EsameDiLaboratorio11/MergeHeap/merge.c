#include "minheap.h"


Heap* MergeHeap(const Heap* h1, const Heap* h2) {
	Heap* res = HeapCreateEmpty();
	size_t h1_size = h1->size, h2_size = h2->size;
	while (h1_size > 0 && h1 != NULL) {
		HeapMinInsertNode(res, &h1->data[(int)h1_size - 1]);
		h1_size--;
	}
	while (h2_size > 0 && h2 != NULL) {
		HeapMinInsertNode(res, &h2->data[(int)h2_size - 1]);
		h2_size--;
	}
	return res;
}