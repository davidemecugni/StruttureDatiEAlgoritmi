#include "list.h"
#include <stdlib.h>

Item* Sort(Item* i) {
	Item* tmp = i;
	bool ordinato = true;
	while (!ListIsEmpty(tmp)) {
		Item* prev = tmp;
		Item* succ = tmp->next;
		while (succ != NULL) {
			if (ElemCompare(&prev->value, &succ->value) > 0) {
				ElemSwap(&prev->value, &succ->value);
				ordinato = false;
			}
			prev = succ;
			succ = prev->next;
		}
		if (ordinato) {
			break;
		}
		ordinato = true;
		tmp = ListGetTail(tmp);
	}
	return i;
}