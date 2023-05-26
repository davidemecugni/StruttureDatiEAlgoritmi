#include <stdlib.h>
#include <stdio.h>
int CombinaMonete(int b, const int* m, size_t m_size);
int main(void) {
	int b = 90;
	int m[] = { 2,50,10,5,20 };
	printf("Total: %d",CombinaMonete(b, m, 5));
	return 0;
}