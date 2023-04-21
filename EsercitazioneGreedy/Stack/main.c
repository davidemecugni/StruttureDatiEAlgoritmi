#include "stacks.h"

int main(void) {
	Stack lista[3];
	int elementi[] = { 1, 1, 1, 2, 3 };
	lista[0].elements = elementi;
	lista[0].m = 5;
	int elementi1[] = { 2, 3, 4 };
	lista[1].elements = elementi1;
	lista[1].m = 3;
	int elementi2[] = { 1, 4, 5, 2 };
	lista[2].elements = elementi2;
	lista[2].m = 4;
	unsigned res =  MaxSumNStack(lista, 3);
	return 0;
}