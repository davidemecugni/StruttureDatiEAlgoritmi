#include <stdlib.h>
#include <stdio.h>
char* SolveSuperstring(const char** v, size_t v_size);
int main(void) {
	char** a = calloc(3, sizeof(char));
	a[0] = calloc(20, 1);
	a[1] = calloc(20, 1);
	a[2] = calloc(20, 1);

	a[0] = "FEDERICO";
	a[1] = "MAURIZIO";
	a[2] = "GIANPAOLO";
	char* res = SolveSuperstring(a, 3);
	printf("%s", res);
	free(res);
	return 0;
}