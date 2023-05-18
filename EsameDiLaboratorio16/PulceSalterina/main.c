#include <stdlib.h>
extern char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size);
int main(void) {
	int f[] = { 12, 4, 7, 1, 15 };
	int a = 3;
	int b = 15;
	int h = 9;
	int n = 5;
	size_t dim = 0;
	char* res = GuidaLaPulce(f, 5, a, b, n, h, &dim);
	free(res);
	a = 3;
	b = 15;
	h = 9;
	n = 2; 
	dim = 0;
	res = GuidaLaPulce(f, 5, a, b, n, h, &dim);
	free(res);
	
	return 0;
}