#include "maxheap.h"
extern bool HeapMaxPop(Heap* h, ElemType* e) {
	if (HeapIsEmpty(h) || e == NULL) {
		return false;
	}
	*e = h->data[0];
	h->data[0] = h->data[h->size - 1];
	h->size -= 1;
	HeapMaxMoveDown(h, 0);
	return true;
}