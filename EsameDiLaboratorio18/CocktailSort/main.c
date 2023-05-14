#include <stdlib.h>

extern void CocktailSort(int* v, size_t v_size);

int main(void) {
	int v[] = {1,4,6,87,3,1,3,6,8,11,24};
	CocktailSort(v, 11);
	return 0;
}