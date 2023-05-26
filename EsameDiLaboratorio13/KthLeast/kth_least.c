//Time 39m 
//Tried other solution before this trivial one
#define _CRT_SECURE_NO_WARNINGS
#include "minheap.h"
#include <stdlib.h>
#include <string.h>
int Compare(const void* a, const void* b) {
	const ElemType* x = a;
	const ElemType* y = b;
	return ElemCompare(x, y);
}
extern ElemType KthLeast(const Heap* h, int k) {
	ElemType* copy = malloc(h->size * sizeof(ElemType));
	memcpy(copy, h->data, h->size * sizeof(ElemType));
	qsort(copy, h->size, sizeof(ElemType), &Compare);
	ElemType res = copy[k - 1];
	free(copy);
	return res;
}