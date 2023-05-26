#include "minheap.h"
extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);
int main(void) {
	ElemType *v = NULL;
	size_t s = 8;
	Heap* h = HeapMinHeapify(v, s);
	HeapWriteStdout(h);
	return 0;
}