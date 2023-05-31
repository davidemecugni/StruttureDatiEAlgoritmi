#include <stdio.h>
#include <stdlib.h>
extern int* RisolviProdotto(int n, const int* s);
int main(void) {
	int n = 2;
	int data[] = { 1,1,2,2 };
	int* res = RisolviProdotto(n,data);
	printf("Found = %s", res == NULL ? "false" : "true");
	free(res);
	return 0;
}