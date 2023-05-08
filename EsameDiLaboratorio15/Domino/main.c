#include "domino.h"
//Used to print the dominos
void PrintDomino(const Tessera* t, const Placing* p, size_t n) {
	if (n == 0) {
		return;
	}
	printf("Value : ");
	for (size_t i = 0; i < n; i++) {
		if (!p[i].flipped) {
			printf("[ %1d %1d ] ", t[p[i].indice].val1, t[p[i].indice].val2);
		}
		else {
			printf("[ %1d %1d ] ", t[p[i].indice].val2, t[p[i].indice].val1);
		}

	}
	printf("\nIndex : ");
	for (size_t i = 0; i < n; i++) {
		printf("%5i   ", p[i].indice);
	}
	printf("\n");
}

int main(void) {
	Tessera t[] = { {.val1 = 5, .val2 = 3 }, {.val1 = 5, .val2 = 6 }, {.val1 = 6, .val2 = 2 }, {.val1 = 5, .val2 = 6 }, {.val1 = 1, .val2 = 0 }, {.val1 = 0, .val2 = 1 }, {.val1 = 2, .val2 = 4 }, {.val1 = 3, .val2 = 2 }, {.val1 = 4, .val2 = 3 }, {.val1 = 2, .val2 = 2 }, {.val1 = 2, .val2 = 4 }, {.val1 = 1, .val2 = 4 }, {.val1 = 3, .val2 = 1 }, {.val1 = 3, .val2 = 4 } };
	size_t dim = 0;
	Placing* res = Domino(t, 14, &dim);
	PrintDomino(t, res, dim);
	//Value: [5 3] [3 2] [2 4] [4 3] [3 1] [1 0] [0 1] [1 4] [4 2] [2 2] [2 6] [6 5] [5 6]
	//Index : 0      7     6     8    12     4     5    11    10     9     2     1     3	
	free(res);
	return 0;
}