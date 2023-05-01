#include <stdio.h>
extern int Potenza(int a, int b);
int main(void) {
	printf("8 to the 0 = %d", Potenza(8, 0));
	printf("\n2 to the 10 = %d", Potenza(2, 10));
	printf("\n1 to the 10 = %d", Potenza(1, 10));
	printf("\n3 to the 3 = %d", Potenza(3, 3));
	printf("\n10 to the 9 = %d", Potenza(10, 9));
	return 0;
}