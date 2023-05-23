//Time 1hr 27 min
#include "list.h"
/*
FULL REMOVE

Item* FirstNonDuplicate(Item* list) {
	Item* copy = list;
	if (ListIsEmpty(list)) {
		return NULL;
	}
	if (list->next == NULL) {
		return list;
	}
	bool mod = false;
	while (!ListIsEmpty(list->next) && ElemCompare(&list->value, &list->next->value) == 0) {
		list = ListGetTail(list);
		mod = true;
	}
	if (mod) {
		Item* to_return = list->next;
		list->next = NULL;
		ListDelete(copy);
		return FirstNonDuplicate(to_return);
	}
	return list;
	
}
extern Item* RemoveDuplicates(Item* i) {
	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}
	Item* to_return = FirstNonDuplicate(i);
	Item* to_return_copy = to_return;
	i = to_return;
	while (i != NULL) {
		to_return_copy->next = FirstNonDuplicate(i->next);
		to_return_copy = ListGetTail(to_return_copy);
		i = ListGetTail(i);
	}
	return to_return;
}

*/

Item* RemoveDuplicates(Item* i) {
	//Base case
	if (i == NULL)
		return NULL;
	//Next non-duplicate element
	Item* head = i;
	for (Item* tmp = i->next; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(head), ListGetHeadValue(tmp)) == 0) {
			head->next = tmp->next;
			tmp->next = NULL;
			ListDelete(tmp);
			tmp = head;
		}
		else {
			head = head->next;
		}
	}
	return i;
}