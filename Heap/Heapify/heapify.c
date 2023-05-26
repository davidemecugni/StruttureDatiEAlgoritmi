#include "minheap.h"
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