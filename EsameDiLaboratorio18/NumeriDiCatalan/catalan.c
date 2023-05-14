//Time 6m 43s
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
int Catalan(int n) {
	if (n == 0) {
		return 1;
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += Catalan(i) * Catalan(n - 1 - i);
	}
	return res;
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
	printf("%d", Catalan(n));
	return 0;
}