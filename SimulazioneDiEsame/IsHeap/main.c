#include <stdlib.h>
#include "minheap.h"
extern bool IsHeap(const Heap* h);
int main(void) {
    ElemType v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, -1 };
    size_t v_size = sizeof(v) / sizeof(ElemType);

    Heap* h = HeapCreateEmpty();
    for (unsigned i = 0; i < v_size; ++i) {
        HeapMinInsertNode(h, &v[i]);
    }
    HeapWriteStdout(h);
    bool res = IsHeap(h);
    HeapDelete(h);

    return EXIT_SUCCESS;
}