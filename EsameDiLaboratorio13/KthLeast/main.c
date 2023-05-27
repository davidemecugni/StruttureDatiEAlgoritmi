#include "minheap.h"
#include <stdlib.h>
extern ElemType KthLeast(const Heap* h, int k);

int main(void) {
	Heap* h = HeapCreateEmpty();
	h->size = 4;
	int *data = calloc(9, sizeof(ElemType));
	data[0] = 0;
	data[1] = 2;
	data[2] = 4;
	data[3] = 8;
	data[4] = 12;
	data[5] = 18;
	data[6] = 77;
	data[7] = 21;
	data[8] = 9;
	h->data = data;
	printf("KthLeast %d = %d\n", 1, KthLeast(h, 1));
	return 0;
}