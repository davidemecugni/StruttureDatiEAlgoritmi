#include <stdio.h>
extern int Minimo(const int* v, int v_size);
int main() {
	int v[] = { 1,2,3,4,-1,-2,-3,-4,10,20 };
	printf("%d", Minimo(v, 10));
}