//Time 26m
#include "differenza.h"

extern Item* Differenza(const Item* i1, const Item* i2) {
	if (i1 == NULL && i2 == NULL) {
		return NULL;
	}
	if (i2 == NULL) {
		Item* copy = ListCreateEmpty();
		while (!ListIsEmpty(i1)) {
			copy = ListInsertBack(copy, &i1->value);
			i1 = ListGetTail(i1);
		}
		return copy;
	}
	Item* res = ListCreateEmpty();
	ElemType digit, s, m;
	bool riporto = false;
	while (!ListIsEmpty(i1)) {
		s = i1->value;
		if (!ListIsEmpty(i2)) {
			m = i2->value;
		}
		else {
			m = '0';
		}
		if (riporto) {
			s = s - 1;
		}
		riporto = false;
		if (ElemCompare(&s, &m) >= 0) {
			digit =  s-m+'0';
		}
		else {
			digit = s + 10 - m+'0';
			riporto = true;
		}
		res = ListInsertBack(res, &digit);
		if (!ListIsEmpty(i2)) {
			i2 = ListGetTail(i2);
		}
		i1 = ListGetTail(i1);
	}
	return res;
}