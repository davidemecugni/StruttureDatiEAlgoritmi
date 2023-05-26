#include "minheap.h"
extern void HeapMinHeapsort(Heap* h){
	if (HeapIsEmpty(h)) {
		return ;
	}
	size_t original_size = h->size;
	while (h->size > 1) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, (int)h->size - 1));
		h->size -= 1;
		HeapMinMoveDown(h, 0);
	}
	h->size = original_size;
}
extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size == 0) {
		return HeapCreateEmpty();
	}
	Heap* h = HeapCreateEmpty();
	for (size_t i = 0; i < v_size; i++) {
		HeapMinInsertNode(h, &v[i]);
	}
	return h;
}