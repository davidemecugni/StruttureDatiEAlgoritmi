#include "colora.h"
int main(void) {
	struct Matrix* m = calloc(1, sizeof(struct Matrix));
	m->size = 3;
	bool d[] = { 1,1,1,1,1,0,1,0,1 };
	m->data = d;
	char c[] = { 'r', 'v' };
	int total = MappaColori(m, c, 2);
	printf("\nTotal %d", total);
	return 0;
}