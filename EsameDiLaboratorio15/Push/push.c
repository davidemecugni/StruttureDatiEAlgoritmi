#include "minheap.h"
#include <stdlib.h>
extern void Push(Heap* h, const ElemType* e) {
	HeapMinInsertNode(h, e);
}