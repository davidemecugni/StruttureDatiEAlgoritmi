#include "minheap.h"
extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);
extern bool HeapMinPop(Heap* h, ElemType* e);
int main(void) {
	ElemType v[] = { 1,2,3,4,5,6,7,8,9,10 };
	size_t s = 10;
	Heap* h = HeapMinHeapify(v, s);
	HeapWriteStdout(h);
	ElemType r;
	bool res = HeapMinPop(h, &r);
	HeapWriteStdout(h);
	return 0;
}