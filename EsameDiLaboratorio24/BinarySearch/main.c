#include <stdlib.h>
extern int BinarySearch(const int* v, size_t v_size, int value);
int main(void) {
	int v[] = { 1,2,3,4,5,6,7,8,9,10,11 };
	int pos = BinarySearch(v, 11, 8);
	return 0;
}