//Time embarrassingly long (>1hr)
#include "list.h"
void Swap(ElemType* a, ElemType* b) {
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}

Item* Reverse(Item* i) {
	Item* current = i;
	Item* prev = NULL;
	Item* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}