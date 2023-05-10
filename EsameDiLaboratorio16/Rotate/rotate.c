//Time 45min 00s
#include "list.h"
Item* Rotate(Item* i, int n) {
	if (i == NULL) {
		return NULL;
	}
	Item* new_head = NULL;
	int count = 0;
	Item* old_head = i;
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		//If we reached the first element of the new list
		if (count == n) {
			new_head = i;
		}
		count++;
		//When we reach the end of the input list
		if (i->next == NULL) {
			//The input list is appended to the back of the new list
			i->next = old_head;
			//Just before we reach the end n
			for (int j = 0; j < n - 1; j++) {
				old_head = ListGetTail(old_head);
			}
			//This is to eliminate a circling loop
			old_head->next = NULL;
			break;
		}
	}
	//The input list is the modified list
	i = new_head;
	return i;
}