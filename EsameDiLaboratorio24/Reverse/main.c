#include "reverse.h"
#include <stdlib.h>

Item* ListCreateFromVector(const int* v, size_t v_size) {
    Item* list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    int v[] = { 0,1,2,3,4,5,6,7,8,9 };
    Item* list = ListCreateFromVector(v, 10);
    ListWriteStdout(list);
    list = Reverse(list, 200);
    ListWriteStdout(list);
	return 0;
}