#include <stdio.h>
#include <stdlib.h>
extern char* ReverseString(const char* str);
int main(void) {
	char str[] = "stringa da invertire";
	printf("Input   : %s\n", str);
	char* res = ReverseString(str);
	printf("Reversed: %s", res);
	free(res);
	return 0;
}
