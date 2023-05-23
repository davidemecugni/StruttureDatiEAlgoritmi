#include "remove.h"

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    int v[] = {1,1,1,2,2,2,3,3,3,4,4,4,5,6,7,8,9,10,10,10};
    size_t v_size = sizeof(v) / sizeof(int);
    Item* list = ListCreateFromVector(v, v_size);
    ListWriteStdout(list);
    list = RemoveDuplicates(list);
    ListWriteStdout(list);
    return 0;
}
