#include "list.h"
Item* PariDispari(Item* i);
#include <stdlib.h>

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    int v[] = { 12,4,6};
    size_t v_size = sizeof(v) / sizeof(int);
    Item* list = ListCreateFromVector(v, v_size);
    ListWriteStdout(list);
    Item* res = PariDispari(list);
    ListWriteStdout(res);
    ListDelete(list);

    return EXIT_SUCCESS;
}