//5min 00s
#include "list.h"
Item* ElementiPari(const Item* i) {
	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}
	int counter = 0;
	Item* res = ListCreateEmpty();
	ElemType copy;
	while (!ListIsEmpty(i)) {
		if (counter % 2 == 0) {
			copy = ElemCopy(&i->value);
			res = ListInsertBack(res, &copy);
		}
		i = ListGetTail(i);
		++counter;
	}
	return res;
}