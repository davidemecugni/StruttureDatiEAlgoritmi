#include "maxheap.h"
extern void HeapMaxHeapsort(Heap* h){
	if (HeapIsEmpty(h)) {
		return ;
	}
	size_t original_size = h->size;
	while (h->size > 1) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1));
		h->size -= 1;
		HeapMaxMoveDown(h, 0);
	}
	h->size = original_size;
}