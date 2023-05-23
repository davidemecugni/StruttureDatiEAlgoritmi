#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


float LogisticMap(int i, int n, float r, float x) {
	if (i + 1 == n) {
		return r * x * (1 - x);
	}
	return LogisticMap(i + 1, n, r, r * x * (1 - x));
}
int main(int argv, char** argc) {
	if (argv != 4) {
		return 1;
	}
	int res = 0;
	float x0, r;
	int n;
	res = sscanf(argc[1], "%f", &x0);
	if (res != 1) {
		return 1;
	}
	res = 0;
	res = sscanf(argc[2], "%f", &r);
	if (res != 1) {
		return 1;
	}
	res = 0;
	res = sscanf(argc[3], "%d", &n);
	if (res != 1) {
		return 1;
	}
	if (x0 < 0 || x0 > 1 || r < 0 || n < 0) {
		return 1;
	}
	printf("%f", LogisticMap(0, n, r, x0));
	//0.3 4 52
	//0.120190
	return 0;
}