//Time 21min
#include "next_greater.h"
size_t DimList(const Item* list) {
	size_t total = 0;
	for (; !ListIsEmpty(list); list = ListGetTail(list), total++);
	return total;
}
ElemType FindMax(const Item* list, const ElemType *val) {
	list = ListGetTail(list);
	for (; !ListIsEmpty(list); list = ListGetTail(list)) {
		if (ElemCompare(val, &list->value) < 0) {
			return list->value;
		}
	}
	return INT_MIN;
}
ElemType* NextGreater(const Item* list, size_t* answer_size) {
	if (ListIsEmpty(list)) {
		*answer_size = 0;
		return NULL;
	}
	*answer_size = DimList(list);
	ElemType* res = calloc(*answer_size, sizeof(ElemType));
	
	for (int i=0; !ListIsEmpty(list); list = ListGetTail(list), ++i) {
		res[i] = FindMax(list, ListGetHeadValue(list));
	}
	return res;
}