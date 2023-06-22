#include <stdlib.h>
#include <stdbool.h>
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
bool CircleSortRec(int* v, int start, int stop) {
	if (start >= stop) {
		return false;
	}
	bool scambio = false;
	int v_size = (stop - start + 1);
	int copy_start = start, copy_stop = stop;
	while (copy_start < copy_stop) {
		if (v[copy_start] > v[copy_stop]) {
			Swap(&v[copy_start], &v[copy_stop]);
			scambio = true;
		}
		copy_start++;
		copy_stop--;
	}
	
	if ((v_size) % 2 == 1){
		if (v[(stop+start)/2] > v[(stop + start)/2 +1]) {
			Swap(&v[(stop + start) / 2], &v[(stop + start) / 2 + 1]);
			scambio = true;
		}
		int diff = (stop + start) / 2;
		scambio |= CircleSortRec(v, start, diff-1) || CircleSortRec(v, diff, stop);
		if (scambio) {
			return CircleSortRec(v, start, stop);
		}
	}
	scambio |= CircleSortRec(v, start, (stop + start) / 2) || CircleSortRec(v, (stop + start) / 2 + 1, stop);
	if (scambio) {
		return CircleSortRec(v, start, stop);
	}
	return false;
	
	
}
extern void CircleSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	CircleSortRec(v, 0, (int)v_size-1);
}