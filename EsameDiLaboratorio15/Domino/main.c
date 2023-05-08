#include "domino.h"
int main(void) {
	Tessera t[] = { {.val1 = 5, .val2 = 3 }, {.val1 = 5, .val2 = 6 }, {.val1 = 6, .val2 = 2 }, {.val1 = 5, .val2 = 6 }, {.val1 = 1, .val2 = 0 }, {.val1 = 0, .val2 = 1 }, {.val1 = 2, .val2 = 4 }, {.val1 = 3, .val2 = 2 }, {.val1 = 4, .val2 = 3 }, {.val1 = 2, .val2 = 2 }, {.val1 = 2, .val2 = 4 }, {.val1 = 1, .val2 = 4 }, {.val1 = 3, .val2 = 1 }, {.val1 = 3, .val2 = 4 } };
	size_t dim = 0;
	Placing* res = Domino(t, 14, &dim);
	free(res);
	return 0;
}