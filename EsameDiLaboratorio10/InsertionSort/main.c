#include <stdlib.h>
extern void InsertionSort(int* v, size_t v_size);
int main(void) {
	int v[] = { 1 ,12 ,5 ,4 ,3 ,2 ,13 };
	InsertionSort(v, 7);
	return 0;
}