#include "sum_dlist.h"
Item* DListCreateFromVector(const ElemType* v, size_t v_size) {
    Item* list = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = DListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    ElemType v1[] = {9,9,9,9 };
    size_t v_size1 = sizeof(v1) / sizeof(ElemType);
    Item* list1 = DListCreateFromVector(v1, v_size1);
    ElemType v2[] = { 1 };
    size_t v_size2 = sizeof(v2) / sizeof(ElemType);
    Item* list2 = DListCreateFromVector(v2, v_size2);

    Item* res = DListSum(list1,list2);
    DListWriteStdout(res);
    DListDelete(list1);
    DListDelete(list2);
    DListDelete(res);
    return 0;
}