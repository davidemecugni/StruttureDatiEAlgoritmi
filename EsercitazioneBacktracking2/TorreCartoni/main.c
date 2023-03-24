#include "torrecartoni.h"

int main(void) {
	Cartone c[] = {{.p = 10,.a = 20,.l = 40}, {.p = 10,.a = 10,.l = 8}, {.p = 9,.a = 3,.l = 5}};
	int tick = clock(), tock;
	TorreCartoni(c, 3);
	tock = clock();
	printf("\nTime : % f", ((tock - tick) / (double)CLOCKS_PER_SEC));
	return 0;
}