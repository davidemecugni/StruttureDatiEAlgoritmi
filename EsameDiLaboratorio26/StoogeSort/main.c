#include <stdlib.h>
extern void Stooge(int* vector, size_t vector_size);
int main(void) {
	int a[] = { 3,5,7,1,2,3,46,21 };
	Stooge(a, 8);
	return 0;
}