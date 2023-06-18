//Time 20min
#include "reverse.h"

int LenList(Item* list) {
	int i;
	for (i = 0; !ListIsEmpty(list); list = ListGetTail(list), ++i);
	return i;
}
Item* Revert(Item* list) {
	Item* last = list;
	
	Item* current = ListGetTail(list);
	Item* next = ListGetTail(current);
	last->next = NULL;
	while (!ListIsEmpty(next)) {
		current->next = last;
		last = current;
		current = next;
		next = ListGetTail(next);
	}
	current->next = last;
	return current;
}
Item* Reverse(Item* list, int left) {
	int len = LenList(list);
	if (left >= len - 1) {
		return list;
	}
	if (left <= 0) {
		return Revert(list);
	}
	Item* beginning = list;
	for (int i = 0; i < left-1; i++) {
		list = ListGetTail(list);
	}
	Item* to_reverse = ListGetTail(list);
	to_reverse = Revert(to_reverse);;
	list->next = to_reverse;
	return beginning;
}