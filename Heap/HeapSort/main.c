#include "minheap.h"
#include "minheap.h"
extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);
extern void HeapMinHeapsort(Heap* h);
int main(void) {
	ElemType v[] = { 1 };
	size_t s = 8;
	Heap* h = HeapMinHeapify(v, 1);
	h->data[1] = 5;
	HeapWriteStdout(h);
	HeapMinHeapsort(h);
	HeapWriteStdout(h);
	return 0;
}
