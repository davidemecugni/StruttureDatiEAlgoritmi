//Time 15m 00s
#include "list.h"
const Item* CommonTail(const Item* i1, const Item* i2) {
	//If one is empty return an empty list
	if (ListIsEmpty(i1) || ListIsEmpty(i2)) {
		return ListCreateEmpty();
	}
	const Item* i1_copy = i1;
	const Item* i2_copy = i2;
	//For every element of the first list
	while (!ListIsEmpty(i1_copy)) {
		const Item* i2_copy = i2;
		//For every element of the second list
		while (!ListIsEmpty(i2_copy)) {
			//If the address of the first list is the same as the second
			//Return the remaining list
			if (&i1_copy->value == &i2_copy->value) {
				return i1_copy;
			}
			//If the next element of the list has the same address, return it
			if (i1_copy->next == i2_copy->next) {
				return ListGetTail(i1_copy);
			}
			//Check for the next element in i2
			i2_copy = ListGetTail(i2_copy);
		}
		//Check for the next element in i1
		i1_copy = ListGetTail(i1_copy);
	}
	//If no common tail is found
	return ListCreateEmpty();
}