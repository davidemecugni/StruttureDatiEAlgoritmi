//Time 48min
#include "reverse.h"
int ListLenght(Item* list) {
	if (ListIsEmpty(list)) {
		return 0;
	}
	return ListLenght(ListGetTail(list)) + 1;
}
Item* Reverse(Item* list, int right) {
	if (right <= 1 || ListIsEmpty(list)) {
		return list;
	}
	int len = ListLenght(list);
	Item* beginning = list;
	Item* prev_prev = list;
	Item* prev = ListGetTail(prev_prev);
	Item* copy = ListGetTail(prev);
	prev_prev->next = NULL;
	for (int i = 0; i < right-1 && (!ListIsEmpty(copy)); i++) {
		prev->next = prev_prev;
		prev_prev = prev;
		prev = copy;
		copy = ListGetTail(copy);
	}
	//ListWriteStdout(prev_prev);
	
	if ( len <= right) {
		prev->next = prev_prev;
		return prev;
	}
	beginning->next = prev;
	return prev_prev;
}