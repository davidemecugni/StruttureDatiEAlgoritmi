#include <stdlib.h>
#include <string.h>

#include "minheap.h"

void HeapsortMinHeap(Heap* h) {
    size_t origin_size = h->size; // Ci salviamo la dimensione originaria per
    // ripristinarla al termine. 

    while (h->size >= 2) {
        ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
        h->size--;
        HeapMinMoveDown(h, 0);
    }
    h->size = origin_size; // Ripristiniamo la dimensione originaria altrimenti
    // il distruttore della heap (HeapDelete) non può
    // fare il suo dovere. 
}

Heap* HeapifyMinHeap(ElemType* v, size_t v_size) {
    Heap* h = HeapCreateEmpty();
    h->size = v_size;
    h->data = malloc(sizeof(ElemType) * (v_size));
    memcpy(h->data, v, v_size * sizeof(ElemType));

    for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
        HeapMinMoveDown(h, i);
    }
    return h;
}

int main(void) {
    ElemType v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(ElemType);

    Heap* h = HeapifyMinHeap(v, v_size);
    HeapWriteStdout(h);

    HeapsortMinHeap(h);
    HeapWriteStdout(h);

    HeapDelete(h);

    return EXIT_SUCCESS;
}