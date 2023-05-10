#include <stdlib.h>
extern void PancakeSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 1,3,4,10,23,7,6 };
	PancakeSort(v, 7);
	return 0;
}