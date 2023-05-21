//Time 8m 55s
#include <stdlib.h>
void Swap(int* a, int* b) {
	int tmp = *b;
	*b = *a;
	*a = tmp;
}
extern void GnomeSort(int* v, size_t v_size) {
	//If is null is not valid, if is size 1 it 
	//doesn't need to be sorted
	if (v == NULL || v_size < 2) {
		return;
	}
	int pos = 1;
	while (pos < (int)v_size) {
		if (v[pos] >= v[pos - 1]) {
			pos += 1;
		}
		//If the order is wrong
		else {
			Swap(&v[pos], &v[pos - 1]);
			//Check again
			pos -= 1;
		}
	}
}