//Time 25min
#include "doublelist.h"
Item* GetLast(Item* v) {
	for (; v->next != NULL; v = DListGetTail(v));
	return v;
}
extern Item* ConcatenaN(Item** v, size_t v_size) {
	if (v_size == 0) {
		return NULL;
	}
	Item* first_node = NULL;
	Item* last_node = NULL;
	for (int i = 0; i < (int)v_size; i++) {
		if (v[i] != NULL) {
			if (last_node != NULL) {
				last_node->next = v[i];
				v[i]->prev = last_node;
			}
			else {
				first_node = v[i];
			}
			last_node = GetLast(v[i]);
		}
	}
	return first_node;
}