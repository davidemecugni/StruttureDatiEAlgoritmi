//Time 4m37s
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int DivideNConquer(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (n % 2 == 0) {
		return 2*DivideNConquer(n / 2) + n;
	}
	return DivideNConquer(n / 2) + DivideNConquer(n / 2 + 1) + n;
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
	printf("%d", DivideNConquer(n));
	return 0;
}