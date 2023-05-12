#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>
#include <stdlib.h>
Item* Delete(Item* i, const char* name) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	ElemType to_find;
	strcpy(to_find.name, name);
	Item* tmp = i;
	Item* prec = i;
	bool first = true;
	while (!ListIsEmpty(tmp)) {
		if (ElemCompare(&tmp->value, &to_find) == 0) {
			if (first) {
				tmp = ListGetTail(tmp);
				free(&i->value);
				return tmp;
			}
			prec->next = tmp->next;
			free(&tmp->value);
			return i;
		}
		first = false;
		prec = tmp;
		tmp = ListGetTail(tmp);
	}
	return i;
}
