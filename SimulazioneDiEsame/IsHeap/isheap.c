//Time 15min
#include "minheap.h"
bool IsHeapRec(const Heap* h, int current) {
	if (current >= (int)h->size) {
		return true;
	}
	ElemType* val = HeapGetNodeValue(h, current);
	ElemType* r = NULL;
	ElemType* l = NULL;
	if (HeapLeft(current) < (int)h->size) {
		l = HeapGetNodeValue(h, HeapLeft(current));
	}	
	if (HeapRight(current) < (int)h->size) {
		r = HeapGetNodeValue(h, HeapRight(current));
	}
	if (l != NULL && ElemCompare(val, l) > 0) {
		return false;
	}
	if(r != NULL &&ElemCompare(val, r) > 0) {
		return false;
	}
	return IsHeapRec(h, HeapRight(current)) && IsHeapRec(h, HeapLeft(current));
}
extern bool IsHeap(const Heap* h) {
	if (h == NULL) {
		return false;
	}
	return IsHeapRec(h, 0);
}