#include <stdlib.h>
extern int* Monete(const int* tagli, size_t tagli_size, int budget);

int main(void) {
	int* tagli = calloc(6, sizeof(int));
	tagli[0] = 50;
	tagli[1] = 20;
	tagli[2] = 10;
	tagli[3] = 5;
	tagli[4] = 2;
	tagli[5] = 1;
	int* sol = Monete(tagli, 6, 126);
	free(sol);
	return 0;
}