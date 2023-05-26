#include "minheap.h"
#include <string.h>
#include <stdlib.h>
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
extern bool HeapMinPop(Heap* h, ElemType* e) {
	if (HeapIsEmpty(h) || e == NULL) {
		return false;
	}
	*e = ElemCopy(h->data);
	h->data[0] = h->data[h->size - 1];
	h->size -= 1;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, 0);
	return true;
}