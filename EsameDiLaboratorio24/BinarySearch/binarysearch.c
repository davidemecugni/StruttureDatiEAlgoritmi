//Time 15min
#include <stdlib.h>
int BinarySearchRec(const int* v, size_t v_size, int value, int start, int stop) {
	int half = (stop + start) / 2;
	if (start > stop) {
		return -1;
	}
	if (v[half] == value) {
		return half;
	}
	if (v[half] < value) {
		return BinarySearchRec(v, v_size, value, half+1, stop);
	}
	return BinarySearchRec(v, v_size, value, start, half-1);
}
extern int BinarySearch(const int* v, size_t v_size, int value) {
	if (v == NULL) {
		return -1;
	}
	return BinarySearchRec(v, v_size, value, 0, (int)v_size);
}