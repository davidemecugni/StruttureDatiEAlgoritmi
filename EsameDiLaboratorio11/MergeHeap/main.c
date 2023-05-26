//Time 10m 44s
#include "minheap.h"
extern Heap* MergeHeap(const Heap* h1, const Heap* h2);
int main(void) {
	Heap* h1 = HeapCreateEmpty();
	h1->size = 5;
	int v[] = { 1,2,3,4,5 };
	h1->data = v;
	Heap* h2 = HeapCreateEmpty();
	h2->size = 5;
	int v_2[] = {6,7,8,9,10 };
	h2->data = v_2;
	Heap* res = MergeHeap(h1, h2);
	HeapWriteStdout(res);
	HeapDelete(res);
	return 0;
}