#include "minheap.h"
#include <stdlib.h>
extern ElemType KthLeast(const Heap* h, int k);

int main(void) {
	Heap* h = HeapCreateEmpty();
	h->size = 4;
	int *data = calloc(4, sizeof(ElemType));
	data[0] = -1;
	data[1] = 3;
	data[2] = 6;
	data[3] = 4;
	h->data = data;
	printf("KthLeast %d = %d\n", 4, KthLeast(h, 4));
	return 0;
}