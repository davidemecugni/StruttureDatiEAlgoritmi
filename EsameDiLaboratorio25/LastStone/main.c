#include "maxheap.h"
extern int LastStoneWeight(Heap* h);
int main(void) {
	Heap* h = HeapCreateEmpty();
	ElemType x = 77;
	HeapMaxInsertNode(h, &x);
	x = 21;
	HeapMaxInsertNode(h, &x);
	x = 18;
	HeapMaxInsertNode(h, &x);
	HeapWriteStdout(h);
	printf("%d", LastStoneWeight(h));
	return 0;
}