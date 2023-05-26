//Time 7min
#include "minheap.h"
#include <stdlib.h>
extern bool Pop(Heap* h, ElemType* e) {
	if ( h== NULL || HeapIsEmpty(h)) {
		return false;
	}
	*e = h->data[0];
	h->data[0] = h->data[h->size - 1];
	h->size -= 1;
	realloc(h->data, sizeof(ElemType) * h->size);
	HeapMinMoveDown(h, 0);
	return true;
}