#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>
Item* Filtra(const Item* i, const char* city) {
	Item* res = ListCreateEmpty();
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		if (strcmp(i->value.city, city) == 0) {
			res = ListInsertBack(res, &i->value);
		}
	}
	return res;
}