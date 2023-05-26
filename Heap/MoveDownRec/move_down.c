#include "minheap.h"
extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
    if (v == NULL || v_size == 0) {
        return HeapCreateEmpty();
    }
    Heap* h = HeapCreateEmpty();
    for (size_t i = 0; i < v_size; i++) {
        HeapMinInsertNode(h, &v[i]);
    }
    return h;
}
extern void HeapMinMoveDownRec(Heap* h, int i) {
    if (HeapIsEmpty(h)) {
        return;
    }
    int l = HeapLeft(i), r = HeapRight(i);
    if ((int)h->size > i) {
        int smallest = 0;
        bool mod = false;
        if(l < (int)h->size && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, l)) > 0) {
            smallest = l;
            mod = true;
        }
        if(r < (int)h->size && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, r)) > 0){
            smallest = r;
            mod = true;
        }
        if (!mod) {
            return;
        }
        ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h,smallest));
        HeapMinMoveDownRec(h, smallest);
    } 
}

