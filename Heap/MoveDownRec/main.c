#include "minheap.h"
#include "minheap.h"
extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);
extern void HeapMinMoveDownRec(Heap* h, int i);
int main(void) {
	ElemType v[] = { 1,2,3,4,5,6,7 };
	size_t s = 8;
	Heap* h = HeapMinHeapify(v, 7);
	h->data[1] = 5;
	HeapWriteStdout(h);
	HeapMinMoveDownRec(h, 1);
	HeapWriteStdout(h);
	return 0;
}
