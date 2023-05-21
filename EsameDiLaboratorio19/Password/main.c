#include <stdio.h>
extern int Password(const char* str, int n);

int main(void) {
	printf("\n\nTotal strings : %d", Password("a1",5));
	return 0;
}