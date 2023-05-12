#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <string.h>
#include <stdlib.h>
const ElemType* Find(const Item* i, const char* name) {
	ElemType to_find;
	strcpy(to_find.name, name);
	while (!ListIsEmpty(i)) {
		if (ElemCompare(&i->value, &to_find)==0) {
			return &i->value;
		}
		i = ListGetTail(i);
	}
	return NULL;
}