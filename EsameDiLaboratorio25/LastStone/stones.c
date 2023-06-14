//Time 14min
#include "maxheap.h"
#include <stdlib.h>
void Pop(Heap* h, ElemType* popped) {
    if (h->size == 0) {
        popped = NULL;
        return;
    }
    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    h->data = realloc(h->data, sizeof(ElemType) * h->size);
    HeapMaxMoveDown(h, 0);
    return;
}

extern int LastStoneWeight(Heap* h) {
    ElemType n_1, n_2;
    while ((int)h->size >= 2) {
        Pop(h, &n_1);
        Pop(h, &n_2);
        if (ElemCompare(&n_1, &n_2) != 0) {
            n_1 -= n_2;
            HeapMaxInsertNode(h, &n_1);
        }
    }
    if (h->size == 0) {
        return 0;
    }
    else {
        return h->data[0];
    }

}