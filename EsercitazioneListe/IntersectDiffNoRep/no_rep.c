#include "list.h"
bool IsIn(const Item* list, const ElemType* val) {
	for (; !ListIsEmpty(list); list = ListGetTail(list)) {
		if (ElemCompare(ListGetHeadValue(list), val) == 0) {
			return true;
		}
	}
	return false;
}
Item* IntersectNoRep(const Item* i1, const Item* i2) {
	Item* res = ListCreateEmpty();
	for (; !ListIsEmpty(i1); i1 = ListGetTail(i1)) {
		if (IsIn(i2, ListGetHeadValue(i1)) && !IsIn(res, ListGetHeadValue(i1))) {
			res = ListInsertBack(res, ListGetHeadValue(i1));
		}
	}
	return res;
}
Item* DiffNoRep(const Item* i1, const Item* i2) {
	Item* res = ListCreateEmpty();
	for (; !ListIsEmpty(i1); i1 = ListGetTail(i1)) {
		if (!IsIn(i2, ListGetHeadValue(i1)) && !IsIn(res, ListGetHeadValue(i1))) {
			res = ListInsertBack(res, ListGetHeadValue(i1));
		}
	}
	return res;
}

