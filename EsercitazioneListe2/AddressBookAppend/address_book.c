#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>

Item* Append(const Item* i1, const Item* i2) {
	Item* res = ListCreateEmpty();
	if (i1 != NULL) {
		for (; !ListIsEmpty(i1); i1 = ListGetTail(i1)) {
			res = ListInsertBack(res, &i1->value);
		}
	}
	Item* res2 = ListCreateEmpty();
	if (i2 != NULL) {
		for (; !ListIsEmpty(i2); i2 = ListGetTail(i2)) {
			res2 = ListInsertBack(res2, &i2->value);
		}
	}
	if (res == NULL && res2 == NULL) {
		return NULL;
	}
	else if (res == NULL) {
		return res2;
	}
	else if (res2 == NULL) {
		return res;
	}
	Item* copy = res;
	for (; res->next != NULL; res = ListGetTail(res));
	res->next = res2;
	return copy;
}