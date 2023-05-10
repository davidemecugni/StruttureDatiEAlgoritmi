#include <stdlib.h>

int main(void) {
	int f[] = { 12, 4, 7, 1, 15 };
	int a = 3;
	int b = 15;
	int h = 9;
	int n = 5; 
	size_t dim = 0;
	char* res = GuidaLaPulce(f, 5, a, b, n, h, &dim);
	free(res);
	return 0;
}