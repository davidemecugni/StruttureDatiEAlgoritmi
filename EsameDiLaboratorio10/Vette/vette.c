//Time 10m 00s
#include "list.h"
//Returns true if the first element is bigger than all other elements after it
bool IsVetta(const Item* i) {
	if (i->next == NULL) {
		return true;
	}
	ElemType value = i->value;
	i = ListGetTail(i);
	while (!ListIsEmpty(i)) {
		if (ElemCompare(&value, &i->value) <= 0) {
			return false;
		}
		i = ListGetTail(i);
	}
	return true;
}
int ContaVette(const Item* i) {
	if (i == NULL) {
		return 0;
	}
	int vette = 0;
	//For all the elements in the list
	while (!ListIsEmpty(i)) {
		//If it's a Vetta the vette counter is increased
		if (IsVetta(i)) {
			vette++;
		}
		i = ListGetTail(i);
	}
	return vette;
}