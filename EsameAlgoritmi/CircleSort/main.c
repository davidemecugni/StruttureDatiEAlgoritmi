#include <stdlib.h>
extern void CircleSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 3, 6, 2, 4, -21474648, 21473647 };
	CircleSort(v, 6);
 	return 0;
}