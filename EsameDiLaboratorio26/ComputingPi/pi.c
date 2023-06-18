//Time 6min
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double MinusOneTo(int n) {
	if (n % 2 == 0) {
		return 1;
	}
	return -1;
}
double Pi(int n) {
	if (n == 0) {
		return 4;
	}
	return (4.0 * MinusOneTo(n)) / (2 * (double)n + 1) + Pi(n - 1);
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
	printf("%lf", Pi(n));
	return 0;
}