//Time 10m 51s
#include "cc.h"
int IsIn(const ElemType* v, const size_t v_size, const ElemType val) {
	for (int i = 0; i < (int)v_size; i++) {
		if (ElemCompare(&v[i], &val) == 0) {
			return i;
		}
	}
	return -1;
}
int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (ListIsEmpty(i) || v == NULL || v_size<1) {
		return 0;
	}
	int index;
	int total = 0;
	bool streak = false;
	while (!ListIsEmpty(i)) {
		index = IsIn(v, v_size, i->value);
		if (index != -1 && !streak) {
			streak = true;
			++total;
		}
		if (index == -1 && streak) {
			streak = false;
		}
		i = ListGetTail(i);
	}
	return total;
}