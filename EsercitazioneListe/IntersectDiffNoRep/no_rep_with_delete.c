#include "list.h"
//Deletes an element, if val is present
void DeleteElement(Item* i, ElemType* val) {
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
		Item* succ = i->next;
		if (succ != NULL) {
			Item* succ_succ = succ->next;
			//Se il valore corrente e' quello da eliminare
			if (ElemCompare(&i->value, val) == 0) {
				//Valore attuale = al successivo
				i->value = succ->value;
				//L'elemento successivo diventa il successivo successivo
				i->next = succ_succ;
			}
		}

	}
}
bool IsIn(const Item* list, const ElemType* val) {
	for (; !ListIsEmpty(list); list = ListGetTail(list)) {
		if (ElemCompare(ListGetHeadValue(list), val) == 0) {
			return true;
		}
	}
	return false;
}
//Returns if the first element of the list is repeated within the list
bool IsRepeated(const Item* list) {
	const ElemType* val = &list->value;
	list = ListGetTail(list);
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
		if (IsIn(i2, ListGetHeadValue(i1))) {
			res = ListInsertBack(res, ListGetHeadValue(i1));
		}
	}
	ListWriteStdout(res);
	Item* tmp = res;
	for (; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (IsRepeated(tmp)) {
			DeleteElement(tmp, &tmp->value);
		}
	}
	return res;
}

