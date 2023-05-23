#include <stdlib.h>
extern void CountingSort(int* v, size_t v_size);

int main(void) {
	int v[] = { 3,4,3,4,5,7,5,5,3 };
	CountingSort(v, 9);
	return 0;
}