//Time 5min
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int TNumbers(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 3;
	}
	return 3 * TNumbers(n - 1) - 3 * TNumbers(n - 2) + TNumbers(n - 3);
}
int main(int argc, char** argv) {
	if (argc != 2) {
		return 1;
	}
	int res, n;
	res = sscanf(argv[1], "%d", &n);
	if (res != 1 || n < 0) {
		return 1;
	}
	printf("%d", TNumbers(n));
}