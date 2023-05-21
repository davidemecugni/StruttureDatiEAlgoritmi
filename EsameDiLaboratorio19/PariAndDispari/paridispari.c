//Time 55min
#include "list.h"

Item* PariDispari(Item* i) {
	if (ListIsEmpty(i)) {
		return NULL;
	}
	Item* copy = i;
	Item* even = NULL;
	Item* odd = NULL;
	Item* even_copy = even;
	Item* odd_copy = odd;
	bool first_even = true;
	bool first_odd = true;
	bool last_even = false;
	//Go thru the list as a copy
	for (; !ListIsEmpty(copy); copy = ListGetTail(copy)) {
		//Even
		if (copy->value % 2 == 0) {
			//If it's the first time just copy the value in even and even_copy
			if (first_even) {
				even = copy;
				even_copy = even;
				first_even = false;
			}
			//If even_copy is not empty, set the next as the current element of
			//the list as the current element of copy and move on even
			else {
				even->next = copy;
				even = ListGetTail(even);
			}
			//For final checks
			last_even = true;
			
		}
		//Odd
		else {
			//If it's the first time just copy the value in odd and odd_copy
			if (first_odd) {
				odd = copy;
				odd_copy = odd;
				first_odd = false;
			}
			//If odd_copy is not empty, set the next as the current element of
			//the list as the current element of copy and move on odd
			else {
				odd->next = copy;
				odd = ListGetTail(odd);
			}
			//For final checks
			last_even = false;
		}
	}
	//If the last one was even and odd is not empty
	if (last_even && !first_odd) {
		//We remove the last element of odd(bc it's even)
		odd->next = NULL;
	}
	//If the last one was odd and even is not empty
	else if (!first_even) {
		//We remove the last element of even(bc it's odd)
		even->next = NULL;
	}	
	//It there isn't any even elements, we just return the odd ones
	if (first_even) {
		return odd_copy;
	}
	//It there isn't any odd elements, we just return the even ones
	else if (first_odd) {
		return even_copy;
	}
	even = even_copy;
	while (even->next != NULL) {
		even = ListGetTail(even);
	}
	//We set the next element of even to the first of the odd ones
	//As to concatenate even to odd
	even->next = odd_copy;
	//Return the start of even
	return even_copy;
}