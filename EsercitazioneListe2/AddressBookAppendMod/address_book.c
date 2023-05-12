#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>

Item* AppendMod(Item* i1, Item* i2) {
	if (i1 == NULL && i2 == NULL) {
		return NULL;
	}
	else if (i1 == NULL) {
		return i2;
	}
	else if (i2 == NULL) {
		return i1;
	}
	Item* copy = i1;
	for (; i1->next != NULL; i1 = ListGetTail(i1));
	i1->next = i2;
	return copy;
}