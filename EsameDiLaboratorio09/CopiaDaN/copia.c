#include "list.h"
Item* CopiaDaN(const Item* i, int n) {
	//The new copy
	Item* copy = ListCreateEmpty();
	//Each element to be copied
	ElemType copied_element;
	//Reached the i-est element
	bool found = false;
	int j = 1;
	//Until the list is empty
	while (!ListIsEmpty(i)) {
		//If we reach the i-est element
		if (!found && j==n) {
			found = true;
		}
		//If we reached or passed the element we put a copy in the copied list 
		if (found) {
			copied_element = ElemCopy(&i->value);
			copy = ListInsertBack(copy, &copied_element);
		}
		//Next element in the list
		i = ListGetTail(i);
		//Updates the index
		j++;
	}
	return copy;
}