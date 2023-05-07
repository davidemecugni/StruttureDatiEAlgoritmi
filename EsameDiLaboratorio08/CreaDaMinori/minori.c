#include "list.h"
/*
Item* CreaDaMinori(const Item* i, int v) {
	Item* res = ListCreateEmpty();
	Item* res_start = ListCreateEmpty();
	ElemType value = v;
	while (!ListIsEmpty(i)) {
		if (ElemCompare(&i->value, &value) < 0) {
			res = ListInsertBack(res, &i->value);
			if(ListIsEmpty(res_start)){
				res_start = res;
			}
		}
		i = ListGetTail(i);
	}
	return res_start;
}
*/
Item* CreaDaMinori(const Item* i, int v) {
    Item* new_head = ListCreateEmpty();

    const Item* current = i;
    while (current != NULL) {
        if (current->value <= v) {
            int* new_elem = malloc(sizeof(int));
            if (new_elem == NULL) {
                ListDelete(new_head);
                return NULL;
            }
            new_elem = &current->value;
            new_head = ListInsertBack(new_head, new_elem);
        }
        current = current->next;
    }

    return new_head;
}