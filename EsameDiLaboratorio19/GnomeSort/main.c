#include <stdlib.h>
extern void GnomeSort(int* v, size_t v_size);
int main(void) {
	int v[] = { 3,6,2,4 };
	GnomeSort(v, 4);
	return 0;
}