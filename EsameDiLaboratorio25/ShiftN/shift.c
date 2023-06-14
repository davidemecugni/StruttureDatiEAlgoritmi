//Time 21min
#include "shift.h"
int LenList(Item* list) {
	int n = 0;
	while (!ListIsEmpty(list)) {
		n++;
		list = ListGetTail(list);
	}
	return n;
}
Item* ShiftN(Item* list, size_t n) {
	if (ListIsEmpty(list)) {
		return NULL;
	}
	if (n == 0) {
		return list;
	}
	int len = LenList(list);
	n %= (len-1);
	if (n == 0) {
		n = (len - 1);
	}
	Item* first = list;
	Item* beginning = ListGetTail(list);
	for (int i = 0; i < (int)n; i++) {
		list = ListGetTail(list);
	}
	first->next = ListGetTail(list);
	list->next = first;
	
	return beginning;
}