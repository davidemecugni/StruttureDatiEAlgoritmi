#include "list.h"
#include <stdlib.h>
const ElemType* MaxElement(const Item* i) {
	if (ListIsEmpty(i) ){
		return NULL;
	}
	const ElemType* max = ListGetHeadValue(i);
	i = ListGetTail(i);
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		if (ElemCompare(ListGetHeadValue(i), max)>0) {
			max = ListGetHeadValue(i);
		}
	}
	return max;
}

