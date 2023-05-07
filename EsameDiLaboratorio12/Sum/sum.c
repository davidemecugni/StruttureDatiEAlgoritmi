//Time 20min 00s
#include "list.h"
#include <stdlib.h>
#include <string.h>
/*
int ListLen(Item* i1) {
	int i = 0;
	while (!ListIsEmpty(i1)) {
		++i;
		i1 = ListGetTail(i1);
	}
	return i;
}
char* ListToString(Item* i1) {
	char* res = calloc((size_t)(ListLen(i1) + 1), sizeof(char));
	int pos = 0;
	while (!ListIsEmpty(i1)) {
		res[pos] = (int)(i1->value) + '0';
		i1 = ListGetTail(i1);
		++pos;
	}
	return res;
}
*/
Item* Sum(const Item* i1, const Item* i2) {
	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return ListCreateEmpty();
	}
	Item* res = ListCreateEmpty();
	int riporto=0;
	ElemType sum = 0; 
	//While there is something to add
	while (!ListIsEmpty(i1) || !ListIsEmpty(i2)) {
		sum = 0;
		//If both numbers have to be summed
		if (!ListIsEmpty(i1) && !ListIsEmpty(i2)) {
			//Riporto can be 1 if the previous operation overflowed
			sum = i1->value + i2->value + riporto;
			//If the operation overflows
			if (sum / 10 > 0) {
				riporto = 1;
			}
			else {
				riporto = 0;
			}
			sum = sum % 10;
			res = ListInsertBack(res, &sum);
			i1 = ListGetTail(i1);
			i2 = ListGetTail(i2);
		}
		//If i1 is longer
		else if (!ListIsEmpty(i1)) {
			sum = i1->value + riporto;
			res = ListInsertBack(res, &sum);
			i1 = ListGetTail(i1);
			riporto = 0;
		}
		//If i2 is longer
		else if (!ListIsEmpty(i2)) {
			sum = i2->value + riporto;
			res = ListInsertBack(res, &sum);
			i2 = ListGetTail(i2);
			riporto = 0;
		}
		
	}
	if (riporto) {
		sum = 1;
		res = ListInsertBack(res, &sum);
	}
	return res;
}