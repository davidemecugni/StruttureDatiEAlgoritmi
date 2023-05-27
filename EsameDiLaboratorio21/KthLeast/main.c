#include "minheap.h"
extern int KthLeast(const int* v, size_t n, int k);

int main(void) {
	int v[] = { 2,4,5,7,8,12,2,4,6 };
	size_t n = 9;
	int k = 3;
	printf("Res %d", KthLeast(v, n, k));
	return 0;
}