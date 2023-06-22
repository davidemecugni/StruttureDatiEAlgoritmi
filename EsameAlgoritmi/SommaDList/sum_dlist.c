#include "sum_dlist.h"
Item* CreateCopy(const Item* list) {
	Item* copy = DListCreateEmpty();
	while (!DListIsEmpty(list)) {
		ElemType val = list->value;
		copy = DListInsertBack(copy, &val);
		list = DListGetTail(list);
	}
	return copy;
}
Item* Sum(const Item* i1, const Item* i2) {
	while (i1->next != NULL) {
		i1 = DListGetTail(i1);
	}
	while (i2->next != NULL) {
		i2 = DListGetTail(i2);
	}
	Item* sum = DListCreateEmpty();
	int riporto = 0;
	while (i1 != NULL || i2 != NULL) {
		if (i1 != NULL && i2 != NULL) {
			ElemType x = i1->value + i2->value + riporto;
			if (x < 9) {
				sum = DListInsertHead(&x, sum);
				riporto = 0;
			}
			else {
				x -= 10;
				sum = DListInsertHead(&x, sum);
				riporto = 1;
			}
			i1 = i1->prev;
			i2 = i2->prev;
		}
		else if (i1 != NULL) {
			ElemType x = i1->value + riporto;
			if (x < 9) {
				sum = DListInsertHead(&x, sum);
				riporto = 0;
			}
			else {
				x -= 10;
				sum = DListInsertHead(&x, sum);
				riporto = 1;
			}
			i1 = i1->prev;
		}
		else if (i2 != NULL) {
			ElemType x = i2->value + riporto;
			if (x < 9) {
				sum = DListInsertHead(&x, sum);
				riporto = 0;
			}
			else {
				x -= 10;
				sum = DListInsertHead(&x, sum);
				riporto = 1;
			}
			i2 = i2->prev;
		}
		
	}
	if (riporto) {
		ElemType x = 1;
		sum = DListInsertHead(&x, sum);
	}
	return sum;
}

Item* DListSum(const Item* i1, const Item* i2) {
	if (DListIsEmpty(i1) && DListIsEmpty(i2)) {
		return DListCreateEmpty();
	}
	if (DListIsEmpty(i1)) {
		return CreateCopy(i2);
	}
	if (DListIsEmpty(i2)) {
		return CreateCopy(i1);
	}
	return Sum(i1,i2);
}

