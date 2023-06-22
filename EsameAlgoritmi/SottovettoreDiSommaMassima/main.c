#include <stdlib.h>
extern int OptimalSubarray(const int* v, size_t n);

int main(void) {
	int v[] = { 1, 2, 1, -100, 5, 6 };
	int res = OptimalSubarray(v, 6);
	return 0;
}