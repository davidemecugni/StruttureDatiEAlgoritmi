#include "minheap.h"
#include <stdlib.h>
extern void HeapDeleteNode(Heap* h, int k);
int main(void) {
	Heap* h = HeapCreateEmpty();
	h->size = 10;
	ElemType* v = calloc(10, sizeof(ElemType));
	for (int i = 0; i < 10; i++) {
		v[i] = i;
	}
	h->data = v;
	HeapDeleteNode(h, 0);
	HeapWriteStdout(h);
	return 0;
}