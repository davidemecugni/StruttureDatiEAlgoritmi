#include "maxheap.h"

extern Heap* HeapMaxHeapify(const ElemType* v, size_t v_size);
extern bool HeapMaxPop(Heap* h, ElemType* e);
extern void HeapMaxHeapsort(Heap* h);
int main(void) {
	ElemType v[] = { 1,4,2,5,3,6,8,7 };
	size_t s = 8;
	Heap* h = HeapMaxHeapify(v, s);
	HeapWriteStdout(h);
	ElemType elem;
	HeapMaxPop(h, &elem);
	printf("Max: %d\n", elem);
	HeapWriteStdout(h);
	HeapMaxHeapsort(h);
	HeapWriteStdout(h);
	return 0;
}
