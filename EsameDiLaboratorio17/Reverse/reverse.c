//Time embarrassingly long (>1hr)
#include "list.h"

Item* Reverse(Item* i) {
	//Keeps track of the current element
	Item* current = i;
	//Keeps track of the previous element
	Item* prev = NULL;
	//Keeps track of the next element
	Item* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}