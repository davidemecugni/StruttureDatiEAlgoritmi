#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>

Item* Reverse(const Item* i) {
	Item* res = ListCreateEmpty();
	if (i == NULL) {
		return res;
	}
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		res = ListInsertHead(&i->value, res);
	}
	return res;
}