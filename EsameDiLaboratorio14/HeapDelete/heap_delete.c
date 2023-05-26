//Time 9m 30s
#include "minheap.h"
#include <stdlib.h>
extern void HeapDeleteNode(Heap* h, int k) {
	if (k<0 || k>=(int)h->size) {
		return;
	}
	h->data[k] = h->data[h->size - 1];
	h->size -= 1;
	realloc(h->data, sizeof(ElemType) * h->size);
	HeapMinMoveDown(h, (size_t)k);
}