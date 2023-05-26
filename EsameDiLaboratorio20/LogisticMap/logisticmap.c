#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


double LogisticMap(double x0, int n, double r) {
	if (n == 0) {
		return  x0;
	}
	return LogisticMap((r * x0) * (1 - x0),n-1, r);
}
int main(int argv, char** argc) {
	if (argv != 4) {
		return 1;
	}
	int res = 0;
	double x0, r;
	int n;
	res = sscanf(argc[1], "%lf", &x0);
	if (res != 1) {
		return 1;
	}
	res = 0;
	res = sscanf(argc[2], "%lf", &r);
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
	printf("%lf", LogisticMap(x0,n,r));
	//0.3 4 52
	//0.721109
	return 0;
}