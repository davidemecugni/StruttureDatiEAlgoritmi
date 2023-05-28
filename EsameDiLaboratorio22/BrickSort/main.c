#include <stdlib.h>
extern void BrickSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 2,3,6,1,2,4,8,3,1,10,0 };
	BrickSort(v, 11);
	return 0;
}